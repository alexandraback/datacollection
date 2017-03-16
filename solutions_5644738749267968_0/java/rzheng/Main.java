import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("D-small-attempt0.in"));
		System.setOut(new PrintStream("D-small-attempt0.out"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			int N = sc.nextInt();
			double[] naomi1 = new double[N], naomi2 = new double[N], ken1 = new double[N], ken2 = new double[N];
			for (int j = 0; j < N; j++) {
				naomi1[j] = naomi2[j] = sc.nextDouble();
			}
			for (int j = 0; j < N; j++) {
				ken1[j] = ken2[j] = sc.nextDouble();
			}
			Arrays.sort(naomi1);
			Arrays.sort(naomi2);
			Arrays.sort(ken1);
			Arrays.sort(ken2);
			System.out.println("Case #" + i + ": " + (N - war(naomi1, ken1))
					+ " " + war(ken2, naomi2));
		}
		sc.close();
	}

	private static int war(double[] a1, double[] a2) {
		int result = 0;
		for (int j = 0; j < a1.length; j++) {
			for (int k = 0; k <= a1.length; k++) {
				if (k == a1.length) {
					for (int l = 0; l < a1.length; l++) {
						if (a1[l] != 0) {
							a1[l] = 0;
							result++;
						}
					}
				} else {
					if (a1[k] > a2[j]) {
						a1[k] = 0;
						break;
					}
				}
			}
		}
		return result;
	}
}