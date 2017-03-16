package actual;
import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;

public class A
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
		new A(argv[0]);
	}
	
	
	public A(String inputFile)
	{
		openInput(inputFile);
		readNextLine();

		int TC = NextInt();
		
		
		for(int tt=0; tt<TC; tt++)
		{	
			
			String output=solve();
			System.out.println("Case #"+(tt+1)+": "+output);
		}
		closeInput();
	}

	private String solve() {
		readNextLine();
		int A=NextInt(), N=NextInt();
		readNextLine();
		int [] p = new int[N];
		for(int i=0; i<N; i++)
			p[i]=NextInt();
		if(A==1)return ""+N;
		Arrays.sort(p);
		int ret=N;
		int added=0;
		for(int i=0; i<N; i++)
		{
			if(p[i]<A)A+=p[i];
			else
			{
				ret=Math.min(ret, added+N-i);
				
				added++;
				A+=(A-1);
				i--;
			}
		}
		ret=Math.min(ret, added);
		
		
		return ""+ret;
	}
	
	

	
}

