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
		String C = nword();
		String J = nword();
		int N = C.length();
		/*
		for (int i=0;i<N;i++){
			cdigits[i] = C.charAt(i);
			jdigits[i] = J.charAt(i);
		}
		*/
		cdigits = C.toCharArray();
		jdigits = J.toCharArray();
		best = Long.MAX_VALUE;
		bestA = null;
		combo(0, 0);

		return bestA;
	}

	static char[] cdigits;
	static char[] jdigits;
	static long best;
	static String bestA;
	
	static void combo(int c, int j) {
		while (c < cdigits.length && cdigits[c] != '?') {
			c++;
		}
		if (c < cdigits.length) {
			for (char i='0';i<='9';i++) {
				cdigits[c] = i;
				combo(c+1, j);
			}
			cdigits[c] = '?';
		}
		else {
			while (j < jdigits.length && jdigits[j] != '?') {
				j++;
			}
			if (j < jdigits.length) {
				for (char i='0';i<='9';i++) {
					jdigits[j] = i;
					combo(c, j+1);
				}
				jdigits[j] = '?';
			}
			else {
				long code = Long.parseLong(new String(cdigits));
				long jam = Long.parseLong(new String(jdigits));
				long diff = Math.abs(code - jam);
				if (diff < best) {
					String a = new String(cdigits) + " " + new String(jdigits);
					best = diff;
					bestA = a;
				}
				else if (diff == best) {
					String a = new String(cdigits) + " " + new String(jdigits);
					if (a.compareTo(bestA) < 0) {
						bestA = a;
					}
				}
				return;
			}
		}
			
	}
}
