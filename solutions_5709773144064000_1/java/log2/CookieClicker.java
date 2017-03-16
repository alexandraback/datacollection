import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Locale;
import java.util.Set;

public class CookieClicker {

	private File from;
	private File to;

	public CookieClicker(String in, String out) {
		from = new File(in);
		to = new File(out);
	}

	public static void main(String[] args) throws IOException {
		new CookieClicker(args[0], args[1]).go();
	}

	private void go() throws IOException {
		try (FileReader fileReader = new FileReader(from)) {
			try (BufferedReader bufferedReader = new BufferedReader(fileReader)) {
				int cases = getNextInt(bufferedReader);
				translateAll(cases, bufferedReader);
			}
		}

	}

	private int getNextInt(BufferedReader bufferedReader) throws IOException {
		String readLine = bufferedReader.readLine();
		return Integer.valueOf(readLine);
	}

	private void translateAll(int count, BufferedReader bufferedReader)
			throws IOException {
		try (PrintWriter writer = new PrintWriter(new FileWriter(to))) {
			for (int i = 1; i <= count; i++) {
				translateNext(i, bufferedReader, writer);
			}
		}
	}

	private void translateNext(int caseIndex, BufferedReader bufferedReader,
			PrintWriter writer) throws IOException {
		double[] values = readVector(bufferedReader);
		double c = values[0];
		double f = values[1];
		double x = values[2];

		double rate = 2.0d;
		double finalRate = rate;
		double totalAccumulatedTime = 0d;
		for (;;) {
			double eta = x / finalRate;
			double nextPossibleBuy = c / finalRate;

			double rateWithClick = finalRate + f;

			double etaWithBuy = nextPossibleBuy + x / rateWithClick;
			if (etaWithBuy < eta) {
				totalAccumulatedTime += nextPossibleBuy;
				finalRate = rateWithClick;
			} else {
				totalAccumulatedTime += eta;
				break;
			}
		}

		writer.print("Case #" + caseIndex + ": ");
		writer.printf(Locale.US, "%1.7f", totalAccumulatedTime);
		writer.println();
	}

	private Set<Integer> getSet(int row, int[][] arrangement) {
		Set<Integer> values = new HashSet<>();
		for (int i : arrangement[row - 1]) {
			values.add(i);
		}
		return values;
	}

	private double[] readVector(BufferedReader bufferedReader)
			throws IOException {
		String line = bufferedReader.readLine();
		String[] parts = line.split(" ");
		double[] values = new double[parts.length];
		for (int i = 0; i < parts.length; i++) {
			values[i] = Double.valueOf(parts[i]);
		}
		return values;
	}
}
