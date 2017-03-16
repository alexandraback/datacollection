import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class C
{
	static int findDivisor(BigInteger x)
	{
		for (int i = 2; i < 10000; i++)
			if (x.mod(BigInteger.valueOf(i)).equals(BigInteger.ZERO))
				return i;
		return -1;
		// throw new RuntimeException();
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		sc.nextInt();
		int N = sc.nextInt();
		int J = sc.nextInt();
		System.out.println("Case #1:");
		Set<String> found = new HashSet<String>();
		while (found.size() != J)
		{
			char[] ccand = new char[N];
			for (int i = 0; i < N; i++)
				if (Math.random() < 0.5)
					ccand[i] = '0';
				else
					ccand[i] = '1';
			ccand[0] = '1';
			ccand[N-1] = '1';
			String s = new String(ccand);
			if (found.contains(s))
				continue;
			boolean ok = true;
			for (int base = 2; base <= 10; base++)
			{
				BigInteger b = new BigInteger(s, base);
				if (b.isProbablePrime(40) || findDivisor(b) == -1)
				{
					// System.err.println(s + " fail");
					ok = false;
					break;
				}
			}
			if (ok) {
				found.add(s);
				System.out.print(s);

				for (int base = 2; base <= 10; base++)
				{
					BigInteger x = new BigInteger(s, base);
					System.out.print(" " + findDivisor(x));
				}
				System.out.println();
			}
		}
	}
}