import java.util.Scanner;


public class B {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testNum = scan.nextInt();
		for (int test = 1; test <= testNum; test++) {
			scan.nextLine();
			int a = scan.nextInt();
			int b = scan.nextInt();
			int k = scan.nextInt();
			int la = 0, lb = 0, lk = 0;
			for (int i = 1; i < 32; i++) {
				if (a >> i > 0) {
					la++;
				}
				if (b >> i > 0) {
					lb++;
				}
				if (k >> i > 0) {
					lk++;
				}
			}
			int minl = Math.min(la, Math.min(lb, lk));
			int minValue = 1;
			for (int i = 0; i < minl; i++) {
				minValue = 2 * minValue;
			}
			long res = minValue * minValue;
			for (int i = minValue; i < a; i++) {
				for (int j = 0; j < b; j++) {
					if ((i & j) < k) {
						res++;
					}
				}
			}
			for (int i = 0; i < minValue; i++) {
				for (int j = minValue; j < b; j++) {
					if ((i & j) < k) {
						res++;
					}
				}
			}
			System.out.println("Case #" + test + ": " + res);
		}
		scan.close();
	}
	
}
