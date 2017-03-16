using System;
using System.Text;

namespace TheLastWord
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			var cases = int.Parse(Console.ReadLine());
			for (var i = 1; i <= cases; i++)
			{
				var s = Console.ReadLine();
				var result = new StringBuilder();

				result.Append (s[0]);
				for (int j = 1; j < s.Length; j++) {
					if (result[0] > s[j])
					{
						result.Append (s[j]);
					}
					else
					{
						result.Insert (0, s[j]);
					}
				}

				Console.WriteLine("Case #{0}: {1}", i, result);
			}
		}
	}
}
