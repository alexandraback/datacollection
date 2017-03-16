import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class B {
	public static void main(String args[]) throws Exception {
		Scanner in = new Scanner(new File("in.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
		long T = in.nextLong();

		for (long num = 1; num <= T; num++) {
			int X = in.nextInt();
			int Y = in.nextInt();

			int myX = 0;
			int myY = 0;

			String ans = "";

			if (X > 0) {
				while (X > myX) {
					ans += "WE";
					myX++;
				}
			} else if(X < 0) {
				while (X < myX) {
					ans += "EW";
					myX--;
				}
			}
			if (Y > 0) {
				while (Y > myY) {
					ans += "SN";
					myY++;
				}
			} else if(Y < 0) {
				while (Y < myY) {
					ans += "NS";
					myY--;
				}
			}
			
			System.out.println(ans.length());
			out.write("Case #" + num + ": " + ans + "\n");
		}

		in.close();
		out.close();
	}
}