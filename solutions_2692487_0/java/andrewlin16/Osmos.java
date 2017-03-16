import java.util.*;

public class Osmos {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for (int t = 1; t <= T; t++) {
			int A = in.nextInt();
			int N = in.nextInt();
			
			int[] motes = new int[N];
			
			for (int n = 0; n < N; n++) {
				motes[n] = in.nextInt();
			}
			
			Arrays.sort(motes);
			
			System.out.printf("Case #%d: %d\n", t, moves(A, motes, 0));
		}
	}
	
	public static int moves(long A, int[] motes, int i) {
		// done
		if (i >= motes.length) {
			return 0;
		}
		
		// absorb
		if (A > motes[i]) {
			return moves(A + motes[i], motes, i+1);
		}
		
		// avoid trap answer when A = 1 - cannot add!
		if (A == 1) {
			return motes.length;
		}
		
		// compare moves_add and moves_delete, return better answer
		int add = moves(A * 2 - 1, motes, i) + 1;
		return Math.min(add, motes.length - i);
	}
}
