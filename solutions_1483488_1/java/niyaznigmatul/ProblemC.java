import java.io.*;
import java.util.*;

public class ProblemC {
	public static void main(String[] args) throws Throwable {
		Scanner in = new Scanner(new File("c.in"));
		PrintWriter out = new PrintWriter("c.out");
		int testCount = Integer.parseInt(in.nextLine().trim());
		for (int i = 0; i < testCount; i++) {
			out.print("Case #" + (i + 1) + ": ");
			solve(in, out);
		}
		out.close();
	}

	static void solve(Scanner in, PrintWriter out) {
		int a = in.nextInt();
		int b = in.nextInt();
		int ans = 0;
		for (int i = a; i <= b; i++) {
			int z = getD(i) / 10;
			int p = i;
			do {
				p = p / 10 + p % 10 * z;
				if (p > i && p <= b) {
					++ans;
				}
			} while (p != i);
		}
		out.println(ans);
	}
	
	static int getD(int i) {
		return i == 0 ? 1 : getD(i / 10) * 10;
	}
}
