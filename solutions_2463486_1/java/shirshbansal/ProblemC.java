import java.util.Scanner;

public class ProblemC {
	static long a[] = new long[10000000];
	public static void main(String...args) {
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		long x[] = new long[t];
		long y[] = new long[t];
		
		int len = preProcess();
		
		for(int i = 0; i < t; i++) {
			x[i] = scan.nextLong();
			y[i] = scan.nextLong();
			System.out.println(calcResult(a, x[i], y[i], i+1, len));
		}		
	}
	
	private static String calcResult(long[] a, long x, long y, int testCase, int len) {
		int result = 0;
		for(int i = 0; i < len; i++) {
			if(x <= a[i] && a[i] <= y) {
				result++;
			}
		}
		return "Case #" + testCase + ": " + result;
	}

	private static int preProcess() {
		int len = 0;
		for(long i = 1; i < 10000000; i++) {
			if(checkPalin(i) && checkPalin(i * i)) { a[len++] = i*i; }  
		}
		return len;
	}
	private static boolean checkPalin(long num) {
		long x = 0;
		long tmp = num;
		while(tmp != 0) {
			long r = tmp % 10;
			x = x*10 + r;
			tmp /= 10;
		}
		return x == num;
	}
}
