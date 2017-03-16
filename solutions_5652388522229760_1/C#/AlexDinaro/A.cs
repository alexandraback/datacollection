using System.Collections.Generic;
using System.IO;

// ReSharper disable AssignNullToNotNullAttribute

namespace ConsoleApplication2
{
	class A
	{
		public void Solve()
		{
			using (var sr = new StreamReader("A.in"))
			using (var sw = new StreamWriter("A.out"))
			{
				var t = int.Parse(sr.ReadLine());
				for (var testCase = 1; testCase <= t; ++testCase)
				{
					sw.Write("Case #{0}: ", testCase);
					var n = int.Parse(sr.ReadLine());
					if (n == 0)
						sw.WriteLine("INSOMNIA");
					else 
						sw.WriteLine(FindLastNumber(n));
				}
			}
		}

		private int FindLastNumber(int startNumber)
		{
			var found = new HashSet<int>();
			var curr = startNumber;
			while (true)
			{
				found.UnionWith(IntToDigits(curr));
				if (found.Count == 10)
					return curr;
				curr += startNumber;
			}
		}

		private HashSet<int> IntToDigits(int value)
		{
			var digits = new HashSet<int>();
			while (value != 0)
			{
				digits.Add(value%10);
				value /= 10;
			}
			return digits;
		}
	}
}
