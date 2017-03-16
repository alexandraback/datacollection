package com.congli.gcj;

import java.io.*;
import java.util.*;

public class r1A_3 {

	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok = new StringTokenizer("");

	public static void main(String[] args) {
		r1A_3 test = new r1A_3();
		test.start();
	}

	public void solve() throws IOException 
	{
		int useless = readInt();
		
		int R = readInt();
		int N = readInt();
		int M = readInt();
		int K = readInt();
		
		for(int i = 0; i < R; ++i)
		{
			HashSet<Integer> set = new HashSet<Integer>();
			for(int j = 0; j < K; ++j)
				set.add(readInt());
			int[] result = new int[N];
			dfs(set, N, M, K, 0, result);
		}
	}
	
	public boolean dfs(HashSet<Integer> set, int N, int M, int K, int level, int[] result)
	{
		if(level == N)
		{
			if(is_valid(set, result)) 
			{
				for(int i = 0; i < result.length; ++i)
					out.print(result[i]);
				out.println();
				return true;
			}
			return false;
		}
		
		for(int i = 2; i <= M; ++i)
		{
			result[level] = i;
			if(dfs(set, N, M, K, level+1, result))
				return true;
		}
		return false;
	}
	
	public boolean is_valid(HashSet<Integer> set_old, int[] s) 
    {
		HashSet<Integer>set = (HashSet<Integer>) set_old.clone();
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        
        for(int marker = 0; marker <= ((1<<s.length)-1); ++marker)
        {
            ArrayList<Integer> list = new ArrayList<Integer>();
            int temp = marker;
            for(int i = 0; i < s.length; ++i)
            {
                if((temp & 1) == 1)
                    list.add(s[i]);
                temp = (temp >> 1);
            }
            int product = 1;
            for(Integer aa : list)
            	product *= aa;
            if(set.contains(product))
            	set.remove(product);
            if(set.isEmpty()) return true;
            result.add(list);
        }
        return false;
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