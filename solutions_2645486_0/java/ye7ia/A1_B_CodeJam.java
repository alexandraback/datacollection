import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A1_B_CodeJam
{
	static int e, r, n;
	static int[] v;

	public static int solve(int i, int c)
	{
		if (i == n)
			return 0;
		if (c < 0)
			return 0;
		int sol = 0;
		for (int j = 0; j <= c; j++)
		{
			sol = Math.max(sol, v[i] * j +  solve(i + 1, Math.min(e, c - j + r)));
		}
		return sol;
	}

	public static void main(String[] args) throws FileNotFoundException
	{
		 Scanner in = new Scanner(new File("D:\\D\\B-small-attempt0 (1).in"));
		 PrintWriter out = new PrintWriter(new File("D:\\D\\output.txt"));
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		int t = in.nextInt();
		for (int tc = 1; tc <= t; tc++)
		{
			e = in.nextInt();
			r = in.nextInt();
			n = in.nextInt();
			v = new int[n];
			for (int i = 0; i < n; i++)
				v[i] = in.nextInt();
			out.printf("Case #%d: ", tc);
			out.println(solve(0, e));
		}
		out.close();

	}
}
