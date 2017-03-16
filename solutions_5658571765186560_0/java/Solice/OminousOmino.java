package Qualification2015;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class OminousOmino {
	public static void main(String[] args) throws IOException {
		String fileName = "D-small-attempt11";
		Scanner s = null;
		PrintWriter p = null;
		try {
			s = new Scanner(new FileInputStream(fileName + ".in"));
			p = new PrintWriter(new File(fileName + ".out"));
		} catch (IOException e) {
		}

		int t = s.nextInt();
		for (int a = 0; a < t; a++) {
			int x = s.nextInt();
			int r = s.nextInt();
			int c = s.nextInt();
			boolean ans = true;
			if (x >= 7)
				ans = false;
			else if (x > r && x > c)
				ans = false;
			else if ((r * c) % x != 0)
				ans = false;
			else if ((x + 1) / 2 > Math.min(r, c))
				ans = false;
			else if (x < 4)
				ans = true;
			else if (x == 4)
				ans = Math.min(r, c) > 2;
			else if (x == 5)
				ans = !(Math.min(r, c) == 3 && Math.max(r, c) == 5);
			else if (x == 6)
				ans = Math.min(r, c) > 3;
			p.println("Case #" + (a + 1) + ": " + (ans ? "GABRIEL" : "RICHARD"));
		}
		p.close();
		s.close();
	}
}
