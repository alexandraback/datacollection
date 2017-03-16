package hu.csq.codejam2013;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class taskB {
	
	static final boolean DEBUG = false;

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		
		//final String baseFileName = args.length > 2 ? "taskB."+args[1] : "taskB.example";
		final String baseFileName = "taskB.small0";
		Scanner sc = new Scanner(new File(baseFileName+".in"));
		
		PrintWriter pw = new PrintWriter(baseFileName+".out");
		
		int tn = sc.nextInt();
		for (int ti = 0; ti < tn; ++ti) {
			int lvl = mainTestCase(sc);
			
			System.out.println("Last level that could be cut: " + (lvl + 1));

			String output = "Case #" + (ti+1) + ": " + (0 == lvl?"YES":"NO");
			System.out.println(output);
			pw.println(output);
		}

		sc.close();
		pw.close();

	}

	private static int mainTestCase(Scanner sc) {
		final int n = sc.nextInt();
		final int m = sc.nextInt();
		
		int garden[][] = new int[n][m];
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				garden[i][j] = sc.nextInt();
			}
		}
		
		return solve(n, m, garden);
	}

	static final int MAX_HEIGHT = 100;
	static final int INITIAL_HEIGHT = MAX_HEIGHT;
	private static int solve(int n, int m, int[][] targetGarden) {
		
		int currGarden[][] = new int[n][m];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				currGarden[i][j] = INITIAL_HEIGHT;
			}
		}

		for (int currHeight = MAX_HEIGHT; currHeight >= 1; --currHeight) {
			cut(n, m, currGarden, targetGarden, currHeight);
			if (DEBUG) {
				System.out.println("After cut to " + currHeight);
				printGarden(currGarden);
			}
			boolean b = check(n, m, currGarden, targetGarden, currHeight);
			if (!b)
				return currHeight;
		}
		
		return 0;
	}

	private static void cut(int n, int m, int[][] currGarden, int[][] targetGarden, int height) {
		//first dimension
		for (int i = 0; i < n; ++i) {
			boolean b = canCutSingle(targetGarden, i, 0, 0, 1, height);
			if (b) cutSingle(currGarden, i, 0, 0, 1, height);
		}
		
		//other dimension
		for (int j = 0; j < m; ++j) {
			boolean b = canCutSingle(targetGarden, 0, j, 1, 0, height);
			if (b) cutSingle(currGarden, 0, j, 1, 0, height);
		}
	}

	private static boolean check(int n, int m, int[][] currGarden, int[][] targetGarden, int height) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (targetGarden[i][j] >= height && (currGarden[i][j] > targetGarden[i][j])) {
					return false;
				}
			}
		}
		return true;
	}

	private static boolean canCutSingle(int[][] targetGarden, int i, int j, final int inci,
			final int incj, final int height) {
		int n = targetGarden.length;
		int m = targetGarden[0].length;
		
		while (i < n && j < m) {
			if (height < targetGarden[i][j]) {
				return false;
			}
			
			i += inci;
			j += incj;
		}
		return true;
	}
	
	private static boolean cutSingle(int[][] currGarden, int i, int j, final int inci,
			final int incj, final int height) {
		int n = currGarden.length;
		int m = currGarden[0].length;
		
		while (i < n && j < m) {
			if (currGarden[i][j] > height) {
				currGarden[i][j] = height;
			}
			
			i += inci;
			j += incj;
		}
		return true;
	}
	
	private static boolean printGarden(int[][] garden) {
		for (int[] line : garden) {
			for (int h: line) {
				if (h < 100) System.out.print(" ");
				if (h < 10) System.out.print(" ");
				System.out.print(h+" ");
			}
			System.out.println();
		}
		return true;
	}
	
}
