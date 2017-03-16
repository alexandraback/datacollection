using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace Beresta
{

	class ContestIO : StreamWriter
	{
		public ContestIO(Stream streamIn, Stream streamOut) : base(streamOut, Encoding.ASCII, 8192) { Reader = new StreamReader(streamIn, Encoding.ASCII, false, 8192); }
		public ContestIO(string inputFilePath, string outputFilePath) : this(File.OpenRead(inputFilePath), File.OpenWrite(outputFilePath)) { }
		public ContestIO(string inputText) : this(new MemoryStream(Encoding.ASCII.GetBytes(inputText)), Console.OpenStandardOutput(8192)) { }
		public ContestIO() : this(Console.OpenStandardInput(8192), Console.OpenStandardOutput(8192)) { }
		//d.ToString("N12", CultureInfo.InvariantCulture).Replace(",", "")
		public StreamReader Reader;
		
		bool IsDigit(int c) { return c >= '0' && c <= '9'; }
		public long Read()
		{
			int c1 = 0, c;
			while (!IsDigit(c = Reader.Read())) { c1 = c; }
			long r = c - '0';
			while (IsDigit(c = Reader.Read()))
				r = r * 10 + c - '0';
			return c1 == '-' ? -r : r;
		}
		public long[] ReadArray(int size) { return Enumerable.Range(0, size).Select(v => Read()).ToArray(); }
	}

	class Program
	{

		static void Main(string[] args)
		{
			using (var io = new ContestIO(@"D:\Contests\input\GCJ2016_R1B_A\A-small-attempt1.in", @"D:\Contests\input\GCJ2016_R1B_A\A-small-attempt1.out"))
			{
				var t = io.Read();
				for (var i = 0; i < t; i++)
				{
					var s = io.Reader.ReadLine();
					var res = Solve(s.ToLower());
					io.WriteLine(string.Format("Case #{0}: {1}", (i + 1), res));
				}
			}

			Console.ReadLine();
		}

		static string Solve(string s)
		{
			var count = new long[100];
			for (var i = 0; i < s.Length; i++)
			{
				count[Id(s[i])]++;
			}
			var result = new long[10];

			Add(count, result, 0, 'z', 1, 'z', 'e', 'r', 'o');
			Add(count, result, 6, 'x', 1, 's', 'i', 'x');
			Add(count, result, 8, 'g', 1, 'e', 'i', 'g', 'h', 't');
			Add(count, result, 7, 's', 1, 's', 'e', 'v', 'e', 'n');
			Add(count, result, 3, 'h', 1, 't', 'h', 'r', 'e', 'e');
			Add(count, result, 2, 't', 1, 't', 'w', 'o');
			Add(count, result, 4, 'r', 1, 'f', 'o', 'u', 'r');
			Add(count, result, 1, 'o', 1, 'o', 'n', 'e');
			Add(count, result, 5, 'f', 1, 'f', 'i', 'v', 'e');
			Add(count, result, 9, 'n', 2, 'n', 'i', 'n', 'e');

			for (var i = 0; i < 100; i++)
			{
				if (count[i] != 0)
					throw new Exception();
			}

			StringBuilder res = new StringBuilder();
			for (var i = 0; i < 10; i++)
			{
				var ch = i.ToString();
				for (var j = 0; j < result[i]; j++)
					res.Append(ch);
			}

			return res.ToString();
		}
		static void Add(long[] count, long[] result, long pos, char c, int mod, params char[] arr)
		{
			result[pos] = count[Id(c)] / mod;
			for (var i = 0; i < arr.Length; i++)
			{
				count[Id(arr[i])] -= result[pos];
				if (count[Id(arr[i])] < 0)
					throw new Exception();
			}
		}
		static int Id(char c)
		{
			return c - 'a';
		}

	}

}
