import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class Csmall
{
	static int[] arr = new int[20];
	static int[] map = new int[2000000];
	public static int[] sol(int sub, int sum, int i)
	{
		if (i == 20)
		{
			if (sum == 0)
				return null;
			if (map[sum] != 0)
			{
				int[] a = new int[2];
				a[0] = sum;
				a[1] = sub;
				return a;
			}
			else
			{
				map[sum] = sub;
				return null;
			}
		}
		else
		{
			int[] a = sol(sub, sum, i+1);
			if (a != null) return a;
			int[] b = sol(sub | (1 << i), sum+arr[i], i+1);
			if (b != null) return b;
			return null;
		}
	}
	public static LinkedList<Integer> subset(int sub)
	{
		LinkedList<Integer> ls = new LinkedList<Integer>();
		for (int i = 0; i < 20; i++)
		{
			if ((sub & (1<<i)) != 0)
				ls.add(arr[i]);
		}
		return ls;
	}
	public static void main(String[] args) throws Exception
	{
		//BufferedReader br = new BufferedReader(new InputStreamReader(in));
		Scanner sc = new Scanner(in);
		PrintStream ps = new PrintStream(new BufferedOutputStream(out));
		int cases = sc.nextInt();
		for (int c = 1; c <= cases; c++)
		{
			Arrays.fill(map, 0);
			sc.nextInt();
			for (int i = 0; i < 20; i++)
				arr[i] = sc.nextInt();
			int[] pair = sol(0, 0, 0);
			ps.printf("Case #%d:\n", c);
			if (pair == null)
				ps.println("Impossible");
			else
			{
				LinkedList<Integer> ls = subset(pair[1]);
				ps.print(ls.removeFirst());
				while (ls.size() != 0)
					ps.print(" "+ls.removeFirst());
				ps.println();
				ls = subset(map[pair[0]]);
				ps.print(ls.removeFirst());
				while (ls.size() != 0)
					ps.print(" "+ls.removeFirst());
				ps.println();
			}
		}
		ps.flush();
	}
}

