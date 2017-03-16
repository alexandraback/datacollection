import java.util.*;

public class dancing_googlers {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int T = scanner.nextInt();
		int[] answers = new int[T];
		
		for (int c = 0; c < T; c++) {
			
			int N = scanner.nextInt();
			int S = scanner.nextInt();
			int p = scanner.nextInt();
			answers[c] = 0;
			
			for (int i = 0; i < N; i++) {
				int t = scanner.nextInt();
				if (t >= (p + (p - 1) + (p - 1))) {
					answers[c]++;
				}
				else if ((t >= (p + (p - 1) + (p - 1)) - 2) && (S > 0) && (t > 1) && (t < 29)) {
					answers[c]++;
					S--;
				}
			}
		}
		for (int c = 0; c < T; c++) {
			int j = c+1;
			System.out.println("Case #"+j+": "+answers[c]);
		}
	}
}
