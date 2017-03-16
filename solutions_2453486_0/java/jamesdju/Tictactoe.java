import java.util.*;

class Tictactoe{
	public static char[][] board = new char[4][4];
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		int counter = 1;
		String winner;
		boolean isFinished = true;

		while(tc-- > 0){
			isFinished = true;
			sc.nextLine();
			for(int i = 0; i < 4; i++){
				String line = sc.nextLine();
				for(int j = 0; j < line.length(); j++){
					board[i][j] = line.charAt(j);
					if(board[i][j] == '.'){
						isFinished = false;
					}
				}
			}
			winner = determineWinner();
			if(winner.equals("no") && isFinished){
				System.out.println("Case #" + (counter++) + ": Draw");
			} else if(winner.equals("no") && !isFinished){
				System.out.println("Case #" + (counter++) + ": Game has not completed");
			} else{
				System.out.println("Case #" + (counter++) + ": " + winner);
			}
		}	
	}

	public static String determineWinner(){
		int xcount = 0, ocount = 0, tcount = 0;
		for(int i = 0; i < 4; i++){
			
			//horizontal
			xcount = 0; ocount = 0; tcount = 0;
			for(int j = 0; j < 4; j++){
				if(board[i][j] == 'X'){
					xcount++;
				} else if(board[i][j] == 'O'){
					ocount++;
				} else if(board[i][j] == 'T'){
					tcount++;
				}
				if(xcount + tcount == 4){
					return "X won";
				} else if(ocount + tcount == 4){
					return "O won";
				}
			}

			//vertical
			xcount = 0; ocount = 0; tcount = 0;
			for(int j = 0; j < 4; j++){
				if(board[j][i] == 'X'){
					xcount++;
				} else if(board[j][i] == 'O'){
					ocount++;
				} else if(board[j][i] == 'T'){
					tcount++;
				}
				if(xcount + tcount == 4){
					return "X won";
				} else if(ocount + tcount == 4){
					return "O won";
				}
			}
		}
		//diagonal 1
		xcount = 0; ocount = 0; tcount = 0;
		for(int i = 0; i < 4; i++){
			if(board[i][i] == 'X'){
				xcount++;
			} else if(board[i][i] == 'O'){
				ocount++;
			} else if(board[i][i] == 'T'){
				tcount++;
			}
			if(xcount + tcount == 4){
				return "X won";
			} else if(ocount + tcount == 4){
				return "O won";
			}
		}
			
		xcount = 0; ocount = 0; tcount = 0;
		for(int i = 0; i < 4; i++){
			if(board[i][3-i] == 'X'){
				xcount++;
			} else if(board[i][3-i] == 'O'){
				ocount++;
			} else if(board[i][3-i] == 'T'){
				tcount++;
			}
			if(xcount + tcount == 4){
				return "X won";
			} else if(ocount + tcount == 4){
				return "O won";
			}
		}
		return "no";
	}
}