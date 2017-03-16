import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Lawnmower{

	public static String isPossible(int[][] lawn){
		int n = lawn.length;
		int m = lawn[0].length;
		int[] colrestrict = new int[m];
		int[] rowrestrict = new int[n];
		
		//Setting up some base restrictions
		for(int i = 0; i < n; i++){
			rowrestrict[i] = Lawnmower.findRowMax(lawn, i);
		}
		for(int i = 0; i < m; i++){
			colrestrict[i] = Lawnmower.findColMax(lawn, i);
		}

		// Now we check to see if the restrictions are satisfied
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(lawn[i][j] < rowrestrict[i] && lawn[i][j] < colrestrict[j]){
					return "NO";
				}
			}
		}
		return "YES";
	}//Lawnmower.isPossible()

	private static int findColMax(int[][] lawn, int col){
		int n = lawn.length;
		int max = 1;
		
		for(int i = 0; i < n; i++){
			max = Math.max(max, lawn[i][col]);
		}
		return max;
	}//Lawnmower.findColMax()
	
	private static int findRowMax(int[][] lawn, int row){
		int m = lawn[0].length;
		int max = 1;
		
		for(int i = 0; i < m; i++){
			max = Math.max(max, lawn[row][i]);
		}
		return max;
	}//Lawnmower.findRowMax()
	
	
	public static void main(String[] args) throws IOException{
		// IO preliminaries
		String filename = args[0];
		File file = new File(filename + ".in");
		BufferedReader reader = new BufferedReader(new FileReader(file));
		BufferedWriter writer = new BufferedWriter(new FileWriter(filename + ".out"));
		
		// Actually reading the input and solving
		int numCases = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= numCases; i++){
			int caseNumber = i;
			String[] size = reader.readLine().split(" ");
			int n = Integer.valueOf(size[0]);
			int m = Integer.valueOf(size[1]);
			
			int[][] lawn = new int[n][m];
			for(int j = 0; j < n; j++){
				String[] heights = reader.readLine().split(" ");
				for(int k = 0; k < m; k++){
					lawn[j][k] = Integer.valueOf(heights[k]);
				}
			}

			writer.write("Case #" + caseNumber + ": " + Lawnmower.isPossible(lawn));
			writer.newLine();
		}
		reader.close();
		writer.close();
	}//Lawnmower.main()
}//Lawnmower
