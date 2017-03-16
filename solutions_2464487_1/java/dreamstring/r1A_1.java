package com.congli.gcj;

import java.io.*;
import java.util.*;

public class r1A_1 {

	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok = new StringTokenizer("");

	public static void main(String[] args) {
		r1A_1 test = new r1A_1();
		test.start();
	}

	public void solve() throws IOException 
	{
		int num_test = readInt();
		for(int i = 0; i < num_test; ++i)
		{
			long r = readLong();
			long t = readLong();
			calculate(r, t, i+1);
		}
	}
	
	public void calculate(long r, long t, int case_num)
	{
		long n = 1;
		long sum = cal_sum(r, 1);
		while(sum <= t)
		{
			n *= 2;
			sum = cal_sum(r, n);
		}
		
		long start = n/2;
		long end = n;
		
		while(start < end)
		{
			long mid = start + (end-start)/2;
			sum = cal_sum(r, mid);
			if(sum == t)
			{
				out.println("Case #" + case_num + ": " + mid);
				return;
			}
			else if(sum > t)
				end = mid-1;
			else
				start = mid+1;
		}
		if(cal_sum(r, start) <= t)
			out.println("Case #" + case_num + ": " + start);
		else
			out.println("Case #" + case_num + ": " + (start-1));
	}
	
	public long cal_sum(long r, long n)
	{
		return 2*n*n + (2*r-1)*n;
	}
	
	public void start()
	{
		try {
			long t1 = System.currentTimeMillis();
			in = new BufferedReader(new FileReader("..\\GCJ\\src\\com\\congli\\gcj\\input.txt"));
			out = new PrintWriter(new File("..\\GCJ\\src\\com\\congli\\gcj\\output.txt"));
			//out = new PrintWriter(System.out);
			Locale.setDefault(Locale.US);
			solve();
			in.close();
			out.close();
			long t2 = System.currentTimeMillis();
			System.err.println("Time = " + (t2 - t1));
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