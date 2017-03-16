using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace A
{
	public class Program
	{
		private static readonly List<string> Tokens = new List<string>();
		private static int position;
		private const string InputFile = @"A-small-attempt0.in";
		private const string OutputFile = @"A-small-attempt0.out";
		private const string Folder = @"D:\DotNetProjects\GoogleCodeJam2014\";
		private static readonly StringBuilder sb = new StringBuilder();
		
		static void Main()
		{
			ReadInput();
			int taskCount = NextInt();
			for (int t = 0; t < taskCount; t++)
			{
				Solve(t + 1);
			}
			FlushOutput();
			
		}

		private static void Solve(int taskNumber)
		{
			int n = NextInt();
			var lines = new string[n];
			for (int i = 0; i < n; i++)
			{
				lines[i] = NextToken();
			}

			var line1 = Pair.Make(lines[0]);
			var line2 = Pair.Make(lines[1]);

			string result = "";
			if (line1.Count != line2.Count)
				result = "Fegla Won";
			else
			{
				result = Find(line1, line2);
			}

			WriteLineFormat("Case #{0}: {1}", taskNumber, result);
		}

		private static string Find(List<Pair> f, List<Pair> s)
		{
			var result = "Fegla Won";
			int cnt = 0;
			for (int i = 0; i < f.Count; i++)
			{
				if (f[i].ch != s[i].ch)
					return result;
				int mid = (f[i].count + s[i].count)/2;
				cnt += Math.Abs(f[i].count - mid);
				cnt += Math.Abs(s[i].count - mid);
			}
			return cnt + "";
		}

		public class Pair
		{
			public char ch;
			public int count;

			public static List<Pair> Make(string str)
			{
				var result = new List<Pair>();
				char curChar = str[0];
				int curCnt = 1;
				for (int i = 1; i < str.Length; i++)
				{
					if (str[i] == curChar)
						curCnt++;
					else
					{
						result.Add(new Pair{ch = curChar, count = curCnt});
						curCnt = 1;
						curChar = str[i];
					}
				}
				result.Add(new Pair{ch = curChar, count = curCnt});
				return result;
			}
		}
		
		private static void FlushOutput()
		{
			File.WriteAllText(Folder + OutputFile, sb.ToString());
		}

		private static void ReadInput()
		{
			var lines = File.ReadAllLines(Folder + InputFile);
			foreach (var line in lines)
			{
				var strings = line.Split(' ', '\n');
				Tokens.AddRange(strings);
			}
		}

		private static void WriteLine(string line)
		{
			sb.AppendLine(line);
		}

		private static void WriteLineFormat(string format, params object[] args)
		{
			sb.AppendLine(string.Format(format, args));
		}

		private static void Write(string str)
		{
			sb.Append(str);
		}

		private static string NextToken()
		{
			return Tokens[position++];
		}

		public static int NextInt()
		{
			return int.Parse(NextToken());
		}
		
		public static long NextLong()
		{
			return long.Parse(NextToken());
		}
	}
}
