package R1C_2013;

import java.awt.Point;
import java.io.*;
import java.util.*;

public class B {

	static BufferedWriter writer;

	static final int[][] adj = new int[][] {
		new int[] {-1, 0, 0},
		new int[] {1, 0, 1},
		new int[] {0, 1, 2},
		new int[] {0, -1, 3}
	};

	static final String S = "WENS";

	public static void main(String[] args) throws IOException {
		writer = new BufferedWriter(new FileWriter("output.out"));
		Scanner reader = new Scanner(new FileReader("input.in"));
		int nt = reader.nextInt();
		reader.nextLine();
		for (int tc = 1; tc <= nt; tc++) {
			writer.write("Case #" + tc + ": ");
			int x = reader.nextInt();
			int y = reader.nextInt();
			writer.write(solveSmall(x, y));
			writer.newLine();
		}
		writer.close();
		System.out.println("Done.");
	}

	static String solveSmall(int x, int y) {
		StringBuilder path = new StringBuilder();
		int cX = 0;
		int cY = 0;
		int k = 1;
		while(cX != x) {
			if(k % 2 == 1) {
				cX += k;
				path.append('E');
			} else {
				cX -= k;
				path.append('W');
			}
			k++;
		}
		int r = 0;
		if(y > 0) {
			while(cY != y) {
				if(r % 2 == 0) {
					path.append('S');
					cY -= k;
				} else {
					path.append('N');
					cY += k;
				}
				r++;
				k++;
			}
		} else {
			while(cY != y) {
				if(r % 2 == 0) {
					path.append('N');
					cY += k;
				} else {
					path.append('S');
					cY -= k;
				}
				r++;
				k++;
			}
		}
		return path.toString();
	}


}


