import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;


public class TicTacToe {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		
		String line = null;
		line = br.readLine();
		
		int SIZE = 4;
		int T = Integer.parseInt(line);
		int t = 0;
		String[] results = new String[T];
		while (t<T) {
			char[][] board = new char[SIZE][SIZE];
			boolean haveDots = false;
			boolean haveWinner = false;

			char winner = '\0';
			
			for (int i=0; i<SIZE; i++) {
				line = br.readLine();
				board[i] = line.toCharArray();

				winner = equals(equals(board[i][0], board[i][1]), equals(board[i][2], board[i][3]));
				if (winner == 'X' || winner == 'O') {
					int k = SIZE - i - 1;
					while (k > 0) {
						br.readLine();
						k--;
					}
					haveWinner = true;
					break;
				} else if (winner == '.') {
					haveDots = true;
				}
			}
			
			if (!haveWinner) {
				for (int j=0; j<SIZE; j++) {
					winner = equals(equals(board[0][j], board[1][j]), equals(board[2][j], board[3][j]));
					if (winner == 'X' || winner == 'O') {
						haveWinner = true;
						break;
					} else if (winner == '.') {
						haveDots = true;
					}
				}
			}
			
			if (!haveWinner) {
				winner = equals(equals(board[0][0], board[1][1]), equals(board[2][2], board[3][3]));
				if (winner == 'X' || winner == 'O') {
					haveWinner = true;
				} else if (winner == '.') {
					haveDots = true;
				}
			}
			
			if (!haveWinner) {
				winner = equals(equals(board[0][3], board[1][2]), equals(board[2][1], board[3][0]));
				if (winner == 'X' || winner == 'O') {
					haveWinner = true;
				} else if (winner == '.') {
					haveDots = true;
				}
			}
			
			String result = "Draw";
			if (haveWinner) {
				if (winner == 'X') {
					result = "X won";
				} else if (winner == 'O') {
					result = "O won";
				}
			} else if (haveDots) {
				result = "Game has not completed";
			}
			
			results[t] = "Case #" + (t+1) + ": " + result;
			System.out.println(results[t]);
			
			line = br.readLine();
			t++;
		}
		
		isr.close();
		br.close();
		
		File file = new File("TicTacToe.txt");
        BufferedWriter output = new BufferedWriter(new FileWriter(file));
        for (int i=0; i< results.length; i++) {
        	output.write(results[i]);
        	if (i < results.length - 1) {
        		output.write("\n");
        	}
        }
        output.close();

	}
	
	private static char equals(char a, char b) {
		if (a == b) {
			return a;
		} else if (a == 'T') {
			return b;
		} else if (b == 'T') {
			return a;
		} else if (a == '.' || b == '.') {
			return '.';
		} else {
			return '\0';
		}
	}

}
