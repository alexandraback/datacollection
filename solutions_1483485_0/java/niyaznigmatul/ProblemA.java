import java.io.*;
import java.util.*;

public class ProblemA {
	public static void main(String[] args) throws Throwable {
		Scanner in = new Scanner(new File("a.in"));
		PrintWriter out = new PrintWriter("a.out");
		int testCount = Integer.parseInt(in.nextLine().trim());
		for (int i = 0; i < testCount; i++) {
			out.print("Case #" + (i + 1) + ": ");
			solve(in, out);
		}
		out.close();
	}

	static String MAP = "yhesocvxduiglbkrztnwjpfmaq";

	static void solve(Scanner in, PrintWriter out) {
		String s = in.nextLine();
		StringBuilder sb = new StringBuilder();
		for (char c : s.toCharArray()) {
			if (c == ' ') {
				sb.append(' ');
			} else {
				sb.append(MAP.charAt(c - 'a'));
			}
		}
		out.println(sb.toString());
	}
}
