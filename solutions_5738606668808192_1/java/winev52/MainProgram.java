import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class MainProgram {

	public static long gcd(long a, long b) {
		while (a != 0 && b != 0) // until either one of them is 0
		{
			long c = b;
			b = a % b;
			a = c;
		}
		return a + b; // either one is 0, so return the non-zero value
	}

	public static int j;
	public static int n;
	public static int[] value;
	public static int d;

	public static void main(String args[]) throws FileNotFoundException {
		// System.out.println("yokoso!");

		String inFile = "input.in";
		// String outFile = "output.out";
		// String inFile = "B-small-attempt0.in";
		// String outFile = "C-small-attempt0.out";
		// String inFile = "B-large.in";
		 String outFile = "C-large.out";

		File file = new File(inFile);
		Scanner scan = new Scanner(file);
		PrintWriter writer = new PrintWriter(outFile);

		int t = scan.nextInt();
		scan.nextLine();
		for (int i = 0; i < t; i++) {
			// TODO
			n = scan.nextInt();
			j = scan.nextInt();
			value = new int[n - 2];

			///////
			writer.printf("Case #%d:", i + 1);
			writer.println();

			solve(0, writer);
		}

		writer.close();
	}

	public static BigInteger sqrt(BigInteger x) {
		BigInteger div = BigInteger.ZERO.setBit(x.bitLength() / 2);
		BigInteger div2 = div;
		for (;;) {
			BigInteger y = div.add(x.divide(div)).shiftRight(1);
			if (y.equals(div) || y.equals(div2))
				return y;
			div2 = div;
			div = y;
		}
	}

	/*
	 * public static long isPrime(BigInteger n) { if(n.equals(2) || n.equals(3))
	 * return 0; if(n.mod(BigInteger.valueOf(2)).equals(0)) return 2;
	 * if(n.mod(BigInteger.valueOf(3)).equals(0)) return 3; BigInteger sqrtN =
	 * sqrt(n).add(BigInteger.valueOf(1)); for(BigInteger i =
	 * BigInteger.valueOf(6); i. <= sqrtN; i += 6) { if(n%(i-1) == 0) return
	 * i-1; if(n%(i+1) == 0) return i+1; } return 0; }
	 */

	public static BigInteger isPrime(BigInteger number) {
		if (!number.isProbablePrime(2)) {
			BigInteger two = new BigInteger("2");
			if (!two.equals(number) && BigInteger.ZERO.equals(number.mod(two)))
				return two;

			for (BigInteger i = new BigInteger("3"); i.multiply(i).multiply(i).multiply(i).compareTo(number) < 1; i = i.add(two)) {
				if (BigInteger.ZERO.equals(number.mod(i)))
					return i;
			}

		}

		return BigInteger.ZERO;
	}

	public static void solve(int k, PrintWriter writer) {
		if (k < n - 2 && d < j) {
			for (int i = 0; i < 2; i++) {
				value[k] = i;
				solve(k + 1, writer);
			}
		} else if (d < j) {
			boolean f = false;
			BigInteger[] devide = new BigInteger[11];
			for (int i = 2; i <= 10; i++) {
				BigInteger base = BigInteger.valueOf(i);
				BigInteger s = BigInteger.ONE;
				for (int u = n - 2; u >= 1; u--) {
					if (value[u - 1] == 1) {
						s = s.add(base);
					}
					base = base.multiply(BigInteger.valueOf(i));
				}
				s = s.add(base);

				BigInteger asd = isPrime(s);
				if (asd.equals(BigInteger.ZERO)) {
					f = true;
					break;
				} else {
					devide[i] = asd;
				}
			}

			if (f == false) {
				writer.print("1");
				for (int i = 0; i < value.length; i++)
					writer.printf("%d", value[i]);
				writer.print("1 ");
				for (int i = 2; i <= 10; i++)
					writer.printf("%d ", devide[i]);
				writer.println();
				d++;
				System.out.println("D= " +d);
			}
		}
	}
}

/*
 * qualification 2016
 */

/*
 * B
 */
/*
 * String str = scan.nextLine(); String newstr = ""; for (int u = 0; u<
 * str.length();) { int v = u+1; while (v < str.length() && str.charAt(v) ==
 * str.charAt(u)) v++; newstr = newstr + str.charAt(u); u = v; }
 * 
 * int[] l = new int[newstr.length()]; if (newstr.charAt(0) == '-') l[0] = 1;
 * else l[0] = 0; for (int u = 1; u < newstr.length(); u++) { if
 * (newstr.charAt(u) == '-') l[u] = l[u-1] +2; else l[u] = l[u-1]; }
 */

/*
 * A
 */
/*
 * long n = scan.nextInt(); int d = 1; int l = String.valueOf(n).length(); int[]
 * f = new int['9' - '0' + 1]; // false
 * 
 * long nn = 0; int s = 0; long ll = 1; for (int u = 0; u < l; u++) ll = ll *
 * 10; if (n == 0) { writer.printf("Case #%d: %s", i + 1, "INSOMNIA");
 * 
 * writer.println(); continue; } while (s != 10) { nn = n * d; String str =
 * String.valueOf(nn); for (int u = 0; u < str.length(); u++) if
 * (f[str.charAt(u) - '0'] == 0) f[str.charAt(u) - '0'] = 1; s = 0; for (int u =
 * 0; u < 10; u++) s += f[u]; d++; }
 * 
 * if (s == 10) { writer.printf("Case #%d: %d", i + 1, nn);
 * 
 * writer.println(); } else { writer.printf("Case #%d: %s", i + 1, "INSOMNIA");
 * 
 * writer.println(); }
 */
