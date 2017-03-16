
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class a 
{
	static String path="C:\\Courses\\CodeJam\\roundBa\\";
	static File inputFile=new File(path+"\\"+"input.txt");
	static FileWriter outputFile;
	static Scanner sc;
	static BufferedWriter bw;
	
	public static void main(String[] args)
	{
		int numCases;
		
		try{sc=new Scanner(inputFile);}catch(Exception e){}
		
		try{outputFile=new FileWriter(path+"\\"+"output.txt");}catch(Exception e){System.err.println("ERROR1");}
		bw=new BufferedWriter(outputFile);
		
		numCases=sc.nextInt();
		for(int curCase=0;curCase<numCases;curCase++)
		{
			long start=sc.nextLong();
			int size=sc.nextInt();
			long[] blobs=new long[size];
			
			for(int i=0;i<size;i++)
			{
				blobs[i]=sc.nextLong();
			}
			
			try{bw.write("Case #"+(curCase+1)+": "+dealWith(start, blobs)+"\n");} 
			catch(IOException e){System.err.println("ERROR");}
		}
		
		try{bw.close();}catch(IOException e){}
	}
	
	static long dealWith(long start, long[] iniBlob)
	{
		int size=iniBlob.length;
		
		//Make sure non-trivial case
		if(start<2)
		{
			return size;
		}
		
		//Sort
		Arrays.sort(iniBlob);
		long[] cumBlob=new long[size];
		long[] numToAdd=new long[size];
		long[] moves=new long[size];
		
		
		//Populate cumulative and number of additions
		long toConsume=iniBlob[0];
		long toAdd=start;
		long numTimes=0;
		while(toAdd<=toConsume)
		{
			toAdd+=toAdd-1;
			numTimes++;
		}
		cumBlob[0]=toAdd+toConsume;
		numToAdd[0]=numTimes;
		
		for(int i=1;i<cumBlob.length;i++)
		{
			toConsume=iniBlob[i];
			toAdd=cumBlob[i-1];
			numTimes=0;
			while(toAdd<=toConsume)
			{
				toAdd+=toAdd-1;
				numTimes++;
			}
			cumBlob[i]=toAdd+toConsume;
			numToAdd[i]=numTimes;
		}
		//End add;
		
		int chuckIndex=numToAdd.length;
		int addSince=0;
		for(int i=numToAdd.length-1;i>=0;i--)
		{
			addSince+=numToAdd[i];
			if(chuckIndex-i<=addSince)
			{
				moves[i]=1;
				chuckIndex=i;
				addSince=0;
			}
			
		}
		
		
		long total=0;
		boolean flag=false;
		for(int i=0;i<moves.length;i++)
		{
			if(flag)
			{
				total+=1;
			}
			else
			{
				if(moves[i]==1)
				{
					total+=1;
					flag=true;
				}
				else
				{
					total+=numToAdd[i];
				}
			}
		}
		
		
		return total;
	}
}
