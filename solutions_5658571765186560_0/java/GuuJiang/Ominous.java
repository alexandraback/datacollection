package codejam2015;

import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Ominous {	
	Scanner cin;

	public void solveAll() {
		cin = new Scanner(System.in);
		int t = cin.nextInt();
		for (int i = 1; i <= t; ++i) {
			System.out.printf("Case #%d: %s\n", i, solve());
		}
	}

	private String solve() {
		int x = cin.nextInt();
		int r = cin.nextInt();
		int c = cin.nextInt();
		if (r > c) {
			int t = r;
			r = c;
			c = t;
		}
		switch (x) {
		case 1:
			return "GABRIEL";
		case 2:
			switch (r) {
			case 1:
				return c % 2 == 0 ? "GABRIEL" : "RICHARD";
			case 2:
				return "GABRIEL";
			case 3:
				return c % 2 == 0 ? "GABRIEL" : "RICHARD";
			case 4:
				return "GABRIEL";
			}
		case 3:
			switch (r) {
			case 1:
				return "RICHARD";
			case 2:
				return c % 2 == 0 ? "RICHARD" : "GABRIEL";
			case 3:
				return "GABRIEL";
			case 4:
				return "RICHARD";
			}
		case 4:
			switch (r) {
			case 1:
				return "RICHARD";
			case 2:
				return "RICHARD";
			case 3:
				return c == 3 ? "RICHARD" : "GABRIEL";
			case 4:
				return "GABRIEL";				
			}
		}
		return null;
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("D-small-attempt1.in"));
		System.setOut(new PrintStream("D-small.out"));
		new Ominous().solveAll();
	}
}
