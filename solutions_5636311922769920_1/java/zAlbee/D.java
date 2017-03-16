import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.StringTokenizer;


/**
 * Problem D. Fractiles
 * @author Albert Choi
 */
public class D {
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
		nline();
		int K = nint(), C = nint(), S = nint();
		return findPos(K, C, S); 
	}
	
	static String findPos(int K, int C, int S) {
		if (S * C < K) return "IMPOSSIBLE";

		StringBuilder ans = new StringBuilder();
		
		int p = 0; // number of positions encoded
		while (p < K) {
			
			long tile = 0;
			
			long pow = 1;
			for (int i=0; i<C; i++) {
				tile += pow * (p % K);
				pow *= K;
				p++;
			}
			
			ans.append(" " + (tile + 1));
		}
		return ans.toString().substring(1);
	}

}
