import static java.util.Arrays.deepToString;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public class C {
	static final boolean _PRACTICE = false;
	static final boolean _SMALL = true;
	static final boolean _FILEOUT = true;
	static final String _PROBLEM = "C";

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	private int L;
	private int X;
	private String text;
	private int at;
	private int repeat;

	void run() {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int k = 1; k <= t; k++) {
			System.out.print("Case #" + k + ": ");

			L = sc.nextInt();
			X = sc.nextInt();
			text = sc.next();
			at = 0;
			repeat = 0;

			if (searchIOrJ('i') && searchIOrJ('j') && searchK()) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
		}
		if (sc != null) {
			sc.close();
		}
	}

	private boolean searchIOrJ(int target) {
		int current = 1;
		for (int i = 0; i < L * 4; i++) {
			current = reduce(current, getCurrent());
			if (!forword()) {
				return false;
			}
			if (current == target) {
				return true;
			}
		}
		return false;
	}

	private boolean searchK() {
		int current = 1;
		boolean forwordResult = false;
		for (int i = 0; i < L; i++) {
			current = reduce(current, getCurrent());
			forwordResult = forword();
			if (!forwordResult || at == 0) {
				break;
			}
		}

		int remaining = (X - 1 - repeat + (forwordResult ? 1 : 0)) % 4;
		int reducedText = getReducedText();
		for (int i = 0; i < remaining; i++) {
			current = reduce(current, reducedText);
		}

		return current == 'k';
	}

	private boolean forword() {
		if (at < L - 1) {
			at++;
			return true;
		}
		if (repeat < X - 1) {
			at = 0;
			repeat++;
			return true;
		}
		return false;
	}

	private int getCurrent() {
		return text.charAt(at);
	}

	private int getReducedText() {
		int current = 1;
		for (int i = 0; i < L; i++) {
			current = reduce(current, text.charAt(i));
		}
		return current;
	}

	private int reduce(int left, int right) {
		int result = 0;
		switch (Math.abs(left)) {
		case 1:
			result = Math.abs(right);
			break;
		case 'i':
			switch (Math.abs(right)) {
			case 1:
				result = 'i';
				break;
			case 'i':
				result = -1;
				break;
			case 'j':
				result = 'k';
				break;
			case 'k':
				result = -'j';
				break;
			}
			break;
		case 'j':
			switch (Math.abs(right)) {
			case 1:
				result = 'j';
				break;
			case 'i':
				result = -'k';
				break;
			case 'j':
				result = -1;
				break;
			case 'k':
				result = 'i';
				break;
			}
			break;
		case 'k':
			switch (Math.abs(right)) {
			case 1:
				result = 'k';
				break;
			case 'i':
				result = 'j';
				break;
			case 'j':
				result = -'i';
				break;
			case 'k':
				result = -1;
				break;
			}
			break;
		}
		if (left < 0) {
			result *= -1;
		}
		if (right < 0) {
			result *= -1;
		}
		return result;
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
			new C().run();
		} else {
			System.setIn(is = new FileInputStream(_LARGENAME() + ".in"));
			if (_FILEOUT) {
				System.setOut(ps = new PrintStream(_LARGENAME() + ".out"));
			}
			new C().run();
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
