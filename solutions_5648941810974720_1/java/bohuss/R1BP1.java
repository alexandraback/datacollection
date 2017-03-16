package codeJam2016;

import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;

public class R1BP1 {
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
		new R1BP1(argv[0]);
	}
	
	public R1BP1(String inputFile)
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
		String s = line;
		
		return solve(s);
		
	}
	
	private String solve(String s){
		String [] nums = new String [] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"}; 
		
		int [] p = new int[10];
		int N = s.length();
		
		int [] c = new int[26];
		
		for(int i=0; i<N; i++)
			c[s.charAt(i)-'A']++;
		p[0]=c['Z'-'A'];
		p[2]=c['W'-'A'];
		p[6]=c['X'-'A'];
		p[8]=c['G'-'A'];
		c['Z' - 'A']-=p[0];
		c['E' - 'A']-=p[0];
		c['R' - 'A']-=p[0];
		c['O' - 'A']-=p[0];
		c['T' - 'A']-=p[2];
		c['W' - 'A']-=p[2];
		c['O' - 'A']-=p[2];
		c['S' - 'A']-=p[6];
		c['I' - 'A']-=p[6];
		c['X' - 'A']-=p[6];
		c['E' - 'A']-=p[8];
		c['I' - 'A']-=p[8];
		c['G' - 'A']-=p[8];
		c['H' - 'A']-=p[8];
		c['T' - 'A']-=p[8];
		p[7]=c['S'-'A'];
		c['S' - 'A']-=p[7];
		c['E' - 'A']-=p[7];
		c['V' - 'A']-=p[7];
		c['E' - 'A']-=p[7];
		c['N' - 'A']-=p[7];
		p[5]=c['V'-'A'];
		c['F' - 'A']-=p[5];
		c['I' - 'A']-=p[5];
		c['V' - 'A']-=p[5];
		c['E' - 'A']-=p[5];
		p[4]=c['F'-'A'];
		c['F' - 'A']-=p[4];
		c['O' - 'A']-=p[4];
		c['U' - 'A']-=p[4];
		c['R' - 'A']-=p[4];
		p[1]=c['O'-'A'];
		c['O' - 'A']-=p[1];
		c['N' - 'A']-=p[1];
		c['E' - 'A']-=p[1];
		p[3]=c['T'-'A'];
		c['T' - 'A']-=p[3];
		c['H' - 'A']-=p[3];
		c['R' - 'A']-=p[3];
		c['E' - 'A']-=p[3];
		c['E' - 'A']-=p[3];
		p[9]=c['I'-'A'];
		c['N' - 'A']-=p[9];
		c['I' - 'A']-=p[9];
		c['N' - 'A']-=p[9];
		c['E' - 'A']-=p[9];
		
		for(int i=0; i<26; i++)
			assert(c[i]==0);
		
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<10; i++)
		{
			for(int j=0; j<p[i]; j++)
				sb.append(i);
		}
		return sb.toString();
		
	}
	
	
}


