import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class A
{
	static LL[] el = null;
	static long[][] ways = null;
	static class LL extends LinkedList<Integer>{}
	public static long compute(int i, int j)
	{
		if (i == j) return 1;
		if (ways[i][j] == -1)
		{
			long tot = 0;
			for (int k : el[i])
			{
				tot += compute(k, j);
			}
			if (tot > 2) ways[i][j] = 2;
			else ways[i][j] = tot;
		}
		return ways[i][j];
	}
	public static void main(String[] args) throws Exception
	{
		//BufferedReader br = new BufferedReader(new InputStreamReader(in));
		Scanner sc = new Scanner(in);
		PrintStream ps = new PrintStream(new BufferedOutputStream(out));
		int cases = sc.nextInt();
		for (int c = 1; c <= cases; c++)
		{
			int n = sc.nextInt();
			el = new LL[n];
			ways = new long[n][n];
			for (int i = 0; i < n; i++) Arrays.fill(ways[i], -1);
			for (int i = 0; i < n; i++) el[i] = new LL();
			for (int i = 0; i < n; i++)
			{
				el[i] = new LL();
				int next = sc.nextInt();
				for (int j = 0; j < next; j++)
				{
					el[i].add(sc.nextInt()-1);
				}
			}
			boolean ok = false;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i == j) continue;
					if (compute(i, j) > 1)
					{
						ok = true;
						i = n;
						break;
					}
				}
			}
			ps.printf("Case #%d: %s\n",  c, ok?"Yes":"No");
		}
		ps.flush();
	}
}
