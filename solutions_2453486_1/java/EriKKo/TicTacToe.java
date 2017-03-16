

import java.util.*;
import java.io.*;

public class TicTacToe {
	
	static final char TOMEK = 'T';
	
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		
		int T = io.getInt();
		for (int test = 1; test <= T; test++) {
			char[][] board = new char[4][];
			boolean over = true;
			for (int i = 0; i < 4; i++) {
				board[i] = io.getWord().toCharArray();
				for (char c : board[i]) if (c == '.') over = false;
			}
			io.print("Case #" + test + ": ");
			if (isWin(board, 'O')) {
				io.println("O won");
			} else if (isWin(board, 'X')) {
				io.println("X won");
			} else if (over) {
				io.println("Draw");
			} else {
				io.println("Game has not completed");
			}
		}
		
		io.close();
	}
	
	static boolean isWin(char[][] board, char player) {
		if (isWin(board, player, 0, 0, 1, 1) || isWin(board, player, 3, 0, -1, 1)) return true;
		for (int i = 0; i < 4; i++) if (isWin(board, player, 0, i, 1, 0) || isWin(board, player, i, 0, 0, 1)) return true;
		return false;
	}
	
	static boolean isWin(char[][] board, char player, int r, int c, int dr, int dc) {
		for (int i = 0; i < 4; i++) {
			if (board[r][c] != player && board[r][c] != TOMEK) return false;
			r += dr; c += dc;
		}
		return true;
	}
	
	static class Kattio extends PrintWriter {
	    public Kattio(InputStream i) {
		super(new BufferedOutputStream(System.out));
		r = new BufferedReader(new InputStreamReader(i));
	    }
	    public Kattio(InputStream i, OutputStream o) {
		super(new BufferedOutputStream(o));
		r = new BufferedReader(new InputStreamReader(i));
	    }

	    public boolean hasMoreTokens() {
		return peekToken() != null;
	    }

	    public int getInt() {
		return Integer.parseInt(nextToken());
	    }

	    public double getDouble() { 
		return Double.parseDouble(nextToken());
	    }

	    public long getLong() {
		return Long.parseLong(nextToken());
	    }

	    public String getWord() {
		return nextToken();
	    }

	    private BufferedReader r;
	    private String line;
	    private StringTokenizer st;
	    private String token;

	    private String peekToken() {
		if (token == null) 
		    try {
			while (st == null || !st.hasMoreTokens()) {
			    line = r.readLine();
			    if (line == null) return null;
			    st = new StringTokenizer(line);
			}
			token = st.nextToken();
		    } catch (IOException e) { }
		return token;
	    }

	    private String nextToken() {
		String ans = peekToken();
		token = null;
		return ans;
	    }
	}
}
