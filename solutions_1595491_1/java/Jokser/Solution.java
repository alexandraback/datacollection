import java.io.*;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	int sum1 []; // diff < 2
	int sum2 []; // diff == 2
	
	public void solve () throws Exception {
		int tt = nextInt();
		
		sum1 = new int [31];
		sum2 = new int [31];
		
		for (int num1 = 0; num1 <= 10; num1++)
			for (int num2 = num1; num2 <= 10; num2++)
				for (int num3 = num2; num3 <= 10; num3++) {
					int sum = num1 + num2 + num3;
					int diff = num3 - num1;
					if (diff < 2) {
						sum1 [sum] = max (sum1 [sum], num3);
					} else if (diff == 2) {
						sum2 [sum] = max (sum2 [sum], num3);
					}
				}
		
		for (int test = 1; test <= tt; test++) {
			int n = nextInt();
			int s = nextInt();
			int p = nextInt();
			
			int d [][] = new int [n + 1][s + 1];
			boolean can [][] = new boolean [n + 1][s + 1];
			can [0][0] = true;
			
			for (int i = 0; i < n; i++) {
				int sum = nextInt();
				int add1 = 0, add2 = 0;
				
				int p1 = sum1[sum]; if (p1 >= p) add1 = 1;
				int p2 = sum2[sum]; if (p2 >= p) add2 = 1;
				
				for (int j = 0; j <= s; j++) {
					if (can[i][j]) {
						
						d[i + 1][j] = max (d[i + 1][j], d[i][j] + add1);
						can[i + 1][j] = true;
						
						if (j < s) {
							d[i + 1][j + 1] = max (d[i + 1][j + 1], d[i][j] + add2);
							can [i + 1][j + 1] = true;
						}
						
					}
				}
			}
			
			out.println("Case #"+test+": "+d[n][s]);
			
		}
	}
	
	final String fname = "";
	long stime = 0;
	
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
		new Thread(null, new Solution(), "", 1<<26).start();
	}

}