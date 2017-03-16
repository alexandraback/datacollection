using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round1CA
{
	class Program
	{
		public static int[] ReadNumbers(string line)
		{
			string[] strNumbers = line.Split(new char[] { ' ' });
			int[] numbers = new int[strNumbers.Length];

			for (int i = 0; i < strNumbers.Length; i++)
			{
				numbers[i] = int.Parse(strNumbers[i]);
			}

			return numbers;
		}

		static void Main(string[] args)
		{
			int tcCount = int.Parse(Console.ReadLine());
			for (int tcIndex = 1; tcIndex <= tcCount; tcIndex++)
			{
				int classCount = int.Parse(Console.ReadLine());

				List<int>[] inheritedFrom = new List<int>[classCount+1];

				for (int i = 1; i <= classCount; i++)
				{
					inheritedFrom[i] = new List<int>();

					int[] numbers = ReadNumbers(Console.ReadLine());
					int classInheritCount = numbers[0];

					for (int j = 1; j <= classInheritCount; j++)
					{
						inheritedFrom[i].Add(numbers[j]);
					}
				}

				bool hasDiamondInheritance = false;

				for (int i = 1; i < classCount; i++)
				{
					bool[] inherited = new bool[classCount + 1];

					if (InheritedMultipleTimes(inheritedFrom, inherited, i))
					{
						hasDiamondInheritance = true;
						break;
					}
				}

				// Output
				Console.WriteLine("Case #{0}: {1}", tcIndex, hasDiamondInheritance ? "Yes" : "No");
			}
		}

		static bool InheritedMultipleTimes(List<int>[] inheritedFrom, bool[] inherited, int c)
		{
			foreach (int inheritedClass in inheritedFrom[c])
			{
				if (inherited[inheritedClass])
				{
					return true;
				}
				inherited[inheritedClass] = true;
				if (InheritedMultipleTimes(inheritedFrom, inherited, inheritedClass))
				{
					return true;
				}
			}

			return false;
		}
	}
}
