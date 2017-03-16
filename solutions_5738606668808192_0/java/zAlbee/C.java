import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;


/**
 * Problem C. Coin Jam
 * @author Albert Choi
 */
public class C {
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
	static boolean debug = false;

	public static void main(String[] args) throws IOException {
		/*
		sout.println(check("101")); // no
		sout.println(check("1001")); // yes
		sout.println(check("110111")); // no
		sout.println(check("10101")); // yes
		sout.println(check("110011")); // yes
		sout.println(check("100011")); // yes
		sout.println(check("111111")); // yes
		sout.println(check("111001")); // yes
		*/

		//System.out.println(solve(16,50));
		
		//System.out.println(solve(32,500));

		try {
			nline();
			int T = nint();
			for (int t=1; t<=T; t++) {
				String sans = doProblem();
				sout.println("Case #" + t + ":\n" + sans); // NOTE: NEWLINE INSTEAD OF SPACE
			}
		} catch (Throwable t) {
			System.err.println("At input line " + _l + ": " + _s); throw t;
		}
	}
	
	static String doProblem() throws IOException {
		nline();
		int N = nint();
		int J = nint();
		return solve(N, J); 
	}
	
	static String solve(int len, int num) {
		boolean[] bits = new boolean[len];
		bits[0] = true;
		bits[len-1] = true;
		List<String> answers = new ArrayList<>(num);
		generate(bits, 1, answers, num);
		StringBuilder sb = new StringBuilder();
		for (String ans : answers) {
			sb.append(ans);
			sb.append("\n");
		}
		return sb.toString();
	}
	
	static void generate(boolean[] bits, int idx, List<String> answers, int max) {
		int len = bits.length;
		if (answers.size() >= max) {
			return;
		}
		
		if (idx == len - 1) {
			String ans = check(bits);
			if (ans != null) {
				answers.add(ans);
			}
		}
		else {
			bits[idx] = false;
			generate(bits, idx+1, answers, max);
			bits[idx] = true;
			generate(bits, idx+1, answers, max);
		}	
	}
	
	static String check(String str) {
		if (debug) sout.println("checking " + str);
		boolean[] bits = new boolean[str.length()];
		for (int i=0; i<str.length(); i++) {
			bits[i] = str.charAt(i) == '1';
		}
		return check(bits);
	}

	static String check(boolean[] bits) {
		long[] factors = new long[9];
		for (int base = 2; base <= 10; base++) {
			long num = 0;
			long mult = 1;
			for (int d = bits.length - 1; d >= 0; d--) {
				if (bits[d]) num += mult;
				mult *= base;
			}
			if (debug) sout.printf("base %s: %s\n", base, num);
			long f = findFactor(num);
			if (f == 0) {
				if(debug) sout.println("is prime!");
				return null;
			}
			factors[base - 2] = f;
		}
		
		StringBuilder sb = new StringBuilder();
		for (int i=0; i<bits.length; i++) {
			sb.append(bits[i] ? '1':'0');
		}
		for (long f : factors) {
			sb.append(" " + f);
		}
		return sb.toString();
	}

	
	static long findFactor(long num) {
		for (long f=2; f < Math.sqrt(num) + 1; f++) {
			if (num % f == 0) return f;
		}
		return 0;
	}
}
