package round1b;

import java.util.Scanner;

public class Lottery {
	
	private static int test(Scanner scanner) {
		int A = scanner.nextInt();
		int B = scanner.nextInt();
		int K = scanner.nextInt();
		int count = 0;
		for (int a = 0; a < A; a++) {
			for (int b = 0; b < B; b++) {
				if ((a & b) < K) {
					count++;
				}
			}
		}
		return count;
	}
	
	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in))
		{
			int cntTests = scanner.nextInt();
			for (int i = 0; i < cntTests; i++) {
				int result = test(scanner);
				System.out.println("Case #" + (i+1) + ": " + result);
			}
		}
	}

}
