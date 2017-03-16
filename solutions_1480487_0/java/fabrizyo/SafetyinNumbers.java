import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Locale;
import java.util.Scanner;

public class SafetyinNumbers {

	private static double e = 1e-9;

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("inputA.txt"));
		PrintWriter pw = new PrintWriter("outputA.txt");
		DecimalFormat format = new DecimalFormat("0.0000000", DecimalFormatSymbols.getInstance(Locale.US));

		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			int N = sc.nextInt();
			int[] cs = new int[N];
			for (int i = 0; i < cs.length; i++) {
				cs[i] = sc.nextInt();
			}

			int sum = 0;
			for (int c : cs) {
				sum += c;
			}

			pw.print("Case #" + t + ": ");
			for (int i = 0; i < cs.length; i++) {
				double low = 0;
				double high = sum;
				while (high - low > e) {
					double mid = (low + high) / 2;
					if (can(mid, sum, cs, i)) {
						high = mid;
					} else {
						low = mid;
					}
				}
				pw.print(format.format(100 * ((double) high / sum)));
				if (i < cs.length - 1) {
					pw.print(" ");
				}
			}
			pw.println();
		}
		pw.flush();
		pw.close();
	}

	private static boolean can(double scoreAudience, double sum, int[] cs, int index) {
		double score = cs[index] + scoreAudience;
		double rest = sum - scoreAudience;
		for (int i = 0; i < cs.length; i++) {
			if (i != index) {
				rest -= cs[i] < score ? score - cs[i] : 0;
			}
		}
		return rest <= 0;
	}
}
