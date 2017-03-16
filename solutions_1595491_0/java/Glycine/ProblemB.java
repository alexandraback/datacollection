package glycine.gcj2012.qr;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ProblemB {
	private static Map<Integer, Integer> normal = new HashMap<Integer, Integer>();
	private static Map<Integer, Integer> surprise = new HashMap<Integer, Integer>();

	private static void init() {
		for (int i = 0; i <= 1; ++i) {
			normal.put(new Integer(i), new Integer(i));
			surprise.put(new Integer(i), new Integer(i));
		}

		for (int i = 2; i <= 10; ++i) {
			normal.put(new Integer(i), new Integer((i - 1) * 3 + 1));
			surprise.put(new Integer(i), new Integer((i - 2) * 3 + 2));
		}
	}

	private static int solve(int n, int s, int th, List<Integer> valList) {
		Integer normalThMin = normal.get(new Integer(th));
		Integer surpriseThMin = surprise.get(new Integer(th));
		// System.out.println("normalThMin = " + normalThMin +
		// ": surpriseThMin = " + surpriseThMin);
		int count = 0;
		int index;
		for (index = valList.size() - 1; index >= 0; --index) {
			if (valList.get(index) < normalThMin)
				break;
			++count;
		}
		int indexDiff;
		for (indexDiff = 0; indexDiff < s; ++indexDiff) {
			if (index - indexDiff < 0)
				break;
			if (valList.get(index - indexDiff) < surpriseThMin)
				break;
			++count;
		}
		return count;
	}

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		if (args.length != 1) {
			System.err.println("Usage: <program> inputFilename");
			return;
		}
		init();
		BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		String line = reader.readLine();
		int times = Integer.parseInt(line);
		List<Integer> valList = new ArrayList<Integer>();
		for (int i = 0; i < times; ++i) {
			line = reader.readLine();
			String[] tokens = line.split(" ");
			int n = Integer.valueOf(tokens[0]);
			int s = Integer.valueOf(tokens[1]);
			int th = Integer.valueOf(tokens[2]);
			valList.clear();
			for (int j = 0; j < n; ++j) {
				valList.add(new Integer(tokens[j + 3]));
			}
			Collections.sort(valList);
			int result = solve(n, s, th, valList);
			System.out.println("Case #" + (i + 1) + ": " + result);

		}

	}

}
