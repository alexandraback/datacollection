package codejam2013.qual.lawnmower;

import java.util.*;
import java.io.*;

public class CodejamProblem {
	final static String PROBLEM_NAME = "lawnmower";
	final static String WORK_DIR = "./src/codejam2013/qual/lawnmower/";


	void solve(Scanner sc, PrintWriter pw) {
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		int[][] grid = new int[N][M];
		int[] rowMin = new int[N];
		int[] colMin = new int[M];
	
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				grid[i][j] = sc.nextInt();
			}
		}


		for(int i=0;i<N;i++){
			rowMin[i] = grid[i][0];
			for(int j=1;j<M;j++){
				if(rowMin[i]<grid[i][j])
					rowMin[i]=grid[i][j];				
			}

		}

		for(int j=0;j<M;j++){
			colMin[j] = grid[0][j];
			for(int i=1;i<N;i++){
				if(colMin[j]<grid[i][j])
					colMin[j]=grid[i][j];
			}

		}

		
		boolean result = true;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(grid[i][j]<rowMin[i]&&grid[i][j]<colMin[j]){
					result = false;
					break;
				}
			}
			if(result==false)
				break;
		}

		pw.println(""+(result?"YES":"NO"));
	}

	public static void main(String[] args) throws Exception {

		Scanner sc = new Scanner(new FileReader(WORK_DIR + "B-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
		int caseCnt = sc.nextInt();
		sc.nextLine();
		for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
			System.out.println("Processing test case " + (caseNum + 1));
			pw.print("Case #" + (caseNum + 1) + ": ");
			new CodejamProblem().solve(sc, pw);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
}
