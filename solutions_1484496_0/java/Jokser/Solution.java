import java.io.*;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	int n;
	int a [];
	int to [];
	ArrayList<Integer> first;
	ArrayList<Integer> second;
	boolean find;
	
	void brutforce (int k, int sum1, int sum2) {
		if (find) return;
		if (k == n) {
			if (sum1 == sum2 && sum1 != 0) {
				find = true;
				for (int i = 0; i < n; i++) {
					if (to [i] == 1) {
						first.add(a [i]);
					}
					if (to [i] == 2) {
						second.add(a [i]);
					}
				}
			}
			return;
		}
		to [k] = 0;
		brutforce (k + 1, sum1, sum2);
		to [k] = 1;
		brutforce (k + 1, sum1 + a [k], sum2);
		to [k] = 2;
		brutforce (k + 1, sum1, sum2 + a [k]);
	}
	
	public void solve () throws Exception {
		int t = nextInt();
		for (int test = 1; test <= t; test++) {
			n = nextInt();
			a = new int [n];
			for (int i = 0; i < n; i++) {
				a [i] = nextInt();
			}
			to = new int [n];
			find = false;
			first = new ArrayList<Integer>();
			second = new ArrayList<Integer>();
			brutforce (0, 0, 0);
			
			out.println("Case #"+test+":");
			if (find) {
				for (int num : first) {
					out.print(num+" ");
				}
				out.println();
				for (int num : second) {
					out.print(num+" ");
				}
				out.println();
			} else {
				out.println("Impossible");
			}
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