import java.util.*;

public class S4 {
	
	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			int T = sc.nextInt();
			for (int i = 1; i <= T; i++) {
				int K = sc.nextInt();
				int C = sc.nextInt();
				int S = sc.nextInt();
				
				System.out.print("Case #");
				System.out.print(i);
				System.out.print(": ");
				
				if (S * C >= K) {
					int running = 0;
					while (running < K) {
						long ans = 0;
						for (int j= 0; j < C; j++) {
							ans = ans * K + (running++ % K);
						}
						System.out.print(ans + 1);
						System.out.print(" ");
					}
				} else {
					System.out.print("IMPOSSIBLE");
				}
				System.out.println();
				
			}
		}
	}

}
