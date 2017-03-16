using System;
using System.Linq;
using System.Collections.Generic;

class Program
{		
	static void Main()
	{
		var n = int.Parse(Console.ReadLine());
		for (var i = 0; i++ < n; )
			Console.WriteLine("Case #{0}: {1}", i, Solve());
	}

	static int Solve()
	{
		var read = Console.ReadLine();
		var data = read.Split(' ').ToArray();
		var name = data[0];
		var n = int.Parse(data[1]);

		var vow = "aiueo";
		/*
		var dic = new Dictionary<int, int>();
		int i = 0, last = -1;
		var flag = false;
		foreach (var c in name)
		{
			if (vow.Contains(c))
			{
				// vowel
				if (flag)
				{
					dic.Add(last, i - last);
					flag = false;
				}
			}
			else if (!flag)
			{
				flag = true;
				last = i;
			}
			i++;
		}
		if (flag)
			dic.Add(last, i - last);
		*/


		/*
		var a = new Queue<int>();
		var i = 0;
		for (i = 0; i < name.Length && a.Count < n; i++)
			if (!vow.Contains(name[i]))
				a.Enqueue(i);
		if (a.Count < n) return 0;

		var j = a.Dequeue();
		var sum = j + 1;
		for (; i < name.Length; i++)
		{
			if (!vow.Contains(name[i]))
			{
				a.Enqueue(i);
				j = a.Dequeue();
			}
			sum += j + 1;
		}
		return sum;
		*/

		int i, j = 0, k = -1, sum = 0;
		var flag = false;
		for (i = 0; i < name.Length; i++)
		{
			if (!vow.Contains(name[i]))
			{
				j = flag ? j + 1 : 1;
				flag = true;
				if (j >= n)
					k = i - n + 1;
			}
			else
			{
				flag = false;
			}
			if (k != -1) sum += k + 1;
		}
		return sum;
	}
}