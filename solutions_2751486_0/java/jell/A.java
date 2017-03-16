import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Arrays;

public class A {

	static PrintStream out;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		out = new PrintStream(args[0] + ".out");

		int T = Integer.parseInt(in.readLine());

		for (int t = 1; t <= T; t++) {
			String[] next = in.readLine().split(" ");
			String name = next[0];
			int n = Integer.parseInt(next[1]);
			int L = name.length();

			boolean[] nameVals = toBool(name);

			int[][] consec = new int[L][L];

			int validSubstringCount = 0;

			for (int j = L - 1; j >= 0; j--) {
				consec[j][j] = nameVals[j] ? 1 : 0;
				for (int i = j; i >= 0; i--) {
					if (consec[i][j] >= n) {
						validSubstringCount += i + 1;
						break;
					} else {
						if (i > 0) {
							consec[i - 1][j] = nameVals[i - 1] ? consec[i][j] + 1 : 0;
						}
					}
				}
			}

			print(t, validSubstringCount);

		}
	}

	private static void print(int t, int val) {
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
