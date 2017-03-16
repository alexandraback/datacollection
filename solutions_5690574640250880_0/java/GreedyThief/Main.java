package amazon;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader fileIn = new BufferedReader(new FileReader("C-small-attempt13.in"));
		PrintWriter fileOut = new PrintWriter(new FileWriter("result"));
		int caseNum = Integer.parseInt(fileIn.readLine());
		for (int k = 1; k <= caseNum; k++) {
			String[] mp = fileIn.readLine().split(" ");
			fileOut.println("Case #" + k + ":");
			char[][] result = solve(Integer.parseInt(mp[0]), Integer.parseInt(mp[1]), Integer.parseInt(mp[2]));
			if (result == null) {
				fileOut.println("Impossible");
			} else {
				for (int i = 0; i < result.length; i++) {
					for (int j = 0; j < result[0].length - 1; j++) {
						fileOut.print(result[i][j]);
					}
					fileOut.print(result[i][result[0].length - 1] + "\n");
				}
			}
			
		}
		fileOut.close();
        fileIn.close();
	}
	
	public static char[][] solve(int r, int c, int m) {
		char[][] result = new char[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				result[i][j] = '.';
			}
		}
		if (m == 0) {
			result[0][0] = 'c';
			return result;
		}
		if (m == r * c - 1) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					result[i][j] = '*';
				}
			}
			result[0][0] = 'c';
			return result;
		}
		if (r == 1) {
			for (int i = 0; i < m; i++) {
				result[0][i] = '*';
			}
			result[0][c - 1] = 'c';
			return result;
		}
		
		if (c == 1) {
			for (int i = 0; i < m; i++) {
				result[i][0] = '*';
			}
			result[r - 1][0] = 'c';
			return result;
		}
		if (r == 2) {
			if (m % 2 != 0 || m >= r * c - 2) {
				return null;
			} else {
				for (int i = 0; i < m / 2; i++) {
					result[0][i] = '*';
					result[1][i] = '*';
				}
				result[0][c - 1] = 'c';
				return result;
			}
		}
		
		if (c == 2) {
			if (m % 2 != 0 || m >= r * c - 2) {
				return null;
			} else {
				for (int i = 0; i < m / 2; i++) {
					result[i][0] = '*';
					result[i][1] = '*';
				}
				result[r - 1][0] = 'c';
				return result;
			}
		}
		
		int lastRow = r - 1;
		int lastCol = c - 1;
		while (m >= c && lastRow > 2) {
			for (int i = 0; i < c; i++) {
				result[lastRow][i] = '*';
				m--;
			}
			lastRow--;
		}
		if (m < c - 1) {
			for (int i = 0; i < c - 2; i++) {
				if (m == 0) {
					break;
				}
				result[lastRow][i] = '*';
				m--;
			}
			result[0][0] = 'c';
			return result;
		}
		if (m == c - 1 && lastRow > 3) {
			for (int i = 0; i < c - 2; i++) {
				if (m == 0) {
					break;
				}
				result[lastRow][i] = '*';
				m--;
			}
			if (m > 0) {
				result[0][lastCol] = '*';
			}
			
			result[0][0] = 'c';
			return result;
		}
		
		int curWidth = lastRow + 1;
		if (lastRow == 3) {
			while (m >= curWidth && lastCol > 2) {
				for (int i = 0; i <= lastRow; i++) {
					if (m == 0) {
						break;
					}
					result[i][lastCol] = '*';
					m--;
				}
				lastCol--;
			}
			if (lastCol < 3) {
				if (m == 0) {
					result[0][0] = 'c';
					return result;
				} else if (m == 1){
					result[0][0] = 'c';
					result[3][lastCol] = '*';
					return result;
				} else if (m == 2){
					result[0][0] = 'c';
					result[2][lastCol] = '*';
					result[3][lastCol] = '*';
					return result;
				} else {
					return null;
				}
			} else if (lastCol >= 3){
				if (m == 0) {
					result[0][0] = 'c';
					return result;
				} else if (m == 1){
					result[0][0] = 'c';
					result[3][lastCol] = '*';
					return result;
				} else if (m == 2){
					result[0][0] = 'c';
					result[2][lastCol] = '*';
					result[3][lastCol] = '*';
					return result;
				} else if (m == 3){
					result[0][0] = 'c';
					result[2][lastCol] = '*';
					result[3][lastCol] = '*';
					result[3][lastCol - 1] = '*';
					return result;
				} else {
					return null;
				}
			}
		}
		if (lastRow == 2) {
			while (m >= curWidth && lastCol > 2) {
				for (int i = 0; i <= lastRow; i++) {
					if (m == 0) {
						break;
					}
					result[i][lastCol] = '*';
					m--;
				}
				lastCol--;
			}
			if (lastCol == 2) {
				if (m == 0) {
					result[0][0] = 'c';
					return result;
				} else if (m == 1){
					result[0][0] = 'c';
					result[2][2] = '*';
					return result;
				} else if (m == 2){
					return null;
				} else if (m == 3){
					result[0][0] = 'c';
					result[2][2] = '*';
					result[1][2] = '*';
					result[0][2] = '*';
					return result;
				} else if (m == 4){
					return null;
				} else if (m == 5) {
					result[0][0] = 'c';
					result[2][2] = '*';
					result[1][2] = '*';
					result[0][2] = '*';
					result[2][1] = '*';
					result[2][0] = '*';
					return result;
				} else {
					return null;
				}
			} else {
				if (m == 0) {
					result[0][0] = 'c';
					return result;
				} else if (m == 1){
					result[0][0] = 'c';
					result[2][lastCol] = '*';
					return result;
				} else {
					result[0][0] = 'c';
					result[2][lastCol] = '*';
					result[2][lastCol - 1] = '*';
					return result;
				}
			}
		}
		return result;
	}

}
