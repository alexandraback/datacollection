import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class JamcoinLarge {

	static ArrayList<BigInteger> primes = new ArrayList<>();
	static OutputStream os = null;
	static PrintStream ps = null;

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(new File("C:\\Users\\JeffreyChan\\Downloads\\C-large.in"));
		//		Scanner scan = new Scanner(System.in);
		os = new FileOutputStream("C:\\Users\\JeffreyChan\\Desktop\\coinOutput.txt");
		ps = new PrintStream(os);
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

		BigInteger limit = new BigInteger("100");
		BigInteger start = new BigInteger(jam.toString(), 2);

		ps.println("Case #1:");

		while (count < jamNum) {

			BigInteger[] divisors = new BigInteger[9];
			int d = 0;
			boolean badCoin = true;
			for (int i = 2; i <= 10; i++) {
				boolean isJam = false;
				BigInteger l = new BigInteger(start.toString(2), i);

				if (l.mod(BigInteger.valueOf(2L)).equals(BigInteger.ZERO)) {
					divisors[d] = new BigInteger("2");
					isJam = true;
					badCoin = false;
				}

				if (!isJam) {
					for (BigInteger k = new BigInteger("3"); k.compareTo(limit) < 0; k = k.add(BigInteger.valueOf(2L))) {
						if (l.mod(k).equals(BigInteger.valueOf(0))) {
							divisors[d] = new BigInteger(k.toString(10));
							badCoin = false;
							break;
						}
					}
				}

				if (badCoin) {
					break;
				} else {
					badCoin = true;
					d++;
				}

			}

			if (d == 9) {
				StringBuilder sb = new StringBuilder();
				sb.append(start.toString(2));
				for (int i = 0; i < 9; i++) {
					sb.append(" " + divisors[i]);
				}

				ps.println(sb.toString());
				count++;
				//				System.out.println(count);
				//				System.out.println(sb.toString());

			}

			start = start.add(BigInteger.valueOf(2L));
		}

		System.out.println("DONE");
	}

	//	public static void calculatePrimes(BigInteger limit) {
	//		primes.add(BigInteger.valueOf(2));
	//		primes.add(BigInteger.valueOf(3));
	//
	//		BigInteger i = new BigInteger("5");
	//		BigInteger j = new BigInteger("100001");
	//		for (; i.compareTo(limit) < 0; i = i.add(BigInteger.valueOf(2L))) {
	//			if (i.mod(j).equals(BigInteger.ZERO)) System.out.println(i.toString());
	//			if (isPrime(i)) primes.add(i);
	//		}
	//	}
	//
	//	public static boolean isPrime(BigInteger i) {
	//		for (BigInteger p : primes) {
	//			if (i.mod(p).equals(BigInteger.ZERO)) return false;
	//		}
	//		return true;
	//	}
}
