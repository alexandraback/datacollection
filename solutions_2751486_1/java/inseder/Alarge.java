package roundC;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;

public class Alarge {

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
			long ret = 0;

			int max[] = new int[name.length()];
			int pos[] = new int[name.length()];
			for (int i = 0; i < name.length(); i++) {
				if (i == 0) {
					if (set.contains(name.charAt(0))) {
						max[i] = 0;
						pos[i] = -1;
					} else {
						max[i] = 1;
						pos[i] = 0;
					}
				} else {
					if (set.contains(name.charAt(i))) {
						max[i] = 0;
						pos[i] = pos[i - 1];
					} else {
						if (set.contains(name.charAt(i - 1))) {
							max[i] = 1;
							pos[i] = i;
						} else {
							max[i] = max[i - 1] + 1;
							pos[i] = pos[i - 1];
						}
					}
				}
			}

			boolean infront = false;
			int add[] = new int[name.length()];
			for (int i = 0; i < name.length(); i++) {
				if (max[i] >= n) {
					infront = true;
					int dif = max[i] - n;
					add[i] = pos[i] + dif + 1;
				} else if (infront) {
					add[i] = add[i - 1];
				}
			}

			for (int i = 0; i < name.length(); i++) {
				ret += add[i];
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

}
