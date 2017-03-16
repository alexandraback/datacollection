using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace B
{
	public class Program
	{
		private static readonly List<string> Tokens = new List<string>();
		private static int position;
		private const string InputFile = @"B-small-attempt0.in";
		private const string OutputFile = @"B-small-attempt0.out";
		private const string Folder = @"D:\DotNetProjects\GoogleCodeJam2014\";
		private static readonly StringBuilder sb = new StringBuilder();

		static void Main()
		{
			ReadInput();
			int taskCount = NextInt();
			for (int i = 0; i < taskCount; i++)
			{
				Solve(i + 1);
			}
			FlushOutput();
		}

		private static void Solve(int taskNumber)
		{
			string result = "";
			long a = NextLong();
			long b = NextLong();
			long k = NextLong();

			long cnt = 0;
			for (int i = 0; i < a; i++)
			{
				for (int j = 0; j < b; j++)
				{
					if ((i & j) < k)
						cnt++;
				}
			}
			result = cnt + "";
			WriteLineFormat("Case #{0}: {1}", taskNumber, result);
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
