import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Set;

public class RecycledNumbers {

	private RecycledNumbers() {

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

			final long A = Long.parseLong(words[0]);
			final long B = Long.parseLong(words[1]);

			final Set<String> resultSet = new HashSet<String>();

			for (long M = B; M >= A; M--) {
				final String str1 = String.valueOf(M);
				if (str1.length() == 1) {
					continue;
				}
				for (int max = str1.length() - 1; max >= 1; max--) {
					final String first = str1.substring(0, str1.length() - max);
					final String last = str1.substring(str1.length() - max,
							str1.length());

					final String str2 = last + first;
					final long N = Long.valueOf(str2);

					if (A <= N && N < M && M <= B && str1.charAt(0) != '0'
							&& str2.charAt(0) != '0') {

						/*
						 * System.out.println(A + " <= " + N + "(" + str2 +
						 * ") < " + M + "(" + str1 + ") <= " + B);
						 */
						resultSet.add(str1 + str2);
					}
				}
			}

			if (caseNo > 1) {
				writer.write("\n");
			}

			final String text = "Case #" + (caseNo++) + ": " + resultSet.size();
			System.out.println(text);
			writer.write(text);
			writer.flush();
		}
		writer.close();
		reader.close();
	}

	public static void main(final String[] args) throws Exception {
		final RecycledNumbers number = new RecycledNumbers();

		final File outputFile = new File("output/C-large.out");
		if (outputFile.exists()) {
			outputFile.delete();
		}
		final FileOutputStream fos = new FileOutputStream(outputFile);

		number.solveInput(
				SpeakingInTongues.class.getResourceAsStream("C-large.in"), fos);

	}

}
