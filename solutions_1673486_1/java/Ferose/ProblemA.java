import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class ProblemA {

	public static void main(String[] args) throws FileNotFoundException {
		start();
	}

	public static void start() throws FileNotFoundException {
		File file = new File("./");
		String name = "";
		for (File f : file.listFiles()) {
			if (f.getName().endsWith(".in")) {
				name = f.getName().replaceFirst("\\.in", "");
				break;
			}
		}
		Scanner in = new Scanner(new File(name + ".in"));
		PrintWriter out = new PrintWriter(new File(name + ".out"));
		long startTime = System.nanoTime();
		new Solution(in, out);
		System.out.println("\n" + (System.nanoTime() - startTime)
				* Math.pow(10, -9) + " seconds");
		out.close();
	}

	public static class Solution {

		public Solution(Scanner in, PrintWriter out) {
			int cases = in.nextInt();
			in.nextLine();
			for (int i = 1; i <= cases; i++) {
				String answer = "Case #" + i + ": "
						+ compute(in.nextLine(), in.nextLine());
				out.println(answer);
				System.out.println(answer);
			}
		}

		DecimalFormat df = new DecimalFormat("0.000000");
		
		int numTyped;
		int total;
		ArrayList<Double> correctChance;
		double everythingCorrectChance;

		private String compute(String line1, String line2) {
			Scanner sc1 = new Scanner(line1);

			numTyped = sc1.nextInt();
			total = sc1.nextInt();

			Scanner sc2 = new Scanner(line2);

			correctChance = new ArrayList<Double>();

			while (sc2.hasNextDouble()) {
				correctChance.add(sc2.nextDouble());
			}

			everythingCorrectChance = 1;
			for (double d : correctChance) {
				everythingCorrectChance *= d;
			}

			ArrayList<Double> probabilityList = new ArrayList<Double>();

			probabilityList.add(keepTypingProbability());
			probabilityList.add(pressingEnterProbability());

			double bec = 1;
			
			for (int i = numTyped; i > 0; --i) {
				probabilityList.add(backspaceProbability(i, bec));
				bec *= correctChance.get(numTyped-i);
			}

			double answer = Collections.min(probabilityList);
			return df.format(answer);
		}

		private Double backspaceProbability(int numBack, double bec) {
			return bec * (numBack + numBack + (total - numTyped) + 1)
					+ (1 - bec)
					* (numBack + numBack + (total - numTyped) + 1 + total + 1);
		}

		private Double pressingEnterProbability() {
			if (numTyped < total) {
				return (double) (total + 2);
			}
			return everythingCorrectChance * 1 + (1 - everythingCorrectChance)
					* (total + 2);
		}

		private Double keepTypingProbability() {

			return everythingCorrectChance * (total - numTyped + 1)
					+ (1 - everythingCorrectChance)
					* (total - numTyped + 1 + total + 1);
		}
	}
}
