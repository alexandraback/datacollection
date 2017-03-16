import java.io.*;
import java.util.*;

public class test
{

	public static void main(String[] args) throws Exception
	{
		new test().run();
	}

	PrintWriter out = null;
	int N;
	boolean[][] mat = null;
	HashMap<Integer, HashSet<Integer>> hm = new HashMap<Integer, HashSet<Integer>>();

	boolean dfs(int i)
	{
		if (hm.containsKey(i))
			return false;

		hm.put(i, new HashSet<Integer>());

		hm.get(i).add(i);
		for (int j = 0; j < N; j++)
		{
			if (mat[i][j])
			{
				if (dfs(j))
					return true;
				else
				{
					Iterator<Integer> it = hm.get(j).iterator();
					while (it.hasNext())
					{
						int x = it.next();
						if (hm.get(i).contains(x))
							return true;
						else
							hm.get(i).add(x);
					}

				}
			}
		}

		return false;
	}

	void run() throws Exception
	{
		Scanner in = new Scanner(System.in);
		out = new PrintWriter(new FileWriter("gcj.txt"));

		int T = in.nextInt();

		for (int t = 0; t < T; t++)
		{
			mat = null;
			hm.clear();
			N = in.nextInt();

			mat = new boolean[N][N];
			for (int i = 0; i < N; i++)
			{
				int M = in.nextInt();
				for (int j = 0; j < M; j++)
					mat[i][in.nextInt() - 1] = true;
			}

			boolean ret = false;
			for (int i = 0; i < N; i++)
			{
				if (dfs(i))
				{
					ret = true;
					break;
				}
			}
			out.printf("Case #%d: %s\n", t + 1, ret ? "Yes" : "No");
		}

		out.close();
	}

}
