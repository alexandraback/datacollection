import java.io.*;
import java.util.*;

public class GCJ_B {
	public static void main(String[] args) throws Exception {
		new GCJ_B().solve();
	}

	void solve() throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")));
		PrintStream out = new PrintStream(new FileOutputStream(new File("output.txt")));
		Scanner sc = new Scanner(System.in);
		String[] sp;

		int T = Integer.parseInt(in.readLine());
		for (int test = 0; test < T; test++) {
			sp = in.readLine().split(" ");
			int E = Integer.parseInt(sp[0]);
			int R = Integer.parseInt(sp[1]);
			int N = Integer.parseInt(sp[2]);
			sp = in.readLine().split(" ");
			int[] v = new int[N];
			for (int i = 0; i < N; i++) {
				v[i] = Integer.parseInt(sp[i]);
			}

			System.out.println("---");
			long[][] dp = new long[N][E + 1];
			for (int e = 1; e <= E; e++) {
				dp[N - 1][e] = e * v[N - 1];
			}
			for (int i = N - 2; i >= 0; i--) {
				for (int e = 1; e <= E; e++) {
					for (int ee = 0; ee <= e; ee++) {
						long d = ee * v[i];
						dp[i][e] = Math.max(dp[i][e], d + dp[i + 1][Math.min(E, e - ee + R)]);
					}
				}
			}
			out.println("Case #" + (test + 1) + ": " + dp[0][E]);

			// LinkedList<Tuple> Q = new LinkedList<Tuple>();
			// Q.add(new Tuple(0, N, E, true));
			// long sum = 0;
			// System.out.println("-----");
			// while (Q.size() > 0) {
			// Tuple tuple = Q.poll();
			// int s = tuple.s;
			// int e = tuple.e;
			// long ene0 = tuple.ene;
			// boolean flg = tuple.flg;
			// System.out.println(s + "," + e + "," + ene0 + "," + flg);
			//
			// if (s >= e) {
			// continue;
			// } else if (e - s == 1) {
			// if (flg) {
			// sum += v[s] * ene0;
			// } else {
			// sum += v[s] * Math.max(0, Math.min(ene0, ene0 + R - E));
			// }
			// } else {
			// int midx = s;
			// int max = 0;
			// for (int i = s; i < e; i++) {
			// if (max < v[i]) {
			// max = v[i];
			// midx = i;
			// }
			// }
			//
			// long nextene;
			// long ene1;
			// if (flg) {
			// ene1 = Math.min(E, ene0 + (midx - s) * R);
			// nextene = Math.min(E, R);
			// } else {
			// nextene = Math.min(E, ene0 + (e - s) * R);
			// long e1 = Math.min(E, ene0 + (midx - s) * R);
			// long r1 = nextene - (e - midx) * R;
			// ene1 = e1 - Math.max(r1, 0);
			// }
			// sum += v[midx] * ene1;
			// // left?
			// Q.add(new Tuple(s, midx, ene0, false));
			// // right?
			// Q.add(new Tuple(midx + 1, e, nextene, flg));
			// }
			// }
			// out.println("Case #" + (test + 1) + ": " + sum);




		}
	}
	class Tuple {
		int s;
		int e;
		long ene;
		boolean flg;
		public Tuple(int s, int e, long ene, boolean flg) {
			this.s = s;
			this.e = e;
			this.ene = ene;
			this.flg = flg;
		}
	}

}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
