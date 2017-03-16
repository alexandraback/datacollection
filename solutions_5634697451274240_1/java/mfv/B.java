import java.io.*;
import java.util.*;

public class B {

	int solveOne(String s) {
		int count = 0;
		for (int i = 1; i < s.length(); i++) {
			if (s.charAt(i) != s.charAt(i - 1)) {
				count++;
			}
		}
		if (s.charAt(s.length() - 1) == '-') {
			count++;
		}
		return count;
	}

	void solve(Scanner in, PrintWriter out) {
		int nTests = in.nextInt();
		for (int iTest = 1; iTest <= nTests; iTest++) {
			out.printf("Case #%d: %s%n", iTest, solveOne(in.next()));
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
		new B().run();
	}
}
