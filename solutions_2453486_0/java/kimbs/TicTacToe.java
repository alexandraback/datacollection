import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;


public class TicTacToe {
	
	public static String solve(String str) {
		int input[][] = new int[4][4];
		boolean flag;
		int sum;
		
		flag = true;
		
		for (int i = 0; i < str.length(); i++){
			if (str.charAt(i) == 'X'){
				input[i/4][i%4] = 1;
			}
			else if (str.charAt(i) == 'O'){
				input[i/4][i%4] = -1;
			}
			else if (str.charAt(i) == '.'){
				input[i/4][i%4] = 0;
				flag = false;
			}
			else if (str.charAt(i) == 'T'){
				input[i/4][i%4] = 10;
			}
		}
		
		for (int i = 0; i < 4; i++){
			sum = 0;
			for (int j = 0; j < 4; j++){
				sum += input[i][j];
			}
			if (sum == 4 || sum == 13)
				return "X won";
			else if (sum == -4 || sum == 7)
				return "O won";
			
			sum = 0;
			for (int j = 0; j < 4; j++){
				sum += input[j][i];
			}
			if (sum == 4 || sum == 13)
				return "X won";
			else if (sum == -4 || sum == 7)
				return "O won";
		}
		
		sum = 0;
		for (int i = 0; i < 4; i++){
			sum += input[i][i];
		}
		if (sum == 4 || sum == 13)
			return "X won";
		else if (sum == -4 || sum == 7)
			return "O won";
		
		sum = 0;
		for (int i = 0; i < 4; i++){
			sum += input[3 - i][i];
		}
		if (sum == 4 || sum == 13)
			return "X won";
		else if (sum == -4 || sum == 7)
			return "O won";
		
		if (flag){
			return "Draw";
		}
		else{
			return "Game has not completed";
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int T = 0;
		String str = "";
		String result = "";
		
		File input = new File(args[0]);
		FileReader fileReader;
		BufferedReader br;
		
		File output = new File("output_tictactoe.txt");
		BufferedWriter bw;

		StringTokenizer tokenizer;
		
		try {
			bw = new BufferedWriter(new FileWriter(output));
			
			fileReader = new FileReader(input);
			br = new BufferedReader(fileReader);
			str = br.readLine();
			
			T = Integer.parseInt(str);
			
			for (int i = 0; i < T; i++) {
				str = "";
				for (int j = 0; j < 4; j++){
					str += br.readLine();
				}
				br.readLine();
				result = solve(str);
				System.out.println(result);
				bw.write(String.format("Case #%d: %s\n", i+1, result));
			}
			
			fileReader.close();
			br.close();
			
			bw.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}

