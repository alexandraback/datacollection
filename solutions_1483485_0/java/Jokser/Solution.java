import java.io.*;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	int mapping [] = {24, 7, 4, 18, 14, 2, 21, 23, 3, 20, 8, 6, 11, 1, 10, 17, 25, 19, 13, 22, 9, 15, 5, 12, 0, 16};
	
	public void solve () throws Exception {
		int tt = nextInt();
		for (int test = 1; test <= tt; test++) {
			String s = in.readLine();
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) == ' ') {
					sb.append(s.charAt(i));
					continue;
				}
				int c = s.charAt(i) - 'a';
				char cc = (char) (mapping[c] + 'a');
				sb.append(cc);
			}
			out.println("Case #"+test+": "+sb.toString());
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