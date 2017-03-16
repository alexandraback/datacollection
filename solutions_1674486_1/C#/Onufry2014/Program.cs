using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Application
{
	class Program
	{
		static void Main(string[] inputs)
		{
			Console.WriteLine("Executing {0}", typeof(Program).FullName);
			Console.WriteLine();

			if (inputs == null || !inputs.Any())
				inputs = Directory.GetFiles(".", "*.in");

			foreach (string input in inputs)
			{
				Process(input);
			}

			Console.WriteLine();
			Console.WriteLine("Done.");
			Console.WriteLine();

			Console.ReadLine();
		}

		public static void Process(string input)
		{
			Console.WriteLine("Processing {0}", input);

			using (StreamWriter writer = new StreamWriter(input.Replace(".in", ".out"), false))
			{
				foreach (var testCase in GetTestCases(input))
				{
					Solution solution = Solve(testCase);

					writer.Write("Case #{2}: {3}{1}", " ", (char)10, solution.ID, solution.ToString());
				}
			}
		}

		public static Solution Solve(TestCase testCase)
		{
			for (int i = 0; i < testCase.Inheritance.Count; i++)
			{
				if (Solve(i, testCase.Inheritance))
					return new Solution { ID = testCase.ID, Diamond = true };
			}

			return new Solution { ID = testCase.ID, Diamond = false };
		}

		private static bool Solve(int i, List<List<int>> list)
		{
			HashSet<Tuple<int, int>> pairs = new HashSet<Tuple<int, int>>();

			for (int j = 0; j < list[i].Count; j++)
			{
				var pair = new Tuple<int, int>(i, list[i][j]);
				if (pairs.Contains(pair))
					return true;
				else
					pairs.Add(pair);
			}

			for (int j = 0; j < list[i].Count; j++)
			{
				if (Solve(i, list[i][j], list, pairs))
					return true;
			}

			return false;
		}

		private static bool Solve(int start, int i, List<List<int>> list, HashSet<Tuple<int, int>> pairs)
		{
			for (int j = 0; j < list[i].Count; j++)
			{
				var pair = new Tuple<int, int>(start, list[i][j]);
				if (pairs.Contains(pair))
					return true;
				else
					pairs.Add(pair);
			}

			for (int j = 0; j < list[i].Count; j++)
			{
				if (Solve(start, list[i][j], list, pairs))
					return true;
			}

			return false;
		}

		public static IEnumerable<TestCase> GetTestCases(string input)
		{
			using (StreamReader reader = new StreamReader(input))
			{
				string @string = reader.ReadToEnd();

				var lines = @string.Split((char)10);

				int testCases = Int32.Parse(lines.First());

				int lineIndex = 1;

				for (int testCase = 1; testCase <= testCases; testCase++)
				{
					int numberOfClass = Int32.Parse(lines[lineIndex++]);

					List<List<int>> inheritance = new List<List<int>>();

					for (int i = 0; i < numberOfClass; i++)
					{
						inheritance.Add(lines[lineIndex++].Split(' ').Skip(1).Select(s => Int32.Parse(s) - 1).ToList());
					}

					yield return new TestCase
					{
						ID = testCase,
						Inheritance = inheritance,
					};
				}
			}
		}

		public class TestCase : IEquatable<TestCase>, IEqualityComparer<TestCase>
		{
			public int ID { get; set; }
			public List<List<int>> Inheritance { get; set; }

			public bool Equals(TestCase other)
			{
				if (other == null) return false;

				if (this.ID != other.ID) return false;

				return true;
			}

			public bool Equals(TestCase x, TestCase y)
			{
				return x.Equals(y);
			}

			public int GetHashCode(TestCase obj)
			{
				return obj.GetHashCode();
			}

			public override bool Equals(object obj)
			{
				var other = obj as TestCase;

				return this.Equals(other);
			}

			public override int GetHashCode()
			{
				return ID.GetHashCode();
			}

			public override string ToString()
			{
				return String.Format("{0}", ID);
			}
		}

		public class Solution : IEquatable<Solution>, IEqualityComparer<Solution>
		{
			public int ID { get; set; }
			public bool Diamond { get; set; }

			public bool Equals(Solution other)
			{
				if (other == null) return false;

				if (this.ID != other.ID) return false;
				if (this.Diamond != other.Diamond) return false;

				return true;
			}

			public bool Equals(Solution x, Solution y)
			{
				return x.Equals(y);
			}

			public int GetHashCode(Solution obj)
			{
				return obj.GetHashCode();
			}

			public override bool Equals(object obj)
			{
				var other = obj as Solution;

				return this.Equals(other);
			}

			public override int GetHashCode()
			{
				return ID.GetHashCode();
			}

			public override string ToString()
			{
				return String.Format("{1}", ID, Diamond ? "Yes" : "No");
			}
		}
	}
}
