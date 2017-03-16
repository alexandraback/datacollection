package glycine.gcj2012.qr;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class ProblemC {
	private static Set<String> set = new HashSet<String>();

	private static void countRecycle(String numStr, int min, int max) {
		int num = Integer.valueOf(numStr);

		for (int i = 1; i < numStr.length(); ++i) {
			String frontStr = numStr.substring(0, i);
			String backStr = numStr.substring(i, numStr.length());
			if (backStr.charAt(0) == '0') {
				continue;
			}
			String newNumStr = backStr + frontStr;
			int newNum = Integer.valueOf(newNumStr);
			if (newNum >= min && newNum <= max && newNum > num) {
				// System.out.println( numStr + ", " + newNumStr);
				set.add(numStr + ":" + newNumStr);
			}

		}
		return;
	}

	private static void solve(String minStr, String maxStr) {
		set.clear();
		int min = Integer.valueOf(minStr);
		int max = Integer.valueOf(maxStr);
		int length = minStr.length();
		for (int i = min; i <= max; ++i) {
			String numStr = Integer.toString(i);
			countRecycle(numStr, min, max);

		}

		// System.out.println("result = " + set.size());
	}

	public static void main(String[] args) throws IOException {
		if (args.length != 1) {
			System.err.println("Usage: <program> inputFilename");
			return;
		}
		BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		String line = reader.readLine();
		int times = Integer.parseInt(line);
		for (int i = 0; i < times; ++i) {
			line = reader.readLine();
			String[] tokens = line.split(" ");
			solve(tokens[0], tokens[1]);
			System.out.println("Case #" + (i+1) + ": " + set.size());

		}
	}

}
