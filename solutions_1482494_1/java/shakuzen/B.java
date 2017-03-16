import java.util.Scanner;
/*
 * CodeJam 2012 Round 1A
 * Coder: Tommy Ludwig
 * Problem B: Kingdom Rush
 */

public class B {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T, N;	//N = how many levels
		T = in.nextInt();
		
		for (int i = 1; i <= T; i++) {
			String y = "Too Bad";
			N = in.nextInt();
			int [] a = new int[N];	//one-star rating required
			int [] b = new int[N];	//two-star rating required
			boolean beatall = true;	//possible to beat all levels
			
			for (int j = 0; j < N; j++) {
				a[j] = in.nextInt();
				b[j] = in.nextInt();
				if (a[j] >= (N*2) || b[j] >= (N*2)) {
					beatall = false;
					break;
				}
			}
			
			int stars = 0;
			int [] levels = new int[N];
			for (int j = 0; j < N; j++)
				levels[j] = 0;
			int turns = 0;	//# of turns required
			
			for (int x = 0; x < (N*2) && beatall; x++) {
				boolean skip = false;
				int max = -1, max_index = -1;
				for (int j = 0; j < N; j++) {
					if (levels[j] == 2)
						continue;
					if (b[j] > max && a[j] <= stars && levels[j] == 0) {
						max = b[j];
						max_index = j;
					}
					
					if (b[j] <= stars) {	//if you have enough stars to beat w/ 2-star rating
						if (levels[j] == 0) {
							stars += 2;
						} else {
							stars++;
						}
						levels[j] = 2;
						turns++;
						skip = true;
						break;
					}
				}
				if (skip)
					continue;
				else if (max_index != -1){
					levels[max_index] = 1;
					stars++;
					turns++;
				}/*
				for (int j = 0; j < N; j++) {
					if (levels[j] >= 1)	//already beaten
						continue;
					if (a[j] <= stars) {	//if you have enough stars to beat w/ 1-star rating ONLY
						stars++;
						levels[j] = 1;
						turns++;
						break;
					}
				} */
			}
			
			for (int j = 0; j < N && beatall; j++) {
				if (levels[j] != 2) {
					beatall = false;
					break;
				}
			}
			if (beatall)
				y = String.valueOf(turns);
			
			System.out.printf("Case #%d: %s\n", i, y);
		}
	}

}
