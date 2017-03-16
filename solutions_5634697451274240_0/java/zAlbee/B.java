import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.StringTokenizer;


/**
 * Problem B. Revenge of the Pancakes
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
				String sans = doProblem();
				sout.println("Case #" + t + ": " + sans);
			}
		} catch (Throwable t) {
			System.err.println("At input line " + _l + ": " + _s); throw t;
		}
	}
	
	static String doProblem() throws IOException {
		String s = nline().trim();
		return solve(s).toString(); 
	}
	
	static Integer solve(String s) {
		int cnt = 0;
		char last = 0;
		for (int i=0; i<s.length(); i++) {
			char c = s.charAt(i);
			if (c != last) cnt++;
			last = c;
		}
		if (last == '+') return cnt - 1;
		else return cnt;
	}

}
