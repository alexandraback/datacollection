package actual;
import java.io.*;
import java.util.*;

public class B
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
	
	double NextDouble()
	{
		String n = inputParser.nextToken();
		double val = Double.parseDouble(n);
		
		//System.out.println("I read this number: " + val);
		return val;
	}
	
	int NextInt()
	{
		String n = inputParser.nextToken();
		int val = Integer.parseInt(n);
		
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
		new B(argv[0]);
	}

	public B(String inputFile)
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
		int N=NextInt();
		String [] s=new String[N];
		int [] p = new int[N];
		readNextLine();
		for(int i=0; i<N; i++)
		{
			s[i]=NextString();
			p[i]=i;
		}
		int ret=0;
		do
		{
			StringBuilder sb = new StringBuilder();
			for(int i=0; i<N; i++)
				sb.append(s[p[i]]);
			if(ok(sb.toString()))ret++;
		}while(next_permutation(p));
		return ""+ret;
	}
	
	private boolean ok(String x) {
		StringBuilder sb = new StringBuilder();
		sb.append(x.charAt(0));
		
		for(int i=1; i<x.length(); i++)
			if(x.charAt(i)!=x.charAt(i-1))sb.append(x.charAt(i));
		String string = sb.toString();
		for(char c='a'; c<='z'; c++)
		{
			boolean done=false;
			boolean first=false;
			int id=string.indexOf(c);
			if(id==-1)continue;
			for(int i=id; i<string.length(); i++)
			{
				if(string.charAt(i)==c)
				{
					if(!first)
					{
						first=true;
					}
					else
					{
						if(done)return false;
					}
				}
				else
				{
					if(first)done=true;
				}
			}
		}
		
		return true;
	}

	boolean next_permutation(int[] p) {
		for (int a = p.length - 2; a >= 0; --a)
			if (p[a] < p[a + 1])
				for (int b = p.length - 1;; --b)
					if (p[b] > p[a]) {
						int t = p[a];
						p[a] = p[b];
						p[b] = t;
						for (++a, b = p.length - 1; a < b; ++a, --b) {
							t = p[a];
							p[a] = p[b];
							p[b] = t;
						}
						return true;
					}
		return false;
	}
	
	
}

