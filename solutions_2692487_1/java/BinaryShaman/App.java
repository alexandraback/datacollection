package com.mavtushenko.gcj.r1b;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class App 
{
	public void solve() {
		int t = in.nextInt();
		caseNb:
		for (int caseN = 0; caseN < t; ++caseN) {
			out.print("Case #" + (caseN + 1) + ": ");
			int n = in.nextInt();
			int m = in.nextInt();
			int ss[] = new int[m];
			for (int i = 0; i < m; ++i) {
				ss[i] = in.nextInt();
			}
			
			Arrays.sort(ss);
			if (n == 1) {
				out.println(m);
				continue;
			}
			boolean need = false;
			int cur = 0;
			int curAdd = 0;
			int add[] = new int[m];
			while (cur < m) {
				if (n > ss[cur]) {
					n += ss[cur];
					add[cur] = curAdd;
					curAdd = 0;
					++cur;
					if (n > 1000000)
						break;
				} else {
					need = true;
					n += (n - 1);
					curAdd++;
				}
			}
			
			int skip = 1;
			int last = -1;
			int res = 0;
			for (int i = 1; i <= m; ++i) {
				if (add[m - i] >= skip) {
					last = m - i - 1;
					res += skip;
					skip = 1;
				} else {
					skip++;
				}
			}
			if (need && res == 0)
				last = m - 1;
			if (last >= 0) {
				for (int i = 0; i <= last; ++i)
					res += add[i];
			}
			out.println(res);
		}
	}
	
	public static void main( String[] args ) {
		new App().run();
	}
	
	FastScanner in;
	PrintWriter out;

	public void run() {
		try {
	    	out = new PrintWriter(new File("A-large.out"));
			in = new FastScanner(new FileInputStream("A-large.in"));
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
