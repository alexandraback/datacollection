import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Ivan Anisimov (ivananisimov2010@gmail.com)
 * 
 */
public class ManageYourEnergy {
	public static long getMaxGain(final int E, final int R, final int[] v,
			final int e, final int step) {
		if (step == (v.length - 1)) {
			return e * v[step];
		}
		long result = 0;
		for (int i = 0; i <= e; i++) {
			result = Math.max(result,
					getMaxGain(E, R, v, Math.min(E, (e - i) + R), step + 1)
							+ (v[step] * i));
		}
		return result;
	}

	public static void main(final String[] args) {
		final String inputFileName = "C:\\Users\\Valter\\B-small-attempt1.in";
		final String outputFileName = "C:\\Users\\Valter\\B-small-attempt1.out";

		try (final Scanner in = new Scanner(new File(inputFileName));
				final PrintWriter out = new PrintWriter(
						new File(outputFileName))) {
			final int testNum = in.nextInt();
			for (int i = 0; i < testNum; i++) {
				System.out.println("Processing test #" + (i + 1));
				final int E = in.nextInt();
				final int R = in.nextInt();
				final int N = in.nextInt();
				final int[] v = new int[N];
				for (int j = 0; j < N; j++) {
					v[j] = in.nextInt();
				}
				out.write("Case #" + (i + 1) + ": " + getMaxGain(E, R, v, E, 0)
						+ '\r' + '\n');
			}
		} catch (final IOException ex) {
			System.out.println("IO error");
		}
	}
}
