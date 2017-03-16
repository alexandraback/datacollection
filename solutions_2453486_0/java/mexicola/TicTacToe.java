package Qualification2013;


import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;



public class TicTacToe {

	private static final int SIZE_MATRIX = 4;
	private static char[][] matrix;
	
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		String inFile = "in"+File.separator+"A-small-attempt0.in.txt";
		String outFile = "out"+File.separator+"A-small-attempt0.out";
		
//		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader in = new BufferedReader(new FileReader(inFile));
		PrintWriter out = new PrintWriter(new FileWriter(outFile));

		String s = "";
//		String[] sArray = null;
		
		// num examples
		s = in.readLine();
		int t = Integer.parseInt(s);
		

		
		for (int i = 0; i < t; i++) {
			matrix = new char[SIZE_MATRIX][SIZE_MATRIX];
			for (int j = 0; j < SIZE_MATRIX; j++) {
				s = in.readLine();
				
				for (int k = 0; k < SIZE_MATRIX; k++) {
					matrix[j][k] = s.charAt(k);
				}
			}
			
			// check winner
			// lines
			out.println("Case #"+(i+1)+": "+getWinner());
			
			s = in.readLine(); // empty line after test
		}
		
		


		in.close();
		out.close();
	}
	
	// TODO draw
	private static String getWinner() {
		boolean lineHasO, lineHasX, colHasO, colHasX, skipLine, skipCol, hasDot, wonO, wonX;
		hasDot = wonO = wonX = false;
		
		// check lines and cols
		for (int j = 0; j < SIZE_MATRIX; j++) {
			lineHasO = lineHasX = colHasO = colHasX = skipLine = skipCol = false;
			for (int k = 0; k < SIZE_MATRIX; k++) {
				if (matrix[j][k] == '.') {
					lineHasO = lineHasX = false;
					hasDot = skipLine = true;
				}
				if (!skipLine && matrix[j][k] == 'O')
					lineHasO = true;
				if (!skipLine && matrix[j][k] == 'X')
					lineHasX = true;
				
				if (matrix[k][j] == '.') {
					colHasO = colHasX = false;
					hasDot = skipCol = true;
				}
				if (!skipCol && matrix[k][j] == 'O')
					colHasO = true;
				if (!skipCol && matrix[k][j] == 'X')
					colHasX = true;
			}
			
			if (lineHasO && !lineHasX)
				wonO = true;
			if (!lineHasO && lineHasX)
				wonX = true;
			if (colHasO && !colHasX)
				wonO = true;
			if (!colHasO && colHasX)
				wonX = true;
		}
		
		// check diagonals
		lineHasO = lineHasX = colHasO = colHasX = skipLine = skipCol = false;
		for (int i = 0; i < SIZE_MATRIX; i++) {
			
			if (matrix[i][i] == '.') {
				lineHasO = lineHasX = false;
				hasDot = skipLine = true;
			}
			if (!skipLine && matrix[i][i] == 'O')
				lineHasO = true;
			if (!skipLine && matrix[i][i] == 'X')
				lineHasX = true;
			
			if (matrix[i][SIZE_MATRIX-(i+1)] == '.') {
				colHasO = colHasX = false;
				hasDot = skipCol = true;
			}
			if (!skipCol && matrix[i][SIZE_MATRIX-(i+1)] == 'O')
				colHasO = true;
			if (!skipCol && matrix[i][SIZE_MATRIX-(i+1)] == 'X')
				colHasX = true;
		}
		if (lineHasO && !lineHasX)
			wonO = true;
		if (!lineHasO && lineHasX)
			wonX = true;
		if (colHasO && !colHasX)
			wonO = true;
		if (!colHasO && colHasX)
			wonX = true;
		
		if (wonO && !wonX)
			return "O won";
		else if (!wonO && wonX)
			return "X won";
		else if (hasDot)
			return "Game has not completed";
		else
			return "Draw";
		
	}

}
