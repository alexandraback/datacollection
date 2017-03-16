/*
 * 
 */
package codejam2016.q.d;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 *
 * @author Gabor Bakos
 */
public class Fractiles {
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
				String [] parts = br.readLine().split(" ");
				int k = Integer.parseInt(parts[0]), c = Integer.parseInt(parts[1]), s = Integer.parseInt(parts[2]);
				out.write("Case #" + i + ": " + checksString(k, c, s) + lineSep);
			}
		}
	}

	private static String checksString(int k, int c, int s) {
		if (k == s) {
			return String.join(" ", Arrays.stream(checks(k, c)).mapToObj(v -> String.valueOf(v)).collect(Collectors.toList()));
		}
		if (s == 1) {
			return "IMPOSSIBLE";
		}
		//TODO
		return null;
	}

	private static int[] checks(int k, int c) {
		return IntStream.iterate(1, i -> i + 1).limit(k).toArray();
	}
}
