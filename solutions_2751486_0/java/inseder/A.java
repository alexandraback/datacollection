package roundC;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;

public class A {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("ca.in"),
				1024 * 1024 * 2);
		BufferedWriter bw = new BufferedWriter(new FileWriter("ca.out"),
				1024 * 1024 * 2);

		int t = Integer.parseInt(br.readLine());
		int count = 1;
		StringBuilder sb = new StringBuilder();

		String line;
		while (count <= t) {
			line = br.readLine();
			int index = line.indexOf(' ');
			String name = line.substring(0, index);
			int n = Integer.parseInt(line.substring(index + 1));

			int ret = 0;
			if (name.length() == 1) {
				if (set.contains(name.charAt(0))) {
					ret = 0;
				} else if (n == 1) {
					ret = 1;
				}
			} else {
				for (int i = 0; i < name.length(); i++) {
					for (int j = i; j < name.length(); j++) {
						// System.out.println(name.substring(i, j + 1));
						if (hasNCon(name.substring(i, j + 1), n)) {
							ret++;
						}
					}
				}
			}

			sb.append("Case #" + count + ": " + ret + "\n");

			count++;
		}
		bw.write(sb.toString());
		System.out.println(sb.toString());
		bw.close();
		br.close();
	}

	public static HashSet<Character> set = new HashSet<Character>();
	static {
		// a, e, i, o, and u
		set.add('a');
		set.add('e');
		set.add('i');
		set.add('o');
		set.add('u');
	}

	public static boolean hasNCon(String x, int n) {
		int count = 0;
		for (int i = 0; i < x.length(); i++) {
			if (!set.contains(x.charAt(i))) {
				count++;
				if (count == n) {
					return true;
				}
			} else {
				count = 0;
			}
		}
		return false;
	}

	public static int[] readArrayLine(String line, int n) {
		int[] ret = new int[n];
		int start = 0;
		int end = line.indexOf(' ', start);
		for (int i = 0; i < n; i++) {
			if (end > 0)
				ret[i] = Integer.parseInt(line.substring(start, end));
			else
				ret[i] = Integer.parseInt(line.substring(start));
			start = end + 1;
			end = line.indexOf(' ', start);
		}
		return ret;
	}
}
