import java.util.*;
import java.math.*;
public class C {
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		int ptr = 0;
		
		
		
		for (int ii = 1; ii<=T; ++ii) {
			int R = sc.nextInt();
			int N = sc.nextInt();
			int M = sc.nextInt();
			int K = sc.nextInt();
			System.out.printf("Case #%d:\n", ii);
			
			for (int iii = 0; iii<R; ++iii) {
			 int [] prod = new int [K];
			 for (int i = 0; i<K; ++i) prod[i] = sc.nextInt();
			 int [] A = new int [N];
			 Arrays.fill(A, 2);
			
			 String ans = "";
			 A : do {
				if (works(A, prod)) {
					for (int i : A) ans += i;
					break A;
		 		}
			 } while (next(A,M));
			 System.out.printf("%s\n",ans);
			}
		}
	}
	static boolean works (int [] A, int [] p) {
		boolean [] done = new boolean [p.length];
		for (int i = 0; i< 1<<(A.length); ++i) {
			int prod = 1;
			for (int j = 0; j<A.length; ++j) {
				if ((i & (1<<j)) != 0) prod *= A[j];
			}
			for (int j = 0; j<p.length; ++j) if (p[j] == prod) done[j]= true;
		
		}
		for (int j = 0; j<p.length; ++j) if (!done[j]) return false;
		return true;
	}
	static boolean next(int [] A, int M) {
		int i = 0;
		for (i = 0; i<A.length; ++i) {
			A[i]++;
			if (A[i] > M) A[i] = 2; 
			else break;
		}
		return (i != A.length);
	}
	
}