import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Scanner;

public class PancakeRevenge {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("\\in"));
		PrintWriter out = new PrintWriter(new File("\\out"));
		
		int T = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": ");

			String s = in.nextLine();
			int ans = 0;
			for (ans = 0; s.indexOf("-") != -1; ans++) {
				int i1 = s.indexOf("-");
				int i2 = s.indexOf("+");
				if (i1 > i2) {
					int tmp = i1;
					i1 = i2;
					i2 = tmp;
				}

				if (s.indexOf("+") == -1) {
					i2 = s.length();
				}

				StringBuilder next = new StringBuilder(s);

				for (int i = 0; i < i2; i++) {
					char c = s.charAt(i);
					next.setCharAt(i, c == '+' ? '-' : '+');
				}
				debug(s + " " + i1 + " " + i2 + " " + next.toString());

				s = next.toString();
			}

			out.println(ans);
		}

		in.close();
		out.close();
	}

	public static void debug(Object o) {
		System.out.println("\t\tDEBUG: " + o.toString().replace("\n", "\n\t\tDEBUG: "));
	}
}
