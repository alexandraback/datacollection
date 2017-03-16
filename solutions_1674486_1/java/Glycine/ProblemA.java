package glycine.gcj2012.rc;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ProblemA {

	public static int[] marked = null;
	public static int[][] connectMatrix = null;
	public static boolean[] isRoot = null;

	private static boolean solve(int currentIndex) {
		int size = marked.length;
		if (marked[currentIndex] == 0) {
			marked[currentIndex] = 1;
		} else {
			marked[currentIndex] = 2;
			return true;
		}

		for (int i = 0; i < size; ++i) {

			if (i != currentIndex && connectMatrix[currentIndex][i] != 0) {
				if (solve(i)) {
					return true;
				}

			}
		}
		return false;

	}

	public static void main(String[] args) throws IOException {
		if (args.length != 1) {
			System.err.println("Usage: <program> inputFilename");
			return;
		}
		BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		String line = reader.readLine();
		int times = Integer.parseInt(line);
		for (int i = 0; i < times; ++i) {
			line = reader.readLine();
			int classNum = Integer.parseInt(line);
			marked = new int[classNum];
			connectMatrix = new int[classNum][classNum];
			isRoot = new boolean[classNum];
			for (int j = 0; j < classNum; ++j) {
				marked[j] = 0;
			}
			for (int j = 0; j < classNum; ++j) {
				for (int k = 0; k < classNum; ++k) {
					connectMatrix[j][k] = 0;
				}
			}
			for (int j = 0; j < classNum; ++j) {
				line = reader.readLine();
				String[] tokens = line.split(" ");
				int n = Integer.parseInt(tokens[0]);
				if (n == 0) {
					isRoot[j] = true;
				} else {
					isRoot[j] = false;
				}
				for (int k = 0; k < n; ++k) {
					int colI = Integer.parseInt(tokens[k + 1]) - 1;
					connectMatrix[colI][j] = 1;
				}
			}

//			for (int j = 0; j < classNum; ++j) {
//				for (int k = 0; k < classNum; ++k) {
//					System.out.print(connectMatrix[j][k] + ", ");
//				}
//				System.out.println("");
//			}

			boolean resultCheck = false;
			for (int j = 0; j < classNum; ++j) {
				if (isRoot[j]) {
					boolean r = solve(j);
					if (r) {
						resultCheck = true;
						break;
					}
				}
				for( int k = 0; k < classNum; ++k ){
					marked[k] = 0;
				}
			}
			// for (int j = 0; j < classNum; ++j) {
			// if (marked[j] == 0) {
			// boolean r = solve(j);
			// if (r) {
			// resultCheck = true;
			// break;
			// }
			// }
			// }
//			for (int j = 0; j < classNum; ++j) {
//				System.out.print(marked[j] + ": ");
//			}
//			System.out.println("");
			System.out.println("Case #" + (i + 1) + ": "
					+ (resultCheck ? "Yes" : "No"));

		}
	}

}
