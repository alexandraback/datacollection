package gcj2012r1c;

import java.io.*;
import java.util.*;
import java.util.concurrent.*;

import com.google.*;

/**
 * @author Roman Kosenko <madkite@gmail.com>
 */
public class CBoxFactory extends SingleThreadSolution<Object> {
	public static void main(String[] args) throws Exception {
		solve(new SolutionFactory<Object>() {
			public Callable<Object> read(BufferedReader br) throws IOException {
				String[] ss = br.readLine().split(" ");
				assert ss.length == 2;
				int n = Integer.parseInt(ss[0]), m = Integer.parseInt(ss[1]);
				long[] c1 = new long[n], c2 = new long[m];
				int[] t1 = new int[n], t2 = new int[m];
				ss = br.readLine().split(" ");
				assert ss.length == n * 2;
				for(int i = 0; i < n; i++) {
					c1[i] = Long.parseLong(ss[i * 2]);
					t1[i] = Integer.parseInt(ss[i * 2 + 1]);
				}
				ss = br.readLine().split(" ");
				assert ss.length == m * 2;
				for(int i = 0; i < m; i++) {
					c2[i] = Long.parseLong(ss[i * 2]);
					t2[i] = Integer.parseInt(ss[i * 2 + 1]);
				}
				return new CBoxFactory(c1, t1, c2, t2);
			}
		}, "google/src/gcj2012r1c/" + "C-small-attempt0.in");
	}
	private final long[] c1, c2;
	private final int[] t1, t2;
	private final int n, m;
	public CBoxFactory(long[] c1, int[] t1, long[] c2, int[] t2) {
		this.n = t1.length;
		this.m = t2.length;
		this.c1 = c1;
		this.t1 = t1;
		this.c2 = c2;
		this.t2 = t2;
	}
	public String call() throws Exception {
		return Long.toString(solve());
	}
	private long solve() {
		long result = 0;

		if(n == 1) {
			long c = 0;
			for(int i = 0; i < m; i++) {
				if(t2[i] == t1[0])
					c += c2[i];
			}
			result = Math.min(c1[0], c);
		} else if(n == 2) {
			for(int i1 = 0; i1 <= m; i1++) {
				long c[] = new long[n];
				for(int i = 0; i < i1; i++) {
					if(t2[i] == t1[0])
						c[0] += c2[i];
				}
				for(int i = i1; i < m; i++) {
					if(t2[i] == t1[1])
						c[1] += c2[i];
				}
				long s = 0;
				for(int j = 0; j < n; j++)
					s += Math.min(c1[j], c[j]);
				result = Math.max(result, s);
			}
		} else if(n == 3) {
			for(int i1 = 0; i1 <= m; i1++) {
				for(int i2 = i1; i2 <= m; i2++) {
					long c[] = new long[n];
					for(int i = 0; i < i1; i++) {
						if(t2[i] == t1[0])
							c[0] += c2[i];
					}
					int t3 = -1; long c3 = 0;
					if(i1 > 0 && t2[i1 - 1] == t1[0] && c[0] > c1[0]) {
						t3 = t2[i1 - 1];
						c3 = c[0] - c1[0];
						if(t3 == t1[1])
							c[1] += c3;
					}
					for(int i = i1; i < i2; i++) {
						if(t2[i] == t1[1])
							c[1] += c2[i];
					}
					if(i2 > 0 && t2[i2 - 1] == t1[1] && c[1] > c1[1]) {
						t3 = t2[i2 - 1];
						c3 = c[1] - c1[1];
						if(t3 == t1[2])
							c[2] += c3;
					} else if(c[1] == 0) {
						if(t3 == t1[2])
							c[2] += c3;
					}
					for(int i = i2; i < m; i++) {
						if(t2[i] == t1[2])
							c[2] += c2[i];
					}
					long s = 0;
					for(int j = 0; j < n; j++)
						s += Math.min(c1[j], c[j]);
					//System.out.println(i1 + "/" + i2 + " - " + s);
					result = Math.max(result, s);
				}
			}
		}
		return result;
	}
}
