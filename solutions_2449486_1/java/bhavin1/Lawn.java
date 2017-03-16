import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Lawn {

	boolean pending = false;
	boolean complete = false;
	public void output(BufferedWriter out, int caseNum, int string) throws IOException{
		out.write("Case #" + caseNum + ": " + string + "\n");		
	}
	public void output(BufferedWriter out, int caseNum, String string) throws IOException{
		out.write("Case #" + caseNum + ": " + string + "\n");		
	}

	
	public void solve() throws IOException{
		
		Scanner in = new Scanner(new FileReader("C:\\Users\\Bhavin\\workspace\\Test\\src\\store.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("C:\\Users\\Bhavin\\workspace\\Test\\src\\store.out"));
		
		
		int numCases = in.nextInt();
		
		for (int i = 1; i <= numCases; i++) {
			
			
			int rows = in.nextInt();
			int columns = in.nextInt();
			
			int[][] board = new int[rows][columns];
			int[] rowmax = new int[rows];
			for(int j=0; j<rows; j++) {
				rowmax[j] = 0;
				for(int k=0; k<columns; k++) {
					board[j][k] =  in.nextInt();
					if(board[j][k] > rowmax[j]) 
						rowmax[j] = board[j][k];
				}
			}

			if(process(rows, columns, board, rowmax))
				output(out, i, "YES");
			else 
				output(out, i, "NO");
		}
		out.close();
	}
	private boolean process(int rows, int columns, int[][] board, int[] rowmax) {
		
		for(int j=0; j<rows; j++) {
			for(int k=0; k<columns; k++) {
				
				if(board[j][k] < rowmax[j]) {
					if(!checkCol(board[j][k], board, k, rows)) {
						return false;
					}
				}
			}
		}
		return true;
	}
	
	private boolean checkCol(int value, int[][] board, int k, int rows) {
		
		for(int i=0; i<rows; i++) {
			if(board[i][k] > value) return false;
		}
		return true;
	}
	public static void main(String[] args) throws IOException{
		Lawn s = new Lawn();
		s.solve();
		
	}

}


