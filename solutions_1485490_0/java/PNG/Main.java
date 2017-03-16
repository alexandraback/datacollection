import java.io.*;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("input"));
		BufferedWriter w = new BufferedWriter(new FileWriter(new File("output")));
		int cases = s.nextInt();
		s.nextLine();

		for (int i = 1; i <= cases; i++) {
			w.write("Case #");
			w.write(String.valueOf(i));
			w.write(": ");

			solve(s, w);

			w.write("\n");
		}
		w.close();
	}

	private static void solve(Scanner s, BufferedWriter w) throws Exception {
		int N = s.nextInt();
		int M = s.nextInt();

		long[] as = new long[N];
		int[] As = new int[N];
		long[] bs = new long[M];
		int[] Bs = new int[M];

		for (int i = 0; i < N; i++) {
			as[i] = s.nextLong();
			As[i] = s.nextInt();
		}

		for (int i = 0; i < M; i++) {
			bs[i] = s.nextLong();
			Bs[i] = s.nextInt();
		}

		long ans = 0;
		int i = 0, j = 0;
		long usedA = 0, usedB = 0;
		while (i < N && j < M) {
			int typeA = As[i];
			int typeB = Bs[j];

			if (typeA == typeB) {
				long toy = as[i] - usedA;
				long box = bs[j] - usedB;
				long min = Math.min(toy, box);
				ans += min;
				if (toy - min == 0) {
					usedA = 0;
					i++;
				} else {
					usedA += min;
				}
				if (box - min == 0) {
					usedB = 0;
					j++;
				} else {
					usedB += min;
				}
			} else {
				int it = i + 1;
				int jt = j + 1;
				long wa = as[i] - usedA , wb = bs[j] - usedB;
				boolean fa = false, fb = false;
				for (; it < N; it++) {
					if (As[it] != Bs[j]) {
						wa += as[it];
					} else {
						fa = true;
						break;
					}
				}

				for (; jt < N; jt++) {
					if (As[i] != Bs[jt]) {
						wb += bs[jt];
					} else {
						fb = true;
						break;
					}
				}

				if (fa == fb == true) {
					if (wa < wb) {
						i = it;
						usedA = 0;
					} else {
						j = jt;
						usedB = 0;
					}
				} else if (fa) {
					i = it;
					usedA = 0;
				} else if (fb) {
					j = jt;
					usedB = 0;
				} else {
					break;
				}
			}

		}

		w.write(String.valueOf(ans));

	}

}
