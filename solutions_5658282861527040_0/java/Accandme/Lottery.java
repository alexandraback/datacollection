
import java.util.Scanner;


public class Lottery {

	public static void main(String[] args) {
		Scanner s = new Scanner(Logger.in);
		int T = s.nextInt();
		for(int t = 0; t < T; t++) {
			int A = s.nextInt();
			int B = s.nextInt();
			int K = s.nextInt();
			int count = 0;
			for(int a = 0; a < A; a++) {
				for(int b = 0; b < B; b++) {
					if((a & b) < K)
						count++;
				}
			}
			Logger.out.println("Case #" + (t + 1) + ": " + count);
		}
		s.close();
	}
	

}
