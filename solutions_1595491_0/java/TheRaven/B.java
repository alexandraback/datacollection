import java.util.*;
public class B {
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		for (int ii = 1; ii<=T; ++ii) {
			//Something
			int N = sc.nextInt();
			int S = sc.nextInt();
			int p = sc.nextInt();
			int ans = 0;
			
			for (int i = 0;i<N; ++i) {
				int SCORE = sc.nextInt();
				int MAX_NORM = (SCORE == 0) ? 0 : (SCORE-1)/3 + 1;
				if (MAX_NORM >= p) { 
					ans++;
				} else if (SCORE <= 1) {
					//nothing
				} else if (SCORE % 3 != 1 && MAX_NORM+1 >= p && S > 0) {
					ans++;
					S--;
				}
			}
			
			System.out.printf("Case #%d: %s\n",ii,ans);
		}
	}
}