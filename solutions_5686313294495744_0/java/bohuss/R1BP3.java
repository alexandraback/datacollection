package codeJam2016;

import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;

public class R1BP3 {
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
		new R1BP3(argv[0]);
	}
	
	public R1BP3(String inputFile)
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
		String [] a = new String[N];
		String [] b = new String[N];
		for(int i=0; i<N; i++)
		{
			readNextLine();
			a[i]=NextString();
			b[i]=NextString();
		}
		int res = 0;
		
		for(int i=0; i<1<<N; i++)
		{
			HashSet <String> origA = new HashSet<String>();
			HashSet <String> origB = new HashSet<String>();
			ArrayList <String> fakeA = new ArrayList<String>();
			ArrayList <String> fakeB = new ArrayList<String>();
			for(int j=0; j<N; j++)
			{
				if((i&(1<<j))>0)
				{
					origA.add(a[j]);
					origB.add(b[j]);
				}
				else
				{
					fakeA.add(a[j]);
					fakeB.add(b[j]);
				}
			}
			if(poss(origA, origB, fakeA, fakeB))
			{
				res = Math.max(res, fakeA.size());
			}
		}
		
		
		return ""+res;
		
	}

	private boolean poss(HashSet<String> origA, HashSet<String> origB,
			ArrayList<String> fakeA, ArrayList<String> fakeB) {
		for(String a:fakeA)
			if(!origA.contains(a))return false;
		for(String b:fakeB)
			if(!origB.contains(b))return false;
		return true;
	}
}


