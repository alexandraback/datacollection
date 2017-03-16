package net.shivramk;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		FileInputStream stream = new FileInputStream("A-large.in");
		Scanner sc = new Scanner(stream);
		int count = sc.nextInt();
		sc.nextLine();
		
		for (int i = 0; i < count; ++i) {
			Solver s = new Solver();
			for (int j = 0; j < 4; ++j) {
				s.addLine(sc.nextLine());
			}
			sc.nextLine();
			System.out.print("Case #" + (i+1) + ": ");
			s.solve();
		}
	}
}
