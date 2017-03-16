import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
 
public class Main {
 
	public static void main(String[] args) {
 
		BufferedReader br = null;
 
		try {
 
			br = new BufferedReader(new FileReader("C-large.in"));
			
			int t = Integer.parseInt(br.readLine());
			
			for (int i = 0; i < t; i++) {
				String[] line = br.readLine().split(" ");
				int row = Integer.parseInt(line[0]);
				int col = Integer.parseInt(line[1]);
				int mine = Integer.parseInt(line[2]);
				int empty = row * col - mine;
				char[][] grid = new char[row][col];
				boolean possible = true;
				
				System.out.println("Case #" + (i+1) + ":");
				
				
				if (empty == 1) {
					for (int j = 0; j < row; j++) {
						for (int k = 0; k < col; k++) {
							grid[j][k] = '*';
						}
					}
				}
				else if (row == 1 || col == 1) {
					int count = 0;
					for (int j = 0; j < row; j++) {
						for (int k = 0; k < col; k++) {
							if (count < empty) {
								grid[j][k] = '.';
								count++;
							}
							else {
								grid[j][k] = '*';
							}
						}
					}
				}
				else if (row == 2) {
					if (empty % 2 == 0 && empty != 2) {
						int count = 0;
						for (int j = 0; j < col; j++) {
							if (count < empty) {
								grid[0][j] = '.';
								grid[1][j] = '.';
								count += 2;
							}
							else {
								grid[0][j] = '*';
								grid[1][j] = '*';
							}
						}
					}
					else {
						possible = false;
					}
				}
				else if (col == 2) {
					if (empty % 2 == 0 && empty != 2) {
						int count = 0;
						for (int j = 0; j < row; j++) {
							if (count < empty) {
								grid[j][0] = '.';
								grid[j][1] = '.';
								count += 2;
							}
							else {
								grid[j][0] = '*';
								grid[j][1] = '*';
							}
						}
					}
					else {
						possible = false;
					}
				}
				else {
					if (empty == 2 || empty == 3 || empty == 5 || empty == 7) {
						possible = false;
					}
					else if (empty % 2 == 0) {
						int count = 0;
						for (int j = 0; j < row; j++) {
							if (count < empty) {
								grid[j][0] = '.';
								grid[j][1] = '.';
								count += 2;
							}
							else {
								grid[j][0] = '*';
								grid[j][1] = '*';
							}
						}
						for (int j = 2; j < col; j++) {
							if (count < empty) {
								grid[0][j] = '.';
								grid[1][j] = '.';
								count += 2;
							}
							else {
								grid[0][j] = '*';
								grid[1][j] = '*';
							}
						}
						for (int j = 2; j < row; j++) {
							for (int k = 2; k < col; k++) {
								if (count < empty) {
									grid[j][k] = '.';
									count++;
								}
								else {
									grid[j][k] = '*';
								}
							}
						}
					}
					else {
						int count = 9;
						for (int j = 0; j < 3; j++) {
							for (int k = 0; k < 3; k++) {
								grid[j][k] = '.';
							}
						}
						for (int j = 3; j < row; j++) {
							if (count < empty) {
								grid[j][0] = '.';
								grid[j][1] = '.';
								count += 2;
							}
							else {
								grid[j][0] = '*';
								grid[j][1] = '*';
							}
						}
						for (int j = 3; j < col; j++) {
							if (count < empty) {
								grid[0][j] = '.';
								grid[1][j] = '.';
								count += 2;
							}
							else {
								grid[0][j] = '*';
								grid[1][j] = '*';
							}
						}
						for (int j = 2; j < row; j++) {
							for (int k = 2; k < col; k++) {
								if (j == 2 && k == 2)
									continue;
								if (count < empty) {
									grid[j][k] = '.';
									count++;
								}
								else {
									grid[j][k] = '*';
								}
							}
						}
					}
				}
				
				
				if (possible) {
					grid[0][0] = 'c';
					for (int j = 0; j < row; j++) {
						for (int k = 0; k < col; k++) {
							System.out.print(grid[j][k]);
						}
						System.out.println();
					}
				}
				else {
					System.out.println("Impossible");
				}
			}
 
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
	}
}