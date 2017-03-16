import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class TicTacToeTomek {

	private static final String inputFilePath = "Input/Small.txt";
	private static final int SIZE = 4;
	
	private static String solve(char[][] map) {
		
		char test = 'X';
		boolean flagDA = true;
		boolean flagDB = true;
		for (int i = 0; i < SIZE; i ++) {
			boolean flagA = true;
			boolean flagB = true;
			
			for (int j = 0; j < SIZE; j ++) {
				if (map[i][j] != test && map[i][j] != 'T')
					flagA = false;
				if (map[j][i] != test && map[j][i] != 'T')
					flagB = false;
			}
			
			if (map[i][i] != test && map[i][i] != 'T')
				flagDA = false;
			if (map[i][SIZE - 1 - i] != test && map[i][SIZE - 1 - i] != 'T')
				flagDB = false;
							
			if (flagA || flagB)
				return "X won";
		}
		if (flagDA || flagDB)
			return "X won";
				
		test = 'O';
		flagDA = true;
		flagDB = true;
		for (int i = 0; i < SIZE; i ++) {
			boolean flagA = true;
			boolean flagB = true;
			
			for (int j = 0; j < SIZE; j ++) {
				if (map[i][j] != test && map[i][j] != 'T')
					flagA = false;
				if (map[j][i] != test && map[j][i] != 'T')
					flagB = false;
			}
			
			if (map[i][i] != test && map[i][i] != 'T')
				flagDA = false;
			if (map[i][SIZE - 1 - i] != test && map[i][SIZE - 1 - i] != 'T')
				flagDB = false;
							
			if (flagA || flagB)
				return "O won";
		}
		if (flagDA || flagDB)
			return "O won";
		
		for (int i = 0; i < SIZE; i ++) 
			for (int j = 0; j < SIZE; j ++)
				if (map[i][j] == '.')
					return "Game has not completed";
			
		return "Draw";
	}
	
	/**
	 * Good Luck, Wash!
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(inputFilePath)); 
		int T = Integer.parseInt(br.readLine());
		for (int i = 1; i <= T; i ++) {
			System.out.print(String.format("Case #%d: ", i));
			char[][] map = new char[SIZE][SIZE];
			String line; 
			for (int j = 0; j < SIZE; j ++) {
				line = br.readLine();
				map[j] = line.toCharArray();
			}
			br.readLine();
			System.out.println(solve(map));
		}
		br.close();
	}

}
