package gcj.y2012.round1.krige;

import gcj.krige.commons.Utils;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.StringTokenizer;

public class PasswordProblem {
	private static final String PATH = "input" + File.separator + "y2012"
			+ File.separator + "round1" + File.separator;
	private static final String INPUT_FILE_NAME = "A-small-attempt0.in";
	private static final String OUTPUT_FILE_NAME = "A-small-attempt0.out";

	public static void main(String[] args) throws IOException {
		String[] input = readFromFile(PATH + INPUT_FILE_NAME);
		String[] output = new String[input.length / 2];
		int x = 0;
		for (int i = 0; i < input.length; i += 2) {

			StringTokenizer st1 = new StringTokenizer(input[i]);
			int numCharactersTyped = Integer.valueOf(st1.nextToken());
			int passwordLength = Integer.valueOf(st1.nextToken());

			StringTokenizer st2 = new StringTokenizer(input[i + 1]);
			double[] probabilities = new double[numCharactersTyped];
			for (int j = 0; j < probabilities.length; j++) {
				probabilities[j] = Double.valueOf(st2.nextToken());
			}
			DecimalFormat twoDForm = new DecimalFormat("#.######");
			System.out.println("Computing case #" + (x + 1));
			output[x++] = "Case #"
					+ x
					+ ": "
					+ twoDForm.format(expectedKeystrokes(passwordLength,
							probabilities));
		}
		Utils.writeToFile(output, PATH + OUTPUT_FILE_NAME);
	}

	private static double expectedKeystrokes(int passwordLength,
			double[] probabilities) {
		double minKeystrokes = passwordLength + 2;
		for (int numBackspaces = 0; numBackspaces < probabilities.length; numBackspaces++) {

			double keystrokes = keystrokesNeeded(passwordLength, numBackspaces,
					probabilities);
			if (keystrokes < minKeystrokes) {
				minKeystrokes = keystrokes;
			}
		}
		return minKeystrokes;
	}

	private static double keystrokesNeeded(int passwordLength,
			int numBackspaces, double[] probabilities) {
		double prob = probabilities[0];
		int x = probabilities.length - numBackspaces;
		for (int i = 1; i < x; i++) {
			prob *= probabilities[i];
		}
		return prob * (passwordLength - x + 1) + (1 - prob)
				* (2 * passwordLength - x + 2) + numBackspaces;
	}

	public static String[] readFromFile(String fileName) throws IOException {
		System.out.println("Reading file " + fileName);
		String[] lines = null;
		FileInputStream fstream = new FileInputStream(fileName);
		DataInputStream in = new DataInputStream(fstream);
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		String strLine = br.readLine();
		lines = new String[Integer.valueOf(strLine) * 2];
		int i = 0;
		while ((strLine = br.readLine()) != null) {
			lines[i++] = strLine;
		}
		in.close();
		return lines;
	}
}
