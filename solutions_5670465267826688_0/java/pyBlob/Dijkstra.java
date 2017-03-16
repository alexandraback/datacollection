

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Double.parseDouble;
import static java.lang.Float.parseFloat;

public class Dijkstra {
	public static Scanner s = new Scanner(System.in);
	
	public static void main(String[] args) {
		int n = parseInt(s.nextLine());
		
		for (int i=1 ; i<=n ; i++) {
			System.out.print("Case #" + i + ": ");
			debug("Case #" + i + ": ");
			
			System.out.println(run() ? "YES" : "NO");
		}
	}
	
	private static final String print[] = new String[] {
		"1", "i", "j", "k", "-1", "-i", "-j", "-k"
	};
	private static final int P_1 = 0;
	private static final int P_i = 1;
	private static final int P_j = 2;
	private static final int P_k = 3;
	private static final int N_1 = 4;
	private static final int N_i = 5;
	private static final int N_j = 6;
	private static final int N_k = 7;
	private static final int[] map = new int[] {
			//         1,   i,   j,   k
			/*  1 */ P_1, P_i, P_j, P_k,    
			/*  i */ P_i, N_1, P_k, N_j,
			/*  j */ P_j, N_k, N_1, P_i,
			/*  k */ P_k, P_j, N_i, N_1
	};
	
	public static int multiply(int a, int b) {
		return map[((a<<2) & 12) | (b & 3)] ^ ((a ^ b) & 4);
	}
	
	public static int pot(int q, long x) {
		int res = P_1;
		
		for ( ; x>0 ; x>>=1) {
			if ((x & 1L) != 0) {
				res = multiply(res, q);
			}
			
			q = multiply(q, q);
		}
		
		return res;
	}
	
	public static boolean run() {
		String line[] = s.nextLine().split(" ");
		int L = parseInt(line[0]);
		long X = parseLong(line[1]);
		
		long N = X * ((long) L);
		
		int[] pattern = new int[L];
		
		char[] text = s.nextLine().toCharArray();
		for (int i=0 ; i<L ; i++) {
			switch (text[i]) {
			case 'i': pattern[i] = P_i; break;
			case 'j': pattern[i] = P_j; break;
			case 'k': pattern[i] = P_k; break;
			default:
				debug("INVALID CHAR '" +text[i]+"'");
				break;
			}
		}
		
		if (N <= 2) return false; // "too short"
		
		int[] prefix = new int[L];
		int[] postfix = new int[L];
		
		prefix[0] = pattern[0];
		for (int i=1 ; i<L ; i++) {
			prefix[i] = multiply(prefix[i-1], pattern[i]);
		}
		
		postfix[L-1] = pattern[L-1];
		for (int i=L-2 ; i>=0 ; i--) {
			postfix[i] = multiply(pattern[i], postfix[i+1]);
		}
		
		int whole = prefix[L-1];
		if (postfix[0] != whole) {
			debug("EEK: pre/post differ!");
			throw new RuntimeException();
		}
		debug("whole="+print[whole]);
		
		// i*j*k == -1  =>  (..)*(..)*(..) also must be -1
		int seq = pot(whole, X);
		debug("seq="+print[seq]);
		if (seq != N_1) {
			return false;
		}
		
		int cycle = 0;
		for (int q=whole ; cycle==0 || q!=whole ; cycle++) {
			q = multiply(q, whole);
		}
		debug(cycle+" cyclic");
		
		int[] pots = new int[cycle];
		pots[0] = P_1;
		for (int i=1 ; i<cycle ; i++) {
			pots[i] = multiply(pots[i-1], whole);
		}
		
		// find earliest i such that: i * post = i * (j * k) = i * i = -1
		long match_i = -1L;
		outer: for (int a=0 ; a<cycle ; a++) {
			for (int b=0 ; b<L ; b++) {
				int q = multiply(pots[a], prefix[b]);
				
				if (q == P_i) {
					match_i = a*L + b;
					break outer;
				}
			}
		}
		
		// find latest   k such that: pre * k  = (i * j) * k = k * k = -1
		long match_k = -1L;
		outer: for (int a=0 ; a<cycle ; a++) {
			for (int b=0 ; b<L ; b++) {
				int q = multiply(postfix[L - b - 1], pots[a]);
				
				if (q == P_k) {
					match_k = N - (long) (a*L + b) - 1;
					break outer;
				}
			}
		}
		
		debug("mi="+match_i+" mk="+match_k);
		
		// intersection of pre/post = j
		// ... if it exists
		return (match_i>=0) && (match_k>=0L) && (((long) match_i) + 1L < match_k);
	}
	
	public static void debug(String str) {
		System.out.flush();
		
		System.err.println(str);
		System.err.flush();
	}
	
}
