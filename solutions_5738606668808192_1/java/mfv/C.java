import java.io.*;
import java.util.*;

public class C {

	boolean isDivisor(int d, String s, int base) {
		int rem = 0;
		for (int i = 0; i < s.length(); i++) {
			int digit = s.charAt(i) - '0';
			rem = rem * base + digit;
			rem %= d;
		}
		return rem == 0;
	}

	int getDivisor(String s, int base) {
		for (int d = 3; d <= 99; d += 2) {
			if (isDivisor(d, s, base)) {
				return d;
			}
		}
		return -1;
	}

	void solveOne(Scanner in, PrintWriter out, int iTest) {
		int len = in.nextInt();
		int toGen = in.nextInt();
		out.printf("Case #%d:%n", iTest);
		long cur = (1L << (len - 1)) + 1;
		while (toGen > 0) {
			String s = Long.toString(cur, 2);
			List<Integer> divisors = new ArrayList<>();
			boolean good = true;
			for (int base = 2; base <= 10; base++) {
				int d = getDivisor(s, base);
				if (d == -1) {
					good = false;
					break;
				}
				divisors.add(d);
			}
			if (!good) {
				cur += 2;
				continue;
			}
			out.print(s);
			for (int value : divisors) {
				out.print(" " + value);
			}
			out.println();
			toGen--;
			cur += 2;
		}
	}

	void solve(Scanner in, PrintWriter out) {
		int nTests = in.nextInt();
		for (int iTest = 1; iTest <= nTests; iTest++) {
			solveOne(in, out, iTest);
		}
	}
	
	void run() {
		try (
			Scanner in = new Scanner(System.in);
			PrintWriter out = new PrintWriter(System.out);
	   	) {
	   		solve(in, out);
	   	}
	}


	public static void main(String args[]) {
		new C().run();
	}
}
