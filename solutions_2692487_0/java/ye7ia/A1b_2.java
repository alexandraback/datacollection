import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A1b_2
{
	static int[] p;

	static int solve(int c, int i)
	{
		if (i == p.length)
			return 0;
		if (c > p[i])
			return solve(c + p[i], i + 1);
		if (c - 1 > 0)
			return 1 + Math.min(solve(c, i + 1), solve(c + c - 1, i));
		return 1 + solve(c, i + 1);
	}

	public static void main(String[] args) throws FileNotFoundException
	{
		Scanner in = new Scanner(new File("D:\\D\\A-small-attempt1.in"));
		PrintWriter out = new PrintWriter(new File("D:\\D\\output.txt"));
		// Scanner in = new Scanner(System.in);
		// PrintWriter out = new PrintWriter(System.out);
		int ttc = in.nextInt();
		for (int tc = 1; tc <= ttc; tc++)
		{
			int a = in.nextInt(), n = in.nextInt();
			p = new int[n];
			for (int i = 0; i < n; i++)
				p[i] = in.nextInt();
			Arrays.sort(p);
			// out.println("------------------");
			out.printf("Case #%d: ", tc);
			// out.println(a + " " + n + "\n" + Arrays.toString(p));
			out.println(solve(a, 0));
			// out.println("------------------");
		}
		out.close();
	}

}
