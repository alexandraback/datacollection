package com.congli.gcj;

import java.io.*;
import java.util.*;

public class r1A_2 {

	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok = new StringTokenizer("");

	public static void main(String[] args) {
		r1A_2 test = new r1A_2();
		test.start();
	}

	public void solve() throws IOException 
	{
		int num_test = readInt();
		for(int i = 0; i < num_test; ++i)
		{
			int E = readInt();
			int R = readInt();
			int num_act = readInt();
			int[] vi = new int[num_act];
			for(int j = 0; j < num_act; ++j)
				vi[j] = readInt();
			
			calculate(E, R, vi, i+1);
		}
	}
	
	public void calculate(int E, int R, int[] vi, int case_num)
	{
		int num_act = vi.length;
		int max_poss_val = 0;
		for(int i = 0; i < num_act; ++i)
			max_poss_val += vi[i] * E;
		
		int lowest_spend = R;
		int[][] dp = new int[num_act][max_poss_val+1];
		for(int i = 0; i < num_act; ++i)
			Arrays.fill(dp[i], -1);
		
		for(int i = 0; i <= E; ++i)
		{
			dp[0][i*vi[0]] = Math.min(E, E-i+R);
		}
		
		for(int i = 0; i < num_act-1; ++i)
		{
			for(int j = 0; j <= max_poss_val; ++j)
			{
				if(dp[i][j] != -1)
				{
					for(int k = 0; k <= dp[i][j]; ++k)
					{
						dp[i+1][j + k*vi[i+1]] = Math.max(dp[i+1][j + k*vi[i+1]], Math.min(E, dp[i][j] - k + R));
					}
				}
			}
		}
		
		int result = 0;
		for(int i = 0; i <= max_poss_val; ++i)
		{
			if(dp[num_act-1][i] != -1)
				result = i;
		}
		
		out.println("Case #" + case_num + ": " + result);
	}
	
	public void start()
	{
		try {
			long t1 = System.currentTimeMillis();
			in = new BufferedReader(new FileReader("..\\GCJ\\src\\com\\congli\\gcj\\input.txt"));
			//out = new PrintWriter(new File("..\\GCJ\\src\\com\\congli\\gcj\\output.txt"));
			out = new PrintWriter(System.out);
			Locale.setDefault(Locale.US);
			solve();
			in.close();
			out.close();
			long t2 = System.currentTimeMillis();
			//System.err.println("Time = " + (t2 - t1));
		} catch (Throwable t) {
			t.printStackTrace(System.err);
			System.exit(-1);
		}
	}
	
	public String readString() throws IOException {
		while (!tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public int readInt() throws IOException {
		return Integer.parseInt(readString());
	}

	public long readLong() throws IOException {
		return Long.parseLong(readString());
	}

	public double readDouble() throws IOException {
		return Double.parseDouble(readString());
	}
}