import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Arrays;

public class ALarge {

	static PrintStream out;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		out = new PrintStream(args[0] + ".out");

		int T = Integer.parseInt(in.readLine());

		for (int t = 1; t <= T; t++) {
			System.out.println(t);
			String[] next = in.readLine().split(" ");
			String name = next[0];
			int n = Integer.parseInt(next[1]);
			int L = name.length();

			boolean[] nameVals = toBool(name);

			long validSubstringCount = 0;

			// find first substring
			int startIndex = 0;
			int index = getNextIndex(nameVals, startIndex, n);
			while (index != -1) {
				validSubstringCount += (index - startIndex - n + 2)
						* (L - index);
				startIndex = index - n + 2;
				index = getNextIndex(nameVals, startIndex, n);
			}

			print(t, validSubstringCount);

		}
	}

	public static int getNextIndex(boolean[] nameVals, int startIndex, int n) {
		int index = -1;
		int currentCons = 0;
		for (int i = startIndex; i < nameVals.length; i++) {
			if (nameVals[i]) {
				currentCons++;
				if (currentCons == n) {
					index = i;
					break;
				}
			} else {
				currentCons = 0;
			}
		}
		return index;
	}

	private static void print(int t, long val) {
		out.println(String.format("Case #%d: %d", t, val));
	}

	private static boolean[] toBool(String name) {
		boolean[] nameVals = new boolean[name.length()];
		for (int i = 0; i < name.length(); i++) {
			char c = name.charAt(i);
			switch (c) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				nameVals[i] = false;
				break;
			default:
				nameVals[i] = true;
			}
		}
		return nameVals;
	}

}
