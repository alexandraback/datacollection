import java.util.Scanner;


public class A {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			long N = in.nextLong();
			System.out.println("Case #" + (i+1) + ": " + solve(N));
			//System.out.println(N + "-> " + solve(110));
		}
		in.close();
	}

	private static long solve(long n) {
		long result = 0;
		while (true) {
			if (n <= 20) {
				return result + n;
			}
			long fH = getFirstHalf(n);
			long fHR = reverse(fH);
			long reversible = completeDigits(fHR, DigitUtils.numDigits(n));
			if (reversible < n) {
				long reversed = reverse(reversible);
				if (reversed <= n) {
					result += n - reversed;
					if (reversed != reversible) {
						result++;
					}
					n = reversible;
				}
			}
			result++;
			n--;	
		}		
	}

	private static long completeDigits(long n, int numDigits) {
		long base = PowUtils.pow(10, numDigits - 1);
		return base + n;
	}

	private static long getFirstHalf(long n) {
		int numDigits = DigitUtils.numDigits(n);
		int halfDigits = numDigits / 2;
		for (int i = 0; i < numDigits - halfDigits; i++) {
			n /= 10;
		}
		return n;
	}

	private static long reverse(long n) {
		long result = 0;
		while (n > 0) {
			result *= 10;
			result += n % 10;
			n /= 10;
		}
		return result;
	}
}
