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
		Guess [] g = new Guess[64];
		int id=0;
		for(int i=2; i<=5; i++)
			for(int j=2; j<=5; j++)
				for(int k=2; k<=5; k++)
					g[id++]=new Guess(i,j,k);
		
		for(int t=0; t<TC; t++)
		{	
			StringBuilder ret=new StringBuilder();
			readNextLine();
			int R=NextInt();
			int N=NextInt();
			int M=NextInt();
			int K=NextInt();
			for(int r=0; r<R; r++)
			{
				readNextLine();
				TreeSet <Integer> poss = new TreeSet<Integer>();
				for(int i=0; i<64; i++)
					poss.add(i);
				for(int k=0; k<K; k++)
				{					
					int now=NextInt();
					TreeSet <Integer> wrong = new TreeSet<Integer>();
					for(int i:poss)
						if(!g[i].s.contains(now))wrong.add(i);
					poss.removeAll(wrong);
				}
				ret.append(g[poss.pollFirst()]+"\n");
			}
			
			System.out.println("Case #"+(t+1)+":\n"+ret);
		}
		closeInput();
	}

	private class Guess
	{
		int [] g = new int[3];
		TreeSet <Integer> s = new TreeSet<Integer>();
		Guess(int a, int b, int c)
		{
			g[0]=a;
			g[1]=b;
			g[2]=c;
			s.add(a*b*c);
			s.add(a);
			s.add(b);
			s.add(c);
			s.add(a*b);
			s.add(a*c);
			s.add(b*c);
			s.add(1);
		}
		public String toString()
		{
			return ""+g[0]+g[1]+g[2];
		}
	}
	
}

