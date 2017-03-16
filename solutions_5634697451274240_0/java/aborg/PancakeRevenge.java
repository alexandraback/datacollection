/*
 * 
 */
package codejam2016.q.b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;

/**
 *
 * @author Gabor Bakos
 */
public class PancakeRevenge {
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		String lineSep = System.getProperty("line.separator");
		try (BufferedReader br = new BufferedReader(
				args.length > 0 ? new FileReader(args[0]) : new InputStreamReader(System.in));
				Writer out = new BufferedWriter(
						args.length > 1 ? new FileWriter(args[1]) : new OutputStreamWriter(System.out))) {
			int numCases = Integer.parseInt(br.readLine().trim());
			for (int i = 1; i <= numCases; ++i) {
				String definition = br.readLine();
				out.write("Case #" + i + ": " + minFlips(definition) + lineSep);
			}
		}
	}

	private static int minFlips(String definition) {
		return minFlips(definition, 0);
	}
	private static int minFlips(String definition, int prevFlips) {
		if (definition.indexOf('-') < 0) {
			return prevFlips;
		}
		int lastIndex = definition.lastIndexOf('-');
		if (definition.charAt(0) == '+') {
			prevFlips += 1;
			definition = flip(definition, definition.indexOf('-') - 1);
		}
		String newDef = flip(definition, lastIndex);
		return minFlips(newDef, prevFlips + 1);
	}

	private static String flip(String definition, int lastIndex) {
		StringBuilder sb = new StringBuilder(definition);
		sb.setLength(lastIndex + 1);
		sb.reverse();
		for (int i = lastIndex + 1; i -->0;) {
			sb.setCharAt(i, sb.charAt(i) == '-' ? '+' : '-');
		}
		String ret = sb.append(definition.substring(lastIndex + 1)).toString();
		return ret;
	}
}
