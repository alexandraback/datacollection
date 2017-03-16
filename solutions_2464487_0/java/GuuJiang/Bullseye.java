package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class Bullseye {

	private Scanner cin;
	private PrintStream cout;
	
	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		new Bullseye().solve();
	}
	
	public Bullseye() throws Exception {
		/*
		cin = new Scanner(System.in);
		cout = System.out;
		/*/
		cin = new Scanner(new File("A-small-attempt0.in"));
		cout = new PrintStream("A-small-attempt0.out");
		//*/
	}

	private void solve() {
		int t = cin.nextInt();
		for (int i = 1; i <= t; ++i) {
			cout.printf("Case #%d: %s\n", i, solveCase());
		}
	}
	
	private String solveCase() {
		long r = cin.nextLong();
		long t = cin.nextLong();
		double a = 2.0;
		double b = 2 * r - 1;
		double c = -t;
		double root = (Math.sqrt(b * b - 4 * a * c) - b) / a / 2;
		return String.valueOf((int) root);
	}
}
