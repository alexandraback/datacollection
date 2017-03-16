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
		String file = "D-large";

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
			if (C < R) {
				int hold = C;
				C = R;
				R = hold;
			}

			if (check(X, R, C))
				pw.println("Case #" + t + ": GABRIEL");
			else
				pw.println("Case #" + t + ": RICHARD");
		}

		scan.close();
		pw.close();
	}

	private static boolean check(int X, int R, int C) {
		if (X == 1)
			return true;
		if ((R * C) % X != 0)
			return false;
		if (X > C)
			return false;
		if (X > R + R)
			return false;
		if (X == R + C)
			return false;
		if (X < R + 2)
			return true;
		int extra = X - R;
		// check two partition
		for (int left = 1; left < extra; left++) {
			boolean found = false;
			int right = extra - left;
			for (int loc = left; loc + right < C; loc++) {
				int blankleft = loc * R - left;
				int blankright = (C - loc) * R - right;
				if (blankleft % X == 0 && blankright % X == 0)
					found = true;
			}
			if (!found)
				return false;
		}
		return true;
	}

}
