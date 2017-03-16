
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class b
{
	static String path="C:\\Courses\\CodeJam\\roundCb\\";
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
			long X=sc.nextLong();
			long Y=sc.nextLong();
			
			try{bw.write("Case #"+(curCase+1)+": "+dealWith(X,Y)+"\n");} 
			catch(IOException e){System.err.println("ERROR");}
		}
		
		try{bw.close();}catch(IOException e){}
	}
	
	static String dealWith(long X, long Y)
	{
		String ret="";
		long curX=0;
		long curY=0;
		while(curX<X)
		{
			curX++;
			ret+="WE";
		}
		while(curX>X)
		{
			curX--;
			ret+="EW";
		}
		while(curY<Y)
		{
			curY++;
			ret+="SN";
		}
		while(curY>Y)
		{
			curY--;
			ret+="NS";
		}
		return ret;
	}
}
