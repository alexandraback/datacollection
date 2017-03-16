import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.US);
		Scanner in = new Scanner(new FileInputStream("D-large.in"));
		PrintWriter out = new PrintWriter("OUTPUT.TXT");
		int t = in.nextInt();
		for (int t0 = 0; t0 < t; ++t0) {
			int n = in.nextInt();
			double[] naomi = new double[n];
			double[] ken = new double[n];
			for (int i = 0; i < n; ++i) {
				naomi[i] = in.nextDouble();
			}
			for (int i = 0; i < n; ++i) {
				ken[i] = in.nextDouble();
			}
			Arrays.sort(naomi);
			Arrays.sort(ken);
			int np = 0, kp = 0;
			int score1 = 0;
			while (np < n) {
				if (naomi[np] > ken[kp]) {
					kp++;
					score1++;
				}
				np++;
			}
			np = kp = 0;
			int score2 = 0;
			while (kp < n) {
				if (ken[kp] > naomi[np]) {
					np++;
					score2++;
				}
				kp++;
			}
			out.println(String
					.format("Case #%d: %d %d", t0 + 1, score1, n-score2));
		}
		in.close();
		out.close();
	}

}
