import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class MineSweeper {
	public static void main(final String[] args) throws FileNotFoundException {
		  final Scanner s = new Scanner(new File("C-large.in.txt"));
	        PrintWriter out = new PrintWriter(new File("Clarge.out"));
	      
		final int tc = s.nextInt();
		s.nextLine();
		for (int tci = 1; tci <= tc; tci++) {
			final int r = s.nextInt();
			final int c = s.nextInt();
			final int m = s.nextInt();

			final char[][] map = new char[r][c];
			for (int i = 0; i < map.length; i++) {
				Arrays.fill(map[i], '.');
			}
			int i = r - 1;
			int j = c - 1;
			int mt = m;
			boolean isvalid = true;
			isvalid = build(map, i, j, mt, isvalid);
			print(out, tci, r, c, m, map, isvalid);
		}
		s.close();
		out.close();
	}

	private static void print(PrintWriter out, int tci, final int r,
			final int c, final int m, final char[][] map, boolean isvalid) {
		if (r * c - 1 == m) {
			for (int i1 = 0; i1 < map.length; i1++) {
				Arrays.fill(map[i1], '*');
			}
			map[0][0] = 'c';
			out.printf("Case #%d:%n", tci);
			for (int i1 = 0; i1 < map.length; i1++) {
				out.println(String.valueOf(map[i1]));
			}
		} else {
			if (r >= 2) {
				if (map[1][0] == '*') {
					isvalid = false;
				}
			}
			if (c >= 2) {
				if (map[0][1] == '*') {
					isvalid = false;
				}
			}
			if (r >= 2 && c >= 2) {
				if (map[1][1] == '*') {
					isvalid = false;
				}
			}
			if (isvalid) {
				map[0][0] = 'c';
				out.printf("Case #%d:%n", tci);
				for (int i1 = 0; i1 < map.length; i1++) {
					out.println(String.valueOf(map[i1]));
				}
			} else {
				out.printf("Case #%d:%n", tci);
				out.println("Impossible");
			}
		}
	}

	private static boolean build(final char[][] map, int i, int j, int mt,
			boolean isvalid) {
		while (mt != 0) {
			if (i < j) { // row shorter than column.
				if (i + 1 <= mt) {
					// fill one column
					for (int k = 0; k <= i; k++) {
						map[k][j] = '*';
					}
					mt -= i + 1;
					j--;
				} else {// i +1> m store in long edge
					if (i == 1 && mt == 1) {
						isvalid = false;
						break;
					}
					if (j == mt) {// store this one in corner
						if (j - 1 == 1) {
							isvalid = false;
							break;
						}
						map[i - 1][j] = '*';
						mt--;
					}
					for (int k = j; k > j - mt; k--) {
						map[i][k] = '*';
					}
					mt = 0;
				}
			} else { // if (i >= j) row longer than column.
				if (j + 1 <= mt) {
					// fill one column
					for (int k = 0; k <= j; k++) {
						map[i][k] = '*';
					}
					mt -= j + 1;
					i--;
				} else {// j +1 > m store in long edge
					if (j == 1 && mt == 1) {
						isvalid = false;
						break;
					}
					if (i == mt) {// store this one in corner
						if (i - 1 == 1) {
							isvalid = false;
							break;
						}
						map[i][j - 1] = '*';
						mt--;
					}
					for (int k = i; k > i - mt; k--) {
						map[k][j] = '*';
					}
					mt = 0;
				}
			}
		}
		return isvalid;
	}

}
