/*
 * 
 */
package codejam2016.q.a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.BitSet;

/**
 *
 * @author Gabor Bakos
 */
public class CountingSheep {
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
				int n = Integer.parseInt(br.readLine());
				out.write("Case #" + i + ": " + lastNumberString(n) + lineSep);
			}
		}
	}

	private static String lastNumberString(int n) {
		if (n == 0) {
			return "INSOMNIA";
		}
		return String.valueOf(lastNumber(n));
	}

	private static long lastNumber(int n) {
		BitSet seen = new BitSet(10);
		long v = n;
		while (true) {
			update(seen, v);
			if (seen.cardinality() == 10) {
				return v;
			}
			v += n;
		}
	}

	private static void update(BitSet seen, long v) {
		String s = String.valueOf(v);
		for (int i = s.length(); i-->0;) {
			seen.set(s.charAt(i) - '0');
		}
	}
}
