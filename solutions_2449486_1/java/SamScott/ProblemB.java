package qualificationRound;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemB {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("qualificationRound/B-large.in"));
		PrintWriter out = new PrintWriter(new File("qualificationRound/out.txt"));

		int T = sc.nextInt();
		sc.nextLine();

		for (int tc = 1; tc <= T; tc++) {

			int N = sc.nextInt();
			int M = sc.nextInt();

			int[][] lawn = new int[N][M];
			for (int r=0; r<N; r++) {
				for (int c=0; c<M; c++) {
					lawn[r][c] = sc.nextInt();
				//	System.out.print(lawn[r][c]+" ");
				}
				//System.out.println();
			}
			//System.out.println("-------------");

			int[] rowMax = new int[N];
			for (int r=0; r<N; r++) {
				rowMax[r] = lawn[r][0];
				for (int c=1; c<M; c++)
					if (lawn[r][c] > rowMax[r])
						rowMax[r] = lawn[r][c];
			}
			int[] colMax = new int[M];
			for (int c=0; c<M; c++) {
				colMax[c] = lawn[0][c];
				for (int r=1; r<N; r++) {
				//	System.out.println(r+" "+c+" "+lawn[r][c]+" "+colMax[c]);
					if (lawn[r][c] > colMax[c])
						colMax[c] = lawn[r][c];	
				}
			}
			/*/
			for (int r=0; r<N; r++)
				System.out.print(rowMax[r]+" ");
			System.out.println();
			for (int c=0; c<M; c++)
				System.out.print(colMax[c]+" ");
			//*/

			boolean good = true;

			for (int r=0; r<N && good; r++) {
				for (int c=0; c<M && good; c++) {
					if (lawn[r][c] < rowMax[r] && lawn[r][c] != colMax[c] || 
							lawn[r][c] < colMax[c] && lawn[r][c] != rowMax[r]) {
						good = false;
					//	System.out.println(r+" "+c+" "+rowMax[r]+" "+colMax[c]);
					}
				}
			}

			printSolution(out, tc, good?"YES":"NO");
		}
		out.close();
		sc.close();
	}

	public static void printSolution(PrintWriter out, int tc, String soln) {
		out.println("Case #"+tc+": "+soln);
		out.flush();
		System.out.println("Case #"+tc+": "+soln);

	}
}