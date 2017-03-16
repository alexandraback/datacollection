import java.util.Scanner;


public class B {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int T = scan.nextInt();
		
		int[] shellSizes = new int[25000];
		shellSizes[0] = 1;
		for(int i = 1; i < 25000; i++) {
			shellSizes[i] = shellSizes[i - 1] + 4 * i + 1;
//			System.out.println(shellSizes[i]);
		}
		
		for(int Q = 1; Q <= T; Q++) {
			int N = scan.nextInt();
			int X = scan.nextInt();
			int Y = scan.nextInt();
			
			int K = 0;
			while(shellSizes[K] <= N) K++;
			
			int k = (Math.abs(X) + Y) / 2;

			if(k < K) {
				System.out.printf("Case #%d: 1.0\n", Q);
				continue;
			} else if(k > K) {
				System.out.printf("Case #%d: 0.0\n", Q);
				continue;
			}
			
			int R = N - shellSizes[K - 1];
			Y++;
			
//			System.out.printf("2K=%d R=%d Y=%d\n", 2*K, R, Y);
			
			// build dynamic table!
			
			if(R < Y) {
				System.out.printf("Case #%d: 0.0\n", Q);
				continue;
			}
			
			double[][] prob = new double[R+1][2*K+1];
			
			prob[0][0] = 1;
			for(int i = 1; i < Y; i++) prob[i][0] = 0;
			
			
			for(int i = 1; i <= R; i++) {
				for(int j = 0; j <= 2*K; j++) {
					double p = 0;
					int l = i - j;
					
					if (l > 2*K) {
						prob[i][j] = 0;
						continue;
					}
					
					if(j > 0) { // drop in j happened
						if(l == 2 * K) p += prob[i - 1][j - 1];
						else p += prob[i - 1][j - 1] / 2;
					}
					
					if(l > 0) { // drop in l happened
						if(j == 2 * K) p += prob[i - 1][j];
						else p += prob[i - 1][j] / 2;
					}
					
					prob[i][j] = p;
//					System.out.printf("%.3f ", p);
				}
//				System.out.println();
			}
			
			double out = 0;
			for(int i = Y; i <= 2*K; i++) out += prob[R][i];
			
			// print the whole damn grid
			
			System.out.printf("Case #%d: %f\n", Q, out);
		}
	}
}
