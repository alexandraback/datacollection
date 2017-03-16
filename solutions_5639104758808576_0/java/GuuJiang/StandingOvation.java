package codejam2015;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class StandingOvation {
	Scanner cin;
	
	public void solveAll() {
		cin = new Scanner(System.in);
		int t = cin.nextInt();
		for (int i = 1; i <= t; ++i) {
			System.out.printf("Case #%d: %d\n", i, solve());
		}
	}
	
	private int solve() {
		int smax = cin.nextInt();
		String s = cin.next();
		int count = 0;
		int need = 0;
		for (int i = 0; i <= smax; ++i) {
			int cur = s.charAt(i) - '0';
			if (count < i) {
				need += (i - count);
				count = i;
			}
			count += cur;
		}
		return need;
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("A-small-attempt0.in"));
		System.setOut(new PrintStream("A-small.out"));
		new StandingOvation().solveAll();
	}
}
