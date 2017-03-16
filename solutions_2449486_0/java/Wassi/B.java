package qualification;

import java.util.Scanner;

public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int T = s.nextInt();
		for(int t=1;t<=T;t++){
			int N = s.nextInt();
			int M = s.nextInt();
			int[][] target = new int[N][M];
			int[] maxRow = new int[N];
			int[] maxCol = new int[M];
			for (int n=0;n<N;n++){
				for(int m=0;m<M;m++){
					target[n][m] = s.nextInt();
					maxRow[n] = Math.max(maxRow[n],target[n][m]);
					maxCol[m] = Math.max(maxCol[m],target[n][m]);
				}
			}
			boolean possible = true;
			for(int n=0;n<N;n++){
				for(int m=0;m<M;m++){
					if(target[n][m]<maxRow[n] && 
							target[n][m] < maxCol[m]){
						possible = false;
						break;
					}
				}
				if(!possible) break;
				
			}
			System.out.println("Case #" + t + ": " + (possible?"YES":"NO") );
		}
	}

	}
