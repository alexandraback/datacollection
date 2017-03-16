import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Lawn {

	boolean isValid(int[][] b, int rows, int cols) {

		//check row 
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (!isRowValid(b, b[i][j], i, cols) &&
						!isColValid(b, b[i][j], j, rows)) {
					return false; 
				}
			}
		}

		return true;
	}

	boolean isRowValid(int[][] b, int num, int row, int cols) {
		for (int j = 0; j < cols; ++j) {
			if (b[row][j] > num)
				return false;
		}

		return true;
	}

	boolean isColValid(int[][] b, int num, int col, int rows) {
		for (int i = 0; i < rows; ++i) {
			if (b[i][col] > num)
				return false;
		}

		return true;
	}

	void printBoard(int[][] board, int rows, int cols) {
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				System.out.print(board[i][j] + " ");
			}
			System.out.println();
		}
	}

	void processFile(String file) {
		BufferedReader br;
		FileReader fr;
		BufferedWriter bw;
		FileWriter fw;
		try {
			fr = new FileReader(file);

			br = new BufferedReader(fr);
			fw = new FileWriter("out");
			bw = new BufferedWriter(fw);

			int numCases = Integer.parseInt(br.readLine());

			int rows, cols;
			String line[];
			String result;
			for (int i = 0; i < numCases; ++i) {

				//parse rows and cols
				line = br.readLine().split(" ");
				rows = Integer.parseInt(line[0]);
				cols = Integer.parseInt(line[1]);

				//create board
				int[][] board = new int[rows][cols];

				//process each row
				for (int r = 0; r < rows; ++r) {
					line = br.readLine().split(" ");
					for (int c = 0; c < cols; ++c) {
						board[r][c] = Integer.parseInt(line[c]);
					}
				}
				result = isValid(board, rows, cols) ? "YES" : "NO";
				bw.write("Case #" + (i + 1) + ": " + result + "\n");
				System.out.println("Case #" + (i + 1) + ": " + result);
				//printBoard(board, rows, cols);

			}
			bw.flush();
			fw.flush();
			fr.close();
			br.close();
			fw.close();
			bw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		Lawn l = new Lawn();
		l.processFile("small.in");

	}

}
