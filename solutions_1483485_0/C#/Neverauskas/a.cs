using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleJam2012
{
	public class CodeForcesClass
	{
		private static readonly Dictionary<char, char> dictionary = new Dictionary<char, char>();

		public static void Main()
		{
			Map("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
			Map("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
			Map("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
			Map("y qee", "a zoo");
			var missingKey = default(char);
			var missingValue = default(char);
			for (var i = 'a'; i <= 'z'; i++)
			{
				if (!dictionary.Keys.Contains(i))
				{
					missingKey = i;
				}
				if (!dictionary.Values.Contains(i))
				{
					missingValue = i;
				}
			}
			dictionary[missingKey] = missingValue;

			ReadFromFile();
			var t = Read<int>();
			var lines = ReadListNlines<string>(t);
			using (var sr = new StreamWriter(@"output.txt"))
			{
				for (var i = 0; i < lines.Count; i++)
				{
					sr.WriteLine("Case #{0}: {1}", i + 1, Decrypt(lines[i]));
				}
			}
		}

		public static void Map(string inStr, string outStr)
		{
			for (var i = 0; i < inStr.Length; i++)
			{
				dictionary[inStr[i]] = outStr[i];
			}
		}

		public static string Decrypt(string input)
		{
			var result = string.Empty;
			foreach (var c in input)
			{
				result += dictionary[c];
			}
			return result;
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