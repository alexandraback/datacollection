package com.mavtushenko.gcj.r1b;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.StringTokenizer;

public class App2 
{
	public void solve() {
		int t = in.nextInt();
		caseNb:
		for (int caseN = 0; caseN < t; ++caseN) {
			out.print("Case #" + (caseN + 1) + ": ");
			int n = in.nextInt();
			int x = in.nextInt();
			int y = in.nextInt();
			int cur = 1;
			int lvl = 0;
			while (cur <= n) {
				n -= cur;
				cur += 4;
				lvl++;
			}
//			System.out.println(lvl + " " + cur + " " + n);
			double res = 0.0;
			int temp = (Math.abs(x) + y) / 2;
			if  ( temp < lvl ) {
				res = 1.0;
			} else if (temp > lvl ) {
				res = 0.0;
			} else if ((temp == lvl) && n == 0) {
				res = 0.0;
			} else {
				int side = (cur - 1) / 2;
				if (y + 1 != side + 1) {
					if (n <= side) {
						if (y + 1 <= n) {
							long r = 0;
							for (int i = 0; i < y + 1; ++i) {
								r = r + fact(n, i);
							}
							res = (double) r;
							for (int i = 0; i < n; ++i)
								res = res / 2;
							res = (double)1.0 - res;
						} else {
							res = 1.0;
						}
					} else {
						res = 1.0;
						int k = side - (n - side);
						long r = 0;
						if (y + 1 > n - side) {
							for (int i = k; i < y + 1; ++ i)
								r = r + fact(k, i - k);
							res = (double) r;
							for (int i = 0; i < k; ++i)
								res = res / 2;
							res = (double)1.0 - res;
						}
					}
				}
			}
			StringWriter sw = new StringWriter();
			PrintWriter pw = new PrintWriter(sw);
			pw.printf("%.6f", res);
			out.println(sw.toString());//.replaceAll("\\.?0*$", ""));
		}
	}
	
	public long fact(int n, int k) {
		long res = 1;
		if (k > 0) {
			for (long i = n - k + 1; i <= n; ++i) {
				res = res * i;
			}
			for (long i = 2; i <= k; ++i) {
				res = res / i;
			}
		}
		return res;
	}
	public static void main( String[] args ) {
		new App2().run();
	}
	
	FastScanner in;
	PrintWriter out;

	public void run() {
		try {
	    	out = new PrintWriter(new File("B-small-attempt2.out"));
			in = new FastScanner(new FileInputStream("B-small-attempt2.in"));
			solve();
			out.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	
    }
    
	class FastScanner {

		BufferedReader br;
		StringTokenizer st;

		FastScanner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

}
