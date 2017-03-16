package codejam.y2014.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Random;

public class ProblemC {
	
	private static boolean debug = false;

	int R;
	int C;
	
	static final char EMPTY_SPACE = '.';
	static final char MINE = '*';
	static final char CLICK = 'c';
	
	static final String IMPOSSIBLE = "Impossible";
	
	HashMap<Integer, HashMap<Integer, Integer>> combinations;
	
	
	public ProblemC() {
		
	}
	
	
	public void init(int R, int C) {
		this.R = R;
		this.C = C;
		combinations = new HashMap<Integer, HashMap<Integer, Integer>>();
	}
	
	
	public void reset() {
		this.R = -1;
		this.C = -1;
		this.combinations.clear();
	}

	
	public char[][] flipBoard(char[][] source) {
		if (source == null) {
			return null;
		}
		int r = source.length;
		int c = source[0].length;
		char[][] output = new char[c][r];
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				output[j][i] = source[i][j];
			}
		}
		return output;
	}
	
	public String solution(int R, int C, int M) throws Exception {
		if (debug) {
			System.out.println("case " + R + " " + C + " " + M);
		}
		
		char[][] board;
		
		 if (M == 0) {
			 board = this.getZeroMineBoard(R, C);
			return this.boardToString(board);
		} else if (M == R*C-1) {
			board = this.getOneClickBoard(R, C);
			return this.boardToString(board);
		}
		 
		if (R == 1 || C == 1) {
			board = (R==1) ? this.case11(R, C, M) : this.flipBoard(this.case11(C, R, M));
			return this.boardToString(board);
		}
		
		if (R==2 || C == 2) {
			board = (R==2)? this.case22(R, C, M) : this.flipBoard(this.case22(C, R, M));
			return this.boardToString(board);
		}
		
		if (R >= 3 && C >= 3) {
			board = this.case33(R, C, M);
			return this.boardToString(board);
		}
		
		
		throw new Exception("----------- error, shouldn't be here----------------");
		
	}
	
	public char[][] case11(int R, int C, int M) throws Exception {
		assert (R == 1);
		char[][] array = new char[1][C];
		for (int i = 0; i < C; i++) {
			if (i < M) {
				array[0][i] = MINE;
			} else {
				array[0][i] = EMPTY_SPACE;
			}
		}
		array[0][C - 1] = CLICK;
		return array;
	}
	
	public char[][] case22(int R, int C, int M) {
		
		assert(R==2);
		if (R == 2 && C == 2) {
			if (M == 0) {
				return this.getZeroMineBoard(R, C);
			} else if (M==R*C - 1){
				return this.getOneClickBoard(R, C);
			} else {
				return null;
			}
		}

		if (M %2 !=0 || ((R*C - M) < 4)) {
			return null;
		}
		
		char[][] board = this.getEmptyBoard(R, C);
		int row = M/2;
		
		for (int i=C-1; i>C-1-row; i--) {
			board[0][i] = MINE;
			board[1][i] = MINE;
		}
		board[R-1][0] = CLICK;
		return board;
	}
	
	public char[][] case33(int R, int C, int M) throws Exception {
		int maxMine = R * C - 2*R - 2 * C + 4;
		if (M <= maxMine) {
			return this.case1Board(R, C, M);
		}
		int maxMine2 = R * C - 8;
		if (M <= maxMine2) {
			return this.case2Board(R, C, M);
		} else {
			int left = M - maxMine2;
			char[][] board = this.case2Board(R, C, maxMine2);
			return this.tag33(board, R-3, 0, left);
		} 
	}
	
	char[][] tag33(char[][] board, int leftR, int leftC, int left) throws Exception {
		if (left==1 || left == 3 || left >=5) {
			return null;
		} else if (left == 2) {
			board[leftR][leftC + 0] = MINE;
			board[leftR][leftC + 1] = MINE;
			return board;
		} else if (left == 4) {
			board[leftR][leftC + 0] = MINE;
			board[leftR][leftC + 1] = MINE;
			board[leftR+1][leftC + 2] = MINE;
			board[leftR+2][leftC + 2] = MINE;
			return board;
		}
		throw new Exception("shouldnt be here");
	}
	
	
	public char[][] case2Board(int R, int C, int M) {
		
		int max = R * C - 2*R - 2 * C + 4;
		char[][] board = this.case1Board(R, C, max);
		String board_st = null;
		if (debug) {
			board_st = this.boardToString(board);
		}
		int left = M - max + 1;
		board[R-3][2] = EMPTY_SPACE;
		
		if (debug) {
			board_st = this.boardToString(board);
		}
		
		int row = left / 2;
		
		for (int i=0; i<row; i++) {
			
			if (left == 1) {
				board[R-3][2] = MINE;
				if (debug) {
					board_st = this.boardToString(board);
				}
				return board;
			} else if (left == 0) {
				return board;
			}
			
			if (i < R - 3) {
				Arrays.fill(board[i], 0, 2, MINE);
				if (debug) {
					board_st = this.boardToString(board);
				}
				left -= 2;
				continue;
			} 
			//TODO
			else if (i < R - 3 + C - 3) {
				int j = i - (R-3);
				int loc = C - 1 - j;
				board[R-1][loc] = MINE;
			    board[R-2][loc] = MINE;
			    if (debug) {
					board_st = this.boardToString(board);
				}
			    left -= 2;
			    continue;
			}
		}
		
		if (left == 1) {
			board[R-3][2] = MINE;
		} 
		return board;
	}
	
	
	
	String boardToString(char[][] board) {
		if (board == null) {
			return IMPOSSIBLE;
		}
		StringBuilder sb = new StringBuilder();
		sb.append(new String(board[0]));
		for (int i=1; i<board.length; i++) {
			sb.append("\n").append(new String(board[i]));
		}
		return sb.toString();
	}
	
	
	char[][] getZeroMineBoard (int R, int C)
	{
		char[][] board = this.getEmptyBoard(R, C);
		board[R-1][0] = CLICK;
		return board;
	}
	
	char[][] getOneClickBoard(int R, int C) {
		char[][] board = this.fillBoard(R, C, MINE);
		board[R-1][0] = CLICK;
		return board;
	}
	
	
	char[][] fillBoard(int R, int C, char value) {
		char[][] board = new char[R][C];
		for (int i=0; i<board.length; i++) {
			Arrays.fill(board[i], value);
		}
		return board;
	}
	
	
	
	char[][] getEmptyBoard(int R, int C) {
		return this.fillBoard(R, C, EMPTY_SPACE);
	}
	
	public char[][] case1Board(int R, int C, int M) {
		char[][] board = this.getEmptyBoard(R, C);
		int row = M/(C-2);
		for (int i=0; i<row; i++) {
			Arrays.fill(board[i], 2, C, MINE);
		}
		int left = M - row * (C-2);
		if (left > 0) {
			Arrays.fill(board[row], C - left, C, MINE);
		}
		board[R-1][0] = CLICK;
		return board;
	}
	
	String readBlock(BufferedReader br) throws Exception {
		
		String line = br.readLine();
		String[] sp = line.split(" ");
		int R = Integer.parseInt(sp[0]);
		int C = Integer.parseInt(sp[1]);
		int M = Integer.parseInt(sp[2]);
		return this.solution(R, C, M);
	}
	
	
	public ArrayList<String> read(BufferedReader br) throws Exception {
		ProblemC problem = new ProblemC();
		 ArrayList<String> results = new  ArrayList<String>();
		int cases = Integer.parseInt(br.readLine());
		for (int i=1; i<=cases; i++) {
			String result = problem.readBlock(br);
			results.add("Case #" + i + ":\n" + result);
		}
		return results;
	}
	
	
	public ArrayList<String> read(String file) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(file));
		ArrayList<String> results = this.read(br);
		br.close();
		return results;
	}
	
	
	
	public void writeResult(ArrayList<String> results, String output) throws IOException {
		BufferedWriter bw = new BufferedWriter(new FileWriter(output));
		for (int i=0; i<results.size(); i++) {
			bw.write(results.get(i));
			bw.newLine();
		}
		bw.close();
	}
	

	public static void main(String[] args) throws Exception {
		

		
		//String file_name = "c-test";
		String file_name = "C-small-attempt0.in";
		//String file_name = "C-large.in";
		///String file_name = "A-test";
		String input = "src/input/" + file_name;
			
		String output = "src/output/" + file_name;
		System.out.println(output);
		ProblemC problem = new ProblemC();
		ArrayList<String> results = problem.read(input);
		for (String result : results) {
			System.out.println(result);
		}
		problem.writeResult(results, output);
	}
	

}
