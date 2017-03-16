import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;


public class Lawnmower {
	
	public static String solve(int input[][], int row, int col) {
		int rowMax[] = new int[row];
		int colMax[] = new int[col];
		
		for (int i = 0; i < row; i++){
			rowMax[i] = 0;
		}
		
		for (int i = 0; i < col; i++){
			colMax[i] = 0;
		}
		
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				if (input[i][j] > rowMax[i]){
					rowMax[i] = input[i][j];
				}
				
				if (input[i][j] > colMax[j]){
					colMax[j] = input[i][j];
				}
			}
		}
		
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				if (input[i][j] < rowMax[i] && input[i][j] < colMax[j])
					return "NO";
			}
		}
				
		return "YES";
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
		
		File output = new File("output_lawnmower.txt");
		BufferedWriter bw;

		StringTokenizer tokenizer;
		
		try {
			bw = new BufferedWriter(new FileWriter(output));
			
			fileReader = new FileReader(input);
			br = new BufferedReader(fileReader);
			str = br.readLine();
			
			T = Integer.parseInt(str);
			
			for (int i = 0; i < T; i++) {
				int N, M;
				int array[][];
				
				str = br.readLine();
				tokenizer = new StringTokenizer(str);
				N = Integer.parseInt(tokenizer.nextToken());
				M = Integer.parseInt(tokenizer.nextToken());
				
				array = new int[N][M];
				for (int n = 0; n < N; n++){
					str = br.readLine();
					tokenizer = new StringTokenizer(str);
					for (int m = 0; m < M; m++){
						array[n][m] = Integer.parseInt(tokenizer.nextToken());
					}
				}
				
				result = solve(array, N, M);
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
