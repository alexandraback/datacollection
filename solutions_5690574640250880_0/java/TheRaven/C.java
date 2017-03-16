import java.util.*;
import java.math.*;
public class C {
	static long MOD = 1000002013;
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		
		for (int ii = 1; ii<=T; ++ii) {
			System.out.printf("Case #%d:\n",ii);
			int R1 = sc.nextInt();
			int C1 = sc.nextInt();
			int C = Math.min(R1, C1);
			int R = Math.max(R1, C1);
			int M = sc.nextInt();
			int NM = R*C - M;
			char [][] board = new char[C][R];
			for (int i = 0; i<C; ++i)
				for (int j = 0; j<R; ++j)
					board[i][j] = '*';
			
			boolean possible = true;
			
			if (C == 1 || NM == 1) {
				for (int i = 0; i<R && NM > 0; ++i, NM--)
					board[0][i] = '.';
					
			} else if (C == 2 || (NM % 2 == 0 && NM <= 2*R)) {
				if (NM % 2 == 1 || NM == 2) { possible = false;}
				
				for (int i = 0; i<R && NM > 0; ++i) {
						board[0][i] = '.';
						board[1][i] = '.';
						NM-=2;
				}
				
			} else {
				possible = false;
				for (int c2 = 3; c2 <= C; ++c2) {
					for(int r2 = 3; r2<=R && !possible; ++r2) {
						if (c2*r2 < NM) continue;
						if (2*r2 + 2*c2 - 4 > NM) continue;
						
						for (int i = 0; i<c2; ++i)
							for (int j = 0; j<r2; ++j)
								board[i][j] = '.';
						
						M -= (C*R - c2*r2);
						for (int i = c2-1; i>=2; --i) {
							for (int j = r2-1; j>=2 && M > 0; --j) {
								board[i][j] = '*';
								M--;
							}
						}
						if (M != 0) System.err.println("???");
						possible = true;
					}
				}
			}
			
			
			board[0][0]= 'c';
			if (possible) {
				for (int i = 0; i<R1; ++i) {
					for (int j = 0; j<C1; ++j) 
						System.out.print( (C == C1) ? board[j][i] : board[i][j]);
					System.out.println();
				}
				
			} else {
				System.out.println("Impossible");
				//System.err.println("Not Possible : " + M + " , " + NM + " : " + R + " , " + C);
			}
		}
	}
}