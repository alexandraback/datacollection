using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _2012Q3
{
	class Program
	{
		static void Main(string[] args)
		{
			var line = Console.ReadLine();
			var testCount = int.Parse(line);
			for (var testNumber = 1; testNumber <= testCount; testNumber++)
			{
				var elements = Console.ReadLine().Split();
				var A = int.Parse(elements[0]);
				var B = int.Parse(elements[1]);
				var result = 0L;
				for (var n = A; n <= B; n++)
				{
					var digits = n.ToString().ToArray();
					var mSet = new HashSet<int>();
					for (var i = 1; i < digits.Length; i++)
					{
						var m = int.Parse(new string(digits.Skip(i).Concat(digits.Take(i)).ToArray()));
						if (m > n && m <= B)
							mSet.Add(m);
					}
					result += mSet.Count;
				}
				Console.WriteLine("Case #{0}: {1}", testNumber, result);
			}
		}
	}
}
