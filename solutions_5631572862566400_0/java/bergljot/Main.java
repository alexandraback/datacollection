package BFFs;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
	
	public static int largestCycle(int[] bffs)
	{
		HashMap<Integer, HashSet<Integer>> allCycles = new HashMap<Integer, HashSet<Integer>>();
		HashMap<Integer, HashSet<Integer>> allTails = new HashMap<Integer, HashSet<Integer>>();
		for(int student = 0; student < bffs.length; student++)
		{
			HashSet<Integer> inCycle = new HashSet<Integer>();
			int[] order = new int[bffs.length];
			for (int o = 0; o < order.length; o++) order[o] = 0;
			int current = student + 1;
			int count = 0;
			while(!inCycle.contains(current))
			{
				inCycle.add(current);
				order[current - 1] = count++; 
				current = bffs[current - 1];
			}
			allTails.put(student+1, inCycle);
			//System.out.println("there is a cycle starting at current " + current);
			HashSet<Integer> thisSet = new HashSet<Integer>();
			while(true)
			{
				int oldSize = thisSet.size();
				thisSet.add(current);
				if (oldSize == thisSet.size()) break;
				current = bffs[current - 1];
			}
			for (Integer s : thisSet) allCycles.put(s, thisSet);
			
		}
		//System.out.println(allCycles);
		//System.out.println(allTails);
		
		HashMap<Integer, HashSet<Integer>> all2Tails = new HashMap<Integer, HashSet<Integer>>();
		for(int i = 0; i < bffs.length; i++)
		{
			HashSet<Integer> mySet = allTails.get(i+1);
			boolean fail = false;
			for(Integer j : mySet)
			{
				HashSet cycle = allCycles.get(j);
				if (!(cycle == null || cycle.size() == 2))
				{
					fail = true;
					break;
				}
			}
			if (!fail)
			{
				all2Tails.put(i+1, mySet);
			}
		}
		//System.out.println(all2Tails);
		HashSet<Integer> cycleCores = new HashSet<Integer>();
		
		for(int i = 0; i < bffs.length; i++)
		{
			HashSet<Integer> myCycle = allCycles.get(i+1);
			if (myCycle != null && myCycle.size() == 2)
			{
				//System.out.println(myCycle);
				for (Integer c : myCycle) cycleCores.add(c);
			}
		}
		HashMap<Integer, HashSet<Integer>> coreTails = new HashMap<Integer, HashSet<Integer>>();
		for (Integer k : all2Tails.keySet())
		{
			int current = k;
			HashSet<Integer> path = new HashSet<Integer>();
			path.add(current);
			while(true)
			{
				if (cycleCores.contains(current)) break;
				current = bffs[current - 1];
				path.add(current);
			}
			if (coreTails.get(current) == null || coreTails.get(current).size() < path.size())
			{
				coreTails.put(current, path);
			}
		}
		//System.out.println(coreTails);
		
		int sum = 0;
		for (Integer k : coreTails.keySet())
		{
			sum += coreTails.get(k).size();
		}
		int max = 0;
		for (Integer k : allCycles.keySet())
		{
			if (max < allCycles.get(k).size()) max = allCycles.get(k).size();
		}
		if (max > sum) return max;
		return sum;
	}
	
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for(int i = 0; i < cases; i++)
		{
			int kids = in.nextInt();

			int[] bffs = new int[kids];
			
			for (int kid = 0; kid < kids; kid++)
			{
				bffs[kid] = in.nextInt();
			}
			
			System.out.println("Case #" + (i + 1) + ": " + largestCycle(bffs));
			
		}
		in.close();
	}
}
