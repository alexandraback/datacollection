package codeJam2016;

import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;

public class R1BP2 {
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
		new R1BP2(argv[0]);
	}
	
	public R1BP2(String inputFile)
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
		String a = NextString(), b = NextString();
		
		ArrayList <String> aa = gen(a);
		ArrayList <String> bb = gen(b);
		
		int bestdiff = Integer.MAX_VALUE;
		int bestA = Integer.MAX_VALUE;
		String bestSA = "", bestSB ="";
		for(String sa:aa)
			for(String sb:bb)
			{
				int na = Integer.parseInt(sa);
				int nb = Integer.parseInt(sb);
				int diff = Math.abs(na-nb);
				if(diff<bestdiff)
				{
					bestSA = sa;
					bestSB = sb;
					bestdiff = diff;
					bestA = na;
				}
				else if(diff == bestdiff && na < bestA)
				{
					bestSA = sa;
					bestSB = sb;
					bestdiff = diff;
					bestA = na;
				}
			}
		
		return bestSA+" "+bestSB;
		
		
		
	}

	private ArrayList<String> gen(String a) {
		ArrayList <String> aa = new ArrayList<String>();
		aa.add("");
		for(int i=0; i<a.length(); i++)
		{
			ArrayList <String> tt = new ArrayList<String>();
			if(a.charAt(i)=='?')
			{
				for(String s:aa)
				{
					for(int x=0; x<10; x++)
						tt.add(s+x);
				}
			}
			else
			{
				for(String s:aa)
					tt.add(s+a.charAt(i));
			}
			aa=tt;
		}
		return aa;
	}


}


