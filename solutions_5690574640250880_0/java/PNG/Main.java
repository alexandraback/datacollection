import java.io.*;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		File input = null;
		for (File f : new File(".").listFiles()) {
			if (f.isFile() && f.getName().endsWith(".in")) {
				input = f;
				break;
			}
		}
		Scanner s = new Scanner(input);
		BufferedWriter w = new BufferedWriter(new FileWriter(new File("output")));
		int cases = s.nextInt();
		s.nextLine();

		for (int i = 0; i < cases; i++) {
			w.write("Case #");
			w.write(String.valueOf(i + 1));
			w.write(": \n");

			int r = s.nextInt();
			int c = s.nextInt();
			int m = s.nextInt();

			int empty = r * c - m;

			int side = (int) Math.ceil(Math.sqrt(empty));

			if (side > c || side > r) {
				side = c;
			}

			boolean possible;
			if (empty == 1) {
				possible = true;
			} else if (c == 1 || r == 1) {
				possible = true;
			} else {
				if (empty / side == 1) {
					possible = false;
				} else if (empty % side == 1) {
					possible = false;
				} else {
					possible = true;
				}
			}


			int entered = 0;

			if (possible) {
				for (int aa = 0; aa < r; aa++) {
					int curRow = 0;
					for (int bb = 0; bb < c; bb++) {
						if (entered == 0) {
							w.write("c");
							entered++;
							curRow++;
						} else if (entered < empty){
							if (curRow < side) {
								w.write(".");
								entered++;
								curRow++;
							} else {
								w.write("*");
							}
						} else {
							w.write("*");
						}
					}
					w.write("\n");
				}
			} else {
				w.write("Impossible\n");
			}
		}
		w.close();
	}

}
