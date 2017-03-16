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
		int J = nint(), P = nint(), S = nint();
		K = nint();
		
		all = new ArrayList<>();
		for (byte j=0;j<J;j++){
			for (byte p=0;p<P;p++){
				for (byte s=0;s<S;s++){
					all.add(new byte[]{j,p,s});
				}
			}
		}
		
		jp = new int[J][P];
		ps = new int[P][S];
		js = new int[J][S];
		yes = new boolean[all.size()];
		best = 0;
		pick(0);
//		for (byte[] com : all) {
//			serr.printf("%d %d %d\n", com[0]+1, com[1]+1, com[2]+1);
//		}
//		serr.println();

		StringBuilder sb = new StringBuilder();
		sb.append(best + "\n");
		for (int i=0; i<all.size(); i++) {
			byte[] com = all.get(i);
			if (bestyes[i]) 
				sb.append(String.format("%d %d %d\n", com[0]+1, com[1]+1, com[2]+1));
		}
		return sb; 
	}

	static int K;
	static List<byte[]> all;
	
	static int[][] jp;
	static int[][] ps;
	static int[][] js;
	static boolean[] yes;
	static int best;
	static boolean[] bestyes;
	
	static void pick(int i) {
		int N = all.size();
		if (i == N) {
			int count = 0;
			for (int j=0; j<N; j++) {
				if (yes[j]) {
					count++;
				}
			}
			if (count > best) {
				best = count;
				bestyes = yes.clone();
			}
			return;
		}
		// pick i
		yes[i] = true;
		byte[] c = all.get(i);
		byte j = c[0];
		byte p = c[1];
		byte s = c[2];
		int jpc = ++jp[j][p];
		int jsc = ++js[j][s];
		int psc = ++ps[p][s];
		if (jpc > K || jsc > K || psc > K) ;
		else
			pick(i+1);
		// discard i
		jp[j][p]--;
		js[j][s]--;
		ps[p][s]--;
		yes[i] = false;
		pick(i+1);
	}
}
