import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class BoxFactory {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("inputB.txt"));
		PrintWriter pw = new PrintWriter("outputB.txt");
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			int N = sc.nextInt();
			int M = sc.nextInt();

			long[][] a = new long[N][2];
			for (int i = 0; i < a.length; i++) {
				a[i][0] = sc.nextLong();
				a[i][1] = sc.nextLong();
			}

			long[][] b = new long[M][2];
			for (int i = 0; i < b.length; i++) {
				b[i][0] = sc.nextLong();
				b[i][1] = sc.nextLong();
			}

			long res = 0;
			if (N == 1) {
				res = solve1(a, b);
			} else if (N == 2) {
				res = solve2(a, b);
			} else {
				res = solve3(a, b);
			}
			pw.println("Case #" + t + ": " + res);
		}
		pw.flush();
		pw.close();
	}

	private static long solve3(long[][] a, long[][] b) {
		long res = 0;
		res = Math.max(res, solve2(new long[][] { a[0], a[1] }, b));
		res = Math.max(res, solve2(new long[][] { a[0], a[2] }, b));
		res = Math.max(res, solve2(new long[][] { a[1], a[2] }, b));

		if (a[0][1] == a[1][1] && a[1][1] == a[2][1]) {
			res = Math.max(res, solve1(new long[][] { { a[0][0] + a[1][0] + a[2][0], a[0][1] } }, b));
		} else if (a[0][1] == a[1][1]) {
			res = Math.max(res, solve2(new long[][] { { a[0][0] + a[1][0], a[0][1] }, a[2] }, b));
		} else if (a[1][1] == a[2][1]) {
			res = Math.max(res, solve2(new long[][] { a[0], { a[1][0] + a[2][0], a[1][1] } }, b));
		} else {

			for (int i = 0; i <= b.length; i++) {
				for (int j = i; j <= b.length; j++) {
					long count = 0;

					long tmp0 = a[0][0];
					long tmp1 = a[1][0];
					long tmp2 = a[2][0];

					for (int k = 0; k < i; k++) {
						if (b[k][1] == a[0][1]) { // primo
							long c = Math.min(b[k][0], a[0][0]);
							a[0][0] -= c;
							count += c;
						}
					}

					for (int k = i; k < j; k++) {
						if (b[k][1] == a[1][1]) { // secondo
							long c = Math.min(b[k][0], a[1][0]);
							a[1][0] -= c;
							count += c;
						}
					}

					for (int k = j; k < b.length; k++) {
						if (b[k][1] == a[2][1]) { // secondo
							long c = Math.min(b[k][0], a[2][0]);
							a[2][0] -= c;
							count += c;
						}
					}
					res = Math.max(res, count);

					a[0][0] = tmp0;
					a[1][0] = tmp1;
					a[2][0] = tmp2;
				}
			}
		}
		return res;
	}

	private static long solve2(long[][] a, long[][] b) {
		long res = 0;
		res = Math.max(res, solve1(new long[][] { a[0] }, b));
		res = Math.max(res, solve1(new long[][] { a[1] }, b));

		if (a[0][1] == a[1][1]) {
			// stesso tipo
			res = Math.max(res, solve1(new long[][] { { a[0][0] + a[1][0], a[0][1] } }, b));
		} else {

			for (int i = 0; i <= b.length; i++) {
				long count = 0;
				long tmp0 = a[0][0];
				long tmp1 = a[1][0];

				for (int j = 0; j < i; j++) {
					if (b[j][1] == a[0][1]) { // primo
						long c = Math.min(b[j][0], a[0][0]);
						a[0][0] -= c;
						count += c;
					}
				}

				for (int j = i; j < b.length; j++) {
					if (b[j][1] == a[1][1]) { // secondo
						long c = Math.min(b[j][0], a[1][0]);
						a[1][0] -= c;
						count += c;
					}
				}
				res = Math.max(res, count);

				a[0][0] = tmp0;
				a[1][0] = tmp1;
			}
		}
		return res;
	}

	private static long solve1(long[][] a, long[][] b) {
		long res = 0;
		long type = a[0][1]; // tipo

		long tmp = a[0][0];
		for (long[] ls : b) {
			if (ls[1] == type) {
				long c = Math.min(ls[0], a[0][0]);
				a[0][0] -= c;
				res += c;
			}
		}
		a[0][0] = tmp;

		return res;
	}
}
