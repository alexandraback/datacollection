package Q;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {
	public static void main(String[] args) throws IOException,
			FileNotFoundException {
		String file = "C-small-attempt2";

		Scanner scan = new Scanner(new BufferedReader(new FileReader(file
				+ ".in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(file
				+ ".out")));

		int T = Integer.parseInt(scan.nextLine());
		for (int t = 1; t <= T; t++) {
			String[] info = scan.nextLine().split(" ");
			int X = Integer.parseInt(info[1]);
			String line = scan.nextLine();

			int maxrepeat = 4 * 4;
			if (X < maxrepeat)
				maxrepeat = X;
			if (X > maxrepeat)
				maxrepeat += (X - maxrepeat) % 4;
			String pre = "";
			for (int i = 0; i < maxrepeat; i++)
				pre += line;

			String[] to = { "i", "j", "k", "1" };
			boolean ok = true;
			int i = 0;
			while (ok && pre.length() > 0) {
				int index = compute(pre, to[i]);
				if (index == -1)
					ok = false;
				else {
					pre = pre.substring(index + 1);
					if (i < 3)
						i++;
				}
			}
			if (i < 3)
				ok = false;

			if (ok)
				pw.println("Case #" + t + ": YES");
			else
				pw.println("Case #" + t + ": NO");
		}

		scan.close();
		pw.close();
	}

	private static int compute(String from, String to) {
		String res = "1";
		for (int i = 0; i < from.length(); i++) {
			res = multi(res, from.substring(i, i + 1));
			if (res.compareTo(to) == 0)
				return i;
		}
		return -1;
	}

	private static String multi(String a, String b) {
		boolean sign = (a.length() + b.length() - 2) == 1;
		if (a.length() > 1)
			a = a.substring(1);
		if (b.length() > 1)
			b = b.substring(1);
		String s = get(a, b);
		if (s.length() > 1)
			return sign ? s.substring(1) : s;
		return sign ? "-" + s : s;
	}

	private static String[][] table = { { "1", "i", "j", "k" },
			{ "i", "-1", "k", "-j" }, { "j", "-k", "-1", "i" },
			{ "k", "j", "-i", "-1" } };

	private static String get(String a, String b) {
		int r = 0, c = 0;
		switch (a) {
		case "1":
			r = 0;
			break;
		case "i":
			r = 1;
			break;
		case "j":
			r = 2;
			break;
		case "k":
			r = 3;
			break;
		}
		switch (b) {
		case "1":
			c = 0;
			break;
		case "i":
			c = 1;
			break;
		case "j":
			c = 2;
			break;
		case "k":
			c = 3;
			break;
		}
		return table[r][c];
	}

}
