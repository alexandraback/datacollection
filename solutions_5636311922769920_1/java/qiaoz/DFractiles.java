import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class DFractiles {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int T = sc.nextInt();
		for (int i = 1; i <=T; i++){
			int K = sc.nextInt();
			int C = sc.nextInt();
			int S = sc.nextInt();
			if (C*S < K) {
				System.out.printf("Case #%d: IMPOSSIBLE\n", i);
			}
			else{
				System.out.printf("Case #%d:", i);
				int current = K -1;
				for (int j = 0; j < S; j++) {
					long ans = 1;
					long pow = 1;
					for (int k = 0; k < C; k++) {
						ans += Math.max(0, current)*pow;
						current = current - 1;
						pow *= K;
					}
					System.out.printf(" %d", ans);
					if (current < 0) {
						break;
					}
				}
				System.out.println();
			}
			
		}
		
		
		sc.close();
	}
}
