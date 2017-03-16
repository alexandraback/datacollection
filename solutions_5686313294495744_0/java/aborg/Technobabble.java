/*
 * 
 */
package codejam2016.round1b.c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 *
 * @author Gabor Bakos
 */
public class Technobabble {
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
				int titleCount = Integer.parseInt(br.readLine());
				String[] firstTitles = new String[titleCount], secondTitles = new String[titleCount];
				for (int q = titleCount; q -->0;) {
					String[] parts = br.readLine().split(" ");
					firstTitles[q] = parts[0];
					secondTitles[q] = parts[1];
				}
				out.write("Case #" + i + ": " + maxFakes(firstTitles, secondTitles) + lineSep);
			}
		}
	}

	private static int maxFakes(String[] firstTitles, String[] secondTitles) {
		int res = 0;
		Set<String> firsts = new HashSet<>(Arrays.asList(firstTitles)), seconds = new HashSet<>(Arrays.asList(secondTitles));
//		if (firsts.size() == firstTitles.length || seconds.size() == secondTitles.length) {
//			return 0;
//		}
		return Math.min(firstTitles.length - firsts.size(), secondTitles.length - seconds.size());
	}

}
