import static java.util.Arrays.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import java.util.*;
import java.math.*;
import java.io.*;

public class C implements Runnable
{
	String file = "C-small-attempt0";
	
	void init() throws IOException {
		input = new BufferedReader(new FileReader(file + ".in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));
	}
	
	void solve() throws IOException {
		int n = nextInt();
		boolean[][] ok = new boolean[n + 1][n + 1];
		for (int i = 1; i <= n; i++) {
			int u = nextInt();
			ok[i][u] = true;
		}
		int res = 0;
		int[] a = new int[n];
		
		for (int mask = 1; mask < 1 << n; mask++) {
			int k = 0;
			for (int i = 0; i < n; i++)
				if ((mask >> i & 1) != 0) a[k++] = i + 1;
			if (k <= 1) continue;
			if (k <= res) continue;
			int[] b = Arrays.copyOf(a, k);
			do {
				boolean can = true;
				for (int i = 1; i < k - 1; i++)
					if (!ok[b[i]][b[i + 1]] && !ok[b[i]][b[i - 1]]) {
						can = false;
						break;
					}
				if (!can) continue;
				if (!ok[b[0]][b[1]] && !ok[b[0]][b[k - 1]]) continue;
				if (!ok[b[k - 1]][b[k - 2]] && !ok[b[k - 1]][b[0]]) continue;
				res = max(res, k);
				break;
			} while (next_permutation(b));
		}
		gcj(res);
	}
	
	public boolean next_permutation(int[] a)
	{
		int n = a.length;
		int i = n - 2;
		while(i >= 0 && a[i] >= a[i + 1]) i--;
		if(i == -1) return false;
		int x = a[i];
		int j = n - 1;
		while(a[j] <= x) j--;
		a[i] = a[j];
		a[j] = x;
			
		i++; j = n - 1;
		while(i < j) { int t = a[i]; a[i] = a[j]; a[j] = t; i++; j--; } 
		return true;
	}
	
	String next() throws IOException {
		if(st == null || !st.hasMoreTokens()) st = new StringTokenizer(input.readLine());
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	void debug(Object... o) {
		System.out.println(deepToString(o));
	}
	
	void gcj(Object o) {
		String s = String.valueOf(o);
		out.println("Case #" + test + ": " + s);
		System.out.println("Case #" + test + ": " + s);
	}
	
	BufferedReader input;
	PrintWriter out;
	StringTokenizer st;
	int test;
	
	public static void main(String[] args) throws IOException {
		new Thread(null, new C(), "", 1 << 20).start();
	}
	
	public void run() {
		try {
			init();
			int TEST = nextInt();
			for(test = 1; test <= TEST; test++) {
				System.out.println("Running on testcase #" + test);	
				solve();
			}	
			out.close();		
		}
		catch(Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}