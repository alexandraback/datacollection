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
	
	static String[] numStrings = {
			"ZERO", // Z
			"ONE", // O (after FOUR, TWO)
			"TWO", // W
			"THREE", // R (after FOUR)
			"FOUR", // U
			"FIVE", // F
			"SIX", // X
			"SEVEN",
			"EIGHT", // G
			"NINE"
	};

	static Object doProblem() throws IOException {
		String s = nline().trim();
		int[] map = new int[26];
		
		for (char c : s.toCharArray()) {
			map[c-'A']++;
		}
		int[] digitCount = new int[10];
		while (map['Z'-'A'] > 0) {
			map['Z'-'A']--;
			map['E'-'A']--;
			map['R'-'A']--;
			map['O'-'A']--;
			digitCount[0]++;
		}
		while (map['W'-'A'] > 0) {
			map['T'-'A']--;
			map['W'-'A']--;
			map['O'-'A']--;
			digitCount[2]++;
		}
		while (map['U'-'A'] > 0) {
			map['F'-'A']--;
			map['O'-'A']--;
			map['U'-'A']--;
			map['R'-'A']--;
			digitCount[4]++;
		}
		while (map['X'-'A'] > 0) {
			map['S'-'A']--;
			map['I'-'A']--;
			map['X'-'A']--;
			digitCount[6]++;
		}
		while (map['G'-'A'] > 0) {
			map['E'-'A']--;
			map['I'-'A']--;
			map['G'-'A']--;
			map['H'-'A']--;
			map['T'-'A']--;
			digitCount[8]++;
		}
		while (map['O'-'A'] > 0) {
			map['O'-'A']--;
			map['N'-'A']--;
			map['E'-'A']--;
			digitCount[1]++;
		}
		while (map['R'-'A'] > 0) {
			map['T'-'A']--;
			map['H'-'A']--;
			map['R'-'A']--;
			map['E'-'A']--;
			map['E'-'A']--;
			digitCount[3]++;
		}
		while (map['F'-'A'] > 0) {
			map['F'-'A']--;
			map['I'-'A']--;
			map['V'-'A']--;
			map['E'-'A']--;
			digitCount[5]++;
		}
		while (map['S'-'A'] > 0) {
			map['S'-'A']--;
			map['E'-'A']--;
			map['V'-'A']--;
			map['E'-'A']--;
			map['N'-'A']--;
			digitCount[7]++;
		}
		while (map['N'-'A'] > 0) {
			map['N'-'A']--;
			map['I'-'A']--;
			map['N'-'A']--;
			map['E'-'A']--;
			digitCount[9]++;
		}
		String a = "";
		for (int i=0; i<map.length; i++) {
			if (map[i] < 0) serr.println("at " + i + ": " + ('A'+i) + " was " + map[i]);
		}
		for (int d=0; d<digitCount.length; d++) {
			while (digitCount[d] > 0) {
				digitCount[d]--;
				a += d;
			}
		}
		return a;
	}

}
