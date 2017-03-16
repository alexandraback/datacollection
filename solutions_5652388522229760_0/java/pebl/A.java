package codejam.f2016;

import java.util.Scanner;

public class A {

	static boolean[] digits = new boolean[10];
	static int count = 0;
	
	private static long calc(final long n) {
		for(int i=0; i<10; i++)
			digits[i] = false;
		count = 0;
		
		if (n == 0)
			return -1;

		long c = 1;
		while(true) {
			long res = c*n;
			
			while(res != 0) {
				int d = (int) (res % 10);
				res /= 10;
				if (!digits[d]) {
					digits[d] = true;
					count++;
				}
			}
			if (count == 10)
				return c*n;
			c++;
		}
	}

	public static void preprocess(String[] args) {
		for (int n=0; n<10*1000*1000; n++) {
			long ret = calc(n);
			System.out.println(n+": "+ret);
		}
	}

	private static void handleCase(int nr, Scanner scanner) {
		int N = scanner.nextInt();
		
		long ret = calc(N);
		if (ret == -1) {
			System.out.println("Case #"+nr+": INSOMNIA");
		} else {
			System.out.println("Case #"+nr+": "+ret);
		}
	}
	
	public static void main(String[] args) {
		// preprocess(args);
		
		Scanner scanner = new Scanner(System.in);
		int cases = scanner.nextInt();
		
		for(int i=0;i<cases; i++)
			handleCase(i+1,scanner);
	}

}
