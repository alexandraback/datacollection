import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		File input = null;
		for (File f : new File(".").listFiles()) {
			if (f.isFile() && f.getName().endsWith(".in")) {
				input = f;
				break;
			}
		}
		Scanner s = new Scanner(input);
		BufferedWriter w = new BufferedWriter(new FileWriter(new File("output")));
		int cases = s.nextInt();
		s.nextLine();

		for (int i = 0; i < cases; i++) {
			w.write("Case #");
			w.write(String.valueOf(i + 1));
			w.write(": ");

			int n = s.nextInt();
			double[] naomi = new double[n];
			double[] ken = new double[n];


			for (int j = 0; j < n; j++) {
				naomi[j] = s.nextDouble();
			}

			for (int j = 0; j < n; j++) {
				ken[j] = s.nextDouble();
			}

			Arrays.sort(naomi);
			Arrays.sort(ken);


			int honest = honest(n, Arrays.copyOf(naomi, n), Arrays.copyOf(ken, n));
			int deceitful = deceitful(n, naomi, ken);


			w.write(" ");
			w.write(String.valueOf(deceitful));
			w.write(" ");
			w.write(String.valueOf(honest));
			w.write("\n");
		}
		w.close();
	}

	private static int deceitful(int n, double[] naomi, double[] ken) {
		int scoreNaomi = 0;
		int kenI = 0;

		for (double chosenNaomi : naomi) {
			if (chosenNaomi > ken[kenI]) {
				scoreNaomi++;
				kenI++;
			}
		}

		return scoreNaomi;
	}

	private static int honest(int n, double[] naomi, double[] ken) {
		int scoreNaomi = 0;
		int end = 0;

		outer:
		for (int i = n-1; i >= 0; i--) {
			double chosenNaomi = naomi[i];
			int lastIndex = n;
			for (int j = n - 1; j >= end; j--) {
				if (ken[j] > 0) {
					if (ken[j] > chosenNaomi) {
						lastIndex = j;
					} else {
						if (lastIndex < n) {
							ken[lastIndex] = 0;
						} else {
							scoreNaomi++;
							end++;
						}
						continue outer;
					}
				}
			}
			if (lastIndex  < n) {
				ken[lastIndex] = 0;
			} else {
				scoreNaomi++;
				end++;
			}
		}

		return scoreNaomi;
	}

}
