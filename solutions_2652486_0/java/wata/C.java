import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	
	int R, N, M, K;
	long[] ps;
	
	void read() {
		R = sc.nextInt();
		N = sc.nextInt();
		M = sc.nextInt();
		K = sc.nextInt();
		ps = new long[K];
		while (R-- > 0) {
			for (int i = 0; i < K; i++) {
				ps[i] = sc.nextLong();
			}
			solve();
		}
	}
	
	void solve() {
		Random rand = new Random();
		int[] res = new int[N];
		fill(res, 2);
		double max = 0;
		for (int rep = 0; rep < 10000; rep++) {
			int[] vs = new int[N];
			for (int i = 0; i < N; i++) vs[i] = 2 + rand.nextInt(M - 1);
			double[] prob = new double[K];
			for (int i = 0; i < 1 << N; i++) {
				long prod = 1;
				for (int j = 0; j < N; j++) if ((i >> j & 1) != 0) {
					prod *= vs[j];
				}
				for (int j = 0; j < K; j++) if (ps[j] == prod) prob[j] += 1.0;
			}
			double prod = 1;
			for (int i = 0; i < K; i++) prod *= prob[i];
			if (max < prod) {
				max = prod;
				res = vs;
			}
		}
		debug(max);
		for (int i = 0; i < N; i++) System.out.print(res[i]);
		System.out.println();
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			System.out.printf("Case #%d:%n", caseID);
			read();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new C().run();
	}
}
