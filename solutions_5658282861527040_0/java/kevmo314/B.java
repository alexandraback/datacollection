import java.util.Scanner;


public class B {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int t = 0; t < T; t++) {
			int A = in.nextInt();
			int B = in.nextInt();
			int K = in.nextInt();
			
			int count = 0;
			for(int a = 0; a < A; a++) {
				for(int b = 0; b < B; b++) {
					if((a & b) < K) {
						count++;
					}
				}
			}
			System.out.println("Case #" + (t + 1) + ": " + count);
		}
	}
}
