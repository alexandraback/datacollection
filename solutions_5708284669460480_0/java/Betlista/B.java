import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.StringTokenizer;


public class B {

	static int MB = 1 << 20;
	static BufferedReader br = new BufferedReader( new InputStreamReader(System.in, StandardCharsets.US_ASCII), 30*MB);
	static StringTokenizer st;
	
	static String NL() throws Exception {
		String line = br.readLine();
		st = new StringTokenizer(line);
		return line;
	}
	
	static String NT() {
		return st.nextToken();
	}
	
	public static void main(String[] args) throws Exception {
		int T = Integer.parseInt(NL());
		for (int ii = 1; ii <= T; ii++) {
			NL();
			int K, L, S;
			K = Integer.parseInt(NT());
			L = Integer.parseInt(NT());
			S = Integer.parseInt(NT());
			String k, t;
			k = NL();
			t = NL();
			CNT = 0;
			ALL = 0;
			double exp = solve(K, L, S, k, t);
			int max = CNT == 0 ? 0 : findMax(t, S);
			print(ii, max - exp);
		}
	}

	private static int findMax(String T, int s) {
		// longest same part
		int add = T.length();
		for (int f = 1; f < T.length(); f++) {
			String ss = T.substring(f);
			if (T.startsWith(ss)) {
				// longest
				add = T.length() - ss.length();
				break;
			}
		}
		int res = 1;
		int l = T.length() + add;
		while (l <= s) {
			++res;
			l += add;
		}
		return res;
	}

	private static void print(int ii, double exp) {
		System.out.printf("Case #%d: %.9f%n", ii, exp);
	}

	static double ALL = 0;
	static double CNT = 0;
	
	static String T;
	
	static char[] keys;
	
	private static double solve(int K, int L, int S, String k, String t) {
		keys = k.toCharArray();
		T = t;
		run("", S);
		return CNT/ALL;
	}

	private static void run(String act, int S) {
		if (act.length() == S) {
			++ALL;
			CNT += count(act);
			return;
		}
		for (int ci = 0; ci < keys.length; ci++) {
			run(act + keys[ci], S);
		}
	}

	private static double count(String act) {
		int idx = -1;
		idx = act.indexOf(T, idx + 1);
		int res = 0;
		while (idx != -1) {
			++res;
			idx = act.indexOf(T, idx + 1);
		}
		return res;
	}
	
}
