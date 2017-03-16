import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class A
{
	public static class Pair implements Comparable<Pair>
	{
		int i, v;
		double p;
		public Pair(int i, int v)
		{
			this.i=i;
			this.v=v;
			p = 0;
		}
		public int compareTo(Pair that)
		{
			return that.v-this.v;
		}
	}
	public static double formula(int N, int X, int Ji, int Jmax)
	{
		double res = (double)((N-1)*(Jmax-Ji)+X)/(N*X);
		if (res < 0) res = 0;
		return res*100;
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
			Pair[] arr = new Pair[n];
			int x = 0;
			PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
			for (int i = 0; i < n; i++)
			{
				arr[i] = new Pair(i, sc.nextInt());
				x += arr[i].v;
				pq.add(arr[i]);
			}
			ps.printf("Case #%d:", c);
			int cn = n;
			int cx = x;
			while (pq.size() != 0)
			{
				Pair p = pq.poll();
				if (p.v*cn > 2*cx)
				{
					//ps.println("hipster");
					p.p = 0;
				}
				else
				{
					p.p = 2.0/cn - (double)p.v/cx;
					p.p *= 100;
				}
			}
			for (int i = 0; i < n; i++)
			{
				ps.print(" "+arr[i].p);
			}
			ps.println();
		}
		ps.flush();
	}
}

