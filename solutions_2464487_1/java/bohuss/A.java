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
			
			String output=solve();
			System.out.println("Case #"+(tt+1)+": "+output);
		}
		closeInput();
	}

	private String solve() {
		readNextLine();
		long R=NextLong()*2+1, T=NextLong();
		long ret=0;
		long L=0, r=707106785L;
		long m=(L+r)/2;
		while(L+1<r)
		{
			m=(L+r)/2;
			long now=(m-1)*m*2;

			now+=m*R;
			
			if(now<=T&&now>=0)L=m;
			else r=m;
		}
		long now=(L)*(L+1)*2;
		now+=(L+1)*R;
		if(now<=T)ret=L+1;
		else ret=L;
		return ""+ret;
	}
	
	

	
}

