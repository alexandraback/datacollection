import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.*;


/**
 * Template
 * @author Albert Choi
 */
public class B {
	static BufferedReader _reader = new BufferedReader(new InputStreamReader(System.in));
	static String _s;
	static StringTokenizer _st;
	static int _l;
	static String nline() throws IOException { _s = _reader.readLine(); ++_l; _st = new StringTokenizer(_s); return _s; }
	static String nword() 	{ return _st.nextToken(); }
	static int nint() 		{ return Integer.parseInt(nword()); }
	static long nlong() 	{ return Long.parseLong(nword()); }
	static double ndouble() { return Double.parseDouble(nword()); }
	static BigInteger nbig(){ return new BigInteger(nword()); }
	static PrintStream sout = System.out, serr = System.err;
	
	public static void main(String[] args) throws IOException {
		try {
			nline();
			int T = nint();
			for (int t=1; t<=T; t++) {
				sout.println("Case #" + t + ": " + String.valueOf(doProblem()));
			}
		} catch (Throwable t) {
			System.err.println("At input line " + _l + ": " + _s); throw t;
		}
	}
	
	static Object doProblem() throws IOException {
		nline();
		int N = nint();
		goal = nlong();
		int[][] g = new int[N][N];
		StringBuilder sb = new StringBuilder();
		if (combo(g, 0, 0)) {
			sb.append("POSSIBLE\n");
			sb.append(sprint(ans));
			return sb;
		}
		else return "IMPOSSIBLE";
	}

	static String sprint(int[][] g) {
		StringBuilder sb = new StringBuilder();
		int B = g.length;
		for (int i=0;i<B;i++) {
			for (int j=0; j<B; j++) {
				sb.append(g[i][j]);
			}
			sb.append('\n');
		}
		return sb.toString();
	}
	
	static long count(int[][] g) {
//		serr.println(sprint(g));
		
		int N = g.length;
		int dp[] = new int[N];
		dp[N-1] = 1;
		for (int i=N-2; i>=0; i--) {
			int n = 0;
			for (int j=i+1; j<N; j++) {
				if (g[i][j] == 1) {
					n += dp[j];
				}
			}
			dp[i] = n;
//			serr.printf("%s ", dp[i]);
		}
//		serr.println();
		return dp[0];
	}
	
	static long goal;
	static int[][] ans;

	static boolean combo(int[][] g, int i, int j) {
		int N = g.length;
		if (i == N) {
			if (count(g) == goal) {
				ans = g;
				return true;
			}
			return false;
		}
		g[i][j] = 0;
		if (j+1 < N) {
			if (combo(g, i, j+1)) return true;
		} else {
			if (combo(g, i+1, 0)) return true;
		}
		if (i < j) {
			g[i][j] = 1;
			if (j+1 < N) {
				if (combo(g, i, j+1)) return true;
			} else {
				if (combo(g, i+1, 0)) return true;
			}
		}
		return false;
	}
}
