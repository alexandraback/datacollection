import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.util.HashMap;

public class SpeakingInTongues {

	private final HashMap<Character, Character> googlereseToNormal = new HashMap<Character, Character>();

	public SpeakingInTongues() {
		googlereseToNormal.put('a', 'y');
		googlereseToNormal.put('b', 'h');
		googlereseToNormal.put('c', 'e');
		googlereseToNormal.put('d', 's');
		googlereseToNormal.put('e', 'o');
		googlereseToNormal.put('f', 'c');
		googlereseToNormal.put('g', 'v');
		googlereseToNormal.put('h', 'x');
		googlereseToNormal.put('i', 'd');
		googlereseToNormal.put('j', 'u');
		googlereseToNormal.put('k', 'i');
		googlereseToNormal.put('l', 'g');
		googlereseToNormal.put('m', 'l');
		googlereseToNormal.put('n', 'b');
		googlereseToNormal.put('o', 'k');
		googlereseToNormal.put('p', 'r');
		googlereseToNormal.put('q', 'z');
		googlereseToNormal.put('r', 't');
		googlereseToNormal.put('s', 'n');
		googlereseToNormal.put('t', 'w');
		googlereseToNormal.put('u', 'j');
		googlereseToNormal.put('v', 'p');
		googlereseToNormal.put('w', 'f');
		googlereseToNormal.put('x', 'm');
		googlereseToNormal.put('y', 'a');
		googlereseToNormal.put('z', 'q');
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
			final char[] googlereseText = line.trim().toCharArray();
			final char[] normalText = new char[googlereseText.length];

			for (int i = 0; i < googlereseText.length; i++) {
				if (googlereseText[i] == ' ') {
					normalText[i] = ' ';
					continue;
				}
				final char ch = googlereseToNormal.get(googlereseText[i]);
				normalText[i] = ch;
			}

			if (caseNo > 1) {
				writer.write("\n");
			}
			final String text = "Case #" + (caseNo++) + ": "
					+ new String(normalText);
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
		final SpeakingInTongues sit = new SpeakingInTongues();

		final File outputFile = new File("output/A-small-attempt0.out");
		if (outputFile.exists()) {
			outputFile.delete();
		}
		final FileOutputStream fos = new FileOutputStream(outputFile);

		sit.solveInput(SpeakingInTongues.class
				.getResourceAsStream("A-small-attempt0.in"), fos);

	}

}
