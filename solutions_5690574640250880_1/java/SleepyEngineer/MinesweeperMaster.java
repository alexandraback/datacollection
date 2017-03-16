package minesweeperMaster;

import java.util.*;
import java.io.*;

public class MinesweeperMaster {
	String res;
	
	void solve(int R, int C, int M){
		res = "";
		int numM = M;
		int numC = C;
		int numR = R;
		int leftOver = 0;
		String[][] result = new String[R][C];
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				result[i][j]=".";
			}
		}
		result[0][0] = "c";
		while (numM > 0){
			if (numR <= numC){ //start by filling columns
				if (numM/numR >= 1){ //if we can fill the whole column
					for(int i=0;i<numR;i++){
						result[i][numC-1] = "*";
						numM --;
					}
				numC --;
				} else { //if we can't fill the whole column, put the rest in a row
					for(int i=0;i<(numM-1);i++){
						result[numR-1][numC-1-i] = "*";
					}
					if(numM == numC-1){ //Don't want to stop one space from end
						result[numR-2][numC-1] = "*";
					} else {
						result[numR-1][numC-1-(numM-1)] = "*";
					}
				leftOver = numM;
				numM = 0;
				}
			} else { // numC > numR
				if (numM/numC >= 1){
					for(int i=0;i<numC;i++){
						result[numR-1][i] = "*";
						numM --;
					}
				numR --;
				} else {
					for(int i=0;i<(numM-1);i++){
						result[numR-1-i][numC-1] = "*";
					}
					if(numM == numR-1){ //Don't want to stop one space from end
						result[numR-1][numC-2] = "*";
					} else {
						result[numR-1-(numM-1)][numC-1] = "*";
					}
				leftOver = numM;
				numM = 0;
				}
			}
		}
		
		for(int i=0;i<R;i++){
			for (int j=0;j<C;j++){
				res += result[i][j];
			}
			if(i<R-1){
				res += "\n";
			}
		}
		System.out.println("\n" + res);
		if (numR == 3 && numC == 3){
			if (leftOver == 2){
				res = "Impossible";
			}
		} else if ((numR == 2 && numC == 3) || (numR == 3 && numC == 2)){
			if (leftOver == 1){
				res = "Impossible";
			}
		} else if (numR == 2 && numC ==2){
			if (leftOver == 1){
				res = "Impossible";
			}
		} else if ((numR == 2 && numC == 1 && C != 1) || (numR == 1 && R !=1 && numC == 2)){
			res = "Impossible";
		} else if ((R == 2 || C == 2) && (M > 0 && M == R*C-2)){ //I'm sure there is an easier way here (:
			res = "Impossible";
		} else if ((R == 2 || C == 2) && ((M%2 != 0) && M < (R*C-2))){ //I'm sure there is an easier way here (:
			res = "Impossible";
		}
	}

	public void doMain() throws Exception {
		Scanner fr = new Scanner(new FileReader("src/minesweeperMaster/C-large.in"));
		PrintWriter fw = new PrintWriter(new FileWriter("src/minesweeperMaster/C-large.out"));
		
		int caseCnt = fr.nextInt();
		
		long time = System.currentTimeMillis();
		int R;
		int C;
		int M;
		
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			R = fr.nextInt();
			C = fr.nextInt();
			M = fr.nextInt();
			
			solve(R,C,M);
			System.out.println("Rows:" + R);
			System.out.println("Cols:" + C);
			System.out.println("Mines:" + M);
			fw.println("Case #" + caseNum + ": \n" + res);
			
			
			System.out.println("Finished case " + caseNum + " in " + (System.currentTimeMillis() - time) + "ms.\n" + res);
		}
		
		fw.flush();
		fw.close();
		fr.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new MinesweeperMaster()).doMain();
	}
}
