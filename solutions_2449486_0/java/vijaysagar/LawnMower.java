package in.codejam;

import java.util.Scanner;

public class LawnMower {

	public static Scanner in;

	public static void main(String[] args) {
		in = new Scanner(System.in);
		in.useDelimiter("\\s+");
		int testCases = readNum();
		String[] results = new String[testCases];
		for (int i = 1; i <= testCases; i++) {
			if (canCutLawn()) {
				results[i - 1] = ("Case #" + i + ": YES");
			} else {
				results[i - 1] = ("Case #" + i + ": NO");
			}
		}
		for (int i = 0; i < testCases; i++)
			System.out.println(results[i]);
		in.close();
	}

	public static int readNum() {
		int i = in.nextInt();
		return i;
	}

	public static boolean canCutLawn() {
		int R = readNum();
		int C = readNum();
		int[][] lawn = new int[R][C];
		/*From this point onwards, we delete one row or column per iteration*/
		
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				lawn[i][j] = readNum();
			}
		}
		
		int rows = R, columns = C;
		while(rows > 1 && columns > 1){
			MinRowCol c = verifyMinimumRowCol(lawn, rows, columns);
			if(c.inconsistent)
				return false;
			if(c.isColumn){
				removeCol(lawn, c.rowOrColumn, rows, columns);
				columns--;
			}else{
				removeRow(lawn, c.rowOrColumn, rows, columns);
				rows--;
			}
		}
		return true;
	}
	
	public static class MinRowCol{
		public final boolean isColumn;
		public final int rowOrColumn;
		public final boolean inconsistent;
		public MinRowCol(boolean isColumn,boolean inconsistent, int rowOrCol){
			this.isColumn = isColumn;
			this.inconsistent = inconsistent;
			this.rowOrColumn = rowOrCol;
		}
	}
	
	public static void removeRow(int[][] lawn, int rowNum, int rows, int columns){
		for(int i=rowNum;i<rows-1;i++){
			for(int j=0;j<columns;j++){
				lawn[i][j] = lawn[i+1][j];
			}
		}
	}
	
	public static void removeCol(int[][] lawn, int colNum, int rows, int columns){
		for(int j=colNum;j<columns-1;j++){
			for(int i=0;i<rows;i++){
				lawn[i][j] = lawn[i][j+1];
			}
		}
	}
	
	public static  MinRowCol verifyMinimumRowCol(int[][] lawn, int rows, int cols){
		int minValue = 100, minRow = -1, minCol = -1;
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				if(lawn[i][j] < minValue){
					minValue = lawn[i][j];
					minRow = i;
					minCol = j;
				}
			}
		}
		//Verify consistency for row or column. First column
		boolean columnConsistent = true;
		for(int i=0;i<rows;i++){
			if(lawn[i][minCol] > minValue)
				columnConsistent = false;
		}
		boolean rowConsistent = true;
		for(int j=0;j<cols;j++){
			if(lawn[minRow][j] > minValue)
				rowConsistent = false;
		}
		
		if(columnConsistent == false && rowConsistent == false){
			return new MinRowCol(false, true, 0);
		}
		if(columnConsistent){
			return new MinRowCol(true, false, minCol);
		}else{
			return new MinRowCol(false, false, minRow);
		}
		
	}

}
