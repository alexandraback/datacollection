package net.shivramk;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		FileInputStream stream = new FileInputStream("B-small-attempt0.in");
		Scanner sc = new Scanner(stream);
		int count = sc.nextInt();
		sc.nextLine();
		
		for (int i = 0; i < count; ++i) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			sc.nextLine();
			Solver s = new Solver(n, m);
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < m; ++k) {
					s.addVal(j, k, sc.nextInt());
				}
				sc.nextLine();
			}
			System.out.print("Case #" + (i+1) + ": ");
			s.solve();
		}
	}
}

