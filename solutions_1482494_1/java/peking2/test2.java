import java.io.*;
import java.util.*;

class Pair implements Comparable<Pair>
{
	int id;
	int a;
	int b;

	public Pair(int _id, int _a, int _b)
	{
		id = _id;
		a = _a;
		b = _b;
	}

	public int compareTo(Pair o)
	{
		return o.b - b;
	}
}

public class test2
{

	public static void main(String[] args) throws Exception
	{
		new test2().run();
	}

	PrintWriter out = null;

	int play(int N, Pair[] pairs)
	{
		HashSet<Integer> hs_a = new HashSet<Integer>();
		HashSet<Integer> hs_b = new HashSet<Integer>();
		int star = 0;
		int steps = 0;

		while (hs_b.size() < N)
		{
			// find b for 2 stars
			int tmp = star;

			for (int i = N - 1; i >= 0; i--)
			{
				int id = pairs[i].id;
				int b = pairs[i].b;
				if (!hs_b.contains(id) && !hs_a.contains(id) && star >= b)
				{
					star += 2;
					hs_b.add(id);
					hs_a.add(id);
					steps++;
					break;
				}
			}

			// find b for 1 star
			if (star == tmp)
			{
				for (int i = N - 1; i >= 0; i--)
				{
					int id = pairs[i].id;
					int b = pairs[i].b;
					if (!hs_b.contains(id) && star >= b)
					{
						star += 1;
						hs_b.add(id);
						steps++;
						break;
					}
				}
			}

			// find a without b
			if (star == tmp)
			{
				for (int i = 0; i < N; i++)
				{
					int id = pairs[i].id;
					int a = pairs[i].a;

					if (!hs_a.contains(id) && star >= a)
					{
						star += 1;
						hs_a.add(id);
						steps++;
						break;
					}
				}
			}

			if (star == tmp)
				return -1;
		}

		return steps;
	}

	void run() throws Exception
	{
		Scanner in = new Scanner(System.in);
		out = new PrintWriter(new FileWriter("gcj.txt"));

		int T = Integer.parseInt(in.nextLine());
		for (int i = 0; i < T; i++)
		{
			int N = in.nextInt();
			Pair[] pairs = new Pair[N];

			for (int j = 0; j < N; j++)
			{
				int a = in.nextInt();
				int b = in.nextInt();
				pairs[j] = new Pair(j, a, b);
			}

			Arrays.sort(pairs);
			int ret = play(N, pairs);
			if (ret == -1)
				out.printf("Case #%d: %s\n", i + 1, "Too Bad");
			else
				out.printf("Case #%d: %d\n", i + 1, ret);
		}

		out.close();
	}

}
