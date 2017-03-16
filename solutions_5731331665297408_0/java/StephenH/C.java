import java.util.*;

public class C
{
	public static ArrayList<Integer> cityStack = new ArrayList<Integer>();
	public static boolean[][] adj;
	public static String[] zips;
	public static boolean[] visited;
	public static int maxLen;
	public static int M, N;

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int test = 1, cases = Integer.parseInt(sc.nextLine());
		int v, w;
		String best;
		String route;

		int i, j;

		while(test <= cases)
		{
			N = sc.nextInt();
			M = sc.nextInt();

			zips = new String[N];
			adj = new boolean[N][N];

			for(i = 0; i < N; i++)
			{
				zips[i] = Integer.toString(sc.nextInt());
			}

			for(i = 0; i < N; i++)
			{
				Arrays.fill(adj[i], false);
			}

			for(i = 0; i < M; i++)
			{
				v = sc.nextInt();
				w = sc.nextInt();

				adj[v - 1][w - 1] = true;
				adj[w - 1][v - 1] = true;
			}

			best = null;

			visited = new boolean[N];

			Arrays.fill(visited, false);

			for(i = 0; i < N; i++)
			{
				cityStack.clear();
				visited[i] = true;
				maxLen = Integer.MAX_VALUE;

				route = bestRoute(i, 0, false);

				if(route != null && (best == null || greater(best, route)))
					best = route;

				visited[i] = false;
			}

			System.out.println("Case #" + test + ": " + best);

			test++;
		}
	}

	public static boolean greater(String a, String b)
	{
		if(a.length() > b.length())
			return true;
		else if(a.length() < b.length())
			return false;

		int i;

		for(i = 0; i < a.length(); i++)
		{
			if(a.charAt(i) > b.charAt(i))
				return true;
			else if(a.charAt(i) < b.charAt(i))
				return false;
		}

		return false;
	}

	public static String bestRoute(int curr, int len, boolean inReturn)
	{
		if(len > maxLen)
			return null;

		int removed;
		String best = null;
		String route = null;
		int i;
		boolean visitedCity = false;

		for(i = 0; i < N; i++)
		{
			if(!visited[i])
				visitedCity = true;

			if(!visited[i] && adj[curr][i])
			{
				cityStack.add(curr);
				visited[i] = true;
				route = bestRoute(i, len + 1, false);

				if(inReturn)
				{
					if(route != null && (best == null || greater(best, route)))
						best = route;
				}
				else
				{
					if(route != null && (best == null || greater(best, zips[curr] + route)))
						best = zips[curr] + route;
				}

				visited[i] = false;
				cityStack.remove(cityStack.size() - 1);
			}
		}

		if(!visitedCity)
		{
			maxLen = Math.min(maxLen, len);
			return zips[curr];
		}
		else if(cityStack.size() > 0)
		{
			removed = cityStack.remove(cityStack.size() - 1);

			route = bestRoute(removed, len, true);

			if(inReturn)
			{
				if(route != null && (best == null || greater(best, route)))
					best = route;
			}
			else
			{
				if(route != null && (best == null || greater(best, zips[curr] + route)))
					best = zips[curr] + route;
			}

			cityStack.add(removed);
		}

		return best;
	}
}