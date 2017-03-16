import java.util.Scanner;

public class ProbC {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();

		int R = in.nextInt();
		int N = in.nextInt();
		int M = in.nextInt();
		int K = in.nextInt();

		int[][] prods = new int[R][K];
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < K; j++) {
				prods[i][j] = in.nextInt();
			}
		}

		System.out.println("Case #1:");

		for (int r = 0; r < R; r++) {
			int max1 = 1;
			int max2 = 1;
			int max3 = 1;
			int minscore = Integer.MAX_VALUE;
			for (int x1 = 2; x1 <= 5; x1++) {
				for (int x2 = 2; x2 <= 5; x2++) {
					for (int x3 = 2; x3 <= 5; x3++) {
						int count1 = 0;
						int count2 = 0;
						int count3 = 0;
						boolean valid = true;
						for (int prod : prods[r]) {
							boolean used1 = false;
							boolean used2 = false;
							boolean used3 = false;
							if (prod == x1) {
								used1 = true;
							} 
							if (prod == x2) {
								count2++;
								used2 = true;
							} 
							if (prod == x3) {
								used3 = true;
							} 
							if (prod == x1*x2) {
								used1 = true;
								used2 = true;
							} 
							if (prod == x1*x3) {
								used1 = true;
								used3 = true;
							} 
							if (prod == x2*x3) {
								used2 = true;
								used3 = true;
							} 
							if (prod == x1*x2*x3) {
								used1 = true;
								used2 = true;
								used3 = true;
							}
							if (!(used1 || used2 || used3) && prod != 1) {
								valid = false;
								break;
							}
							count1 += used1?1:0;
							count2 += used2?1:0;
							count3 += used3?1:0;
						}
						if (valid) {
							int dif1 = K - 2 * count1;
							int dif2 = K - 2 * count2;
							int dif3 = K - 2 * count3;
							int score = dif1 * dif1 + dif2 * dif2 + dif3 * dif3;
							if (score < minscore) {
								minscore = score;
								max1 = x1;
								max2 = x2;
								max3 = x3;
							}
						}
					}
				}
			}
			System.out.printf("%d%d%d%n", max1, max2, max3);
		}
	}
}
