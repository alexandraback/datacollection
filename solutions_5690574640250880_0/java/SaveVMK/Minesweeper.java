import java.io.*;
import java.util.*;

public class Minesweeper {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/C-small.in"))));

		String output = "";
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			int r = sc.nextInt();
			int c = sc.nextInt();
			int m = sc.nextInt();
			int nm = r*c-m;
			output += "Case #" + i + ":\n";
			if (nm == 1) {
				for (int j = 0; j < r-1; j++) {
					for (int k = 0; k < c; k++) {
						output += "*";
					}
					output += "\n";
				}
				for (int j = 0; j < c-1; j++) {
					output += "*";
				}
				output += "c\n";
			} else if (r == 1 || c == 1) {
				for (int j = 0; j < m; j++) {
					output += "*";
					if (c == 1)
						output += "\n";
				}
				for (int j = 0; j < nm-1; j++) {
					output += ".";
					if (c == 1)
						output += "\n";
				}
				output += "c\n";
			} else if (nm == 2 || nm == 3 || nm == 5 || nm == 7) {
				output += "Impossible\n";
			} else if (r == c && m == r-1) {
				for (int j = 0; j < r; j++) {
					for (int k = 0; k < c; k++) {
						if ((j == 0 && k < m-m/2) || (j == 1 && k < m/2))
							output += "*";
						else if (j == r-1 && k == c-1)
							output += "c";
						else
							output += ".";
					}
					output += "\n";
				}
			} else {
				output += doRecRem(r, c, m, nm);
			}
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/C-small.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
	
	public static String doRecRem(int r, int c, int m, int nm) {
		String output = "";
		for (int j = 2; j <= c; j++) {
			if ((nm%j == 0 && nm/j <= r && nm/j > 1) || (nm%j != 1 && nm/j < r && nm/j > 1)) {
				int rc = j;
				int rr = nm/j;
				int rem = nm%j;
				char[][] temp = new char[r][c];
				for (int p = 0; p < r; p++) {
					for (int q = 0; q < c; q++) {
						if ((p < rr && q < rc) || (p == rr && q < rem))
							temp[p][q] = '.';
						else
							temp[p][q] = '*';
					}
				}
				temp[0][0] = 'c';
				for (int p = 0; p < r; p++) {
					for (int q = 0; q < c; q++) {
						output += temp[p][q];
					}
					output += "\n";
				}
				return output;
			}
		}
		for (int j = 2; j <= r; j++) {
			if ((nm%j == 0 && nm/j <= c && nm/j > 1) || (nm%j != 1 && nm/j < c && nm/j > 1)) {
				int rr = j;
				int rc = nm/j;
				int rem = nm%j;
				char[][] temp = new char[r][c];
				for (int p = 0; p < r; p++) {
					for (int q = 0; q < c; q++) {
						if ((p < rr && q < rc) || (p < rem && q == rc))
							temp[p][q] = '.';
						else
							temp[p][q] = '*';
					}
				}
				temp[0][0] = 'c';
				for (int p = 0; p < r; p++) {
					for (int q = 0; q < c; q++) {
						output += temp[p][q];
					}
					output += "\n";
				}
				return output;
			}
		}
		return "Impossible\n";
	}
}