import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

class Lawn {
	
	private int nRows;
	private int nColumns;
	
	private int maxInRow[];
	private int maxInColumn[];
	
	private int[][] data;
	
	public Lawn(int nRows, int nColumns) {
		
		this.nRows = nRows;
		this.nColumns = nColumns;
		
		data = new int[nRows][];
		for (int i = 0; i < data.length; ++i) {
			data[i] = new int[nColumns];
		}
		
		maxInRow = new int[nRows];
		maxInColumn = new int[nColumns];
	}
	
	public void set(int row, int column, int value) {
		data[row][column] = value;
	}
	
	public boolean isOk() {
		
		for (int row = 0; row < nRows; ++row) {
			int maxInRow = 0;
			for (int column = 0; column < nColumns; ++column) {
				if (data[row][column] > maxInRow) {
					maxInRow = data[row][column];
				}
			}
			this.maxInRow[row] = maxInRow;
		}
		
		for (int column = 0; column < nColumns; ++column) {
			int maxInColumn = 0;
			for (int row = 0; row < nRows; ++row) {
				if (data[row][column] > maxInColumn) {
					maxInColumn = data[row][column];
				}
			}
			this.maxInColumn[column] = maxInColumn;
		}
		
		for (int row = 0; row < nRows; ++row) {
			for (int column = 0; column < nColumns; ++column) {
				if (data[row][column] != Math.min(maxInRow[row], maxInColumn[column])) {
					return false;
				}
			}
		}
		return true;	
	}
}
	
class Problem2 {
	
	private long T;
	
	public void solve(String in) throws IOException {
		Scanner scanner = new Scanner(new File(in));
		Writer outFile = new FileWriter("OUT-"+in);
		
		T = Integer.parseInt(scanner.nextLine());
		
		for (int k = 1; k <= T; ++k) {
			
			int N = scanner.nextInt();
			int M = scanner.nextInt();
			
			Lawn lawn = new Lawn(N, M);
			
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					lawn.set(i, j, scanner.nextInt());				
				}
			}
			
			boolean isOk = lawn.isOk();
			String result = (isOk) ? "YES" : "NO";
			outFile.write("Case #"+k+": " + result +'\n');
			
		}
		
		outFile.flush();
		outFile.close();		
	}	
}
public class Launcher {

	public static void main(String[] args) {
		Problem2 problem2 = new Problem2();
		try {
			problem2.solve("B-small-attempt0.in.txt");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
