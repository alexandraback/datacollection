import java.io.*;
import java.util.*;

public class D {

	String solveOne(int len, int pow, int attempts) {
		String ans = "";
		int curLen = 0;
		long num = 0;
		for (int i = 0; i < len; i++) {
			num = num * len + i;
			curLen++;
			if (curLen == pow) {
				ans += " " + (num + 1);
				num = 0;
				curLen = 0;
				attempts--;
			}
		}
		if (curLen > 0) {
			ans += " " + (num + 1);
			attempts--;
		}
		if (attempts < 0) {
			return " IMPOSSIBLE";
		} else {
			return ans;
		}
	}

	void solve(Scanner in, PrintWriter out) {
		int nTests = in.nextInt();
		for (int iTest = 1; iTest <= nTests; iTest++) {
			out.printf("Case #%d:%s%n", iTest, solveOne(in.nextInt(), in.nextInt(), in.nextInt()));
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
		new D().run();
	}
}
