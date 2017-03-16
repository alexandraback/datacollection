import java.io.File;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class A {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "A";
	static final String INPUT = "large";
	static final String ID = "0";
	static final String PATH = "C:\\software installation\\codejam-commandline-1.2-beta1\\source\\";

	public static void main(String args[]) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.print("Case #" + t + ": ");

			BigInteger R = in.nextBigInteger();
			BigInteger T = in.nextBigInteger();

			BigInteger a = new BigInteger("2");
			BigInteger b = R.multiply(new BigInteger("2")).subtract(
					BigInteger.ONE);
			BigInteger c = T.negate();

			BigInteger delta = b.pow(2).subtract(
					a.multiply(c).multiply(new BigInteger("4")));
			BigInteger root = sqrt(delta.toString());

			BigInteger circle = root.subtract(b).divide(
					a.multiply(new BigInteger("2")));

			out.println(circle);
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}

	public static BigInteger sqrt(String number) {
		int length = number.length(), i;
		BigInteger result = BigInteger.ZERO;
		BigInteger twenty = BigInteger.valueOf(20);
		BigInteger t;
		BigInteger x = BigInteger.ZERO;
		BigInteger v;
		BigInteger few = BigInteger.ZERO;
		BigInteger hg = BigInteger.valueOf(100);

		String tmpStr = null;
		int pos = 2 - length % 2;
		tmpStr = number.substring(0, pos);
		while (true) {
			v = few.multiply(hg).add(
					BigInteger.valueOf(Integer.parseInt(tmpStr)));
			if (result.compareTo(BigInteger.ZERO) == 0) {
				i = 9;
			} else {
				i = v.divide(result.multiply(twenty)).intValue();
			}
			for (; i >= 0; i--) {
				t = result.multiply(twenty).add(BigInteger.valueOf(i))
						.multiply(BigInteger.valueOf(i));
				if (t.compareTo(v) <= 0) {
					x = t;
					break;
				}
			}
			result = result.multiply(BigInteger.TEN).add(BigInteger.valueOf(i));
			few = v.subtract(x);
			pos++;
			if (pos > length) {
				break;
			}
			tmpStr = number.substring(pos - 1, ++pos);
		}
		return result;
	}
}
