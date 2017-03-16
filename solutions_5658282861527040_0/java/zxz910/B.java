import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;


public class B {
	public static void main(String[] args) {
		
		//read in input
		Scanner scanner = new Scanner(new BufferedInputStream(System.in));
		int n = scanner.nextInt();
		
		for (int i = 0; i < n; i++) {
			System.out.print("Case #" + (i+1) + ": ");
			/*BigInteger A = BigInteger.valueOf(scanner.nextInt());
			BigInteger B = BigInteger.valueOf(scanner.nextInt());
			BigInteger K = BigInteger.valueOf(scanner.nextInt());*/
			long A = scanner.nextLong();
			long B = scanner.nextLong();
			long K = scanner.nextLong();
			
			BigInteger bA = BigInteger.valueOf(A);
			BigInteger bB = BigInteger.valueOf(B);
			BigInteger bK = BigInteger.valueOf(K);
			
			BigInteger count = BigInteger.ZERO;
			if (A < K || B < K) {
				count = bA.multiply(bB);
			}

			else {
				count = bK.multiply(bA.add(bB).subtract(bK));
				for (long j = K; j < A; j++) {
					for (long k = K; k < B; k++) {
						if ((j & k) < K) {
							count = count.add(BigInteger.ONE);
						}
					}
				}
			}
			/*for (long j = 0; j < A; j++) {
				if (j < K) {
					count = count.add(BigInteger.valueOf(B));
				}
				for (long k = 0; k < B; k++) {
					if ((j & k) < K) {
						count = count.add(BigInteger.ONE);
					}
				}
			}*/
			
			System.out.println(count);
		}
	}
}
