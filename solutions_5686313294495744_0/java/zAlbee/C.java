import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;


/**
 * Template
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
		Pair[] orig = new Pair[N];
		for (int i=0; i<N; i++) {
			nline();
			orig[i] = new Pair(nword(), nword());
		}
		
		reals = new ArrayList<>();
		fakes = new ArrayList<>();
		
		return combo(orig, 0);
	}
	
	static List<Pair> reals;
	static List<Pair> fakes;
	
	static int combo(Pair[] orig, int i) {
		if (i >= orig.length) {
			if (valid()) return fakes.size();
			else return 0;
		}
		
		reals.add(orig[i]);
		int r1 = combo(orig, i+1);
		reals.remove(reals.size()-1);

		fakes.add(orig[i]);
		int r2 = combo(orig, i+1);
		fakes.remove(fakes.size()-1);
		
		return Math.max(r1, r2);
	}
	
	static class Pair{
		String s1; String s2;
		Pair(String a, String b) {s1=a; s2=b;}
	}

	static boolean valid() {
		Set<String> firsts = new HashSet<>();
		Set<String> seconds = new HashSet<>();
		for (Pair p : reals) {
			firsts.add(p.s1);
			seconds.add(p.s2);
		}
		for (Pair p : fakes) {
			if (!firsts.contains(p.s1) || !seconds.contains(p.s2)) {
				return false;
			}
		}
		return true;
	}
}
