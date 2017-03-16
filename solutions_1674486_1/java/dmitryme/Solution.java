import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Solution implements Runnable {

	public static void main(String[] args) {
		new Thread(new Solution()).start();
	}
	
	@Override
	public void run() {
		try {
			solve();
		} catch (Exception e) {
			e.printStackTrace();
			throw new RuntimeException("Laja in solution");
		}
	}
	
	private String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(cin.readLine());
		}
		
		return tok.nextToken();
	}
	
	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	private long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	BufferedReader cin;
	StringTokenizer tok;
	PrintWriter cout;
	
	ArrayList<Integer>[] a;
	boolean[] used;
	int n;
	
	public void solve() throws Exception {
		//cin = new BufferedReader(new FileReader("input.txt"));
		cin = new BufferedReader(new FileReader("A-large.in"));
		cout = new PrintWriter("output.txt");
		//cout = new PrintWriter("");
		
		int testcases = nextInt();
		for (int test = 0; test < testcases; ++test) {
			n = nextInt();
			a = new ArrayList[n];
			used = new boolean[n];
			
			for (int i = 0; i < n; ++i) {
				int m = nextInt();
				
				a[i] = new ArrayList<Integer>();
				
				for (int j = 0; j < m; ++j) {
					a[i].add(nextInt() - 1);
				}
			}
			
			boolean found = false;
			
			for (int i = 0; i < n; ++i) {
				Arrays.fill(used, false);
				
				if (dfs(i)) {
					found = true;
					break;
				}
			}
			
			cout.println("Case #" + (test + 1) + ": " + (found ? "Yes" : "No"));
		}
		
		
		
		cout.close();
	}

	private boolean dfs(int v) {
		used[v] = true;
		
		for (int u: a[v]) {
			if (used[u] || dfs(u)) {
				return true;
			}
		}
		
		return false;
	}
}
