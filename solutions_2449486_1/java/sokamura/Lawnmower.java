import java.io.File;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Lawnmower {
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("B-large.in"));

		int caseNum = s.nextInt();
		for (int t = 1; t <= caseNum; ++t) {
			int N = s.nextInt();
			int M = s.nextInt();
			int[][] lawn = new int[N][M];
			Set<Integer> numSet = new TreeSet<Integer>();
			for(int i=0; i<N; ++i) {
				for(int j=0; j<M;++j) {
					lawn[i][j] = s.nextInt();
					numSet.add(lawn[i][j]);
				}
			}

			if (Lawnmower.check(lawn, N, M, numSet)) {
				System.out.println("Case #" + t + ": YES");
			}
			else {
				System.out.println("Case #" + t + ": NO");
			}
		}
	}

	public static boolean check(int[][] lawn, int row, int column, Set<Integer> numSet) {
		boolean[] rowCheck = new boolean[row];
		boolean[] columnCheck = new boolean[column];
		for(int i=0;i<row;++i){
			rowCheck[i] = false;
		}
		for(int i=0;i<column;++i) {
			columnCheck[i] = false;
		}

		Iterator<Integer> it = numSet.iterator();
		while(it.hasNext()) {
			int h = it.next();

			for(int i=0; i<row; ++i) {
				if(rowCheck[i]) {
					continue;
				}

				boolean checkResult = true;
				for(int j=0; j<column; ++j) {
					if(lawn[i][j] != h && !columnCheck[j]) {
						checkResult = false;
						break;
					}
				}

				if(checkResult) {
					rowCheck[i] = true;
				}
			}

			for(int j=0;j<column;++j) {
				if(columnCheck[j]) {
					continue;
				}

				boolean checkResult = true;
				for(int i=0;i<row;++i){
					if(lawn[i][j] != h && !rowCheck[i]) {
						checkResult = false;
						break;
					}
				}

				if(checkResult) {
					columnCheck[j] = true;
				}
			}
		}

		for(int i=0; i<row; ++i) {
			if(!rowCheck[i]) {
				return false;
			}
		}
		for(int j=0; j<column;++j) {
			if(!columnCheck[j]) {
				return false;
			}
		}

		return true;
	}

	public static void printLawn(int[][] lawn) {
		for(int i=0; i<lawn.length; ++i) {
			for(int j=0; j<lawn[0].length; ++j) {
				System.out.print(lawn[i][j]);
			}
			System.out.println();
		}
	}
}
