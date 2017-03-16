package actual;
import java.io.*;
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
			readNextLine();
			String output=solve();
			System.out.println("Case #"+(tt+1)+": "+output);
		}
		closeInput();
	}

	private String solve() {
		StringBuilder ret=new StringBuilder();
		int N=NextInt();
		int [] s = new int [N];
		int sum=0;
		for(int i=0; i<N; i++)
		{
			s[i]=NextInt();
			sum+=s[i];
		}
		
		double [] a = new double [N];
		for(int i=0; i<N; i++)
		{
			int X2=sum-s[i];
			a[i]=X2-(N-1)*s[i]+sum;
			a[i]/=(double)(N*sum);
			a[i]*=100;
			
			
		}
		
		double sumo=0, sumu=0;
		int cnt=0;
		for(int i=0; i<N; i++)
		{
			if(a[i]>0)
			{
				sumo+=a[i];
				cnt++;
			}
			else 
			{
				sumu+=a[i];
				a[i]=0;
			}
		}
		sumu*=-1;
		double test=0;
		for(int i=0; i<N; i++)
		{
			if(a[i]>0)
			{
				a[i]-=sumu/(double)cnt;
			}
			test+=a[i];
		}
		
		for(int i=0; i<N; i++)
			ret.append(a[i]+" ");
		
		
		return ret.toString();
	}

	
}

