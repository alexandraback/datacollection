using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleJam2012
{
	public class CodeForcesClass
	{
		public static void Main()
		{
			ReadFromFile();
			var t = Read<int>();
			using (var sw = new StreamWriter(@"output.txt"))
			{
				for (var i = 0; i < t; i++)
				{
					var input = ReadList<int>();
					var n = input[0];
					var s = input[1];
					var p = input[2];
					var r = new List<int>();
					for (var j = 3; j < input.Count; j++)
					{
						r.Add(input[j]);
					}
					var normal = p*3 - 2;
					var apart2 = p*3 - 4;
					if (p == 1)
					{
						apart2 = int.MaxValue;
					}
					if (p == 0)
					{
						sw.WriteLine("Case #{0}: {1}", i + 1, n);
						continue;
					}
					var count = 0;
					foreach (var res in r)
					{
						if (res >= normal)
						{
							count++;
						}
						else if (s > 0 && res >= apart2)
						{
							s--;
							count++;
						}
					}
					sw.WriteLine("Case #{0}: {1}", i + 1, count);
				}
			}
		}

		// Here goes misc

		public static T Read<T>()
		{
			var line = Console.ReadLine();
			var item = Convert.ChangeType(line, typeof (T));
			return (T) item;
		}

		public static List<T> ReadList<T>(char[] delimiters = null)
		{
			var line = Read<string>();
			var split = line.Split(delimiters ?? new[] {' '});
			var list = split.Select(item => (T) Convert.ChangeType(item, typeof (T))).ToList();
			return list;
		}

		public static List<T> ReadListNlines<T>(int n)
		{
			var list = new List<T>();
			for (var i = 0; i < n; i++)
			{
				list.Add(Read<T>());
			}
			return list;
		}

		public static void ReadFromFile()
		{
			Console.SetIn(new StreamReader(@"input.txt"));
		}

		public static bool NextPermutation<T>(T[] items) where T : IComparable
		{
			var i = -1;
			for (var x = items.Length - 2; x >= 0; x--)
			{
				if (items[x].CompareTo(items[x + 1]) < 0)
				{
					i = x;
					break;
				}
			}

			if (i == -1)
			{
				return false;
			}
			var j = 0;
			for (var x = items.Length - 1; x > i; x--)
			{
				if (items[x].CompareTo(items[i]) > 0)
				{
					j = x;
					break;
				}
			}
			var temp = items[i];
			items[i] = items[j];
			items[j] = temp;
			Array.Reverse(items, i + 1, items.Length - (i + 1));
			return true;
		}

		public static string ReplaceChar(string str, char c, int idx)
		{
			return str.Substring(0, idx) + c + str.Substring(idx + 1);
		}
	}
}