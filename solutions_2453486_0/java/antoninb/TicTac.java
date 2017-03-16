package qualifs;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

public class TicTac {
	
	public static boolean won(char[][] array, char player){
		//lines
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(array[i][j] != player && array[i][j] != 'T') break;
				if(j == 3) return true;
			}
		}
		
		//columns
		for(int j = 0; j < 4; j++){
			for(int i = 0; i < 4; i++){
				if(array[i][j] != player && array[i][j] != 'T') break;
				if(i == 3) return true;
			}
		}
		
		//diagonals
		for(int i = 0; i < 4; i++){
			if(array[i][i] != player && array[i][i] != 'T') break;
			if(i == 3) return true;
		}
		
		for(int i = 0; i < 4; i++){
			if(array[i][3 - i] != player && array[i][3 - i] != 'T') break;
			if(i == 3) return true;
		}
		
		return false;
	}
	
	public static int gameStatus(char[][] array){
		if(won(array, 'X')) return 2;
		if(won(array, 'O')) return 3;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(array[i][j] == '.') return 1;
			}
		}
		return 0;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String fileName = "../A-small-attempt0.in";
		Scanner sC = null;
		try {
			sC = new Scanner(new File(fileName));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		sC.useLocale(Locale.US);
		
		int T = sC.nextInt();
		
		for(int t = 0; t < T; t++){
			char[][] array = new char[4][4];
			for(int j = 0; j < 4; j++){
				String line = sC.next();
				array[j] = line.toCharArray();
			}
			
			int status = gameStatus(array);
			String result = "Case #" + (t + 1) + ": ";
			switch(status){
				case 0: result += "Draw"; break;
				case 1: result += "Game has not completed"; break;
				case 2: result += "X won"; break;
				case 3: result += "O won"; break;
			}
			
			System.out.println(result);
			
		}

	}

}
