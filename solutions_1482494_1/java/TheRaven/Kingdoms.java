import java.util.*;
public class Kingdoms {
	static boolean flag = true;
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		for (int ii = 1; ii<=T; ++ii) {
			//Something
			int N = sc.nextInt();
			int [] A = new int [N];
			int [] B = new int [N];
			Thing [] C = new Thing [N];
			Thing [] D = new Thing [N];
			for (int i = 0; i<N; ++i) {
				A[i] = sc.nextInt();
				B[i] = sc.nextInt();
				C[i] = new Thing(A[i],B[i]);
				D[i] = new Thing(A[i],B[i]);
			}
			Arrays.sort(C);
			int COINS = 0;
			int OLD_COINS = -1;
			int MOVES = 0;
			boolean [] usedA = new boolean[N];
			boolean [] usedB = new boolean[N];
			A : while (COINS != OLD_COINS) {
				OLD_COINS = COINS;
				for (int i = 0; i<C.length; ++i) {
					if (usedB[i]) continue;
					if (C[i].b <= COINS) {
						COINS+= (usedA[i]) ? 1 : 2;
						MOVES++;
						usedB[i] = true;
						continue A;
					}
				}
				for (int i = 0; i<C.length; ++i) {
					if (usedA[i] || usedB[i]) continue;
					if (C[i].a <= COINS) {
						COINS++;
						MOVES++;
						usedA[i] = true;
						continue A;
					}
				}
			}
			int BEST = MOVES;
			for (int i = 0; i<N; ++i) if (!usedB[i]) BEST = Integer.MAX_VALUE;
			
			
			
			
				 
			
				
			
			
			System.out.printf("Case #%d: %s\n",ii, ((BEST == Integer.MAX_VALUE) ? "Too Bad" : "" + BEST));
		}
	}
	static class Thing implements Comparable<Thing> {
		int a,b;
		public Thing(int aa, int bb) { a=aa;b=bb;}
		public int compareTo(Thing t) {
			if (flag) 
				return (b == t.b) ? t.a - a : t.b-b;
			else
				return (a == t.a) ? b - t.b : a-t.a;
		}
		
	
	}
}