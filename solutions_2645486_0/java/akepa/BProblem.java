import java.util.Scanner;


public class BProblem {


	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int testCases = sc.nextInt();

		for (int tcase = 1; tcase <= testCases; tcase++) {
			
			int e = sc.nextInt();
			int r = sc.nextInt();
			int n = sc.nextInt();
			
			int [][] matrix = new int[n][e+1];
			int [] value = new int[n];
			for(int i = n-1; i >= 0; i--){
				value[i] = sc.nextInt();
			}
			
			// Calculo de los valores previos
			
			for(int i = 0; i <= e; i++){
				matrix[0][i] = i*value[0];
			}
			for(int i = 1; i < n; i++ ){
				for(int j = 0; j <= e; j++){
					
					int maxacum = 0;
					for(int k = 0; k <= j; k++){ // gastas
						int ne = Math.min(e, j-k+r);
						if(value[i]*k+matrix[i-1][ne] > maxacum){
							maxacum = value[i]*k+matrix[i-1][ne];
						}
					}
					
					matrix[i][j] = maxacum;
					
				}
			}
			int result = 0;
			for(int i = 0; i <= e; i++){
				if(matrix[n-1][i] > result) result = matrix[n-1][i];
			}

			System.out.println("Case #" + tcase + ": " + result);
		}


	}

}
