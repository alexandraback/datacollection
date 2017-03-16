import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class A {
	public static void main(String args[]) throws Exception {
		Scanner in = new Scanner(new File("in.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
		int T = in.nextInt();
		in.nextLine();

		outer: for (int X = 1; X <= T; X++) {
			String b[] = new String[4];
			boolean full = true;
			for (int n = 0; n < 4; n++) {
				b[n] = in.nextLine();
				if (b[n].contains(".")) {
					full = false;
				}
			}
			if (in.hasNextLine())
				in.nextLine();

			for (int r = 0; r < 4; r++) {
				for (int c = 0; c < 4; c++) {
					if (b[r].charAt(c) != 'X' && b[r].charAt(c) != 'T') {
						break;
					}
					if (c == 3) {
						out.write("Case #" + X + ": X won\n");
						continue outer;
					}
				}
			}

			for (int r = 0; r < 4; r++) {
				for (int c = 0; c < 4; c++) {
					if (b[r].charAt(c) != 'O' && b[r].charAt(c) != 'T') {
						break;
					}
					if (c == 3) {
						out.write("Case #" + X + ": O won\n");
						continue outer;
					}
				}
			}

			for (int c = 0; c < 4; c++) {
				for (int r = 0; r < 4; r++) {
					if (b[r].charAt(c) != 'X' && b[r].charAt(c) != 'T') {
						break;
					}
					if (r == 3) {
						out.write("Case #" + X + ": X won\n");
						continue outer;
					}
				}
			}

			for (int c = 0; c < 4; c++) {
				for (int r = 0; r < 4; r++) {
					if (b[r].charAt(c) != 'O' && b[r].charAt(c) != 'T') {
						break;
					}
					if (r == 3) {
						out.write("Case #" + X + ": O won\n");
						continue outer;
					}
				}
			}

			for (int r = 0; r < 4; r++) {
				if (b[r].charAt(r) != 'X' && b[r].charAt(r) != 'T') {
					break;
				}
				if (r == 3) {
					out.write("Case #" + X + ": X won\n");
					continue outer;
				}
			}
			
			for (int r = 0; r < 4; r++) {
				if (b[r].charAt(r) != 'O' && b[r].charAt(r) != 'T') {
					break;
				}
				if (r == 3) {
					out.write("Case #" + X + ": O won\n");
					continue outer;
				}
			}
			
			for (int r = 0; r < 4; r++) {
				if (b[r].charAt(3-r) != 'X' && b[r].charAt(3-r) != 'T') {
					break;
				}
				if (r == 3) {
					out.write("Case #" + X + ": X won\n");
					continue outer;
				}
			}
			
			for (int r = 0; r < 4; r++) {
				if (b[r].charAt(3-r) != 'O' && b[r].charAt(3-r) != 'T') {
					break;
				}
				if (r == 3) {
					out.write("Case #" + X + ": O won\n");
					continue outer;
				}
			}
			
			if(!full)
				out.write("Case #" + X + ": Game has not completed\n");
			else
				out.write("Case #" + X + ": Draw\n");
		}

		in.close();
		out.close();
	}
}