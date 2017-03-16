package Q;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class D {
	public static void main(String[] args) throws IOException,
			FileNotFoundException {
		String file = "D-small-attempt1";

		Scanner scan = new Scanner(new BufferedReader(new FileReader(file
				+ ".in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(file
				+ ".out")));

		int T = Integer.parseInt(scan.nextLine());
		for (int t = 1; t <= T; t++) {
			String[] info = scan.nextLine().split(" ");
			int X = Integer.parseInt(info[0]);
			int R = Integer.parseInt(info[1]);
			int C = Integer.parseInt(info[2]);

			boolean ok = true;
			if ((R * C) % X != 0)
				ok = false;
			for (int r = 1; r <= X; r++) {
				int maxc = X - r + 1;
				if (r > Math.min(R, C) && maxc > Math.min(R, C))
					ok = false;
				if (Math.max(r, maxc) > Math.max(R, C))
					ok = false;
			}
			if (X == 4) {
				if ((R == 4 && C == 2) || (R == 2 && C == 4))
					ok = false;
			}

			if (!ok)
				pw.println("Case #" + t + ": RICHARD");
			else
				pw.println("Case #" + t + ": GABRIEL");
		}

		scan.close();
		pw.close();
	}

}
