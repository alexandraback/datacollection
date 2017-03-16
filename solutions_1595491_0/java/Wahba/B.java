import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class B {

	static class State {
		boolean surprising, not;
		int max;
		
		State(boolean S, boolean n, int mx) {
			surprising = S;
			not = n;
			max = mx;
		}
	}

	private void solve() throws IOException {
		int T = nextInt();
		while (T-- > 0) {
			int N = nextInt();
			int S = nextInt();
			int P = nextInt();
			int[] a = new int[N];
			State[] St = new State[N];
			for (int i = 0; i < N; i++)
				a[i] = nextInt();
			int res = 0;
			for (int i = 0; i < a.length; i++) {
				St[i] = new State(false, false, -1);
				for (int k1 = 0; k1 <= 10; k1++) {
					for (int k2 = 0; k2 <= 10; k2++) {
						for (int k3 = 0; k3 <= 10; k3++) {
							if (k1 + k2 + k3 == a[i]) {
								if (notValid(k1, k2, k3))
									continue;
								if (surprise(k1, k2, k3)) {
									if (k1 >= P || k2 >= P || k3 >= P) {
										St[i].surprising = true;
										St[i].max = Math.max(St[i].max, Math.max(k1, Math.max(k2, k3)));
									}
								} else {
									if (k1 >= P || k2 >= P || k3 >= P) {
										St[i].not = true;
										St[i].max = Math.max(St[i].max, Math.max(k1, Math.max(k2, k3)));
									}
								}
							}
						}

					}

				}
			}
			
			boolean[] V = new boolean[N];
			for (int i = 0; i < St.length && S > 0; i++) {
				if (St[i].surprising && !St[i].not) {
					res++;
					V[i] = true;
					S--;
				}
			}
			for (int i = 0; i < St.length && S > 0; i++) {
				if (!V[i] && St[i].surprising && St[i].not) {
					res++;
					V[i] = true;
					S--;
				}				
			}
			for (int i = 0; i < St.length; i++) {
				if (!V[i] && St[i].not) {
					res++;
				}				
			}
			pf();
			pl(res);
		}
	}

	private boolean notValid(int k1, int k2, int k3) {
		if (Math.abs(k1 - k2) > 2 || Math.abs(k1 - k3) > 2
				|| Math.abs(k2 - k3) > 2)
			return true;
		return false;
	}

	private boolean surprise(int k1, int k2, int k3) {
		if (Math.abs(k1 - k2) == 2 || Math.abs(k1 - k3) == 2
				|| Math.abs(k2 - k3) == 2)
			return true;
		return false;
	}

	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
			 reader = new BufferedReader(new FileReader("B.in"));
//			reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
//			writer = new PrintWriter(System.out);
			 writer = new PrintWriter("B.out");
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	BigInteger nextBigInteger() throws IOException {
		return new BigInteger(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	void p(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.flush();
			writer.print(objects[i]);
			writer.flush();
		}
	}

	void pl(Object... objects) {
		p(objects);
		writer.flush();
		writer.println();
		writer.flush();
	}

	int cc;

	void pf() {
		writer.printf("Case #%d: ", ++cc);
		writer.flush();
	}

}
