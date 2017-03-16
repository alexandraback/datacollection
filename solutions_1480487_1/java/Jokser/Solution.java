import java.io.*;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	public void solve () throws Exception {
		int t = nextInt();
		for (int test = 1; test <= t; test++) {
			int n = nextInt();
			int a [] = new int [n];
			int sum = 0;
			int maxVal = 0;
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
				sum += a[i];
				maxVal = max (maxVal, a[i]);
			}
			
			double l = 0;
			double r = 3 * sum;
			
			for (int it = 0; it < 50; it++) {
				double value = (r + l) / 2.0;
				double frac = 0.0;
				for (int i = 0; i < n; i++) {
					if (value - a [i] > 0)
						frac += (double)(value - a [i]) / sum; 
				}
				if (frac > 1.0) {
					r = value;
				} else {
					l = value;
				}
			}
			double f [] = new double [n];
			
			out.print("Case #"+test+":");
			
			for (int i = 0; i < n; i++) {
				if (l - a[i] > 0)
				f [i] = (double)(l - a[i]) / sum;
				//out.println(f [i]);
				out.printf(" %.6f", f[i] * 100.0);
			}
			out.println();
		}
	}
	
	static final String fname = "";
	static long stime = 0;
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;
	
	private String nextToken () throws Exception {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
	
	private int nextInt () throws Exception {
		return Integer.parseInt(nextToken());
	}
	
	private long nextLong () throws Exception {
		return Long.parseLong(nextToken());
	}
	
	private double nextDouble () throws Exception {
		return Double.parseDouble(nextToken());
	}
	
	@Override
	public void run() {
		try {
			Locale.setDefault(Locale.US);
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter(new FileWriter("output.txt"));
			solve ();
		} catch (Exception e) {
			throw new RuntimeException(e);
		} finally {
			out.close();
		}
	}
	
	public static void main(String[] args) {
		new Thread(null, new Solution(), "", 1<<25).start();
	}

}