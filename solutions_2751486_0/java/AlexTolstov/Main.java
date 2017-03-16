import java.io.*;
import java.util.*;


public class Main extends Thread {
	
	Scanner in;
	PrintWriter out;
	
	static final String path = "C:/gcj2013_r1/";
	static final String problem = "A-small";
	
	static final char[] gla = {'a', 'e', 'i', 'o', 'u' };
	
	boolean isSogl(char c) {
		for (int i = 0; i < gla.length; i++) {
			if (gla[i] == c) {
				return false;
			}
		}
		return true;
	}
	
	boolean isHasN(String s, int from, int to, int n) {
		if (to > s.length()) {
			return false;
		}
		int max = 0;
		int curr = 0;
		boolean isPrevSogl = false;
		for (int i = from; i < to; i++) {
			if (isPrevSogl && isSogl(s.charAt(i))) {
				curr++;
			} else if (!isPrevSogl && isSogl(s.charAt(i))) {
				curr = 1;
				isPrevSogl = true;
			} else if (!isSogl(s.charAt(i))) {
				isPrevSogl = false;
				max = Math.max(curr, max);
				curr = 0;
			}
		}
		max = Math.max(curr, max);
		return max >= n;
	}
	
	void solveOne(int test) {
		String s = in.next();
		int n = in.nextInt();
		int ans = 0;
		for (int i = 0; i < s.length(); i++) {
			for (int j = i; j < s.length(); j++) {
				if (isHasN(s, i, j + 1, n)) {
					ans++;
				}
			}
		}
		out.println("Case #" + test + ": " + ans);
	}
	
	void solve() {
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			solveOne(i + 1);
		}
	}
	
	
	static void check(boolean e) {
		if (!e) {
			throw new Error();
		}
	}
	
	
	public void run() {
		try {
			in = new Scanner(new FileReader(path + problem + ".in"));
			out = new PrintWriter(new FileWriter(path + problem + ".out"));
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
		}
		
		try {
			solve();
		} finally {
			out.close();
		}
	}
	
	public static void main(String[] args) {
		new Thread(null, new Main(), "GAVNO", 500000000).start();
	}
}