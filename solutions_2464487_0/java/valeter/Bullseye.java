import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Ivan Anisimov (ivananisimov2010@gmail.com)
 * 
 */
public class Bullseye {
	private static long ringSquare(final long ringRadius) {
		return (ringRadius * ringRadius);
	}

	private static long getPaintVolume(final long ringRadius) {
		return ringSquare(ringRadius + 1) - ringSquare(ringRadius);
	}

	private static long getCirclesCount(final long r, final long t) {
		long result = 0;
		long curRadius = r;
		long curPaint = t;
		do {
			final long circPaint = getPaintVolume(curRadius);
			if (curPaint < circPaint) {
				break;
			}
			result++;
			curPaint -= circPaint;
			curRadius += 2;
		} while (true);
		return result;
	}

	public static void main(final String[] args) {
		final String inputFileName = "C:\\Users\\Valter\\A-small-attempt0.in";
		final String outputFileName = "C:\\Users\\Valter\\A-small-attempt0.out";

		try (final Scanner in = new Scanner(new File(inputFileName));
				final PrintWriter out = new PrintWriter(
						new File(outputFileName))) {
			final int testNum = in.nextInt();
			for (int i = 0; i < testNum; i++) {
				out.write("Case #" + (i + 1) + ": "
						+ getCirclesCount(in.nextLong(), in.nextLong()) + '\r'
						+ '\n');
			}
		} catch (final IOException ex) {
			System.out.println("IO error");
		}
	}
}
