import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;

public class A
{
	static String FILE_IN = "A-large.in";
	static String FILE_OUT = "A.out";

	static String solve(BufferedReader in) throws IOException
	{

		int N = Integer.parseInt(in.readLine());

		if (N == 0)
			return "INSOMNIA";

		HashSet<Integer> digits = new HashSet<Integer>();
		for (int i = 0; i < 10; i++)
			digits.add(i);

		int i = 0;

		while (!digits.isEmpty())
		{
			int n = N * ++i, digit;

			while (n > 0)
			{
				digit = n % 10;
				if (digits.contains(digit))
					digits.remove(digit);
				n /= 10;
			}
		}

		return String.format("%d", N * i);
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
