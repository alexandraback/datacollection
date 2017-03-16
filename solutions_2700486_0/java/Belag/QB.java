import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class QB {

	public static void main(String[] Args) throws IOException {
		Scanner sc = new Scanner(new FileReader("B-small.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		sc.nextLine();
		for (int caseNum = 1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);

			int N = sc.nextInt();
			int X = sc.nextInt();
			X = Math.abs(X);
			int Y = sc.nextInt();

			int minCouche;
			if (X < Y) {
				minCouche = (X + 1) / 2 + (Y - X + 1) / 2;
			} else {
				minCouche = (Y + 1) / 2 + (X - Y + 1) / 2;
			}

			long minDiam = minCouche * (4 * (minCouche - 1) + 2) / 2;
			long maxDiam = (minCouche + 1) * (4 * minCouche + 2) / 2;

			double result;
			if (N <= minDiam) {
				result = 0;
			} else if (N >= maxDiam) {
				result = 1;
			} else {
				int diamDispo = (int) (N - minDiam);
				if (diamDispo > 2 * minCouche) {
					int diamMin = diamDispo - (2 * minCouche);
					if (diamMin > Y) {
						result = 1;
					} else if (X == 0) {
						result = 0;
						if (diamDispo == 4 * minCouche + 1) {
							result = 1;
						}
					} else {
						result = 0;
						for (int i = 0; i <= Y; i++) {
							long fac1 = factorielle(diamDispo);
							long fac2 = factorielle(i);
							long fac3 = factorielle(diamDispo - i);
							result += fac1 / (fac2 * fac3)
									* Math.pow(0.5, diamDispo);
						}
						result = 1 - result;
					}
				} else {
					System.out.println("  2 " + diamDispo + Y);
					result = 0;
					if (Y < diamDispo) {
						for (int i = 0; i <= Math.min(Y, diamDispo); i++) {
							long fac1 = factorielle(diamDispo);
							long fac2 = factorielle(i);
							long fac3 = factorielle(diamDispo - i);
							result += fac1 / (fac2 * fac3)
									* Math.pow(0.5, diamDispo);
						}
						result = 1 - result;
					} else {
						result = 0;
					}
				}
			}

			pw.println("Case #" + caseNum + ": " + result);
		}

		pw.flush();
		pw.close();
		sc.close();
	}

	static long factorielle(int i) {
		long res = 1;
		for (int j = 1; j <= i; j++) {
			res *= j;
		}
		return res;
	}
}
