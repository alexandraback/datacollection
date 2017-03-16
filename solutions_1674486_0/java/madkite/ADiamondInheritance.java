package gcj2012r1c;

import java.io.*;
import java.util.*;
import java.util.concurrent.*;

import com.google.*;

/**
 * @author Roman Kosenko <madkite@gmail.com>
 */
public class ADiamondInheritance extends SingleThreadSolution<Object> {
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
		}, "google/src/gcj2012r1c/" + "A-small-attempt3.in");
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
		final int[] c = new int[n];
		new Runnable() {
			@Override
			public void run() {
				for(int i = 0; i < n; i++) {
					Arrays.fill(c, 0);
					dfs(i);
				}

			}
			private void dfs(int v) {
				if(c[v] != 0) {

					if(c[v] == 2)
						result = true;
					return;
				}
				c[v] = 1;
				for(int i = 0; i < a[v].length; i++) {
					if(a[v][i] > 0)
						dfs(i);
				}
				c[v] = 2;
			}
			/*
			private void dfs(int v, int d, int p) {
				if(c[v] != 0) {
					if(d == -1 && c[v] == 3) {
						result = true;
					}
					return;
				}
				c[v] = 2 + d;
				for(int i = 0; i < a[v].length; i++) {
					if(a[v][i] != 0 && i != p) {
						if(d == 1 || a[v][i] == -1)
							dfs(i, a[v][i], v);
					}

				}
				c[v] = d == 1 ? 4 : 0;
			}
			*/
		}.run();
		return result;
	}
}
