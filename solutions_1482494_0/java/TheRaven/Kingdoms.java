import java.util.*;
public class Kingdoms {
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		for (int ii = 1; ii<=T; ++ii) {
			//Something
			int N = sc.nextInt();
			int [] A = new int [N];
			int [] B = new int [N];
			for (int i = 0; i<N; ++i) {
				A[i] = sc.nextInt();
				B[i] = sc.nextInt();
			}
			
			int BEST = Integer.MAX_VALUE;
			B : for (int i = 0; i<(1<<N); ++i) {
				boolean [] usedA = new boolean [N];
				boolean [] usedB = new boolean [N];
				int COINS = 0;
				int OLD_COINS = -1;
				int MOVES = 0;
				A : while (COINS != OLD_COINS) {
					OLD_COINS = COINS;
					for (int j = 0; j<N; ++j) {
						if ((i & (1<<j)) == 0) continue;
						if (!usedA[j] && A[j] <= COINS) {
							COINS++;
							MOVES++;
							usedA[j] = true;
							continue A;
						}
					}
					for (int j = 0; j<N; ++j) {
						if ((i & (1<<j)) == 0) continue;
						if (!usedB[j] && B[j] <= COINS) {
							COINS++;
							MOVES++;
							usedB[j] = true;
							continue A;
						}
					}
					for (int j = 0; j<N; ++j) {
						if ((i & (1<<j)) != 0) continue;
						if (!usedB[j] && B[j] <= COINS) {
							COINS+=2;
							MOVES++;
							usedB[j] = true;
							continue A;
						}
					}
				}
				for (int j = 0; j<N; ++j) if (!usedB[j]) continue B;
				BEST = Math.min(BEST, MOVES);
				 
				 
			
				
			}
			
			
			
			
					
			
			
			
			
			
			
			
			System.out.printf("Case #%d: %s\n",ii, ((BEST == Integer.MAX_VALUE) ? "Too Bad" : "" + BEST));
		}
	}
}