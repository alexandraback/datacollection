import java.util.HashSet;

public class Pair implements Comparable<Pair>
{
	public final int x, y;

	public final String way;

	public Pair(int x, int y, String way)
	{
		this.x = x;
		this.y = y;
		this.way = way;
	}

	@Override
	public int hashCode()
	{
		return 5 * x + y;
	}

	@Override
	public boolean equals(Object obj)
	{
		Pair p = (Pair) obj;
		return this.x == p.x && this.y == p.y;
	}

	@Override
	public String toString()
	{
		return "(" + x + "," + y + ")";
	}

	@Override
	public int compareTo(Pair o)
	{
		if (this.x == o.x && this.y == o.y)
			return 0;
		if (this.y > o.y)
			return 1;
		if (this.y < o.y)
			return -1;
		if (this.x > o.x)
			return 1;
		if (this.x < o.x)
			return -1;
		return 1;
	}

	public static boolean contains(HashSet<Pair> set, Pair p1)
	{
		// Pair p1 = new Pair(x, y);
		for (Pair p : set)
		{
			if (p.equals(p1))
				return true;
		}
		return false;
	}

	public static void main(String[] args)
	{
		HashSet<Pair> set = new HashSet<Pair>();
//		Pair p = new Pair(0, 0);
//		set.add(p);
//		System.out.println(p.equals(new Pair(0, 0)));
//		System.out.println(set.contains(new Pair(0, 0)));
//		System.out.println(contains(set, new Pair(0, 0)));
	}
}
