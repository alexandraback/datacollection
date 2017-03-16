import java.io.BufferedReader;
import java.io.InputStreamReader;


public class R0_2 {
	
	public static void main(String[] args) {
		
		try {
		
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			
			int T = Integer.parseInt(bf.readLine());
			
			for (int i=0; i<T; i++) {
				
				boolean possible = false;
				
				String[] strTemp = bf.readLine().split(" ");
				
				int N = Integer.parseInt(strTemp[0]);
				int M = Integer.parseInt(strTemp[1]);
				
				int[][] lawn = new int[N][M];
				
				int[] maxRow = new int[N];
				int[] maxColumn = new int[M];
				
				
				for (int j=0; j<N; j++ ) {
					strTemp = bf.readLine().split(" ");
					
					for (int k=0; k<M; k++) {
						lawn[j][k] = Integer.parseInt(strTemp[k]);
						maxRow[j] = Math.max(maxRow[j], lawn[j][k]);
						maxColumn[k] = Math.max(maxColumn[k], lawn[j][k]);
					}
					
				}
				
				possible = true;
				
				for (int j=0; j<N; j++ ) {
					for (int k=0; k<M; k++) {
						if (maxRow[j] > lawn[j][k] && maxColumn[k] > lawn[j][k]) {
							possible = false;
							break;
						}
					}
				}
				
				System.out.println("Case #" + (i+1) + ": " + (possible ? "YES" : "NO"));

			}
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		
		
		
	}
}
