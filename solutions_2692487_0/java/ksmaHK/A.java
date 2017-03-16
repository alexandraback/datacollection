import java.util.*;
import java.math.*;

public class A {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	
	for (int nc = 1; nc <= nCase; nc++) {
		long A = scanner.nextLong();
		int N = scanner.nextInt();
		long[] motes = new long[N];
		for (int i = 0; i < N; i++) {
			motes[i] = scanner.nextLong();
		}
		Arrays.sort(motes);
		long ans = 0;
		long oldBest = N;
		for (int i = 0; i < N; i++) {
			if (A == 1) {
				ans = N;
				break;
			}
			oldBest = Math.min(oldBest, ans + N - i);
			if (A > motes[i]) {
				A += motes[i];				
			} else {
				int cnt1 = 0;
				long AA = A;				
				while (AA <= motes[i]) {
					AA += (AA-1);
					cnt1++;
				}
				//System.out.println("AA:" + AA +" cnt1:"+cnt1+" N-i:" +(N-i));
				if (cnt1 <= N - i) {
					A = AA + motes[i];
					
					ans += cnt1;
					if (ans > oldBest)
						break;
				} else {
					ans += (N - i);
					break;
				}
			}
		}
		ans = Math.min(ans, oldBest);
		
		
		System.out.println("Case #" + nc + ": " + ans);
	}
}
}