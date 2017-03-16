import java.math.BigInteger;
import java.util.Scanner;
import java.util.Random;
import java.util.HashSet;

class c {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		Random r = new Random();
		HashSet<String> coins = new HashSet<String>();
		int T, caseCount;
		T = s.nextInt();
		for (caseCount = 1; caseCount <= T; caseCount++) {
			int N, J;
			int yeah = 0;
			StringBuilder sb = new StringBuilder();
			N = s.nextInt();
			J = s.nextInt();
			System.out.println("Case #" + caseCount + ":");
			while (yeah < J) {
				sb.setLength(0);
				sb.append('1');
				for (int i = 2; i < N; i++) sb.append(r.nextBoolean() ? '1' : '0');
				sb.append('1');
				String candidate = sb.toString();
				if (!coins.contains(candidate)) {
					boolean ok = true;
					int[] data = new int[11];
					for (int i = 2; i <= 10; i++) {
						BigInteger examine = new BigInteger(candidate, i);
						if (examine.isProbablePrime(10)) {
							ok = false;
							break;
						} else {
							boolean found = false;
							for (int j = 2; j < 100000; j++) {
								BigInteger jj = BigInteger.valueOf(j);
								if (jj.compareTo(examine) >= 0) {
									ok = false;
									break;
								}
								if (examine.mod(jj).signum() == 0) {
									data[i] = j;
									found = true;
									break;
								}
							}
							if (!found) ok = false;
						}
					}
					if (ok) {
						coins.add(candidate);
						System.out.print(candidate);
						for (int i = 2; i <= 10; i++) {
							System.out.print(" " + data[i]);
						}
						System.out.println();
						yeah++;
					}
				}
			}
		}
	}
}
