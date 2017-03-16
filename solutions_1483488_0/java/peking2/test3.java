import java.io.*;
import java.util.*;

public class test3
{

	public static void main(String[] args) throws Exception
	{
		new test3().run();
	}

	PrintWriter out = null;

	int getCount(int d, int max)
	{
		String s = Integer.toString(d);
		int n = s.length();

		HashSet<Integer> hs = new HashSet<Integer>();
		for (int i = 1; i < n; i++)
		{
			StringBuffer sb = new StringBuffer();
			sb.append(s.substring(n - i, n));
			sb.append(s.substring(0, n - i));

			int b = Integer.parseInt(sb.toString());

			if (b > d && b <= max)
				hs.add(b);
		}

		return hs.size();
	}

	void run() throws Exception
	{
		Scanner in = new Scanner(System.in);
		out = new PrintWriter(new FileWriter("codejam.txt"));

		int T = in.nextInt();
		for (int i = 0; i < T; i++)
		{
			int A = in.nextInt();
			int B = in.nextInt();
			int total = 0;
			for (int j = A; j <= B; j++)
				total += getCount(j, B);

			out.printf("Case #%d: %d\n", i + 1, total);
		}
		out.close();
	}
}
