import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class C {
	
	PrintWriter out;
	
	int I = 2, J = 3, K = 4;
	
	int[][] A = {
			{1, I, J, K},
			{I, -1, K, -J},
			{J, -K, -1, I},
			{K, J, -I, -1},
	};
	
	int L;
	long X;
	int[] is;
	
	void read(Scanner sc) {
		L = sc.nextInt();
		X = sc.nextLong();
		char[] cs = sc.next().toCharArray();
		is = new int[L];
		for (int i = 0; i < L; i++) {
			if (cs[i] == 'i') is[i] = I;
			else if (cs[i] == 'j') is[i] = J;
			else if (cs[i] == 'k') is[i] = K;
			else throw null;
		}
	}
	
	int sgn(int a) {
		return a > 0 ? 1 : -1;
	}
	
	int mul(int a, int b) {
		return A[abs(a) - 1][abs(b) - 1] * sgn(a) * sgn(b);
	}
	
	void solve2() {
		boolean ok = false;
		out.println(ok ? "YES" : "NO");
	}
	
	int pow(int a, long b) {
		int res = 1;
		while (b > 0) {
			if ((b & 1) != 0) res = mul(res, a);
			a = mul(a, a);
			b >>>= 1;
		}
		return res;
	}
	
	void solve() {
		int all = 1, all2 = 1;
		for (int i = 0; i < L; i++) all = mul(all, is[i]);
		all2 = pow(all, X);
		if (all2 != -1) {
			out.println("NO");
			return;
		}
		long left = L * X + 1, right = L * X + 1;
		int crt = 1;
		for (int i = 0; i < L * 100; i++) {
			crt = mul(crt, is[i % L]);
			if (crt == I) {
				left = i + 1;
				break;
			}
		}
		crt = 1;
		for (int i = 0; i < L * 100; i++) {
			crt = mul(is[L - 1 - i % L], crt);
			if (crt == K) {
				right = i + 1;
				break;
			}
		}
		if (left + right <= L * X) {
			out.println("YES");
		} else {
			out.println("NO");
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static int __ID = 0;
	public static boolean __ERROR = false;
	
	public static void main(String[] args) {
		int pN = 1;
		if (args.length == 0) {
			try {
				System.setIn(new BufferedInputStream(new FileInputStream(C.class.getName() + ".in")));
			} catch (Exception e) {
			}
		} else {
			pN = Integer.parseInt(args[0]);
		}
		PrintStream out = System.out;
		System.setOut(null);
		Scanner sc = new Scanner(System.in);
		final int caseN = sc.nextInt();
		final C[] solvers = new C[caseN];
		StringWriter[] outs = new StringWriter[caseN];
		for (int i = 0; i < caseN; i++) {
			solvers[i] = new C();
			outs[i] = new StringWriter();
			solvers[i].out = new PrintWriter(outs[i]);
			solvers[i].out.printf("Case #%d: ", i + 1);
			solvers[i].read(sc);
		}
		Thread[] ts = new Thread[pN];
		for (int i = 0; i < pN; i++) {
			ts[i] = new Thread() {
				@Override
				public void run() {
					for (;;) {
						int id;
						synchronized (C.class) {
							if (__ID == caseN) return;
							id = __ID++;
						}
						try {
							solvers[id].solve();
						} catch (RuntimeException e) {
							__ERROR = true;
							System.err.printf("Error in case %d:%n", id + 1);
							e.printStackTrace();
						}
						solvers[id].out.flush();
						solvers[id] = null;
					}
				}
			};
			ts[i].start();
		}
		for (int i = 0; i < pN; i++) {
			try {
				ts[i].join();
			} catch (InterruptedException e) {
				i--;
				continue;
			}
		}
		for (int i = 0; i < caseN; i++) {
			out.print(outs[i].toString());
		}
		if (__ERROR) out.printf("%nError occured!!!%n");
	}
	
}
