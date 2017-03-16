package gcj2013.B;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Lawnmower {
	public static void main(String args[]) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(args[0]));
		
		int T = scanner.nextInt();
		for(int t=0; t<T; t++) {
			int N = scanner.nextInt();
			int M = scanner.nextInt();
			int[][] lawn = new int[N][];
			for(int i=0; i<N; i++) {
				lawn[i] = new int[M];
				for(int j=0; j<M; j++) {
					lawn[i][j] = scanner.nextInt();
				}
			}
			
			boolean result = check(lawn);
			
			System.out.println("Case #" + (t+1) + ": " + (result?"YES":"NO"));
		}
	}
	
	private static boolean check(int[][] lawn) {
		for(int i=0; i<lawn.length; i++) {
			for(int j=0; j<lawn[i].length; j++) {
				// Can we cut this square the desired height?
				int height = lawn[i][j];
				for(int k=0; k<lawn.length; k++) {
					if(lawn[k][j] > height) {
						// Cannot cut in line - Try in column
						for(int l=0; l<lawn[i].length; l++) {
							if(lawn[i][l] > height) {
								return false;
							}
						}
					}
				}
			}
		}
		return true;
	}
}
