import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class TTTT {

	static char _ = 0;
	static char O = 1;
	static char X = 2;
	static char T = 3;
	
	static int WINNER_O = 1;
	static int WINNER_X = 2;
	static int DRAW = 3;
	static int INCOMPLETE = 4;

	char parseChar(char c) {
		if (c == '.')
			return _;
		if (c == 'T')
			return T;
		if (c == 'X')
			return X;
		if (c == 'O')
			return O;

		//should never reach here
		return (char) -1;
	}

	char [][] parseBoard(String s) {
		char[][] board = new char[4][4];
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				board[i][j] = parseChar(s.charAt(i * 4 + j));
			}
		}
		return board;
	}

	void print(char[][] board) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				System.out.print((int)board[i][j]);
			}
			System.out.println();
		}
	}

	boolean isO(char[][] b) {
		//check each row and col
		for(int i = 0; i < 4; ++i) {
			if ((b[i][0] & b[i][1] & b[i][2] & b[i][3]) == O)
				return true;
			if ((b[0][i] & b[1][i] & b[2][i] & b[3][i]) == O)
				return true;
		}
		//diag
		if ((b[0][0] & b[1][1] & b[2][2] & b[3][3]) == O)
			return true;
		if ((b[0][3] & b[1][2] & b[2][1] & b[3][0]) == O)
			return true;

		return false;
	}
	
	boolean isX(char[][] b) {
		//check each row and col
		for(int i = 0; i < 4; ++i) {
			if ((b[i][0] & b[i][1] & b[i][2] & b[i][3]) == X)
				return true;
			if ((b[0][i] & b[1][i] & b[2][i] & b[3][i]) == X)
				return true;
		}
		//diag
		if ((b[0][0] & b[1][1] & b[2][2] & b[3][3]) == X)
			return true;
		if ((b[0][3] & b[1][2] & b[2][1] & b[3][0]) == X)
			return true;

		return false;
	}
	
	boolean isBoardFull(char[][] b) {
		//just check each row
		for(int i = 0; i < 4; ++i)
			for(int j = 0; j < 4; ++j)
				if (b[i][j] == _)
					return false;
		return true;
	}
	
	int boardResult(char[][] board) {
		if (isO(board))
			return WINNER_O;
		if (isX(board))
			return WINNER_X;
		if (isBoardFull(board))
			return DRAW;
		return INCOMPLETE;
	}
	
	void processFile(String file) {
		BufferedReader br;
		FileReader fr;
		BufferedWriter bw;
		FileWriter fw;
		try {
			fr = new FileReader(file);

			br = new BufferedReader(fr);
			fw = new FileWriter("out");
			bw = new BufferedWriter(fw);

			int numCases = Integer.parseInt(br.readLine());

			String board;
			String result;
			for (int i = 0; i < numCases; ++i) {
				board = "";
				for (int j = 0; j < 4; ++j) {
					board += br.readLine();
				}
				//System.out.println(board);
				br.readLine();	//empty
				char[][] parsed = parseBoard(board);
				//print(parsed);
				
				//get the result of the game
				if (isO(parsed))
					result = "O won";
				else if (isX(parsed))
					result = "X won";
				else if (isBoardFull(parsed))
					result = "Draw";
				else
					result = "Game has not completed";
				
				//out
				bw.write("Case #" + (i + 1) + ": " + result + "\n");
				System.out.println("Case #" + (i + 1) + ": " + result);
			}
			bw.flush();
			fw.flush();
			fr.close();
			br.close();
			fw.close();
			bw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		TTTT t = new TTTT();
		
		String file = "large.in";
		t.processFile(file);

	}

}
