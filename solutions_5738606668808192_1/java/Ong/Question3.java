package code.jam;

import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Question3 {
	private static String path = "C:\\Users\\Ong Keng Chai\\Documents\\property\\codeJam\\src\\code\\jam\\";
	
	private static long[] primes = new long[] {
			2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
			43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109,
			113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
			191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257,
			263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337,
			347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419,
			421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491,
			499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587,
			593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
			661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751,
			757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839,
			853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937,
			941, 947, 953, 967, 971, 977, 983, 991, 997
	};
	
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File(path + "input.txt"));
		PrintWriter out = new PrintWriter(new File(path + "output.txt"));
		
		int caseCount = in.nextInt();
		in.nextLine();
		for (int caseInstance = 1; caseInstance <= caseCount; caseInstance++) {
			System.out.println("======== case " + caseInstance);
			String line = in.nextLine();
			Scanner lineScanner = new Scanner(line);
			
			int n = lineScanner.nextInt();
			int j = lineScanner.nextInt();
			
			out.println("Case #" + caseInstance + ":");
			int count = 0;
			BigInteger max = BigInteger.valueOf(2);
			max = max.pow(n - 2);
			BigInteger num = BigInteger.ZERO;
			while (num.compareTo(max) < 0) {
				String numStr = num.toString(2);
				while (numStr.length() < n - 2) {
					numStr = "0" + numStr;
				}
				numStr = "1" + numStr + "1";
				System.out.print(numStr + " ");
				
				StringBuilder factors = new StringBuilder();
				boolean isJam = true;
				for (int radix = 2; radix <= 10; radix++) {
					BigInteger numRadix = new BigInteger(numStr, radix);
					System.out.print(numRadix + "(");
					
					double maxPrime = Math.sqrt(numRadix.doubleValue());
					long factor = 0;
					for (long prime : primes) {
						if (prime > (long) maxPrime) {
							break;
						}
						BigInteger[] div = numRadix.divideAndRemainder(BigInteger.valueOf(prime));
						if (div[1].equals(BigInteger.ZERO)) {
							System.out.print(prime);
							factors.append(" ").append(prime);
							factor = prime;
							break;
						}
					}
					System.out.print(") ");
					if (factor == 0) {
						isJam = false;
						break;
					}
				}
				System.out.println();
				if (isJam) {
					out.print(numStr);
					out.print(factors);
					out.println();
					count++;
					if (count >= j) {
						break;
					}
				}
				
				num = num.add(BigInteger.ONE);
			}
			
			lineScanner.close();
		}
		in.close();
		out.close();
	}
}