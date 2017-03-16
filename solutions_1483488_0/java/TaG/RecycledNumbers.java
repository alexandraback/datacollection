package google.codejam;

import java.awt.Point;
import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import com.google.common.base.CharMatcher;
import com.google.common.base.Charsets;
import com.google.common.io.Closeables;
import com.google.common.io.Files;

public class RecycledNumbers {

	public static final int LETTERS_IN_ALPHABET = 26;

	public static void main(String[] args) throws IOException {
		File cwd = new File("C:\\Users\\TaG\\workspace\\CodeJam\\");
		File inputFile = new File(cwd, "input.txt");
		File outputFile = new File(cwd, "output.txt");
		if (outputFile.exists())
			outputFile.delete();
		PrintStream out = null;
		try {
			out = new PrintStream(outputFile);

			List<String> lines = Files.readLines(inputFile, Charsets.UTF_8);
			int cases = Integer.parseInt(lines.remove(0));
			int caseNo = 1;
			for (String line : lines) {
				String[] split = line.split(" ");
				int a = Integer.parseInt(split[0]);
				int b = Integer.parseInt(split[1]);
				int recycledPairs = countRecycledPairs(a, b);
				out.printf("Case #%d: %d\n", caseNo, recycledPairs);
				System.out.printf("Case #%d: %d\n", caseNo, recycledPairs);
				caseNo++;
			} // end for-each lines
		} finally {
			Closeables.closeQuietly(out);
		}
	}

	private static int countRecycledPairs(final int a, final int b) {
		if (a >= b) {
			return 0;
		}
		int count = 0;
		for (int n = a; n <= b; n++) {
			Set<Point> set = new HashSet<Point>();
			String ns = Integer.toString(n);
			// System.out.println(ns + ":");
			for (int i = 1; i < ns.length(); i++) {
				String s1 = ns.substring(0, i);
				s1 = CharMatcher.is('0').trimLeadingFrom(s1);
				String s2 = ns.substring(i);
				s2 = CharMatcher.is('0').trimLeadingFrom(s2);
				String ms = s2 + s1;
				if (ns.length() == ms.length()) {
					// System.out.println(s1 + ", " + s2);
					int m = Integer.parseInt(ms);
					if (n > m) {
						int t = n;
						m = n;
						n = t;
					}
					if (a <= n && n < m && m <= b && set.add(new Point(n, m))) {
						count++;
						// System.out.println(ns + ", " + ms);
					}
				}
			}
			// System.out.println();
		}
		return count;
	}

}