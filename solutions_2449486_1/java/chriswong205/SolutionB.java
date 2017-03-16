import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;


public class SolutionB {
	
	// For example, "B-small"
	private static final String FILENAME = "B-large";
	
	private void solveCase(int caseNumber, BufferedReader rd, PrintWriter wr) throws Exception {
		String dimensions = rd.readLine();
		String[] a = dimensions.split(" ");
		int nRows = Integer.parseInt(a[0]);
		int mCols = Integer.parseInt(a[1]);
		
		int[][] finalLawn = new int[nRows][mCols];
		boolean[] numbers = new boolean[101];
		
		for(int row = 0; row < nRows; row++) {
			String line = rd.readLine();
			String[] numbersData = line.split(" ");
			for(int col = 0; col < mCols; col++) {
				finalLawn[row][col] = Integer.parseInt(numbersData[col]);
				numbers[finalLawn[row][col]] = true;
			}
		}
		
		int prevMax = 100;
		int nextNumber = 100;
		int index = 100;
		for( ; index > 0; index--) {
			if(numbers[index]) {
				break;
			}
		}
		prevMax = index;
		index--;
		
		while(true) {
			for( ; index > 0; index--) {
				if(numbers[index]) {
					break;
				}
			}
			if(index == 0) break;
			nextNumber = index;
			index--;
			for(int i = 0; i < nRows; i++) {
				for(int j = 0; j < mCols; j++) {
					if(finalLawn[i][j] == nextNumber) {
						boolean rowIsBad = false;
						//Try row
						for(int col = 0; col < mCols; col++) {
							if(finalLawn[i][col] >= prevMax) {
								rowIsBad = true;
								break;
							}
						}
						
						//Try column if necessary\
						if(rowIsBad) {
							for(int row = 0; row < nRows; row++) {
								if(finalLawn[row][j] >= prevMax) {
									System.out.println("Case #" + caseNumber + ": NO");
									wr.println("Case #" + caseNumber + ": NO");
									return;
								}
							}
						}
						
					}
				}
			}
			prevMax = nextNumber;
			
		}
		
		
		System.out.println("Case #" + caseNumber + ": YES");
		wr.println("Case #" + caseNumber + ": YES");
	}
	
	public SolutionB() {
		BufferedReader rd = null;
		PrintWriter wr = null;
		int numCases = 0;
		try {
			rd = new BufferedReader(new FileReader(FILENAME + ".in"));
			wr = new PrintWriter(new FileWriter(FILENAME + ".out"));
			numCases = Integer.parseInt(rd.readLine());
		} catch (Exception e) {
			System.out.println("Error reading file");
			e.printStackTrace();
			return;
		}
		
		for(int i = 1; i <= numCases; i++) {
			try {
				solveCase(i, rd, wr);
			} catch (Exception e) {
				System.out.println("Exception in Case " + i + ". Stack trace:");
				e.printStackTrace();
				break;
			}
		}
		
		try {
			rd.close();
			wr.close();
		} catch (Exception e) {
			System.out.println("Error closing file");
			e.printStackTrace();
			return;
		}
	}
	
	public static void main(String[] args) {
		new SolutionB();
	}
	
}
