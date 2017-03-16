import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;


public class Lawnmower {
	private static int maxValue(int[] array) {
		int max = array[0];
		for (int i = 0; i < array.length; i++) {
			if (array[i] > max) {
				max = array[i];
			}
		}
		return max;
	}
	public static void main(String[] args){
		String line = null;
		FileReader input;
		Scanner scanner;
		BufferedReader reader;
		int row, col;
		int[][] state;
		int[] cuts;
		
		try {
			input = new FileReader("B-small-attempt1.in.txt");
			PrintStream out = new PrintStream(new FileOutputStream("output.txt"));
			reader = new BufferedReader(input);
			int testcase = Integer.parseInt(reader.readLine());
			for(int k = 1; k <= testcase; k++){
				line = reader.readLine();
				scanner = new Scanner(line);
				row = scanner.nextInt();
				col = scanner.nextInt();
				cuts = new int[col];
				Arrays.fill(cuts, 0);
				state = new int[row][col];
				for(int i = 0; i < row; i++){
					line = reader.readLine();
					scanner = new Scanner(line);
					for(int j = 0; j < col; j++){
						state[i][j] = scanner.nextInt();
					}
				}
				/*for (int i = 0; i < row; i++){
					System.out.println(Arrays.toString(state[i]));
				}
				System.out.println();*/
				boolean valid = true;
				int max = maxValue(state[0]);
				for(int i = 0; i < col; i++){
					if(state[0][i] != max){
						cuts[i] = state[0][i];
					} else {
						cuts[i] = -1 * max;
					}
				}
				for(int i = 1; i < row; i++){
//					System.out.println(Arrays.toString(cuts));
					max = maxValue(state[i]);
					for(int j = 0; j < col; j++){
						if(state[i][j] != max){
							if(cuts[j] < 0){
								if(state[i][j] < -1*cuts[j]){
									valid = false;
									break;
								} else {
									cuts[j] = state[i][j];
								}
							} else if (cuts[j] > 0){
								if(state[i][j] != cuts[j]){
									valid = false;
									break;
								}
							}
						} else {
							if(cuts[j] > 0){
								if(max > cuts[j]){
									valid = false;
									break;
								} 
							} else if (cuts[j]<0){
								cuts[j] = -1*Math.max(-1*cuts[j], max);
							}
						}
					}
				}
				if (valid) {
					out.println("Case #"+k+": YES");
				} else {
					out.println("Case #"+k+": NO");
				}
			}
		} catch (NumberFormatException | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	/*	
		Random ran = new Random();

		int[][] test = new int[10][10];
		for(int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				test[i][j]=10;
			}
		}
		for(int k = 0; k < 100; k++){
			int x = ran.nextInt(10);
			int y = ran.nextInt(9)+1;
			int z = ran.nextInt(2);
			if(z == 0){
				for(int i = 0; i < 10; i++){
					if(test[x][i] > y){
						test[x][i] = y;
					}
				}
			} else {
				for(int i = 0; i < 10; i++){
					if(test[i][x] > y){
						test[i][x] = y;
					}
				}
			}
		}
		for (int i = 0; i < 10; i++){
			System.out.println(Arrays.toString(test[i]));
		}
	*/

	}
}
