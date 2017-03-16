package codejam2015;

import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Dijkstra {
	Scanner cin;

	public void solveAll() {
		cin = new Scanner(System.in);
		int t = cin.nextInt();
		for (int i = 1; i <= t; ++i) {
			System.out.printf("Case #%d: %s\n", i, solve());
		}
	}

	private String solve() {
		int l = cin.nextInt();
		int x = cin.nextInt();
		String s = cin.next();
		int xl = l * x;
		StringBuilder sb = new StringBuilder(xl);
		for (int i = 0; i < x; ++i) {
			sb.append(s);
		}
		s = sb.toString();
		int i = 0;
		Quaternion q = Quaternion.One;
		while (q != Quaternion.I) {
			if (i >= xl) {
				return "NO";
			}
			q = q.mult(Quaternion.fromChar(s.charAt(i)));
			++i;
		}
		q = Quaternion.One;
		while (q != Quaternion.J) {
			if (i >= xl) {
				return "NO";
			}
			q = q.mult(Quaternion.fromChar(s.charAt(i)));
			++i;
		}
		q = Quaternion.One;
		while (q != Quaternion.K) {
			if (i >= xl) {
				return "NO";
			}
			q = q.mult(Quaternion.fromChar(s.charAt(i)));
			++i;
		}
		q = Quaternion.One;
		while (i < xl) {
			q = q.mult(Quaternion.fromChar(s.charAt(i)));
			++i;
		}
		return q == Quaternion.One ? "YES" : "NO";
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("C-small-attempt0.in"));
		System.setOut(new PrintStream("C-small.out"));
		new Dijkstra().solveAll();
	}
}

enum Quaternion {
	One, I, J, K, None, NI, NJ, NK;

	private final static Quaternion[][] mat = {
			{ One, I, J, K, None, NI, NJ, NK },
			{ I, None, K, NJ, NI, One, NK, J },
			{ J, NK, None, I, NJ, K, One, NI },
			{ K, J, NI, None, NK, NJ, I, One },
			{ None, NI, NJ, NK, One, I, J, K },
			{ NI, One, NK, J, I, None, K, NJ },
			{ NJ, K, One, NI, J, NK, None, I },
			{ NK, NJ, I, One, K, J, NI, None } };

	public static Quaternion fromChar(char c) {
		switch (c) {
		case 'i':
			return I;
		case 'j':
			return J;
		case 'k':
			return K;
		default:
			return null;
		}
	}
	
	public Quaternion mult(Quaternion other) {
		return mat[ordinal()][other.ordinal()];
	}
}