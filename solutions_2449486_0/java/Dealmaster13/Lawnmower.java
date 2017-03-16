import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;


public class Lawnmower {

	private static BufferedReader br;
	private static BufferedWriter bw;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			// Open input file.
			br = new BufferedReader(new FileReader("input.in"));

			// Open output file.
			bw = new BufferedWriter(new FileWriter("output.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			return;
		} catch (IOException e) {
			e.printStackTrace();
		}

		try {
			// Initialise input and read number of cases.
			int testCases = Integer.parseInt(br.readLine());

			// For each test case.
			analyseTestCases(testCases);
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		finally {
			try {
				br.close();
				bw.flush();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	private static void analyseTestCases(int testCases) throws IOException {
		for (int i = 1; i <= testCases; i++) {
			// Read the m and n values
			String input = br.readLine();

			String[] inputValues = input.split(" ");

			int n = Integer.parseInt(inputValues[0]);
			int m = Integer.parseInt(inputValues[1]);

			int[][] a = new int[n][m];
			boolean[][] canCut = new boolean[n][m];

			// For each row.
			for (int row = 0; row < n; row++) {
				// Read a row of 'a' values.
				String[] rowValues = br.readLine().split(" ");

				// For each column.
				for (int col = 0; col < m; col++) {
					a[row][col] = Integer.parseInt(rowValues[col]);
				}
			}

			checkRows(a, canCut);
			checkCols(a, canCut);

			boolean patternPossible = checkCanCut(canCut);

			write("Case #" + i + ": " + (patternPossible ? "YES" : "NO") + "\n");
		}
	}

	private static boolean[][] checkRows(int[][] a, boolean[][] canCut) {
		// For each row.
		for (int row = 0; row < canCut.length; row++) {
			ArrayList<Integer> highestCols = new ArrayList<Integer>();

			int highestValue = Integer.MIN_VALUE;

			// For each column.
			for (int col = 0; col < canCut[row].length; col++) {
				if (a[row][col] > highestValue) {
					highestValue = a[row][col];

					highestCols = new ArrayList<Integer>();
					highestCols.add(col);
				}
				else if (a[row][col] == highestValue) {
					highestCols.add(col);
				}
			}

			// Update can cut array.
			for (int i = 0; i < highestCols.size(); i++) {
				canCut[row][highestCols.get(i)] = true;
			}
		}

		return canCut;
	}

	private static boolean[][] checkCols(int[][] a, boolean[][] canCut) {
		// For each column.
		for (int col = 0; col < canCut[0].length; col++) {
			ArrayList<Integer> highestRows = new ArrayList<Integer>();

			int highestValue = Integer.MIN_VALUE;

			// For each row.
			for (int row = 0; row < canCut.length; row++) {
				if (a[row][col] > highestValue) {
					highestValue = a[row][col];

					highestRows = new ArrayList<Integer>();
					highestRows.add(row);
				}
				else if (a[row][col] == highestValue) {
					highestRows.add(row);
				}
			}

			// Update can cut array.
			for (int i = 0; i < highestRows.size(); i++) {
				canCut[highestRows.get(i)][col] = true;
			}
		}

		return canCut;
	}

	private static boolean checkCanCut(boolean[][] canCut) {
		for (int row = 0; row < canCut.length; row++) {
			for (int col = 0; col < canCut[row].length; col++) {
				if (!canCut[row][col]) {
					return false;
				}
			}
		}

		return true;
	}

	private static void write(String s) {
		try {
			bw.write(s);
			System.out.print(s);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
