import java.util.Scanner;
import java.math.BigInteger;

public class AA {
	private static final BigInteger TWO = BigInteger.valueOf(2);
	private static final BigInteger THREE = BigInteger.valueOf(3);
	private static final BigInteger FOUR = BigInteger.valueOf(4);
	private static final BigInteger EIGHT = BigInteger.valueOf(8);

	public static void main(String[] args) {
		int T, i;
		BigInteger r, t, k, b;
		Scanner in = new Scanner(System.in);
		T = in.nextInt();
		for (i = 1; i <= T; i++) {
			System.out.print("Case #" + i + ": ");
			r = new BigInteger(in.next());
			t = new BigInteger(in.next());
			b = BigInteger.ONE.subtract(TWO.multiply(r));
			k = b.add(sqrt((b.pow(2).add(EIGHT.multiply(t))).toString())).divide(FOUR);
			System.out.println(k);
		}
	}

	static String int2str (int i)    // 0 <= i <= 2 ^ 31 -1
	{
		StringBuffer sb = new StringBuffer ("0000000000");
		int digit = 0;
		if (i == 0)
		{
			return "0";
		}
		while (i > 0)
		{
			digit ++;
			int low = i % 10;
			i /= 10;
			sb.setCharAt (10 - digit, (char)(sb.charAt(10 - digit) + low));
		}
		return sb.substring(10 - digit);
	}

	static int isqrt (int x)    // 0 <= x <= 2 ^ 31 -1
	{
		int b, m = 0x40000000, y = 0;
		while (m != 0)
		{
			b = y | m;
			y >>= 1;
			if (x >=b)
			{
				x -= b;
				y |= m;
			}
			m >>= 2;
		}
		return y;
	}

	public static BigInteger sqrt (String str)
	{
		BigInteger bi [] = new BigInteger [3];
		bi [0] = new BigInteger (str);
		int len = str.length ();

		int high = str.charAt(0) - '0';
		if (len % 2 == 0)
		{
			high = high * 10 + str.charAt(1) - '0';
		}

		int r = isqrt (high) + 1;
		int zeros = (len - 1) >> 1;
		str = int2str (r);
		r = str.length ();
		char ch [] = new char [r + zeros];
		for (int i = 0; i < r; i ++)
		{
			ch [i] = str.charAt (i);
		}
		for (int i = r; i < ch.length; i ++)
		{
			ch [i] = '0';
		}
		bi [1] = new BigInteger (new String (ch));

		int i = 1;
		do
		{
			bi [3 - i] = bi [i].pow(2).add (bi [0]).divide (bi [i].shiftLeft (1));
			i = 3 - i;
		} while (bi [i].compareTo (bi [3 - i]) == -1);
		return bi [3 - i];
	}
}
