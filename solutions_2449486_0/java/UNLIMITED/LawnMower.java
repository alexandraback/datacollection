import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class LawnMower {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		Scanner reader = new Scanner(new File(
				"C:\\Users\\boyusun\\workspace\\CodeJam\\input\\B-small-attempt0.in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter(
				"C:\\Users\\boyusun\\workspace\\CodeJam\\output\\B-small-attempt0.out"));
		
		int numOfCases = reader.nextInt();
		reader.nextLine();
		for(int i = 1; i <= numOfCases; i++){
			int row = reader.nextInt();
			int col = reader.nextInt();
			int[][] lawn = new int[row][col];
			for(int k = 0; k < row; k++)
				for(int j = 0; j < col; j++)
					lawn[k][j] = reader.nextInt();
			
			boolean valid = true;
			for(int k = 0; k < row && valid; k++)
				for(int j = 0; j < col && valid; j++){
					boolean cellValid = true;
					for(int h = 0; h < col; h++)
						if(lawn[k][h] > lawn[k][j]){
							cellValid = false;
							break;
						}
					if(cellValid) continue;
					cellValid = true;
					for(int h = 0; h < row; h++)
						if(lawn[h][j] > lawn[k][j]){
							cellValid = false;
							break;
						}
					if(!cellValid){
						valid = false;
					}
				}
			if(valid)
				writer.write("Case #" + i + ": YES\n");
			else
				writer.write("Case #" + i + ": NO\n");
			
		}
		reader.nextLine();
		reader.close();
		writer.close();
	}

}
