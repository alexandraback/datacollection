package G1C;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class b {
	public static void main(String[] args) throws IOException {
		FileInputStream in = new FileInputStream(
				"D:/works/java/G1A/bin/B-small-attempt0 (2).in");
		Scanner s = new Scanner(in);
		PrintWriter out = new PrintWriter(new FileWriter(
				"D:/works/java/G1A/bin/B.out"));

		int n = Integer.parseInt(s.next());
		for (int i = 1; i <= n; i++) {
			int k = s.nextInt(), l = s.nextInt(), s1 = s.nextInt();
			int count = 0;
			boolean p = false;
			String keys = s.next(), letter = s.next();
			for (int j = 0; j < letter.length(); j++) {
				if (!keys.contains(letter.charAt(j) + "")) {
					System.out.println("Case #" + i + ": " + 0.0);
					out.println("Case #" + i + ": " + 0.0);
					p = true;
					break;
				}
			}
			String sol = "";
			if (!p) {
				int o = 0;
				sol += letter;
				count++;
				for (int j = 1; j < sol.length(); j++) {
					if (letter.startsWith(sol.substring(j, sol.length()))) {
						o = sol.substring(j, sol.length()).length();
						break;
					}
				}
				while (sol.length() < s1) {
					sol += letter.substring(o, letter.length());
					count++;
				}
				sol = sol.substring(0, s1);
				// System.out.println(sol + count);
				float tp = 1;
				for (int j = 0; j < letter.length(); j++) {
					float p1 = countOccurrences(keys, letter.charAt(j));
					// System.out.println(p1);
					tp *= p1 / keys.length();
				}
				float r = count - tp * count;
				System.out.println("Case #" + i + ": " + r);
				out.println("Case #" + i + ": " + r);

			}

		}
		out.close();
	}

	public static int countOccurrences(String haystack, char needle) {
		int count = 0;
		for (int i = 0; i < haystack.length(); i++) {
			if (haystack.charAt(i) == needle) {
				count++;
			}
		}
		return count;
	}

}
