import java.io.*;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	static final int [] mul = {1, 10, 100, 1000, 10000, 100000, 1000000};
	
	int getLen (int num) {
		int ret = 0;
		while (num > 0) {
			num /= 10;
			ret++;
		}
		return ret;
	}
	
	public void solve () throws Exception {
		int tt = nextInt();
		
		for (int test = 1; test <= tt; test++) {
			
			int l = nextInt();
			int r = nextInt();

			long result = 0;
			
			int has [] = new int [r + 1];
			
			for (int num = l; num <= r; num++) {
				int len = getLen(num);
				for (int j = 1; j <= len - 1; j++) {
					if ((num % mul[j]) / mul[j - 1] == 0) continue;
					int numto = num / mul [j] + (num % mul [j]) * mul [len - j];
					if (numto > num && numto <= r) {
						if (has [numto] != num) result++;
						has[numto] = num;
					}
				}
			}
			
			out.println("Case #"+test+": "+result);
			
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