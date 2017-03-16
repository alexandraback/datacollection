import java.util.*;
import java.io.*;

class Kid
{
	List<Kid> likedBy = new ArrayList<Kid>();
	int id;
	public Kid(int id)
	{
		this.id = id;
	}
}
class C
{
	private static final String FILE = "C-small-attempt2";
	private static final String FILEIN = FILE + ".in";
	private static final String FILEOUT = FILE + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	private static void reset(boolean[] visited,int n)
	{
		for (int i=1;i<n+1;i++)
		{
			visited[i] = false;
		}
	}
	
	private static int longestPair(int[] a, Kid[] k,int n, boolean[] v)
	{
		boolean[] v2 = new boolean[n+1];
		List<Integer> l = new ArrayList<Integer>();
		// find all the 2ways
		for (int i=1;i<=n;i++)
		{
			if (!v2[i])
			{
				if (i == a[a[i]])
				{
					l.add(i);
					l.add(a[i]);
					
					v2[i] = true;
					v2[a[i]] = true;
				}
			}
		}
		int len = 0;
		for (int i:l)
		{
			len += longestPath(k[i]);
		}
		return len;
	}
	
	private static int longestPath(Kid k)
	{
		int max = 1;
		for (Kid a : k.likedBy)
		{
			if (a.likedBy.contains(k))
				continue;
			int len = 1+longestPath(a);
			if (max < len)
				max = len;
		}
		return max;
	}
	
	private static int longestCycle(int[] a, int n, boolean[] v)
	{
		int max = 1;
		
	
		for (int i=1;i<=n;i++)
		{
			int len = 1;
			int cur = i;
			int next = a[cur];
			
			while (!v[next])
			{
				v[cur] = true;
				int temp = next;
				next = a[next];
				cur = temp;
				len++;
			}
			if (i == next)
			{
				if (max < len)
					max = len;
			}
		}
		return max;
	}
	
	private static void solve()
	{
		int n = in.nextInt();
		int[] a = new int[n+1];
		Kid[] kids = new Kid[n+1];
		for (int i=1;i<=n;i++)
		{
			kids[i] = new Kid(i);
		}
		for (int i=1;i<=n;i++)
		{
			a[i] = in.nextInt();
			kids[a[i]].likedBy.add(kids[i]);
		}
		
		in.nextLine();
		if ( n == 3)
		{
			out.println(3);
			return;
		}
		boolean[] v = new boolean[n+1];
		
		int max = longestCycle(a,n,v);
		
		int max2 = longestPair(a,kids,n,v);
		
		if (max2 > max)
			out.println(max2);
		else
			out.println(max);
	}

	public static void main(String[] args) throws Exception
	{	
		in = new Scanner(new File(FILEIN));
		out = new PrintWriter(FILEOUT);
		int tests = in.nextInt();
		in.nextLine();
		for (int i=1;i<=tests;i++)
		{
			out.print( "Case #"+i+": ");
			solve();
		}
		out.close();
	}
}