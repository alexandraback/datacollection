import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;


public class SolutionA {
	
	// For example, "B-small"
	private static final String FILENAME = "Asmall";
	
	private void solveCase(int caseNumber, BufferedReader rd, PrintWriter wr) throws Exception {
		char[][] board = new char[4][4];
		for(int i = 0; i < 4; i++) {
			String line = rd.readLine();
			for(int j = 0; j < 4; j++) {
				board[i][j] = line.charAt(j);
			}
		}
		rd.readLine();
		
		char winner = ' ';
		boolean gameComplete = true;
		for(int row = 0; row < 4; row++) {
			boolean completeRow = true;
			boolean seenX = false;
			boolean seenO = false;
			for(int col = 0; col < 4; col++) {
				if(board[row][col] == 'X') {
					seenX = true;
				} else if(board[row][col] == 'O') {
					seenO = true;
				} else if(board[row][col] == '.') {
					completeRow = false;
					gameComplete = false;
				}
			}
			if(completeRow && ((!seenX && seenO) || (!seenO && seenX))) {
				winner = seenX ? 'X' : 'O';
			}
		}
		
		if(winner == ' ') {
			for(int row = 0; row < 4; row++) {
				boolean completeRow = true;
				boolean seenX = false;
				boolean seenO = false;
				for(int col = 0; col < 4; col++) {
					if(board[col][row] == 'X') {
						seenX = true;
					} else if(board[col][row] == 'O') {
						seenO = true;
					} else if(board[col][row] == '.') {
						completeRow = false;
						gameComplete = false;
					}
				}
				if(completeRow && ((!seenX && seenO) || (!seenO && seenX))) {
					winner = seenX ? 'X' : 'O';
				}
			}
		}
		
		if(winner == ' ') {
			boolean completeRow = true;
			boolean seenX = false;
			boolean seenO = false;
			for(int row = 0; row < 4; row++) {
				if(board[row][row] == 'X') {
					seenX = true;
				} else if(board[row][row] == 'O') {
					seenO = true;
				} else if(board[row][row] == '.') {
					completeRow = false;
					gameComplete = false;
				}
			}
			if(completeRow && ((!seenX && seenO) || (!seenO && seenX))) {
				winner = seenX ? 'X' : 'O';
			}
		}
		
		if(winner == ' ') {
			boolean completeRow = true;
			boolean seenX = false;
			boolean seenO = false;
			for(int row = 0; row < 4; row++) {
				if(board[row][3 - row] == 'X') {
					seenX = true;
				} else if(board[row][3 - row] == 'O') {
					seenO = true;
				} else if(board[row][3 - row] == '.') {
					completeRow = false;
					gameComplete = false;
				}
			}
			if(completeRow && ((!seenX && seenO) || (!seenO && seenX))) {
				winner = seenX ? 'X' : 'O';
			}
		}
		
		if(winner != ' ') {
			System.out.println("Case #" + caseNumber + ": " + winner + " won");
			wr.println("Case #" + caseNumber + ": " + winner + " won");
		} else if(!gameComplete) {
			System.out.println("Case #" + caseNumber + ": Game has not completed");
			wr.println("Case #" + caseNumber + ": Game has not completed");
		} else {
			System.out.println("Case #" + caseNumber + ": Draw");
			wr.println("Case #" + caseNumber + ": Draw");
		}
	}
	
	public SolutionA() {
		BufferedReader rd = null;
		PrintWriter wr = null;
		int numCases = 0;
		try {
			rd = new BufferedReader(new FileReader(FILENAME + ".in"));
			wr = new PrintWriter(new FileWriter(FILENAME + ".out"));
			numCases = Integer.parseInt(rd.readLine());
		} catch (Exception e) {
			System.out.println("Error reading file");
			e.printStackTrace();
			return;
		}
		
		for(int i = 1; i <= numCases; i++) {
			try {
				solveCase(i, rd, wr);
			} catch (Exception e) {
				System.out.println("Exception in Case " + i + ". Stack trace:");
				e.printStackTrace();
				break;
			}
		}
		
		try {
			rd.close();
			wr.close();
		} catch (Exception e) {
			System.out.println("Error closing file");
			e.printStackTrace();
			return;
		}
	}
	
	public static void main(String[] args) {
		new SolutionA();
	}
	
}
