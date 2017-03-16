import java.io.*;
import java.util.*;
import java.math.*;
import javax.swing.*;
import static java.lang.System.*;

public class B
{
	public static class Pair
	{
		int a, b;
		boolean tagA, tagB;
		public Pair(int a, int b)
		{
			this.a=a;
			this.b=b;
			tagA = false;
			tagB = false;
		}
		public String toChar()
		{
			return "("+a+","+b+")";
		}
	}
	public static class One implements Comparator<Pair>
	{
		public int compare(Pair p1, Pair p2)
		{
			return p1.a-p2.a;
		}
	}
	public static class Two implements Comparator<Pair>
	{
		public int compare(Pair p1, Pair p2)
		{
			return p1.b-p2.b;
		}
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
			int[] a = new int[n];
			int[] b = new int[n];
			boolean[] mark = new boolean[n];
			for (int i = 0; i < n; i++)
			{
				a[i] = sc.nextInt();
				b[i] = sc.nextInt();
			}
			PriorityQueue<Pair> one = new PriorityQueue<Pair>(n, new One());
			PriorityQueue<Pair> two = new PriorityQueue<Pair>(n, new Two());
			
			for (int i = 0; i < n; i++)
			{
				Pair p = new Pair(a[i],b[i]);
				one.add(p);
				two.add(p);
			}
			int stars = 0;
			boolean ok = true;
			int steps = 0;
			while (one.size() != 0 && two.size() != 0)
			{
				Pair p1 = one.poll();
				Pair p2 = two.poll();
/*
				ps.println("one = "+p1.toChar()+p1);
				ps.println("two = "+p2.toChar()+p2);
*/
				if (p2.b <= stars)
				{
					one.add(p1);
					p2.tagB = true;
					if (p2.tagA) stars++;
					else stars += 2;
					steps++;
				}
				else
				{
					two.add(p2);
					if (!p1.tagA && !p1.tagB)
					{
						if (p1.a <= stars)
						{
							p1.tagA = true;
							stars++;
							steps++;
						}
						else
						{
							ok = false;
							break;
						}
					}
				}
			}
			//ps.println("**************");
			//ps.println("one = "+one.size());
			//ps.println("two = "+two.size());
			if (ok)
			{
				while (one.size() != 0)
				{
					Pair p = one.poll();
					if (!p.tagA && !p.tagB)
					{
						if (p.a <= stars)
						{
							stars++;
/*
							ps.println("mali");
*/
						}
						else
						{
							ok = false;
							break;
						}
						steps++;
					}
				}
			}
			if (ok)
			{
				while (two.size() != 0)
				{
					Pair p = two.poll();
					if (!p.tagB)
					{
						if (p.a <= stars)
						{
/*
							ps.println("ere");
*/
							if (p.tagA) stars++;
							else stars += 2;
							steps++;
						}
						else
						{
							ok = false;
							break;
						}
					}
				}
			}
			if (ok) ps.printf("Case #%d: %d\n", c, steps);
			else ps.printf("Case #%d: Too Bad\n", c);
		}
		ps.flush();
	}
}

