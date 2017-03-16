import java.io.*;
import java.util.*;

public class A {

	void addDigits(int n, Set<Integer> digitsUsed) {
		while (n > 0) {
			digitsUsed.add(n % 10);
			n /= 10;
		}
	}

	String solveOne(int n) {
		if (n == 0) {
			return "INSOMNIA";
		}
		Set<Integer> digitsUsed = new TreeSet<>();
		for (int i = 1; i <= 100; i++) {
			addDigits(n * i, digitsUsed);
			if (digitsUsed.size() == 10) {
				return "" + n * i;
			}
		}
		throw new Error("n=" + n);
	}

	void solve(Scanner in, PrintWriter out) {
		int nTests = in.nextInt();
		for (int iTest = 1; iTest <= nTests; iTest++) {
			out.printf("Case #%d: %s%n", iTest, solveOne(in.nextInt()));
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
		new A().run();
	}
}
