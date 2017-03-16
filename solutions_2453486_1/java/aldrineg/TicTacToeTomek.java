import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class TicTacToeTomek {
	private static final String PLAYERS = "XOT";
	String[] board = new String[4];
	
	int f = 0;
	int[][] d = new int[2][2];
	int[][] h = new int[2][4];
	int[][] v = new int[2][4];
	
	public void addVertical(int player, int x) {
		for (int i = 0; i < 2; i++) {
			if (i == player || player == 2) {
				v[i][x]++;
			}
		}
	}

	public void addHorizontal(int player, int x) {
		for (int i = 0; i < 2; i++) {
			if (i == player || player == 2) {
				h[i][x]++;
			}
		}
	}
	
	public void addDiagonal(int player, int x) {
		for (int i = 0; i < 2; i++) {
			if (i == player || player == 2) {
				d[i][x]++;
			}
		}
	}
	
	public int winner() {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < h[i].length; j++) {
				if (h[i][j] == 4) {
					return i;
				}
			}
			for (int j = 0; j < v[i].length; j++) {
				if (v[i][j] == 4) {
					return i;
				}
			}
			for (int j = 0; j < d[i].length; j++) {
				if (d[i][j] == 4) {
					return i;
				}
			}
		}
		return -1;
	}
	
	public String toString() {
		String s = "";
		
		s+="h\n";
		for (int i = 0; i < 2; i++) {
			s+=Arrays.toString(h[i]) + "\n";
		}

		s+="v\n";
		for (int i = 0; i < 2; i++) {
			s+=Arrays.toString(v[i]) + "\n";
		}
		
		s+="d\n";
		for (int i = 0; i < 2; i++) {
			s+=Arrays.toString(d[i]) + "\n";
		}
		
		return s;
	}
	
	public String whoWon() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				char curr = board[i].charAt(j);
				int player = PLAYERS.indexOf(curr);
				
				if (player > -1) {
					if (i == j) {
						addDiagonal(player, 0);
					}
					if (i + j == 3) {
						addDiagonal(player, 1);
					}
					addHorizontal(player, i);
					addVertical(player, j);
					f++;
				}
				
//				System.out.println(i+","+j+":"+player);
//
//				System.out.println(this);
				
				int won = winner();
				
				if (won == 0) {
					return "X won"; 
				} else if (won == 1) {
					return "O won";
				}
			}
		}
		
		if (f == 16) {
			return "Draw";
		} else {
			return "Game has not completed";
		}
	}
	
	public static void main(String args[]) throws IOException {
		Scanner scin = new Scanner(new File("in1.txt"));
		FileWriter fw = new FileWriter(new File("out1.txt"));
		
		int T = scin.nextInt();
		scin.nextLine();
		
		for (int cs = 1; cs < T+1; cs++) {
			TicTacToeTomek game = new TicTacToeTomek();
			
			for (int i = 0; i < 4; i++) {
				game.board[i] = scin.nextLine();
			}
			
			String rs = game.whoWon();
			
			fw.write("Case #" + cs + ": " + rs + "\n");
			
			if (scin.hasNextLine()) {
				scin.nextLine();				
			}
		}
		
		fw.close();
	}
}
