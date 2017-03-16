package gcj2012r1c;

import java.io.*;
import java.util.*;
import java.util.concurrent.*;

import com.google.*;

/**
 * @author Roman Kosenko <madkite@gmail.com>
 */
public class ADiamondInheritance extends MultiThreadSolution<Object> {
	public static void main(String[] args) throws Exception {
		solve(new SolutionFactory<Object>() {
			public Callable<Object> read(BufferedReader br) throws IOException {
				int n = Integer.parseInt(br.readLine());
				int[][] a = new int[n][n];
				for(int i = 0; i < n; i++) {
					String ss[] = br.readLine().split(" ");
					int m = Integer.parseInt(ss[0]);
					for(int j = 0; j < m; j++) {
						int t = Integer.parseInt(ss[1 + j]) - 1;
						a[i][t] = 1;
						a[t][i] = -1;
					}
				}
				return new ADiamondInheritance(a);
			}
		}, "google/src/gcj2012r1c/" + "A-large.in");
	}
	private final int n;
	private final int[][] a;
	public ADiamondInheritance(int[][] a) {
		this.n = a.length;
		this.a = a;
	}
	public String call() throws Exception {
		return solve() ? "Yes" : "No";
	}
	boolean result;
	private boolean solve() {
		final boolean[] c = new boolean[n];
		new Runnable() {
			@Override
			public void run() {
				for(int i = 0; i < n; i++) {
					Arrays.fill(c, false);
					dfs(i);
				}

			}
			private void dfs(int v) {
				if(c[v]) {
					result = true;
					return;
				}
				c[v] = true;
				for(int i = 0; i < a[v].length; i++) {
					if(a[v][i] > 0)
						dfs(i);
				}
			}
		}.run();
		return result;
	}
}
