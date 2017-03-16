import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.StringTokenizer;


/**
 * Template
 * @author Albert Choi
 */
public class A {
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
		//test(10000);
		try {
			nline();
			int T = nint();
			for (int t=1; t<=T; t++) {
				String sans = doProblem();
				sout.println("Case #" + t + ": " + sans);
			}
		} catch (Throwable t) {
			System.err.println("At input line " + _l + ": " + _s); throw t;
		}
	}
	
	static String doProblem() throws IOException {
		nline();
		int N = nint();
		return solve(N);
	}
	
	static String solve(int N) {
		String ans = "INSOMNIA";
		if (N == 0) return ans;
		
		reset();
		int cur = 0;

		while (!allFound())	{
			cur += N;
			int tmp = cur;
			//sout.println(cur);
			while (tmp > 0) {
				int d = tmp % 10;
				set(d);
				tmp = tmp / 10;
			}
		}
		ans = String.valueOf(cur);
		return ans;
	}
	
	static boolean[] digitsFound = new boolean[10];

	static boolean allFound() {
		for (int i=0; i<10; i++) {
			if (!digitsFound[i]) return false;
		}
		return true;
	}
	
	static void reset() {
		for (int i=0; i<10; i++) {
			digitsFound[i] = false;
		}
	}
	
	static void set(int i) {
		digitsFound[i] = true;
	}

	static void test(int n) {
		for (int i=0; i<n; i++) {
			int N = (int)Math.round(Math.random() * 1000000);
			sout.println("solving " + N);
			sout.println("ans: " + solve(N));
		}
		System.exit(0);
	}
	

}
