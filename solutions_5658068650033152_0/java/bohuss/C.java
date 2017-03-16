package actual;
import java.io.*;
import java.util.*;

public class C
{
	String line;
	StringTokenizer inputParser;
	BufferedReader is;
	FileInputStream fstream;
	DataInputStream in;
	
	void openInput(String file)
	{

		//is = new BufferedReader(new InputStreamReader(System.in));//stdin
		try{
			fstream = new FileInputStream(file);
			in = new DataInputStream(fstream);
			is = new BufferedReader(new InputStreamReader(in));
		}catch(Exception e)
		{
			System.err.println(e);
		}

	}
	
	void readNextLine()
	{
		try {
			line = is.readLine();
			inputParser = new StringTokenizer(line, " ");
			//System.err.println("Input: " + line);
		} catch (IOException e) {
			System.err.println("Unexpected IO ERROR: " + e);
		}	
		
	}
	
	int NextInt()
	{
		String n = inputParser.nextToken();
		int val = Integer.parseInt(n);
		
		//System.out.println("I read this number: " + val);
		return val;
	}
	
	long NextLong()
	{
		String n = inputParser.nextToken();
		long val = Long.parseLong(n);
		
		//System.out.println("I read this number: " + val);
		return val;
	}
	
	String NextString()
	{
		String n = inputParser.nextToken();
		return n;
	}
	
	void closeInput()
	{
		try {
			is.close();
		} catch (IOException e) {
			System.err.println("Unexpected IO ERROR: " + e);
		}
			
	}
	
	public static void main(String [] argv)
	{
		new C(argv[0]);
	}
	
	
	public C(String inputFile)
	{
		openInput(inputFile);
		readNextLine();

		int TC = NextInt();
		
		for(int t=0; t<TC; t++)
		{	
			
			readNextLine();
			int N=NextInt();
			int M=NextInt();
			int K=NextInt();
			
			int ret=solve(N, M, K);
			
			//System.out.println(line);
			
			System.out.println("Case #"+(t+1)+": "+ret);
		}
		closeInput();
	}

	private int solve(int N, int M, int K) {
		if(N>M)
		{
			int tm=N;
			N=M;
			M=tm;
		}
		
		if(K<5)return K;
		
		if(N<3)return K;
		int X=N*M;
		
		int d=5,ret=4;
		while(d<K)
		{
			if(d+1==K)return ret+1;
			if(d+2==K)return ret+2;
			ret+=2;
			d+=3;
		}
		if(K+4>X)
		{
			ret=N*2;
			ret+=2*(M-2);
			ret-=(N*M)-K;
		}
		return ret;
	}


	
	
}

