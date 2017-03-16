
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class a 
{
	static String path="C:\\Courses\\CodeJam\\roundCa\\";
	static File inputFile=new File(path+"\\"+"input.txt");
	static FileWriter outputFile;
	static Scanner sc;
	static BufferedWriter bw;
	
	public static void main(String[] args)
	{
		int numCases;
		//System.out.println(Integer.MAX_VALUE+" "+10*10*10*10*10*10);
		try{sc=new Scanner(inputFile);}catch(Exception e){}
		
		try{outputFile=new FileWriter(path+"\\"+"output.txt");}catch(Exception e){System.err.println("ERROR1");}
		bw=new BufferedWriter(outputFile);
		
		numCases=sc.nextInt();
		for(int curCase=0;curCase<numCases;curCase++)
		{
			String name=sc.next();
			int num=sc.nextInt();
			
			try{bw.write("Case #"+(curCase+1)+": "+dealWith(name, num)+"\n");}
					//+" ("+name+","+num+")\n");} 
			catch(IOException e){System.err.println("ERROR");}
		}
		
		try{bw.close();}catch(IOException e){}
	}
	
	static int dealWith(String s, int limit)
	{
		int beginIndex=-1;
		int curRow=0;
		int size=s.length();
		int sol=0;
		for(int i=0; i<size;i++)
		{
			if(isVowel(s.charAt(i)))
			{
				curRow=0;
			}
			else
			{
				curRow++;
				if(curRow>=limit)
				{
					int numBefore=i-beginIndex-limit+1;
					int numAfter=size-i;
					//System.out.println(s.substring(0,i+1)+","+s+","+limit);
					//+","+numBefore+","+numAfter
					sol+=numBefore*numAfter;
					beginIndex=i-limit+1;
				}
			}
		}
		return sol;
	}
	
	static boolean isVowel(char s)
	{
		if(s=='a')
		{
			return true;
		}
		if(s=='e')
		{
			return true;
		}
		if(s=='i')
		{
			return true;
		}
		if(s=='o')
		{
			return true;
		}
		if(s=='u')
		{
			return true;
		}
		return false;
	}
}
