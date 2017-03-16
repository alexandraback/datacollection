package qualifs;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

public class Lawnmower {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String fileName = "../B-small-attempt0.in";
		Scanner sC = null;
		try {
			sC = new Scanner(new File(fileName));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		sC.useLocale(Locale.US);
		
		int T = sC.nextInt();
		int N, M;
		
		for(int t = 0; t < T; t++){
			N = sC.nextInt();
			M = sC.nextInt();
			int[][] lawn = new int[N][M];
			int[] maxL = new int[N];
			int[] maxC = new int[M];
			for(int i = 0; i < N; i++){
				for(int j = 0; j < M; j++){
					lawn[i][j] = sC.nextInt();
					if(lawn[i][j] > maxL[i]) maxL[i] = lawn[i][j];
					if(lawn[i][j] > maxC[j]) maxC[j] = lawn[i][j];
				}
			}
			
			String result = "Case #" + (t + 1) + ": ";
			
			boolean possible = true;
			
			for(int i = 0; i < N; i++){
				for(int j = 0; j < M; j++){
					if(maxL[i] > lawn[i][j] && maxC[j] > lawn[i][j]){
						possible = false;
						break;
					}
				}
				if(!possible) break;
			}
			
			if(possible)
				result += "YES";
			else
				result += "NO";
			
			System.out.println(result);
		}
	}

}
