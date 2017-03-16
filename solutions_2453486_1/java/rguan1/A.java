package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	public static void main(String args[]) throws FileNotFoundException, IOException {
		int cases;
		String line;
		Scanner sc = new Scanner(new FileReader(new File("A-large.in")));
		PrintWriter out = new PrintWriter(new FileWriter("A-large.out"));
		cases = sc.nextInt();
		
		String[][] board = new String[4][4];
		
		for(int i = 0; i < cases; i++) {
			for(int j = 0; j < 4; j++) {
				line = sc.next();
				board[j][0]= Character.toString(line.charAt(0));
				board[j][1]= Character.toString(line.charAt(1));
				board[j][2]= Character.toString(line.charAt(2));
				board[j][3]= Character.toString(line.charAt(3));
				
			}
			processBoard(board, i, out);
		}
		out.close();
	}
	
	public static void processBoard(String[][] board, int thisCase, PrintWriter out) {
		
		boolean xPositiveDiagonal = (board[0][0].equals("X") || board[0][0].equals("T")) && (board[1][1].equals("X") || board[1][1].equals("T")) && (board[2][2].equals("X") || board[2][2].equals("T")) && (board[3][3].equals("X") || board[3][3].equals("T"));
		boolean oPositiveDiagonal = (board[0][0].equals("O") || board[0][0].equals("T")) && (board[1][1].equals("O") || board[1][1].equals("T")) && (board[2][2].equals("O") || board[2][2].equals("T")) && (board[3][3].equals("O") || board[3][3].equals("T"));
		
		boolean xNegativeDiagonal = (board[0][3].equals("X") || board[0][3].equals("T")) && (board[1][2].equals("X") || board[1][2].equals("T")) && (board[2][1].equals("X") || board[2][1].equals("T")) && (board[3][0].equals("X") || board[3][0].equals("T"));
		boolean oNegativeDiagonal = (board[0][3].equals("O") || board[0][3].equals("T")) && (board[1][2].equals("O") || board[1][2].equals("T")) && (board[2][1].equals("O") || board[2][1].equals("T")) && (board[3][0].equals("O") || board[3][0].equals("T"));

		boolean completed = true;
		
		for(int i = 0; i < board.length; i++) {
			boolean xHorizontal = (board[i][0].equals("X") || board[i][0].equals("T")) && (board[i][1].equals("X") || board[i][1].equals("T")) && (board[i][2].equals("X") || board[i][2].equals("T")) && (board[i][3].equals("X") || board[i][3].equals("T"));
			boolean oHorizontal = (board[i][0].equals("O") || board[i][0].equals("T")) && (board[i][1].equals("O") || board[i][1].equals("T")) && (board[i][2].equals("O") || board[i][2].equals("T")) && (board[i][3].equals("O") || board[i][3].equals("T"));

			boolean xVertical = (board[0][i].equals("X") || board[0][i].equals("T")) && (board[1][i].equals("X") || board[1][i].equals("T")) && (board[2][i].equals("X") || board[2][i].equals("T")) && (board[3][i].equals("X") || board[3][i].equals("T"));
			boolean oVertical = (board[0][i].equals("O") || board[0][i].equals("T")) && (board[1][i].equals("O") || board[1][i].equals("T")) && (board[2][i].equals("O") || board[2][i].equals("T")) && (board[3][i].equals("O") || board[3][i].equals("T"));
			
			if(xHorizontal || xVertical || xPositiveDiagonal || xNegativeDiagonal) {
				out.println("Case #" + (thisCase + 1) + ": X won");
				return;
			}
			else if (oHorizontal || oVertical || oPositiveDiagonal || oNegativeDiagonal) {
				out.println("Case #" + (thisCase + 1) + ": O won");
				return;
			}
		}
		
		for(int i = 0; i < board.length; i++) {
			for(int j = 0; j < board.length; j++) {
				if(board[i][j].equals(".")) {
					completed = false;
				}
			}
		}
		
		if(completed) {
			out.println("Case #" + (thisCase + 1) + ": Draw");
		}
		else {
			out.println("Case #" + (thisCase + 1) + ": Game has not completed");
		}
	}
	
	public static void printBoard(String[][] board) {
		for(int i = 0; i < board.length; i++) {
			for(int j = 0; j < board.length; j++) {
				System.out.print(board[i][j]);
			}
			System.out.println();
		}
	}
}
