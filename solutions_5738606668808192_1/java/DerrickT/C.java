import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class C
{
	static String FILE_IN = "C-large.in";
	static String FILE_OUT = "C.out";

	static BigInteger findDivisor(BigInteger n)
	{
		if (n.mod(BigInteger.valueOf(2)) == BigInteger.ZERO)
			return BigInteger.valueOf(2);

		for (BigInteger i = BigInteger.valueOf(3); 
				(i.compareTo(BigInteger.valueOf(13))) <= 0; 
				i = i.add(BigInteger.valueOf(2)))
		{
			if (n.mod(i) == BigInteger.ZERO)
				return i;
		}

		return BigInteger.valueOf(-1);
	}

	static String solve(BufferedReader in) throws IOException
	{
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken());
		int J = Integer.parseInt(st.nextToken());

		String strBinary = String.format("1%0" + (N - 1) + "d", 1);
		StringBuilder result = new StringBuilder();
		// J=5;
		while (J > 0)
		{
			StringBuilder s = new StringBuilder(strBinary);

			boolean quit = false;
			for (int i = 2; !quit && i <= 10; i++)
			{
				BigInteger n = new BigInteger(strBinary, i);
				BigInteger divisor = findDivisor(n);

				if (!divisor.equals(BigInteger.valueOf(-1)))
					s.append(" ").append(divisor);
				else
					quit = true;
			}

			if (!quit)
			{
				System.out.println(s);
				result.append("\n").append(s);
				J--;
			}

			BigInteger b = new BigInteger(strBinary, 2);
			strBinary = (b.add(BigInteger.valueOf(2))).toString(2);
		}
		return result.toString();
	}

	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader
				(new FileReader("files/" + FILE_IN));
		PrintWriter out = new PrintWriter(new BufferedWriter
				(new FileWriter("files/" + FILE_OUT)));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++)
		{
			String result = solve(in);
			System.out.printf("Case #%d: %s%n", t, result);
			out.printf("Case #%d: %s%n", t, result);
		}

		System.out.println("Complete");
		in.close();
		out.close();
	}
}
