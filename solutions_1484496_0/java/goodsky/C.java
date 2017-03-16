import java.util.*;
public class C {
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		for (int t = 1; t <= T; ++t)
		{
			int N = in.nextInt();
			int[] vals = new int[N];
			for (int n = 0; n < N; ++n)
				vals[n] = in.nextInt();
			
			HashMap<Integer, Foo> map = new HashMap<Integer, Foo>();
			
			Foo m1 = null;
			Foo m2 = null;
			
			for (int choose = 1; choose < 1<<N; ++choose)
			{
				ArrayList<Integer> list = new ArrayList<Integer>();
				int temp = choose;
				Integer sum = 0;
				for (int n = 0; n < N; ++n)
				{
					if ((temp&1) != 0) 
					{
						sum += vals[n];
						list.add(vals[n]);
					}
					temp /= 2;
				}
				
				Foo newm = new Foo(list);
				
				if (map.containsKey(sum))
				{
					m1 = map.get(sum);
					m2 = newm;
					break;
				}
				
				map.put(sum, newm);
			}
			
			System.out.printf("Case #%d:\n", t);
			if (m1 == null)
				System.out.println("Impossible");
			else
			{
				for (int i : m1.list)
					System.out.print(i + " ");
				System.out.println();
				for (int i : m2.list)
					System.out.print(i + " ");
				System.out.println();
			}
		}
	}
	
	static class Foo {
		ArrayList<Integer> list;
		Foo(ArrayList<Integer> l)
		{
			list = l;
		}
	}
}

/*
4
20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
20 120 266 858 1243 1657 1771 2328 2490 2665 2894 3117 4210 4454 4943 5690 6170 7048 7125 9512 9600
2 1 2
20 5652 563 432562 352435235 45326236 25 50 430 214 2515 1235 15352 414 6436 1346 13465 1344 6456 364 1462

*/
