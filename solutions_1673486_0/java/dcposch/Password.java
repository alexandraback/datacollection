import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class Password {
	final BufferedReader reader;
	final PrintStream writer;

	double eChars(int a, int b, double[] probs) {
		double[] echars = new double[a + 1];

		double pcorrect = 1.0;
		for (int i = 0; i <= a; i++) {
			echars[i] = (b - i + 1 + (a - i)) * pcorrect + (b - i + 1 + (a - i) + b + 1) * (1 - pcorrect);
			if (i < a) {
				pcorrect *= probs[i];
			}
		}

		double echar = 2 + b;
		for (int i = 0; i <= a; i++) {
			if (echars[i] < echar) {
				echar = echars[i];
			}
		}
		return echar;
	}

	/**
	 * Just IO
	 */
	void run() {
		int ncases = readInt();
		for (int ncase = 1; ncase <= ncases; ncase++) {
			int[] ab = readInts();
			double[] probs = readDs();
			writer.println("Case #" + ncase + ": " + eChars(ab[0], ab[1], probs));
		}
	}

	int readInt() {
		try {
			return Integer.parseInt(reader.readLine());
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	}

	int[] readInts() {
		try {
			String[] parts = reader.readLine().split(" ");
			int[] ret = new int[parts.length];
			for (int i = 0; i < parts.length; i++) {
				ret[i] = Integer.parseInt(parts[i]);
			}
			return ret;
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	double[] readDs() {
		try {
			String[] parts = reader.readLine().split(" ");
			double[] ret = new double[parts.length];
			for (int i = 0; i < parts.length; i++) {
				ret[i] = Double.parseDouble(parts[i]);
			}
			return ret;
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	Password(String input) {
		InputStream inputStream = this.getClass().getResourceAsStream(input);
		reader = new BufferedReader(new InputStreamReader(inputStream));
		writer = System.out;
	}

	public static void main(String[] args) {
		try {
			new Password("A-small-attempt0.in").run();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
