import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class D {
	private int T, X, R, C;
	private Scanner in = null;
	private String str = null;

	void solve() {
		try {
			System.setIn(new FileInputStream("d1"));
			System.setOut(new PrintStream("out"));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		in = new Scanner(System.in);
		T = in.nextInt();
		for (int testcase = 1; T > 0; T--, testcase++) {
			// System.out.format("Case #%d: ", testcase);
			System.out.print("Case #" + testcase + ": ");
			X = in.nextInt();
			R = in.nextInt();
			C = in.nextInt();
			if (R > C) {
				int t = R;
				R = C;
				C = t;
			}
			boolean ok = true;
			if (R == 1) {
				if (X >= 3 || (X == 2 && C % 2 == 1))
					ok = false;
			}
			if (R == 2) {
				if (X >= 4 || (X == 3 && C % 3 != 0))
					ok = false;
			}
			if (R == 3) {
				if ((X == 2 && C % 2 != 0) || (X == 4 && C % 4 != 0))
					ok = false;
			}
			if (R == 4) {
				if ((X == 3 && C % 3 != 0))
					ok = false;
			}
			if (ok)
				System.out.println("GABRIEL");
			else
				System.out.println("RICHARD");
		}
	}
}
