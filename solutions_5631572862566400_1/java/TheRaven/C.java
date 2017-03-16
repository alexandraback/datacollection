import java.util.*;
public class C {
	static boolean [] vis;
	static boolean [] dead;
	static int[][] ENDSIN;
	static int[] stack;
	static int[] G;
	static int last_val = 0;
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		for (int ii = 1; ii<=T; ++ii) {
			
			int N = sc.nextInt();
			G = new int [N+1];
			int [] D = new int [N+1];
			ENDSIN = new int [N+1][];
			vis = new boolean [N+1];
			dead = new boolean [N+1];
			for (int i = 1; i<=N; ++i) {
				G[i] = sc.nextInt();
				D[G[i]]++;
			}
			
			// Find all loops.
			int loopmax = 0;
			for (int i = 1; i<=N; ++i) {
				int L = C.visitLoop(i);
				if (L > 0) C.visit(i);
				if (L < 0) L = -L;
				loopmax = Math.max(L, loopmax);
			}
			
			int ans = 0;
			
			for (int i = 1; i<=N; ++i) {
				if (vis[i]) continue;
				int ONE = G[i];
				int TWO = G[ONE];
				int ONE_AGAIN = G[TWO];
				if (ONE != ONE_AGAIN) continue;
				//System.err.println("Evaluating doublechain for pair " + ONE + " , " + TWO);
				
				int [] MAX1 = C.findMaxEndsIn(ONE, N);
				int [] MAX2 = C.findMaxEndsIn(TWO, N);
				//System.err.println("Found on both sides " + MAX1[0] + " , " + MAX2[0]);
				//System.err.println("With Locations " + MAX1[1] + " , " + MAX2[1]);
				
				if (MAX1[1] > 0) ans += C.visit(MAX1[1]);
				if (MAX2[1] > 0) ans += C.visit(MAX2[1]);
			}
			int MAX = Math.max(ans, loopmax);
			
			System.out.printf("Case #%d: %d\n", ii, MAX);
		}
	}
	
	public static int visit(int i) {
		int count = 0;
		while (!vis[i]) {
			count++;
			vis[i]=true;
			i = G[i];
		}
		return count;
	}
	
	public static int visitLoop(int i) {
		boolean [] vis2 = new boolean[vis.length];
		int start = i;
		int count = 0;
		int prev = i;
		while (!vis2[i]) {
			count++;
			vis2[i]=true;
			prev = i;
			i = G[i];
		}
		if (prev == G[i]) {
			int [] ans = {i, prev, count};
			ENDSIN[start] = ans;
			return -count;
		} else if (i == start) {
			int [] ans = {-1, start, 0};
			ENDSIN[start] = ans;
			return count;
		} else {
			int [] ans = {-1, -1, 0};
			ENDSIN[start] = ans;
		}
		return 0;
	}
	
	public static int [] findMaxEndsIn(int ONE, int N) {
				int [] MAX1 = {-1, -1};
				for (int j = 1; j<=N; ++j) {
					if (ENDSIN[j][0] == ONE) {
						if (MAX1[0] < ENDSIN[j][2]) {
							MAX1[0] = ENDSIN[j][2];
							MAX1[1] = j;
						}
					}
				}
		return MAX1;
	}
}