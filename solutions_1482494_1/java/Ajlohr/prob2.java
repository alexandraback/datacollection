package round1;

import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;

public class prob2 {
	public static void main(String[] args)
	{
	Scanner sc = new Scanner(System.in);
	int cases = sc.nextInt();
	sc.nextLine();
	for(int curcase = 1;curcase<=cases;curcase++)
	{
		long count =0;
		int N = sc.nextInt();
		sc.nextLine();
		TreeMap<Integer,Integer> onestar = new TreeMap<Integer,Integer>();
		TreeMap<Integer,Integer> twostar = new TreeMap<Integer,Integer>();
		TreeSet<Integer> doneonestar = new TreeSet<Integer>();
		TreeSet<Integer> donetwostar = new TreeSet<Integer>();
		for(int i=0;i<N;i++)
		{
			onestar.put(i,sc.nextInt());
			twostar.put(i,sc.nextInt());
			sc.nextLine();
		}
		long numstars =0;
		boolean stay = true;
		while(stay)
		{
			stay = false;
			boolean staytwo = true;
			while(staytwo)
			{
				staytwo = false;
		for( Map.Entry<Integer,Integer> e : twostar.entrySet())
		{
			if((e.getValue()>numstars)||(donetwostar.contains(e.getKey())))
				continue;
			if(doneonestar.contains(e.getKey()))
			{
				numstars++;
			}else
			{
				numstars+=2;
			}
			donetwostar.add(e.getKey());
			count ++;
			staytwo = true;
			stay = true;
		}
			}
			
			Set<Integer> reachone = new TreeSet<Integer>();
		for( Map.Entry<Integer,Integer> e : onestar.entrySet())
		{
			if((e.getValue()>numstars)||(doneonestar.contains(e.getKey()))||(donetwostar.contains(e.getKey())))
				continue;

			reachone.add(e.getKey());
		}
		int maxindex = -1;
		int max = Integer.MIN_VALUE;
		for(Integer i : reachone)
		{
			if(twostar.get(i)>max)
				{max = twostar.get(i);
				maxindex =i;
				}
		}
		if(maxindex>=0)
		{
		doneonestar.add(maxindex);
		numstars++;
		count++;
		stay = true;
		}
		}
		if(donetwostar.size()==N)		
		System.out.println("Case #"+curcase+": "+count);
		else
		System.out.println("Case #"+curcase+": Too Bad");
		
	}}
}
