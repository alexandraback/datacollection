package gcj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class R1_2013_B {
	
	static int E,R,N;
	static int[] vs;
	
	static long[] memoNext = new long[10000001];
	static long[] memoNow = new long[10000001];
	
	static void run() {
		for (int j=0; j<=E; j++) {
			memoNext[j] = 0L;
		}
		
		for (int ix=N-1; ix>=0; ix--) {
			// doing step ix
			long vi = vs[ix];
			for (int e=0; e<=E; e++) {
				long max = 0;
				for (int s=0; s<=e; s++) {
					int e2 = Math.min(E, e-s+R);
					max = Math.max(max, vi*s + memoNext[e2]);
				}
				memoNow[e] = max;
				//System.out.println("memo["+ix+"]["+e+"] = "+max);
			}
			System.arraycopy(memoNow, 0, memoNext, 0, E+1);
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int cases = Integer.parseInt(br.readLine());
		for (int cc=1; cc<=cases; cc++) {
			String ss[] = br.readLine().split(" ");
			E = Integer.parseInt(ss[0]);
			R = Integer.parseInt(ss[1]);
			N = Integer.parseInt(ss[2]);
			ss = br.readLine().split(" ");
			vs  = new int[N];
			for (int i=0; i<N; i++) {
				vs[i] = Integer.parseInt(ss[i]);
			}
			run();
			long ret = memoNow[E];
			System.out.println(String.format("Case #%d: %d", cc, ret));
		}
	}
}
