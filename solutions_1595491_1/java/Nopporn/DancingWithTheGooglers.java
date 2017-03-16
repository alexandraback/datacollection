import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;

public class DancingWithTheGooglers {
	private DancingWithTheGooglers() {
	}

	public void solveInput(final InputStream input, final OutputStream output)
			throws IOException {

		final BufferedReader reader = new BufferedReader(new InputStreamReader(
				input));
		final BufferedWriter writer = new BufferedWriter(
				new OutputStreamWriter(output));

		final int numTestCase = Integer.valueOf(reader.readLine().trim());

		System.out.println("Total Test Cases: " + numTestCase);

		String line = null;
		int caseNo = 1;
		while ((line = reader.readLine()) != null) {
			final String[] words = line.trim().split(" ");
			final int N = Integer.parseInt(words[0]);
			final int S = Integer.parseInt(words[1]);
			final int P = Integer.parseInt(words[2]);
			final int[] scores = new int[N];
			for (int i = 0; i < N; i++) {
				scores[i] = Integer.parseInt(words[3 + i]);
			}
			int Y = 0;
			int nS = S;

			for (int i = 0; i < N; i++) {
				final int score = scores[i];
				final int avg = score / 3;
				if (avg >= P) {
					Y++;
					continue;
				}

				final int[] triplets = new int[] { avg, avg, avg };
				final int remainder = score % 3;

				if (remainder > 0) {
					if ((avg + 1) >= P) {
						Y++;
						continue;
					} else if (avg + remainder >= P && nS > 0) {
						Y++;
						nS--;
						continue;
					}
				}
				if (triplets[1] > 0) {
					++triplets[0];
					--triplets[1];
					if (triplets[0] >= P && nS > 0) {
						Y++;
						nS--;
						continue;
					}
				} else if (triplets[2] > 0) {
					++triplets[0];
					--triplets[2];
					if (triplets[0] >= P && nS > 0) {
						Y++;
						nS--;
						continue;
					}
				}
			}

			if (caseNo > 1) {
				writer.write("\n");
			}
			final String text = "Case #" + (caseNo++) + ": " + (Y);
			System.out.println(text);
			writer.write(text);
			writer.flush();
		}
		writer.close();
		reader.close();
	}

	/**
	 * @param args
	 */
	public static void main(final String[] args) throws Exception {
		final DancingWithTheGooglers dancing = new DancingWithTheGooglers();

		final File outputFile = new File("output/B-large.out");
		if (outputFile.exists()) {
			outputFile.delete();
		}
		final FileOutputStream fos = new FileOutputStream(outputFile);

		dancing.solveInput(
				SpeakingInTongues.class.getResourceAsStream("B-large.in"), fos);

	}
}
