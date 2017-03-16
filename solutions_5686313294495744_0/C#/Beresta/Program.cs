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
			using (var io = new ContestIO(@"D:\Contests\input\GCJ2016_R1B_C\C-small-attempt1.in", @"D:\Contests\input\GCJ2016_R1B_C\C-small-attempt1.out"))
//            using (var io = new ContestIO(@"3
//3
//HYDROCARBON COMBUSTION
//QUAIL BEHAVIOR
//QUAIL COMBUSTION
//3
//CODE JAM
//SPACE JAM
//PEARL JAM
//2
//INTERGALACTIC PLANETARY
//PLANETARY INTERGALACTIC"))
			{
				var t = io.Read();
				for (var i = 0; i < t; i++)
				{
					var n = io.Read();
					
					//io.Reader.ReadLine();

					var titles = new List<string[]>();
					for (var j = 0; j < n; j++)
					{
						var s = io.Reader.ReadLine();
						titles.Add(s.Split(' '));
					}

					var res = Solve(n, titles);

					io.WriteLine(string.Format("Case #{0}: {1}", (i + 1), res));
				}
			}

			//Console.ReadLine();
		}

		static long Solve(long n, List<string[]> titles)
		{
			Dictionary<string, int> map = new Dictionary<string, int>();
			int index = 1;

			bool[] w1f = new bool[100];
			bool[] w2f = new bool[100];
			int[] titles1 = new int[n];
			int[] titles2 = new int[n];

			for (var i = 0; i < n; i++)
			{
				var w1 = titles[i][0];
				var w2 = titles[i][1];
				if (!map.ContainsKey(w1))
					map.Add(w1, index++);
				if (!map.ContainsKey(w2))
					map.Add(w2, index++);

				w1f[map[w1]] = true;
				w2f[map[w2]] = true;

				titles1[i] = map[w1];
				titles2[i] = map[w2];
			}

			for (var i = 1; i < n; i++)
			{
				if (TrySolve(n, i, titles1, titles2, w1f, w2f, new bool[n], w1f.Count(w => w), w2f.Count(w => w)))
					return n - i;
			}

			return 0;
		}

		static bool TrySolve(long n, long c, int[] titles1, int[] titles2, bool[] l1, bool[] l2, bool[] picked, int c1, int c2)
		{
			if (c == 0)
			{
				return c1 == 0 && c2 == 0;
			}
			else
			{
				if (c1 > c || c2 > c)
					return false;
				
				for (var i = 0; i < n; i++)
				{
					if (!picked[i])
					{
						var w1 = titles1[i];
						var w2 = titles2[i];

						bool l1f = l1[w1];
						bool l2f = l2[w2];
						if (l1f || l2f)
						{
							var newc1 = c1;
							var newc2 = c2;
							
							picked[i] = true;
							if (l1f) {
								l1[w1] = false;
								newc1--;
							}
							if (l2f) {
								l2[w2] = false;
								newc2--;
							}

							if (TrySolve(n, c - 1, titles1, titles2, l1, l2, picked, newc1, newc2))
								return true;

							picked[i] = false;
							if (l1f)
								l1[w1] = true;
							if (l2f)
								l2[w2] = true;
						}
					}
				}

				return false;
			}
		}

	}

}
