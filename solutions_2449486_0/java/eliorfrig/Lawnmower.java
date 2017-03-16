import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Lawnmower {
	
	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		String inputFilename = "B-small-attempt0.in";
		StringBuilder answer = new StringBuilder();
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader(inputFilename));
			String line = br.readLine();
			int testCases = Integer.parseInt(line);
			for (int i=1; i<=testCases; i++) {
				line = br.readLine();
				int indexOfSpace = line.indexOf(" ");
				int N = Integer.parseInt(line.substring(0, indexOfSpace));
				int M = Integer.parseInt(line.substring(indexOfSpace+1));
				int[][] lawn = new int[N][M];
				for (int j=0; j<N; j++) {
					line = br.readLine();
					for (int k=0; k<M; k++) {
						indexOfSpace = line.indexOf(" ");
						if (indexOfSpace != -1) {
							lawn[j][k] = Integer.parseInt(line.substring(0, indexOfSpace));
							line = line.substring(indexOfSpace+1);
						} else { //the last one in the line
							lawn[j][k] = Integer.parseInt(line);
						}
					}
				}
				String ans = checkIfLawnValid(lawn, N, M);
				answer.append("Case #" + i + ": " + ans + System.lineSeparator());
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		writeOutput(answer.toString());
		System.out.println("in " + (System.currentTimeMillis() - start));
	}
	
	private static String checkIfLawnValid(int[][] lawn, int rows, int cols) {
		//check rows, starting from left
		for (int i=0; i<rows; i++) {
			for (int j=0; j<cols-1; j++) {
				for (int k=j+1; k<cols; k++) {
					if (lawn[i][j] < lawn[i][k]) {
						if (!isColValid(lawn, i, j, rows)) {
							return "NO";
						}
					}
				}
			}
		}
		//check rows, starting from right
		for (int i=0; i<rows; i++) {
			for (int j=cols-1; j>0; j--) {
				for (int k=j-1; k>=0; k--) {
					if (lawn[i][j] < lawn[i][k]) {
						if (!isColValid(lawn, i, j, rows)) {
							return "NO";
						}
					}
				}
			}
		}
		return "YES";
	}

	private static boolean isColValid(int[][] lawn, int startRow, int col, int rows) {
		//check up
		for (int i=startRow; i>=0; i--) {
			if (lawn[i][col] > lawn[startRow][col])
				return false;
		}
		//check down
		for (int i=startRow; i<rows; i++) {
			if (lawn[i][col] > lawn[startRow][col])
				return false;
		}
		return true;
	}

	private static void writeOutput(String string) {
		try {
			String outputFilename = "output.txt";
			BufferedWriter bw = new BufferedWriter(new FileWriter(outputFilename));
			bw.write(string);
			bw.close();
			System.out.println("success!");
		} catch (Exception e) {
			System.out.println("error!");
		}
	}

}
