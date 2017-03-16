import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Q1 {
	public static Problem[] probs;

	static class Problem {
		char board[][] = new char[4][4];
	}
				
	
	public static void main(String[] args) {
		String inputFile = args[0];
		parseFile(inputFile);
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(inputFile + ".out"));
			for (int i=0; i<probs.length; i++) {
				String output = solveProblem(probs[i]);
				System.out.println(output);
				bw.write("Case #" + (i+1) + ": " + output + "\n");
			}
			bw.flush();
			bw.close();
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}
			
	private static String solveProblem(Problem p) {
		//Check 4 rows, 4 col, 2 diags for X or O win
		//rows
		for (int i=0; i<4; i++) {
			boolean xWin = true;
			boolean oWin = true;
			for (int j=0; j<4; j++) {
				if (p.board[i][j]=='X') {
					oWin = false;
				} else if (p.board[i][j]=='O') {
					xWin = false;
				} else if (p.board[i][j]=='.') {
					oWin = xWin = false;
				}
				if (!(oWin | xWin)) {
					break;
				}
			}
			if (xWin) {
				return "X won";
			} else if (oWin) {
				return "O won";
			}
		}
		//cols
		for (int i=0; i<4; i++) {
			boolean xWin = true;
			boolean oWin = true;
			for (int j=0; j<4; j++) {
				if (p.board[j][i]=='X') {
					oWin = false;
				} else if (p.board[j][i]=='O') {
					xWin = false;
				} else if (p.board[j][i]=='.') {
					oWin = xWin = false;
				}
				if (!(oWin | xWin)) {
					break;
				}
			}
			if (xWin) {
				return "X won";
			} else if (oWin) {
				return "O won";
			}
		}
		//Diags
		boolean xWin = true;
		boolean oWin = true;
		for (int i=0; i<4; i++) {
			if (p.board[i][i]=='X') {
				oWin = false;
			} else if (p.board[i][i]=='O') {
				xWin = false;
			} else if (p.board[i][i]=='.') {
				oWin = xWin = false;
			}
			if (!(oWin | xWin)) {
				break;
			}
		}
		if (xWin) {
			return "X won";
		} else if (oWin) {
			return "O won";
		}

		xWin = true;
		oWin = true;
		
		for (int i=0; i<4; i++) {
			if (p.board[i][i]=='X') {
				oWin = false;
			} else if (p.board[i][i]=='O') {
				xWin = false;
			} else if (p.board[i][i]=='.') {
				oWin = xWin = false;
			}
			if (!(oWin | xWin)) {
				break;
			}
		}
		if (xWin) {
			return "X won";
		} else if (oWin) {
			return "O won";
		}		
		
		xWin = true;
		oWin = true;
	
		for (int i=0; i<4; i++) {
			if (p.board[i][3-i]=='X') {
				oWin = false;
			} else if (p.board[i][3-i]=='O') {
				xWin = false;
			} else if (p.board[i][3-i]=='.') {
				oWin = xWin = false;
			}
			if (!(oWin | xWin)) {
				break;
			}
		}
		if (xWin) {
			return "X won";
		} else if (oWin) {
			return "O won";
		}		
	
		
		//Check for a draw
		boolean draw = true;
outer:	for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++) {
				if (p.board[i][j]=='.') {
					draw = false;
					break outer;
				}
			}
		}
		if (draw) {
			return "Draw";
		}
		return "Game has not completed";
	}

	public static void parseFile(String inputFile) {
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader(inputFile));
			String line = br.readLine();
			probs = new Problem[Integer.parseInt(line)];
			line = br.readLine();
			for (int i=0; i<probs.length; i++) {
				probs[i] = new Problem();
				for (int j=0; j<4; j++) {
					for (int k=0; k<4; k++) {
						probs[i].board[j][k] = line.charAt(k);
					}
					line = br.readLine();
				}
				//Skip blank line
				line = br.readLine();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
