using System;
using System.Collections.Generic;

public class C
{
	static int n;
	static Node[] nodes;

	public static void Main(string[] args)
	{
		int tests = int.Parse(Console.ReadLine());
		for(int testcase = 1; testcase <= tests; testcase++)
		{
			Console.Write("Case #{0}: ", testcase);
			string[] parts = Console.ReadLine().Split();
			n = int.Parse(parts[0]);
			nodes = new Node[n];
			for(int i = 0; i < n; i++)
				nodes[i] = new Node(i, int.Parse(Console.ReadLine()));
			int m = int.Parse(parts[1]);
			for(int i = 0; i < m; i++)
			{
				parts = Console.ReadLine().Split();
				int a = int.Parse(parts[0]) - 1;
				int b = int.Parse(parts[1]) - 1;
				nodes[a].nexts.Add(b);
				nodes[b].nexts.Add(a);
			}

			int[] order = new int[n];
			for(int i = 0; i < n; i++) order[i] = i;
			int[] best = new int[n];
			bool hasbest = false;
			do
			{
				if(possible(order))
				{
					int[] newbest = hasbest ? pickbest(best, order) : order;
					newbest.CopyTo(best, 0);
					hasbest = true;
				}
			} while(NextPermutation(order));
			for(int i = 0; i < n; i++)
				Console.Write(nodes[best[i]].zip);
			Console.WriteLine();
		}
	}

	public static bool possible(int[] order)
	{
		Stack<int> stack = new Stack<int>();
		stack.Push(order[0]);
		for(int i = 1; i < order.Length; i++)
		{
			while(stack.Count > 0 && !nodes[stack.Peek()].nexts.Contains(order[i]))
				stack.Pop();
			if(stack.Count == 0) return false;
			stack.Push(order[i]);
		}
		return true;
	}

	public static int[] pickbest(int[] o1, int[] o2)
	{
		if(o1 == null) return o2;
		if(o2 == null) return o1;
		for(int i = 0; i < o1.Length; i++)
		{
			if(nodes[o1[i]].zip < nodes[o2[i]].zip) return o1;
			if(nodes[o1[i]].zip > nodes[o2[i]].zip) return o2;
		}
		throw new Exception("Same orders given to best");
	}

	public class Node
	{
		public int i;
		public int zip;
		public List<int> nexts;

		public Node(int i, int zip)
		{
			this.i = 0;
			this.zip = zip;
			nexts = new List<int>();
		}
	}

	// Prewritten
	public static bool NextPermutation<T>(T[] array) where T : IComparable
	{
		for (int i = array.Length - 2; i >= 0; i--)
		{
			if (array[i].CompareTo(array[i + 1]) < 0)
			{
				int j = array.Length - 1;
				while (array[i].CompareTo(array[j]) >= 0)
					j--;
				T tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				Array.Reverse(array, i + 1, array.Length - i - 1);
				return true;
			}
		}
		return false;
	}
}