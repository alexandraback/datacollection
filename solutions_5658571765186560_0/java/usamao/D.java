import static java.util.Arrays.deepToString;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public class D {
	static final boolean _PRACTICE = false;
	static final boolean _SMALL = true;
	static final boolean _FILEOUT = true;
	static final String _PROBLEM = "D";

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	private int X;
	private int R;
	private int C;

	void run() {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int k = 1; k <= t; k++) {
			System.out.print("Case #" + k + ": ");

			X = sc.nextInt();
			R = sc.nextInt();
			C = sc.nextInt();

			if(isFit()){
				System.out.println("GABRIEL");
			}else{
				System.out.println("RICHARD");
			}
		}
		if (sc != null) {
			sc.close();
		}
	}

	private boolean isFit() {
		int great = Math.max(R, C);
		int little = Math.min(R, C);

		if (great < X || little < (X + 1) / 2) {
			return false;
		}

		if (X == 4 && little == 2 && great == 4) {
			return false;
		}

		return great * little % X == 0;
	}

	public static void main(String... args) throws IOException {
		FileInputStream is = null;
		PrintStream ps = null;
		if (_SMALL) {
			int i = 0;
			while (new File(_SMALLNAME(i) + ".in").exists())
				i++;
			i--;
			if (new File(_SMALLNAME(i) + ".out").exists()) {
				System.err.println("overwrite?(y/n)");
				char c = (char) System.in.read();
				if (c != 'y') {
					return;
				}
			}
			System.setIn(is = new FileInputStream(_SMALLNAME(i) + ".in"));
			if (_FILEOUT) {
				System.setOut(ps = new PrintStream(_SMALLNAME(i) + ".out"));
			}
			new D().run();
		} else {
			System.setIn(is = new FileInputStream(_LARGENAME() + ".in"));
			if (_FILEOUT) {
				System.setOut(ps = new PrintStream(_LARGENAME() + ".out"));
			}
			new D().run();
		}
		if (is != null)
			is.close();
		if (ps != null)
			ps.close();
	}

	private static String _LARGENAME() {
		return _PROBLEM + "-large" + (_PRACTICE ? "-practice" : "");
	}

	private static String _SMALLNAME(int a) {
		return _PROBLEM + "-small"
				+ (_PRACTICE ? a == 0 ? "-practice" : "" : "-attempt" + a);
	}
}
