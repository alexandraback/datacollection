import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;

public class Solution {

	private static BufferedReader in;
	private static FileWriter out;

	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new FileReader("D-small-attempt2.in"));
		out = new FileWriter("out");

		doWork();

		in.close();
		out.close();
	}

	private static void doWork() throws Exception {
		int t = Integer.parseInt(in.readLine());

		for (int i = 1; i <= t; i++) {
			int n = Integer.parseInt(in.readLine());

			double[] naomi = new double[n];
			String[] split = in.readLine().split(" ");
			for (int j = 0; j < split.length; j++) {
				naomi[j] = Double.parseDouble(split[j]);
			}

			double[] ken = new double[n];
			split = in.readLine().split(" ");
			for (int j = 0; j < split.length; j++) {
				ken[j] = Double.parseDouble(split[j]);
			}

			println("Case #" + i + ": " + solve(naomi, ken));
		}
	}

	private static String solve(double[] naomi, double[] ken) {
		if (naomi.length == 1) {
			if (naomi[0] > ken[0]) {
				return "1 1";
			} else {
				return "0 0";
			}
		}

		sort(naomi);
		sort(ken);

		int deceitful = 0;
		int kenMinIndex = 0;
		int kenMaxIndex = ken.length - 1;
		for (int i = 0; i < ken.length; i++) {
			if (naomi[i] > ken[kenMaxIndex]) {
				deceitful++;
			} else if (naomi[i] < ken[kenMinIndex]) {
				kenMaxIndex--;
			} else {
				kenMinIndex++;
				deceitful++;
			}
		}

		int fair = 0;
		for (int i = 0; i < ken.length; i++) {
			for (int j = 0; j < ken.length; j++) {
				if (naomi[i] < ken[j]) {
					naomi[i] = 0;
					ken[j] = 0;
					break;
				}
			}
			if (naomi[i] > 0) {
				naomi[i] = 0;
				for (int k = 0; k < ken.length; k++) {
					if (ken[k] > 0) {
						ken[k] = 0;
						break;
					}
				}
				fair++;
			}
		}

		return deceitful + " " + fair;
	}

	private static void sort(double[] arr) {
		for (int i = 0; i < arr.length; i++) {
			for (int j = i; j < arr.length; j++) {
				if (arr[j] < arr[i]) {
					double tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			}
		}
	}

	static void println(String line) throws Exception {
		out.write(line + '\n');
		System.out.println(line);
	}
}
