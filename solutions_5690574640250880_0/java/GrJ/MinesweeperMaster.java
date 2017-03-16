package eu.grzegorzjankowski;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Locale;

public class MinesweeperMaster {

	public static void main(String[] args) {
		BufferedReader br = null;
		File file;

		Locale.setDefault(Locale.US);

		try {

			String sCurrentLine;
			file = new File("c:\\CodeJam\\MinesweeperMaster\\result.txt");
			if (file.exists())
				file.delete();
			file.createNewFile();

			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);

			br = new BufferedReader(new FileReader(
					"c:\\CodeJam\\MinesweeperMaster\\C-small-attempt1.in"));

			int t = Integer.parseInt(br.readLine());
			for (int i = 0; i < t; i++) {
				String[] data = br.readLine().split(" ");

				bw.write("Case #" + (i + 1) + ": ");
				bw.newLine();
				String result = solveIt(Integer.parseInt(data[0]),
						Integer.parseInt(data[1]), Integer.parseInt(data[2]));

				String[] lines = result.split(";");
				for (int j = 0; j < lines.length; j++) {
					bw.write(lines[j]);
					bw.newLine();
				}

				System.out.println(i + 1 + " -> " + (i + 1.0) * 100 / t + "%");

			}
			bw.close();
			System.out.println("done");

		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)
					br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
	}

	private static String solveIt(int r, int s, int m) {
		boolean trans = false;
		if (s < r) {
			trans = true;
			int temp = s;
			s = r;
			r = temp;
		}

		char[][] matrix = new char[r][s];
		for (int i = 0; i < r; i++)
			Arrays.fill(matrix[i], '.');

		int x = 0;
		
		if (r == 5) {
			if (m >= s)  {
				Arrays.fill(matrix[4], '*');
			}
			
			if (m < s) {
				if (m <= (s - 2)) {
					for (int i = 0; i < m; i++) {
						matrix[4][i] = '*';
					}
				}
				if (m == (s - 1)) {
					for (int i = 0; i < m-1; i++) {
						matrix[4][i] = '*';
					}
					
				matrix[3][0] = '*';
				}
			}
			
			if (m == (s - 1)) {
				if (m <= (s - 2)) {
					for (int i = 0; i < m; i++) {
						matrix[4][i] = '*';
					}
				}
			}
			
			m-=s;
			r = 4; 
		}
		if (r == 4) {
			if (m >= s)  {
				Arrays.fill(matrix[3], '*');
			}
			
			if (m < s) {
				if (m <= (s - 2)) {
					for (int i = 0; i < m; i++) {
						matrix[3][i] = '*';
					}
				}
				if (m == (s - 1)) {
					for (int i = 0; i < m-1; i++) {
						matrix[3][i] = '*';
					}
					
				matrix[2][0] = '*';
				}
			}
			
			if (m == (s - 1)) {
				if (m <= (s - 2)) {
					for (int i = 0; i < m; i++) {
						matrix[3][i] = '*';
					}
				}
			}
			
			m-=s;
			r = 3; 
		}

		if (r == 1) {
			while (m > 0) {
				matrix[0][x] = '*';
				x++;
				m--;
			}
			matrix[0][s - 1] = 'c';
		}

		if (r == 2) {

			while (m > 0) {
				matrix[0][x] = '*';
				m--;
				if (m == 0 && x < (s - 1))
					return "Impossible";
				matrix[1][x] = '*';
				x++;
				m--;
				if (m==0 && x == (s - 1 ))
					return "Impossible";
			}
			matrix[1][s - 1] = 'c';
		}
		
		if (r == 3) {

			while (m > 0) {
				matrix[2][x] = '*';
				m--;
				if (m==1 && x != s-1) {
					if (x == s-3) return "Impossible";
					matrix[2][x+1] = '*';
					break;
				}
				if (m==0 && x == s-2) {
					return "Impossible";
				}
				if (m==0) break;
				matrix[1][x] = '*';
				m--;
				if (m == 0 && x < (s - 1))
					return "Impossible";
				matrix[0][x] = '*';
				x++;
				m--;
				if (m==0 && x == (s - 1 ))
					return "Impossible";
			}
			if (x == (s - 1)) return "Impossible";
			matrix[0][s - 1] = 'c';
		}

		if (trans)
			return printMatrix(transposeMatrix(matrix));
		else
			return printMatrix(matrix);
	}

	public static char[][] transposeMatrix(char[][] m) {
		int r = m.length;
		int c = m[r - 1].length;
		char[][] t = new char[c][r];
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				t[j][i] = m[i][c - j - 1];
			}
		}
		return t;
	}

	private static String printMatrix(char[][] matrix) {
		StringBuilder stringBuilder = new StringBuilder();
		for (int i = 0; i < matrix.length; i++) {
			stringBuilder.append(matrix[i]);
			stringBuilder.append(";");
		}
		return stringBuilder.toString();
	}
}
