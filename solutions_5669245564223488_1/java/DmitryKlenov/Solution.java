import java.util.*;
import java.io.*;

public class Solution implements Runnable {
	final int MOD = 1000000007;
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Thread(new Solution()).start();
	}

	public void run() {
		try {
			solve();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	BufferedReader cin;
	PrintWriter cout;
	StringTokenizer tok;
	
	String next() throws Exception {
		while (tok == null || !tok.hasMoreTokens())
			tok = new StringTokenizer(cin.readLine());
		return tok.nextToken();
	}
	
	int nextInt() throws Exception {
		return Integer.parseInt(next());
	}
	
	int n;
	String[] a;
	boolean[][] g;
	int[] used;
	
	public class NoSolutionException extends RuntimeException {}
	
	int calc() {
		for (int i = 0; i < n; ++i) {
			if (a[i].length() == 1) continue;
			if (a[i].charAt(0) == a[i].charAt(a[i].length() - 1)) return 0;
			for (int j = 1; j < a[i].length() - 1; ++j) {
				for (int k = 0; k < n; ++k) {
					if (!a[k].contains(a[i].charAt(j) + "")) continue;
					if (k != i) return 0;
					if (a[i].indexOf(a[i].charAt(j)) != a[i].lastIndexOf(a[i].charAt(j))) return 0;
				}
			}
		}
		
		long ans = 1;
		int cnt = n;
		
		for (char c = 'a'; c <= 'z'; ++c) {
			int bi = -1, ei = -1, ec = 0;
			for (int i = 0; i < n; ++i) {
				if (a[i].length() == 1 && a[i].charAt(0) == c) {
					ec++;
					continue;
				}
				if (a[i].startsWith(c + ""))
					if (bi != -1) return 0;
					else bi = i;
				if (a[i].endsWith(c + ""))
					if (ei != -1) return 0;
					else ei = i;
			}
			
			for (int i = 1; i <= ec; ++i)
				ans = (ans * i) % MOD;
			
			
			
			if (ec != 0) {
				cnt -= ec - 1;
				if ((ei != -1) || (bi != -1)) --cnt;
			}
			if (ei != -1 && bi != -1) --cnt;
		}
		
		for (int i = 1; i <= cnt; ++i)
			ans = (ans * i) % MOD;
		
		g = new boolean[26][26];
		used = new int[26];
		for (String s: a)
			if (s.length() > 1)
				g[s.charAt(0) - 'a'][s.charAt(s.length() - 1) - 'a'] = true;
		
		try {
			for (int i = 0; i < 26; ++i)
				if (used[i] == 0) dfs(i);
		} catch (NoSolutionException ee) {
			return 0;
		}
		return (int) (ans % MOD);
	}

	private void dfs(int v) {
		used[v] = 1;
		for (int j = 0; j < 26; ++j)
			if (v != j && g[v][j]) {
				if (used[j] == 1) throw new NoSolutionException();
				dfs(j);
			}
		used[v] = 2;
	}

	private void solve() throws Exception {
		cin = new BufferedReader(new FileReader("input.txt"));
		cout = new PrintWriter(new File("output.txt"));
		
		int tk = nextInt();
		for (int tc = 1; tc <= tk; ++tc) {
			n = nextInt();
			a = new String[n];
			for(int i = 0; i < n; ++i) {
				String tmp = next();

				a[i] = "";
				for (int j = 0; j < tmp.length(); ++j)
					if (j == 0 || tmp.charAt(j) != tmp.charAt(j - 1))
						a[i] += tmp.charAt(j);
			}
			
			
			cout.println("Case #" + tc + ": " + calc());
		}
		
		cin.close();
		cout.close();
	}
}
