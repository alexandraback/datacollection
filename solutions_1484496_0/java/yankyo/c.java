import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map.Entry;
import java.util.Scanner;


public class c
{
	static class C
	{
		Long sum;
		LinkedList<Long> list;
		
		C(Long _sum, LinkedList<Long> _list)
		{
			sum = _sum;
			list = _list;
		}
	}
	
	public static void main(String[] args)
	{
		HashMap<Long, LinkedList<Long>> res = new HashMap<Long, LinkedList<Long>>();
		
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		for (int t = 1; t <= T; t++)
		{
			res.clear();
			System.out.print("Case #" + t + ":\n");

			int N = in.nextInt();
			
			long numbers[] = new long[N];
			
			for (int n = 0; n < N; n++) numbers[n] = in.nextLong();
			
			res.put((long)0, new LinkedList<Long>());
			
			boolean done = false;
			for (int i = 0; i < N; i++)
			{
				LinkedList<C> add = new LinkedList<C>();
				for(Entry<Long, LinkedList<Long>> e : res.entrySet())
				{
					LinkedList<Long> l = res.get(e.getKey() + numbers[i]);
					if (l == null)
					{
						l = new LinkedList<Long>(e.getValue());
						l.add(numbers[i]);
						add.add(new C(e.getKey() + numbers[i], l));
					} else
					{
						for (Long ll : l)
						{
							System.out.print(ll);
							System.out.print(" ");
						}
						System.out.print("\n");
						for (Long ll : e.getValue())
						{
							System.out.print(ll);
							System.out.print(" ");
						}
						System.out.print(numbers[i]);
						System.out.print("\n");
						done = true;
						break;
					}
				}
				for (C c : add) res.put(c.sum, c.list);
				if (done) break;
			}
			
			if (!done) System.out.print("Impossible\n");
		}
	}
}
