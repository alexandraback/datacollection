using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleJam2012
{
	public class CodeForcesClass
	{
		private static string upper;
		private static int length;

		public static void Main()
		{
			ReadFromFile();
			var t = Read<int>();
			using (var sw = new StreamWriter(@"output.txt"))
			{
				for (var i = 0; i < t; i++)
				{
					var line = ReadList<int>();
					var a = line[0];
					var b = line[1];
					upper = b.ToString();
					length = upper.Length;
					var result = new List<string>();
					for (var x = a; x <= b; x++)
					{
						var str = x.ToString();
						for (var j = 1; j < length; j++)
						{
							var res = GetValidValue(str, j);
							if (!string.IsNullOrEmpty(res))
							{
								result.Add(str + res);
							}
						}
					}
					sw.WriteLine("Case #{0}: {1}", i + 1, result.Distinct().Count());
				}
			}
		}

		public static string GetValidValue(string str, int idx)
		{
			for (var i = 0; i < length; i++)
			{
				if (str[i] > str[(idx + i) % length])
				{
					return string.Empty;
				}
				if (str[i] < str[(idx + i) % length])
				{
					for (var j = 0; j < length; j++)
					{
						if (upper[j] > str[(idx + j) % length])
						{
							return str.Substring(idx) + str.Substring(0, idx);
						}
						if (upper[j] < str[(idx + j) % length])
						{
							return string.Empty;
						}
					}
					return str.Substring(idx) + str.Substring(0, idx);
				}
			}
			return string.Empty;
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