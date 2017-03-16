package qualification;

import java.util.Scanner;

public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			
			int a[][] = new int[N][M];
			for (int j = 0; j < N; j++) {
				for (int j2 = 0; j2 < M; j2++) {
					a[j][j2] = sc.nextInt();
				}
			}
			
			boolean bp = true;
			o:
			for (int j = 0; j < N; j++) {
				for (int j2 = 0; j2 < M; j2++) {
					int h = a[j][j2];
					
					boolean bd = true;
					for (int k = 0; k < N; k++) {
						if (k != j) {
							if (a[k][j2] > h) {
								bd = false;
								break;
							}
						}
					}
					if (bd) {
						continue;
					}
					
					bd = true;
					for (int k = 0; k < M; k++) {
						if (k != j2) {
							if (a[j][k] > h) {
								bd = false;
								break;
							}
						}
					}
					if (bd) {
						continue;
					}
					
					bp = false;
					break o;
				}
			}
			
			System.out.println("Case #" + i + ": " + (bp ? "YES" : "NO"));
		}
	}

}
