import java.io.PrintStream;
import java.util.Scanner;

public class B {

	public static void main(String[] args) throws Exception {
		System.setOut(new PrintStream("out"));

		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		for (int t = 1; t <= T; t++) {
			int N = s.nextInt();
			int S = s.nextInt();
			int P = s.nextInt();

			int[][] matrix = { { 0, 0, 0 }, { 0, 0, 1 }, { 0, 1, 0 }, { 0, 1, 1 }, { 0, 0, -1 }, { 0, -1, 0 }, { 0, -1, -1 }, { 1, 0, 0 }, { 1, 0, 1 },
					{ 1, 1, 0 }, { 1, 1, 1 }, { -1, 0, 0 }, { -1, 0, -1 }, { -1, -1, 0 }, { -1, -1, -1 } };

			int[][] matrix2 = { { 1, 1, -1 }, { 1, -1, 0 }, { 1, -1, 1 }, { 1, -1, -1 }, { 1, 0, -1 }, { 1, 1, -1 }, { 1, -1, 0 }, { 1, -1, 1 }, { 1, -1, -1 },
					{ 1, 0, -1 }, { 1, 1, -1 }, { 1, -1, 0 }, { 1, -1, 1 }, { 1, -1, -1 } };

			int max = 0;

			for (int n = 0; n < N; n++) {
				int x = s.nextInt();

				boolean ok = false;
				int m = x / 3;
				for (int i = 0; i < matrix.length; i++) {
					int a = m + matrix[i][0];
					int b = m + matrix[i][1];
					int c = m + matrix[i][2];

					if (a == 7 && b == 6 && c == 9)
						continue;

					if (a + b + c == x && a >= 0 && b >= 0 && c >= 0 && a <= 10 && b <= 10 && c <= 10) {
						if (Math.max(a, Math.max(b, c)) >= P) {
							max++;
							ok = true;
							break;
						}
					}
				}

				if (ok == false) {
					m = x / 3 + 1;
					for (int i = 0; i < matrix.length; i++) {
						int a = m + matrix[i][0];
						int b = m + matrix[i][1];
						int c = m + matrix[i][2];

						if (a == 7 && b == 6 && c == 9)
							continue;

						if (a + b + c == x && a >= 0 && b >= 0 && c >= 0 && a <= 10 && b <= 10 && c <= 10) {
							if (Math.max(a, Math.max(b, c)) >= P) {
								max++;
								ok = true;
								break;
							}
						}
					}
				}

				if (ok == false) {
					m = x / 3 - 1;
					for (int i = 0; i < matrix.length; i++) {
						int a = m + matrix[i][0];
						int b = m + matrix[i][1];
						int c = m + matrix[i][2];

						if (a == 7 && b == 6 && c == 9)
							continue;

						if (a + b + c == x && a >= 0 && b >= 0 && c >= 0 && a <= 10 && b <= 10 && c <= 10) {
							if (Math.max(a, Math.max(b, c)) >= P) {
								max++;
								ok = true;
								break;
							}
						}
					}
				}

				if (ok == false && S > 0) {
					m = x / 3;
					for (int i = 0; i < matrix2.length; i++) {
						int a = m + matrix2[i][0];
						int b = m + matrix2[i][1];
						int c = m + matrix2[i][2];

						if (a == 7 && b == 6 && c == 9)
							continue;

						if (a + b + c == x && a >= 0 && b >= 0 && c >= 0 && a <= 10 && b <= 10 && c <= 10) {
							if (Math.max(a, Math.max(b, c)) >= P) {
								max++;
								S--;
								ok = true;
								break;
							}
						}
					}
				}

				if (ok == false && S > 0) {
					m = x / 3 + 1;
					for (int i = 0; i < matrix2.length; i++) {
						int a = m + matrix2[i][0];
						int b = m + matrix2[i][1];
						int c = m + matrix2[i][2];

						if (a == 7 && b == 6 && c == 9)
							continue;

						if (a + b + c == x && a >= 0 && b >= 0 && c >= 0 && a <= 10 && b <= 10 && c <= 10) {
							if (Math.max(a, Math.max(b, c)) >= P) {
								max++;
								S--;
								ok = true;
								break;
							}
						}
					}
				}
				if (ok == false && S > 0) {
					m = x / 3 - 1;
					for (int i = 0; i < matrix2.length; i++) {
						int a = m + matrix2[i][0];
						int b = m + matrix2[i][1];
						int c = m + matrix2[i][2];

						if (a == 7 && b == 6 && c == 9)
							continue;

						if (a + b + c == x && a >= 0 && b >= 0 && c >= 0 && a <= 10 && b <= 10 && c <= 10) {
							if (Math.max(a, Math.max(b, c)) >= P) {
								max++;
								S--;
								ok = true;
								break;
							}
						}
					}
				}
			}

			System.out.println("Case #" + t + ": " + max);
		}

	}
}
