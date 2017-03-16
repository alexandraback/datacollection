using System;
using System.Linq;
using System.Runtime.Remoting.Messaging;

namespace RankFile
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			var cases = int.Parse(Console.ReadLine());
			for (var i = 1; i <= cases; i++)
			{
				var n = int.Parse (Console.ReadLine ());
				var result = string.Empty;

				int[] heights = new int[2500];
				for (int j = 0; j < 2*n-1; j++) {
					var line = Console.ReadLine ();

					var lineHeights = line.Split (' ');
					foreach (var heightString in lineHeights) {
						var height = int.Parse (heightString);
						heights [height] += 1;
					}
				}

				for (int k = 0; k < heights.Length; k++) 
				{
					if (heights[k] > 0 && heights[k] % 2 != 0)
					{
						result += k + " ";
					}
				}

				Console.WriteLine("Case #{0}: {1}", i, result.TrimEnd ());
			}
		}
	}
}
