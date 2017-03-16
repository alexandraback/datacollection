package ua.rudolf.codejam.contest2012;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeMap;

import javax.swing.text.NumberFormatter;

public class A {

	double s[];
	double res[];
	int n;

	private void solve() {
		res = new double[n];
		double sum = 0;
		for (int i = 0; i < n; i++)
			sum += s[i];

		for (int i = 0; i < n; i++) {
			double min = 0;
			double max = 1;
			while (Math.abs(max - min) >= 1e-12) {
				double c = (min + max) / 2;
				double curValue = s[i] + sum * c;
				double uSum = 0;
				int count = 0;
				for (int k = 0; k < n; k++)
					if (k != i && s[k] <= curValue) {
						uSum += s[k];
						count++;
					}
				if ((uSum + sum * (1 - c))/count >= curValue) min = c;
				else max = c;
			}
			res[i] = (min * 100) + 1e-10;
		}

	}

	public void run() throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int ti = 0; ti < t; ti++) {
			n = sc.nextInt();
			s = new double[n];
			for (int i = 0; i < n; i++)
				s[i] = sc.nextDouble();
			solve();
			System.out.print("Case #" + (ti + 1) + ":");
			for (int i = 0; i < n; i++)
				System.out.print(" " + res[i]);
			System.out.println();

		}
	}

	/**
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new BufferedInputStream(new FileInputStream("A-small-attempt3.in")));
//		System.setIn(new BufferedInputStream(new FileInputStream("a.in")));
		System.setOut(new PrintStream(new FileOutputStream("a.out")));
		new A().run();
	}

}
