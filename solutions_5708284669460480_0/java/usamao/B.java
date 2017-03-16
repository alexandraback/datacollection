import static java.util.Arrays.deepToString;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Scanner;

public class B {
	static final boolean _PRACTICE = false;
	static final boolean _SMALL = true;
	static final boolean _FILEOUT = true;
	static final String _PROBLEM = "B";

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int k = 1; k <= t; k++) {
			System.out.print("Case #" + k + ": ");

			K = sc.nextInt();
			L = sc.nextInt();
			S = sc.nextInt();
			KEYBOARD = sc.next();
			TARGET = sc.next();

			initField();

			if (!canAchive()) {
				System.out.println("0.0");
				continue;
			}

			int carried = computeCarried();
			float seed = computeAtFitLength();
			float expectation = computeExpectation(seed);

			System.out.println(carried - expectation);
		}
		if (sc != null) {
			sc.close();
		}
	}

	private int K, L, S;
	private String KEYBOARD;
	private String TARGET;
	private HashMap<Character, Integer> keyMap = new HashMap<Character, Integer>();

	private void initField() {
		keyMap.clear();
		for (int i = 0; i < KEYBOARD.length(); i++) {
			char c = KEYBOARD.charAt(i);
			Integer count = keyMap.get(c);
			keyMap.put(c, count != null ? ++count : 1);
		}
	}

	private int computeCarried() {
		return (S - countOverlap()) / (TARGET.length() - countOverlap());
	}

	private int countOverlap() {
		for (int overlap = TARGET.length() - 1; overlap > 0; overlap--) {
			if (TARGET.endsWith(TARGET.substring(0, overlap))) {
				return overlap;
			}
		}
		return 0;
	}

	private boolean canAchive() {
		if (TARGET.length() > S) {
			return false;
		}
		for (int i = 0; i < TARGET.length(); i++) {
			if (!keyMap.containsKey(TARGET.charAt(i))) {
				return false;
			}
		}
		return true;
	}

	private float computeAtFitLength() {
		float probability = 1.0f;
		for (int i = 0; i < TARGET.length(); i++) {
			int keyCount = keyMap.get(TARGET.charAt(i)) != null ? keyMap
					.get(TARGET.charAt(i)) : 0;
			probability *= ((float) keyCount / KEYBOARD.length());
		}
		return probability;
	}

	private float computeExpectation(float seed) {
		return (S - TARGET.length() + 1) * seed;
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
			new B().run();
		} else {
			System.setIn(is = new FileInputStream(_LARGENAME() + ".in"));
			if (_FILEOUT) {
				System.setOut(ps = new PrintStream(_LARGENAME() + ".out"));
			}
			new B().run();
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
