namespace CodeJam
{
	using System;
	using System.Collections.Generic;
	using System.Linq;
	using System.Text;

	public static class DiamondInheritance
	{
		public static void Work()
		{
			Example.RunTest(
				@"A-small-attempt0.in",
				@"A-small-attempt0.out",
				(r, w) => Example.WorkCases(r, w, (cases, i, reader) =>
				{
					var nClasses = Convert.ToInt32(reader.ReadLine());
					var classInfo = Enumerable.Range(1, nClasses).ToDictionary(n => n, n => reader.ReadLine().Split(' ').Skip(1).Select(s => Convert.ToInt32(s)).ToArray());
					var tops = classInfo.Where(c => c.Value.Length == 0);

					foreach (var c in classInfo)
					{
						var visited = new HashSet<int>();
						foreach (var p in c.Value)
						{
							if (HandleParent(classInfo, visited, p))
							{
								return "Yes";
							}
						}
					}

					return "No";
				}));
		}

		private static bool HandleParent(Dictionary<int, int[]> classInfo,HashSet<int> visited, int element)
		{
			if (visited.Contains(element))
			{
				return true;
			}

			visited.Add(element);
			foreach (var p in classInfo[element])
			{
				if (HandleParent(classInfo, visited, p))
				{
					return true;
				}
			}

			return false;
		}
	}
}
