package y2016r1A;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class C {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer buffer;
	
	public static void solve() throws Exception {
		int T = ni();
		for (int t=0;t<T;t++) {
			int N = ni();
			int[]bff = new int[N+1];
			for (int i=1;i<=N;i++) bff[i] = ni();
			
			List<Integer>[]ch = new List[N+1];

			boolean[]used = new boolean[N+1];
			boolean[]canCont = new boolean[N+1];
			boolean[]good = new boolean[N+1];
			for (int i=1;i<=N;i++) {
				ch[i] = new ArrayList<Integer>();
				ch[i].add(i);
				Arrays.fill(used, false);
				used[i] = true;
				int f = bff[i];
				while (!used[f]) {
					ch[i].add(f);
					used[f] = true;
					f = bff[f];
				}
				if (f == ch[i].get(ch[i].size()-2)) canCont[i] = true;
				if (canCont[i]) good[i] = true;
				else {
					if (f == ch[i].get(0)) good[i] = true;
				}
			}
		
			int max = -1;
			if (N<=3) max = N;
			else {
				for (int i=1;i<=N;i++) {
					if (max == N) break;
					if (!good[i]) continue;
					int size = ch[i].size();
					max = Math.max(max, size);
					if (canCont[i]) {
						Arrays.fill(used, false);
						for (Integer x: ch[i]) used[x] = true;
						int last = ch[i].get(ch[i].size()-1);
						for (int j=1;j<=N;j++) {
							int plus = 0;
							if (j==i) continue;
							int pos = 0;
							while (pos<ch[j].size() && ch[j].get(pos)!=last) pos++;
							if (pos<ch[j].size()) {
								pos--;
								while (pos>=0 && !used[ch[j].get(pos)]) {
									plus++;
									pos--;
								}
							}
							max = Math.max(max, size+plus);
						}					
					}
				}
			}
			out.println("Case #"+(t+1)+": " + max);
		}
		
	}

	public static void main(String[] args) throws IOException, Exception {
		in = new BufferedReader(new FileReader(new File("/tmp/c1.in")));
		out = new PrintWriter(new FileWriter(new File("/tmp/c1_out.in")));
		solve();
		out.close();
	}

	static String next() {
		while (buffer == null || !buffer.hasMoreElements()) {
			try {
				buffer = new StringTokenizer(in.readLine());
			} catch (IOException e) {
			}
		}
		return buffer.nextToken();
	}

	static int ni() {
		return Integer.parseInt(next());
	}

	static long nl() {
		return Long.parseLong(next());
	}

	static double nd() {
		return Double.parseDouble(next());
	}

	static String ns() {
		return next();
	}

	static int[] ni(int n) {
		int[] res = new int[n];
		for (int i = 0; i < n; i++)
			res[i] = Integer.parseInt(next());
		return res;
	}

	static long[] nl(int n) {
		long[] res = new long[n];
		for (int i = 0; i < n; i++)
			res[i] = Long.parseLong(next());
		return res;
	}

	static double[] nd(int n) {
		double[] res = new double[n];
		for (int i = 0; i < n; i++)
			res[i] = Double.parseDouble(next());
		return res;
	}

	static String[] ns(int n) {
		String[] res = new String[n];
		for (int i = 0; i < n; i++)
			res[i] = next();
		return res;
	}
}
