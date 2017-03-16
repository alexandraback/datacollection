import java.util.*;
public class C {
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		long [] P = new long [10000000];
		int ptr = 0;
		for (long i = 0; i <= P.length+10; ++i) {
			if (isPalin(i) && isPalin(i*i)) {
				P[ptr++] = i*i;
				//System.err.println(i*i);
			}
		}
		
		for (int ii = 1; ii<=T; ++ii) {
			long A = sc.nextLong();
			long B = sc.nextLong();
			int j1 = Arrays.binarySearch(P, 0, ptr, A);
			int j2 = Arrays.binarySearch(P, 0, ptr, B);
			if (j1 < 0) j1 = -j1 -1;
			if (j2 < 0) j2 = -j2 -2;
			String ans = "" + (j2 - j1 + 1);
			
			
			//Something
			System.out.printf("Case #%d: %s\n",ii,ans);
		}
	}
	
	public static boolean isPalin(long L) {
		char [] s = Long.toString(L).toCharArray();
		for (int i = 0; i<s.length; ++i) if (s[i] != s[s.length-i-1]) return false;
		return true;
	}
}