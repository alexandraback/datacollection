import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;


public class ProblemB {

	public static void main(String args[]) throws Exception{
		BufferedReader reader = new BufferedReader(new FileReader("data/B-large.in"));
		int numberOfTestcase = Integer.parseInt(reader.readLine());
		
		for (int i = 0; i < numberOfTestcase; i++){
			String line = reader.readLine();
			String[] elements = line.split(" ");
			int N = Integer.parseInt(elements[0]);
			int M = Integer.parseInt(elements[1]);
			int[][] matrix = new int[N][M];
			for (int n = 0; n < N; n++){
				line = reader.readLine();
				elements = line.split(" ");
				for (int m = 0; m < M; m++){
					matrix[n][m] = Integer.parseInt(elements[m]);
				}
			}
			
			boolean OK = true;
			for (int n = 0; n < N; n++){
				int left = matrix[n][0];
				int right = matrix[n][M-1];
				for (int m = 0; m < M; m++){
					int value = matrix[n][m];
					int top = matrix[0][m];
					int bottom = matrix[N-1][m];
					
					boolean dependsOnVert = false;
					for (int mm = 0; mm < M; mm++){
						if (value < matrix[n][mm]){
							dependsOnVert = true;
							break;
						}
					}
					boolean dependsOnHorz = false;
					for (int nn = 0; nn < N; nn++){
						if (value < matrix[nn][m]){
							dependsOnHorz = true;
							break;
						}
					}
					
/*					boolean dependsOnVert = false;
					if (value < left || value < right){
						dependsOnVert = true;
					}
					
					boolean dependsOnHorz = false;
					if (value < top || value < bottom){
						dependsOnHorz = true;
					}*/
					if (dependsOnVert && dependsOnHorz){
						System.out.println("Case #" + (i + 1) + ": NO");
						OK = false;
						break;
					}
				}
				if (!OK){
					break;
				}
			}
			if (OK){
				System.out.println("Case #" + (i + 1) + ": YES");
			}
		}
		
		reader.close();
		
	}
}
