import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class DeceitfulWar {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("src/in.txt"));
		PrintWriter out = new PrintWriter("out.txt");

		int t = Integer.parseInt(in.readLine());

		for (int tc = 1; tc <= t; tc++) {
			int n = Integer.parseInt(in.readLine());

			double[] naomi = new double[n + 1];
			double[] ken = new double[n + 1];

			String[] splits = in.readLine().split(" ");
			for (int i = 1; i <= n; i++) {
				naomi[i] = Double.parseDouble(splits[i - 1]);
			}

			splits = in.readLine().split(" ");
			for (int i = 1; i <= n; i++) {
				ken[i] = Double.parseDouble(splits[i - 1]);
			}

			Arrays.sort(naomi);
			Arrays.sort(ken);

			boolean[] used = new boolean[n + 1];

			int warPoints = 0;
			int deceitfulWarPoints = 0;

			for (int i = 1; i <= n; i++) {
				// current element played by Naomi
				double crtN = naomi[i];

				// current element played by Ken
				double crtK = 0;

				double min = 1.0;
				int idxMin = 0;

				for (int j = 1; j <= n; j++) {
					if (!used[j] && ken[j] > crtN && ken[j] < min) {
						min = ken[j];
						idxMin = j;
					}
				}

				if (Double.compare(min, 1.0) == 0) {
					// Ken has no block heavier than Naomi
					// he must play his smallest unused block
					for (int j = 1; j <= n; j++) {
						if (!used[j]) {
							crtK = ken[j];
							used[j] = true;
							break;
						}
					}
				} else {
					crtK = ken[idxMin];
					used[idxMin] = true;
				}

				if (Double.compare(crtN, crtK) > 0) {
					warPoints++;
				}
			}

			deceitfulWarPoints = n;

			int size = n;

			boolean hasBigger = true;
			while (size > 0 && hasBigger) {
				hasBigger = false;
				int idx = 0;
				for (int i = 1; i <= size; i++) {
					if (ken[i] > naomi[i]) {
						hasBigger = true;
						idx = i;
					}
				}

				if (hasBigger) {
					size--;
					deceitfulWarPoints--;

					for (int i = 1; i <= n - 1; i++) {
						naomi[i] = naomi[i + 1];
					}

					for (int i = idx; i <= size; i++) {
						ken[i] = ken[i + 1];
					}
				}
			}

			out.println("Case #" + tc + ": " + deceitfulWarPoints + " "
					+ warPoints);
		}

		in.close();
		out.close();
	}
}
