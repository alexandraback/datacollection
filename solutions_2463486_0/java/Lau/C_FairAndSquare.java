import java.math.BigInteger;
import java.util.Scanner;

public class C_FairAndSquare {

    static BigInteger[] fairAndSquareRoots() {
	BigInteger[] numbers = new BigInteger[100000];
	int i = 0;
	numbers[i++] = BigInteger.valueOf(1);
	numbers[i++] = BigInteger.valueOf(2);
	numbers[i++] = BigInteger.valueOf(3);
	for (int m = 1; m < 50; m++) {
	    for (int n = 0; m / 2 + n < m || n == 0; n++) {
		for (int o = 0; o < n || o == 0; o++) {
		    for (int p = 0; p < o || p == 0; p++) {
			numbers[i++] = BigInteger.TEN.pow(m).
				add(n == 0 ? BigInteger.ZERO : BigInteger.TEN.pow(m / 2 + n)).
				add(o == 0 ? BigInteger.ZERO : BigInteger.TEN.pow(m / 2 + o)).
				add(p == 0 ? BigInteger.ZERO : BigInteger.TEN.pow(m / 2 + p)).
				add(p == 0 ? BigInteger.ZERO : BigInteger.TEN.pow((m + 1) / 2 - p)).
				add(o == 0 ? BigInteger.ZERO : BigInteger.TEN.pow((m + 1) / 2 - o)).
				add(n == 0 ? BigInteger.ZERO : BigInteger.TEN.pow((m + 1) / 2 - n)).
				add(BigInteger.TEN.pow(0));
			if (m % 2 == 0)
			    numbers[i++] = numbers[i - 2].add(BigInteger.TEN.pow(m / 2));
			if (m % 2 == 0 && o == 0)
			    numbers[i++] = numbers[i - 2].add(BigInteger.TEN.pow(m / 2));
		    }
		}
	    }
	    numbers[i++] = BigInteger.TEN.pow(m).add(BigInteger.TEN.pow(0)).multiply(BigInteger.valueOf(2));
	    if (m % 2 == 0)
		numbers[i++] = numbers[i - 2].add(BigInteger.TEN.pow(m / 2));
	}
	numbers[i] = BigInteger.TEN.pow(100);
	return numbers;
    }

    static int answer(Scanner in, BigInteger[] roots) {
	BigInteger A = new BigInteger(in.next());
	BigInteger B = new BigInteger(in.next());
	int indexA = 0;
	int indexB = 0;
	while (roots[indexA++].pow(2).compareTo(A) < 0) {}
	while (roots[indexB++].pow(2).compareTo(B) <= 0) {}
	return indexB-indexA;
    }

    public static void main(String[] args) {
	BigInteger[] roots = fairAndSquareRoots();
	Scanner in = new Scanner(System.in);
	int T = in.nextInt();
	for (int cas = 1; cas <= T; cas++)
	    System.out.println("Case #" + cas + ": " + answer(in, roots));
    }
}
