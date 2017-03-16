import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Jamcoin {

	static ArrayList<Long> primes = new ArrayList<>();

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(new File("C:\\Users\\JeffreyChan\\Downloads\\C-small-attempt1.in"));
		//		Scanner scan = new Scanner(System.in);
		int cases = Integer.parseInt(scan.nextLine());

		int length = scan.nextInt();
		int jamNum = scan.nextInt();
		int count = 0;

		StringBuilder jam = new StringBuilder();
		jam.append("1");
		for (int i = 0; i < length - 2; i++) {
			jam.append("0");
		}
		jam.append("1");

		Long limit = (long) Math.pow(2, length);
		Long start = Long.parseLong(jam.toString(), 2);
		calculatePrimes(limit);

		System.out.println("Case #1:");

		while (count < jamNum) {

			if (start % 2 == 1) {
				long[] divisors = new long[9];
				int d = 0;
				boolean isJam = true;
				for (int i = 2; i <= 10; i++) {
					Long l = Long.parseLong(Long.toBinaryString(start), i);
					if (!isPrime(l)) {
						for (long k = 2; k < Math.sqrt(l) + 1; k++) {
							if (l % k == 0) divisors[d] = k;
						}
					} else {
						isJam = false;
					}
					d++;
				}

				if (isJam) {
					System.out.print(Long.toBinaryString(start));
					for (int i = 0; i < 9; i++) {
						System.out.print(" " + divisors[i]);
					}
					System.out.println();

					count++;
				}
			}

			start++;
		}
	}

	public static void calculatePrimes(long limit) {
		primes.add(2L);
		primes.add(3L);

		for (long i = 5; i < Math.sqrt(limit) + 1; i++) {
			if (isPrime(i)) primes.add(i);
		}
	}

	public static boolean isPrime(long i) {
		for (long p : primes) {
			if (i % p == 0) return false;
		}
		return true;
	}
}
