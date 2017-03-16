import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class TicTacToe {

	public static void main(String[] args) throws IOException {
		Scanner reader = new Scanner(new File(
				"C:\\Users\\boyusun\\workspace\\CodeJam\\input\\A-large.in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter(
				"C:\\Users\\boyusun\\workspace\\CodeJam\\output\\A-large.out"));
		
		int numOfCases = reader.nextInt();
		for(int i = 1; i <= numOfCases; i++){
			reader.nextLine();
			char[][] game = new char[4][4];
			for(int j = 0; j < 4; j++)
				game[j] = reader.nextLine().toCharArray();
			
			char Won = '.';
			
			boolean complete = true;
			
			for(int j = 0; j < 4; j++)
				for(int h = 0; h < 4; h++){
					if(game[j][h] == '.')
						complete = false;
					if(game[j][h] == 'T'){
						game[j][h] = 'X';
						if(isWon(game, 'X')){
							Won = 'X';
							break;
						}
						game[j][h] = 'O';
						if(isWon(game, 'O')){
							Won = 'O';
							break;
						}
						game[j][h] = 'T'; 
					}
					if( h == 3 && j == 3 && game[j][h] != 'T'){
						if(isWon(game, 'X')){
							Won = 'X';
						} else if(isWon(game, 'O')){
							Won = 'O';
						}
					}
				}
			writer.write("Case #" + i + ": ");
			if(Won == 'X')
				writer.write("X won");
			else if(Won == 'O')
				writer.write("O won");
			else if(complete)
				writer.write("Draw");
			else
				writer.write("Game has not completed");
			writer.write("\n");
		}
		
		
		reader.close();
		writer.close();
	}
	
	public static boolean isWon(char[][] game, char flag){
		for(int i = 0; i< 4; i++){
			if(game[i][0] == flag && game[i][1] == flag && game[i][2] == flag && game[i][3] == flag)
				return true;
			if(game[0][i] == flag && game[1][i] == flag && game[2][i] == flag && game[3][i] == flag)
				return true;
		}
		
		if(game[0][0] == flag && game[1][1] == flag && game[2][2] == flag && game[3][3] == flag ||
				game[0][3] == flag && game[1][2] == flag && game[2][1] == flag && game[3][0] == flag)
			return true;
		return false;
	}

}
