import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class A
{
	static String FILE_IN = "A-small-attempt0.in";
	static String FILE_OUT = "A.out";
	
	static int[] a;

	static String solve(BufferedReader in, PrintWriter out) throws IOException
	{
		int n = Integer.parseInt(in.readLine());
		return String.format("%d", a[n]);
	}

	static int reverse(int n)
	{
		int rev = 0;

		while (n > 0)
		{
			rev *= 10;
			rev += n % 10;
			n /= 10;
		}

		return rev;
	}

	public static void main(String[] args) throws IOException
	{
		a = new int[1000001];

		for (int i = 1; i < 1000001; i++)
		{
			int rev = reverse(i);
			if (reverse(rev) == i && a[rev] > 0)
				a[i] = Math.min(a[i - 1] + 1, a[rev] + 1);
			else
				a[i] = a[i - 1] + 1;
		}
		
//		for (int i = 1; i <= 101; i++)
//			System.out.println(i+ ": " + a[i]);

		BufferedReader in = new BufferedReader
				(new FileReader("files/" + FILE_IN));
		PrintWriter out = new PrintWriter(new BufferedWriter
				(new FileWriter("files/" + FILE_OUT)));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++)
		{
			String result = solve(in, out);
			System.out.printf("Case #%d: %s%n", t, result);
			out.printf("Case #%d: %s%n", t, result);
		}

		System.out.println("Complete");
		in.close();
		out.close();
	}
}
