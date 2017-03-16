import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;


public class CoinJam {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		/*int T = sc.nextInt();
		int N = sc.nextInt();
		int J = sc.nextInt();*/
		int T = 1; int N = 16; int J = 50;
		byte[] bits = new byte[N];
		bits[0] = 1;
		bits[N-1] = 1;
		for (int i = 1; i < N-1; ++i)
			bits[i] = 0;
		System.out.println("Case #1:");
		while (true) {
			boolean found = true;
			StringBuilder s = new StringBuilder();
			for (int i = 0; i < N; ++i)
				s.append((char)(bits[i] + '0'));
			String ss = s.toString();
			//System.out.println(" " + ss);
			for (int radix = 2; radix <= 10; ++radix) {
				BigInteger b = new BigInteger(ss, radix);
				//System.out.println("  " + b.toString());
				if (b.isProbablePrime(30)) {
					found = false;
					break;
				}
			}
			if (found) {
				System.out.print(ss);
				for (int radix = 2; radix <= 10; ++radix) {
					BigInteger b = new BigInteger(ss, radix);
					long bb = b.longValueExact();
					if (bb % 2 == 0) {
						System.out.print(" 2");
					} else {
						boolean found2 = false;
						for (int p = 3; p <= bb; p += 2) {
							if (bb % p == 0) {
								System.out.print(" " + p);
								found2 = true;
								break;
							}
						}
						if (!found2)
							System.out.println("ERROR ERROR");
					}
				}
				System.out.println();
				if (--J == 0)
					break;
			}
			for (int i = N-1; i-- > 0;) {
				if (bits[i] == 0) {
					bits[i] = 1;
					break;
				} else {
					bits[i] = 0;
				}
			}
		}
		sc.close();
	}

}
/*
1
6 3
*/