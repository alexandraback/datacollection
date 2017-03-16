import java.io.*;

public class TicTacToeTomek {
	 public static void main (String[] args) {
		 int T = 0;
		 try {
			 BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
			 // read T
			 T = Integer.parseInt(br.readLine());
			 char[][] game = new char[4][4];
			 String temp = new String();
			 for (int i = 1; i <= T; i++) {
				 // copy game into 2D array
				 for (int j = 0; j < 4; j++) {
					 temp = br.readLine();
					 for (int k = 0; k < 4; k++) {
						 // add input into 2D array
						 game[j][k] = temp.charAt(k);
					 }
				 }
				 // check and print state of game
				 System.out.println("Case #" + i + ": " + gameState(game));
				 // skip blank line
				 br.readLine();
			 }
			 br.close();
		 } catch (IOException ioe) {
			 ;
		 }
	 }
	 
	 public static String gameState(char[][] game) {
		 for (int i = 0; i < 4; i++) {
			 // vertical
			 if ((game[i][0] == 'X' || game[i][0] == 'T') && (game[i][1] == 'X' || game[i][1] == 'T')
				&& (game[i][2] == 'X' || game[i][2] == 'T') && (game[i][3] == 'X' || game[i][3] == 'T'))
					 return "X won";
			 else if ((game[i][0] == 'O' || game[i][0] == 'T') && (game[i][1] == 'O' || game[i][1] == 'T')
					&& (game[i][2] == 'O' || game[i][2] == 'T') && (game[i][3] == 'O' || game[i][3] == 'T'))
					 return "O won";
			 // horizontal
			 if ((game[0][i] == 'X' || game[0][i] == 'T') && (game[1][i] == 'X' || game[1][i] == 'T')
				&& (game[2][i] == 'X' || game[2][i] == 'T') && (game[3][i] == 'X' || game[3][i] == 'T'))
					 return "X won";
			 else if ((game[0][i] == 'O' || game[0][i] == 'T') && (game[1][i] == 'O' || game[1][i] == 'T')
					&& (game[2][i] == 'O' || game[2][i] == 'T') && (game[3][i] == 'O' || game[3][i] == 'T'))
					 return "O won";
		 }
		 // diagonal
		 if ((game[0][0] == 'X' || game[0][0] == 'T') && (game[1][1] == 'X' || game[1][1] == 'T')
			&& (game[2][2] == 'X' || game[2][2] == 'T') && (game[3][3] == 'X' || game[3][3] == 'T'))
				 return "X won";
		 if ((game[0][0] == 'O' || game[0][0] == 'T') && (game[1][1] == 'O' || game[1][1] == 'T')
			&& (game[2][2] == 'O' || game[2][2] == 'T') && (game[3][3] == 'O' || game[3][3] == 'T'))
				 return "O won";
		 if ((game[0][3] == 'X' || game[0][3] == 'T') && (game[1][2] == 'X' || game[1][2] == 'T')
			&& (game[2][1] == 'X' || game[2][1] == 'T') && (game[3][0] == 'X' || game[3][0] == 'T'))
				 return "X won";
		 if ((game[0][3] == 'O' || game[0][3] == 'T') && (game[1][2] == 'O' || game[1][2] == 'T')
			&& (game[2][1] == 'O' || game[2][1] == 'T') && (game[3][0] == 'O' || game[3][0] == 'T'))
				 return "O won";
		 // Check if incomplete
		 for (int i = 0; i < 4; i++) {
			 for (int j = 0; j <4; j++) {
				 if (game[i][j] == '.')
					 return "Game has not completed";
			 }
	 	}
		// Else draw
	 	return "Draw";
	 }
}
