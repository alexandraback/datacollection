package codejam.round1c;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class C {

	private static final String FILE = "C:\\temp\\C-small-attempt0";

	//////////////////////////////////////////////////
	private static void increaseCount(Map<String, Integer> combs, String key) {

		Integer count = combs.get(key);
		combs.put(key, count == null ? 1 : count + 1);
	}

	//////////////////////////////////////////////////
	private static boolean isAccepted(Map<String, Integer> combs, String key, int combAllowed) {

		Integer count = combs.get(key);
		return count == null || count < combAllowed;
	}

	//////////////////////////////////////////////////
	private static boolean isAccepted(Map<String, Integer> combs, int jacket, int pant, int shirt, int combAllowed) {

		String key1 = "JP" + jacket + " " + pant;
		String key2 = "JS" + jacket + " " + shirt;
		String key3 = "PS" + pant + " " + shirt;

		boolean res = isAccepted(combs, key1, combAllowed) && isAccepted(combs, key2, combAllowed)
				&& isAccepted(combs, key3, combAllowed);

		if (res) {
			increaseCount(combs, key1);
			increaseCount(combs, key2);
			increaseCount(combs, key3);
		}
		return res;
	}

	//////////////////////////////////////////////////
	public static void main(String[] args) throws Exception {

		Scanner in = null;
		PrintStream out = null;

		try {

			in = new Scanner(new BufferedReader(new FileReader(new File(FILE + ".in"))));
			out = new PrintStream(new File(FILE + ".out"));

			// in = new Scanner(new BufferedReader(new
			// InputStreamReader(System.in)));
			// out = System.out;

			int t = in.nextInt();
			// Finish the line.
			in.nextLine();
			for (int i = 1; i <= t; ++i) {

				int jackets = in.nextInt();
				int pants = in.nextInt();
				int shirts = in.nextInt();
				int combAllowed = in.nextInt();
				int count = 0;

				Map<String, Integer> combs = new HashMap<>();

				StringBuilder sb = new StringBuilder();
				for (int j = 1; j <= jackets; j++) {
					for (int p = 1; p <= pants; p++) {
						for (int s = 1; s <= shirts; s++) {
							if (isAccepted(combs, j, p, s, combAllowed)) {
								count++;
								if (sb.length() != 0) {
									sb.append('\n');
								}
								sb.append(j + " " + p + " " + s);
							}
						}
					}
				}

				out.println("Case #" + i + ": " + count);
				out.println(sb.toString());
			}
		} finally {
			if (in != null) {
				in.close();
			}
			if (out != null) {
				out.close();
			}
		}
	}
}
