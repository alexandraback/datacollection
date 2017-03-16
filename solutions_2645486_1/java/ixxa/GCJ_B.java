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
			long E = Integer.parseInt(sp[0]);
			long R = Integer.parseInt(sp[1]);
			int N = Integer.parseInt(sp[2]);
			sp = in.readLine().split(" ");
			int[] v = new int[N];
			for (int i = 0; i < N; i++) {
				v[i] = Integer.parseInt(sp[i]);
			}

			LinkedList<Tuple> Q = new LinkedList<Tuple>();
			Q.add(new Tuple(0, N, E, true));
			long sum = 0;
			System.out.println("-----");
			while (Q.size() > 0) {
				Tuple tuple = Q.poll();
				int s = tuple.s;
				int e = tuple.e;
				long ene0 = tuple.ene;
				boolean flg = tuple.flg;

				if (s >= e) {
					continue;
				} else {
					int midx = s;
					int max = 0;
					for (int i = s; i < e; i++) {
						if (max < v[i]) {
							max = v[i];
							midx = i;
						}
					}

					long nextene;
					long ene1;
					if (flg) {
						ene1 = Math.min(E, ene0 + (midx - s) * R);
						nextene = Math.min(E, R);
					} else {
						long e2 = Math.min(E, ene0 + (e - s) * R);
						long e1 = Math.min(E, ene0 + (midx - s) * R);
						long elb = Math.max(0, e2 - (e - midx) * R);
						ene1 = e1 - elb;
						nextene = Math.min(E, elb + R);
					}
					sum += v[midx] * ene1;

					// left?
					Q.add(new Tuple(s, midx, ene0, false));
					// right?
					Q.add(new Tuple(midx + 1, e, nextene, flg));
				}
			}
			out.println("Case #" + (test + 1) + ": " + sum);




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
