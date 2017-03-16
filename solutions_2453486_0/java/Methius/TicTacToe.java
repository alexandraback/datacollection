package tictactoe;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class TicTacToe {

	public static final char X = 'X', O = 'O', T = 'T', EMPTY = '.';
	public static final int DRAW = 3, PLAYER_O = 2, PLAYER_X = 1, ON_GOING = 0;
	
	private static boolean T_PLACED = false;
	
	public static int getAltWinner(char[] board){
		// Reset static variables
		T_PLACED = false;

		int[][] lineResults = new int[10][];
		int empty = 0;
		
		// Collect Line Results
		for (int i = 0; i < lineResults.length; i++) {

			int[] result = getLine(board, BOARD_CHECK[i], i % 4);				
			lineResults[i] = result;	
			
			int outcome = result[0];
			empty += result[1];
			
			if(outcome > 0 && outcome != DRAW)
				return outcome;
		}		
		
		return empty > 0 ? ON_GOING : DRAW;
	}
	
	public static int[] getLine(char[] board, Key keyGen, int line){
		int winner = ON_GOING;
		int empty = 0;
		for (int i = 0; i < 4; i++) {
			int key = keyGen.key(line, i);
			char loc = board[key];
			
			if(loc == T)
				T_PLACED = true;
			else if(loc == X)
				winner |= PLAYER_X;
			else if(loc == O)
				winner |= PLAYER_O;
			else if(loc == EMPTY)
				empty++;
		}
		
		return new int[]{empty > 0 ? ON_GOING : winner, empty};
	}
	
	public static char[][] getBoards(){
		
		BufferedReader br = null;
		char[][] boards = null;
		
	    try {
			br = new BufferedReader(new FileReader("input/tictactoe.txt"));
	    	int t = Integer.parseInt(br.readLine());
	    	
	    	boards = new char[t][16];
		
			for (int i = 0; i < t; i++) {
				StringBuffer buffer = new StringBuffer();
				for (int j = 0; j < 4; j++) {
					buffer.append(br.readLine());
				}
				boards[i] = buffer.toString().toCharArray();
				
				br.readLine();
			}
	    } catch (NumberFormatException | IOException e) {
			e.printStackTrace();
		} finally {
	        try {
				br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
	    }
	    
	    return boards;
	}
	
	public static void main(String[] args){
		char[][] boards = getBoards();
		
		StringBuffer buf = new StringBuffer();
		for (int i = 0; i < boards.length; i++) {
			int winner = getAltWinner(boards[i]);
			
			String won = "";
			if(winner == PLAYER_X)
				won = "X won";
			else if(winner == PLAYER_O)
				won = "O won";
			else if(winner == DRAW)
				won = "Draw";
			else 
				won = "Game has not completed";
			
			String result = String.format("Case #%d: %s\n", i+1, won);
			buf.append(result);
			System.out.print(result);			
		}		
		
		try {
			PrintWriter out = new PrintWriter("output/tictactoe.txt");
			out.print(buf.toString());
			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	public static Key[] BOARD_CHECK = new Key[10];
	
	static{
		for (int i = 0; i < 4; i++) {
			BOARD_CHECK[i] = Key.HORIZONTAL;
		}

		for (int i = 0; i < 4; i++) {
			BOARD_CHECK[4+i] = Key.VERTICAL;
		}
		
		BOARD_CHECK[8] = Key.DIAG_1;
		BOARD_CHECK[9] = Key.DIAG_2;
	}
	
	public enum Key {
		
		
		HORIZONTAL{

			@Override
			public int key(int i, int j) {
				return (i*4) + j;
			}
			
		}, 
		VERTICAL{

			@Override
			public int key(int i, int j) {
				return i + (j*4);
			}
			
		},
		DIAG_1 {

			@Override
			public int key(int i, int j) {
				return j + (j * 4);
			}
			
		},
		DIAG_2 {

			@Override
			public int key(int i, int j) {
				return (3 - j) + (j * 4);
			}
			
		};

		public abstract int key(int i, int j);
		
	}
}
