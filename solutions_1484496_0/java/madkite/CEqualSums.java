package gcj2012r1b;

import java.io.*;
import java.util.concurrent.*;

import com.google.*;

/**
 * @author Roman Kosenko <madkite@gmail.com>
 */
public class CEqualSums extends SingleThreadSolution<Object> {
	public static void main(String[] args) throws Exception {
		solve(new SolutionFactory<Object>() {
			public Callable<Object> read(BufferedReader br) throws IOException {
				String ss[] = br.readLine().split(" ");
				int n = Integer.parseInt(ss[0]);
				assert ss.length == n + 1;
				long[] a = new long[n];
				for(int i = 0; i < n; i++)
					a[i] = Long.parseLong(ss[1 + i]);
				return new CEqualSums(a);
			}
		}, "google/src/gcj2012r1b/" + "C-small-attempt0.in");
	}
	private final long[] a;
	public CEqualSums(long[] a) {
		this.a = a;
	}
	public String call() throws Exception {
		long[][] result = solve();
		StringBuilder sb = new StringBuilder();
		if(result != null) {
			for(int i = 0; i < result.length; i++) {
				sb.append('\n');
				for(int j = 0; j < result[i].length; j++) {
					if(j != 0)
						sb.append(' ');
					sb.append(result[i][j]);
				}
			}
		} else
			sb.append("Impossible");
		return sb.toString();
	}
	private long[][] solve() {
		long[] s = new long[1 << a.length];
		for(int i = 1; i < s.length; i++) {
			long sum = 0;
			for(int t = i, j = 0; t != 0; j++, t >>>= 1) {
				if((t & 1) != 0)
					sum += a[j];
			}
			for(int l = 1; l < i; l++) {
				if(s[l] == sum) {
					long[][] result = new long[2][];
					int n = 0;
					for(int t = l, j = 0; t != 0; j++, t >>>= 1) {
						if((t & 1) != 0)
							n++;
					}
					result[0] = new long[n];
					for(int t = l, j = 0, k = 0; t != 0; j++, t >>>= 1) {
						if((t & 1) != 0)
							result[0][k++] = a[j];
					}
					n = 0;
					for(int t = i, j = 0; t != 0; j++, t >>>= 1) {
						if((t & 1) != 0)
							n++;
					}
					result[1] = new long[n];
					for(int t = i, j = 0, k = 0; t != 0; j++, t >>>= 1) {
						if((t & 1) != 0)
							result[1][k++] = a[j];
					}
					return result;
				}
			}
			s[i] = sum;
		}
		return null;
	}
}
