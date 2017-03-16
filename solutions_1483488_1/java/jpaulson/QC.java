import java.util.*;

public class QC {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[][] ROT = new int[2000001][7];
		for(int i=1; i<=2000000; i++) {
			int A = i;
			int pow10 = 1;
			while(A > 0) { pow10*=10; A/=10; }
			pow10 /= 10;
			A = i;
			int ix = 0;
			do {
				if(A < i)
					ROT[i][ix++] = A;
				A = pow10*(A%10)+A/10;
			} while(A != i);
		}
		
		int T = in.nextInt();
		for(int cas=0; cas<T; cas++) {
			int A = in.nextInt();
			int B = in.nextInt();
			long ans = 0;
			Set<Integer> U = new HashSet<Integer>();
			for(int i=A; i<=B; i++) {
				long cnt = 0;
				for(int j=0; j<7; j++) {
					if(ROT[i][j]<i && ROT[i][j]>=A && ROT[i][j]<=B)
						cnt++;
				}
				ans += cnt;
			}
			System.out.println("Case #"+(cas+1)+": "+ans);
		}
	}
}