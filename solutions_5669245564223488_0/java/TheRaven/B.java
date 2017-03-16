import java.util.*;
import java.math.*;
public class B {
	static long MOD = 1000000007;
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		
		
		
		for (int ii = 1; ii<=T; ++ii) {
			int N = Integer.parseInt(sc.nextLine());
			String s = sc.nextLine();
			String [] b = s.split(" ");
			char [][] tmp = new char [b.length][];
			for (int i = 0; i<b.length; ++i) tmp[i] = b[i].toCharArray();
			
			
			int [] A = new int [N];
			for (int i = 1; i<=N; ++i) A[i-1] = i-1;
			int count = 0;
			count += (works(A,b));
			while (next(A)) {
				//System.err.println(Arrays.toString(A));
				count += (works(A,b));
			}
			
			System.out.printf("Case #%d: %d\n",ii,count);
		}
	}
	
	
	public static int works(int [] P, String [] s) {
		int count = 0;
		StringBuilder b = new StringBuilder(100);
		for (int i = 0; i<s.length; ++i) {
			b = b.append(s[P[i]]);
		}
		return ((valid(b.toString())) ?1 : 0);
		
	}
	public static boolean valid (String s) {
		boolean [] used = new boolean [256];
		char [] tmp = s.toCharArray();
		used[tmp[0]] = true;
		for (int i = 1; i<s.length(); ++i) {
			if (tmp[i] == tmp[i-1]) continue;
			if (used[tmp[i]]) return false;
			used[tmp[i]] = true;
		
		}
		return true;
	}
	
	public static boolean next(int [] A) {
		
		for (int i = A.length-2; i>=0; --i) {
			if (A[i] > A[i+1]) continue;
				

			int bestj = i+1;
			for (int j = i+2; j<A.length; ++j) if (A[j] < A[bestj] && A[j] > A[i]) bestj = j;
			int tmp = A[i];
			A[i] = A[bestj];
			A[bestj] = tmp;
			Arrays.sort(A, i+1, A.length);
			
			return true;
		}
		return false;
	}

	
	

	
}