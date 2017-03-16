import java.util.Scanner;

public class Bullseye {
	public static void main(String[]Z) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for (int N = 1; N <= T; N++) {
			int r = in.nextInt();
			int t = in.nextInt();
			
			int rs = 0;
			int next = 2 * r + 1;
			
			while (t >= next) {
				rs++;
				t -= next;
				r += 2;
				next = 2 * r + 1;
			}
			
			System.out.printf("Case #%d: %d\n", N, rs);
		}
	}
}
