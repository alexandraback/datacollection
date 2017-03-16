package round1C_2015;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Brattleship {

	private static String OUTPUT_FILE = "Brattleship.out";
	private static String INPUT_FILE = "data/A-large (1).in";

	public static void main(String[] args) {
		File output = new File(OUTPUT_FILE);
		try (FileOutputStream fos = new FileOutputStream(output); PrintWriter out = new PrintWriter(fos);) {
			Scanner in = new Scanner(new File(INPUT_FILE));
			int tests = in.nextInt();
			for (int i = 0; i < tests; i++) {
				String ret = "Case #" + (i + 1) + ": " + solve(in);
				out.println(ret);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	private static String solve(Scanner in) {
		int rows = in.nextInt();
		int columns = in.nextInt();
		int shipLength = in.nextInt();
		int timeForEachRow = columns / shipLength;
		int timeToClearShip = shipLength + Math.min(columns % shipLength, 1) - 1; // to both sides (until we hit the edge)
		int totalTime = (timeForEachRow * rows) + timeToClearShip;
		return String.valueOf(totalTime);
	}

	/*******************************************************************************************
	 * Template/helper methods
	 *******************************************************************************************/
	static class Pair<K, V> {
		K first;
		V second;

		public Pair(K first, V second) {
			this.first = first;
			this.second = second;
		}

		public Object get(Object o) {
			if (first.equals(o)) {
				return second;
			}
			if (second.equals(o)) {
				return first;
			}
			return null;
		}

		public V getSecond() {
			return second;
		}

		public K getFirst() {
			return first;
		}

		@Override
		public boolean equals(Object ob) {
			if (!(ob instanceof Pair<?, ?>)) {
				return false;
			}
			return getFirst().equals(((Pair) ob).getFirst()) && getSecond().equals(((Pair) ob).getSecond());
		}
	}

	private static int sumDiag1(int[][] mat) {
		if (mat.length != mat[0].length) {
			throw new RuntimeException("Wrong matrix size: (" + mat.length + ", " + mat[0].length + ")");
		}
		int sum = 0;
		for (int i = 0; i < mat.length; i++) {
			sum += mat[i][i];
		}
		return sum;
	}

	private static int sumDiag2(int[][] mat) {
		if (mat.length != mat[0].length) {
			throw new RuntimeException("Wrong matrix size: (" + mat.length + ", " + mat[0].length + ")");
		}
		int sum = 0;
		for (int i = 0; i < mat.length; i++) {
			sum += mat[i][mat.length - i - 1];
		}
		return sum;
	}

	private static int sumColumn(int[][] mat, int column) {
		int sum = 0;
		for (int i = 0; i < mat.length; i++) {
			sum += mat[i][column];
		}
		return sum;
	}

	private static int sumRow(int[][] mat, int row) {
		int sum = 0;
		for (int i = 0; i < mat[row].length; i++) {
			sum += mat[row][i];
		}
		return sum;
	}

}
