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
			using (var io = new ContestIO(@"D:\Contests\input\GCJ2016_R1B_B\B-small-attempt1.in", @"D:\Contests\input\GCJ2016_R1B_B\B-small-attempt1.out"))
//            using (var io = new ContestIO(@"7
//1? 2?
//?2? ??3
//? ?
//?5 ?0
//1??? 2???
//2??? 1???
//?9??? ?1???"))
			{
				var t = io.Read();
				//io.Reader.ReadLine();
				for (var i = 0; i < t; i++)
				{
					var s = io.Reader.ReadLine();
					var parts = s.Split(' ');
					var arr1 = parts[0].ToArray();
					var arr2 = parts[1].ToArray();
					
					//var res = Solve(Copy(arr1), Copy(arr2), arr1, arr2);

					var res2 = SolveStupid(parts[0], parts[1]);
					//if (res2 != res)
					//{
					//    throw new Exception();
					//}

					io.WriteLine(string.Format("Case #{0}: {1}", (i + 1), res2));
				}
			}

			//Console.ReadLine();
		}


		static string SolveStupid(string s1, string s2)
		{
			var best1 = 0L;
			var best2 = 0L;
			var bestDelta = 999999;

			for (var i = 0; i <= 999; i++)
			{
				var r1 = i.ToString().PadLeft(s1.Length, '0');

				if (!ValidateStupid(r1, s1))
					continue;

				for (var j = 0; j <= 999; j++)
				{
					var r2 = j.ToString().PadLeft(s1.Length, '0');

					if (!ValidateStupid(r2, s2))
						continue;

					var delta = Math.Abs(i - j);
					if (delta < bestDelta)
					{
						bestDelta = delta;
						best1 = i;
						best2 = j;
					}
					else if (delta == bestDelta)
					{
						if (i < best1 || i == best1 && j < best2)
						{
							bestDelta = delta;
							best1 = i;
							best2 = j;
						}
					}
				}
			}

			return string.Format("{0} {1}", best1.ToString().PadLeft(s1.Length, '0'), best2.ToString().PadLeft(s1.Length, '0'));
		}
		static bool ValidateStupid(string s1, string s2)
		{
			if (s1.Length != s2.Length)
				return false;
			for (var i = 0; i < s2.Length; i++)
			{
				if (s2[i] != '?' && s2[i] != s1[i])
					return false;
			}
			return true;
		}

		static string Solve(char[] s1, char[] s2, char[] s1orig, char[] s2orig)
		{
			var pos = -1;

			for (var i = 0; i < s1.Length; i++)
			{
				var d1 = s1[i];
				var d2 = s2[i];
				if (d1 == d2)
				{
					if (d1 == '?')
					{
						s1[i] = '0';
						s2[i] = '0';
					}
				}
				else
				{
					if (d1 == '?')
					{
						s1[i] = s2[i];
					}
					else if (d2 == '?')
					{
						s2[i] = s1[i];
					}
					else
					{
						pos = i;
						break;
					}
				}
			}

			if (pos == -1)
			{
				return string.Format("{0} {1}", new string(s1), new string(s2));
			}
			else
			{
				var best = GetScore(pos, s1, s2, 0, 0, s1orig, s2orig);
				best = GetBest(best, GetScore(pos, s1, s2, 1, 0, s1orig, s2orig));
				best = GetBest(best, GetScore(pos, s1, s2, -1, 0, s1orig, s2orig));
				best = GetBest(best, GetScore(pos, s1, s2, 0, 1, s1orig, s2orig));
				best = GetBest(best, GetScore(pos, s1, s2, 0, -1, s1orig, s2orig));

				return string.Format("{0} {1}", best.Item1.ToString().PadLeft(s1.Length, '0'), best.Item2.ToString().PadLeft(s1.Length, '0'));
			}
		}

		static Tuple<long, long> GetBest(Tuple<long, long> best, Tuple<long, long> inc)
		{
			if (best == null)
				return inc;
			if (inc == null)
				return best;

			var d1 = Math.Abs(best.Item1 - best.Item2);
			var d2 = Math.Abs(inc.Item1 - inc.Item2);
			if (d2 < d1)
				return inc;
			if (d1 == d2)
			{
				if (inc.Item1 < best.Item1)
					return inc;
				if (inc.Item1 == best.Item1 && inc.Item2 < best.Item2)
					return inc;
			}
			return best;
		}
		static Tuple<long, long> GetScore(int pos, char[] s1, char[] s2, int delta1, int delta2, char[] s1orig, char[] s2orig)
		{
			var s1copy = Copy(s1);
			var s2copy = Copy(s2);
			var r1 = Update(pos, delta1, ref s1copy, s1orig);
			var r2 = Update(pos, delta2, ref s2copy, s2orig);
			if (r1 && r2)
			{
				for (var i = 0; i < s1.Length; i++)
				{
					var d1 = s1copy[i];
					var d2 = s2copy[i];
					if (d1 != d2)
					{
						if (d1 == '?' || d2 == '?')
							throw new Exception();

						return GetScoreInternal(i, s1copy, s2copy);
					}
				}
				throw new Exception();
			}
			else
				return null;
		}
		static bool Update(int pos, int delta, ref char[] s, char[] validation)
		{
			if (delta == 0)
				return true;

			if (pos == 0)
				return false;

			var s2 = new char[pos];
			Array.Copy(s, s2, pos);
			
			var val = long.Parse(new string(s2));
			val += delta;
			if (val < 0)
				return false;

			s2 = val.ToString().PadLeft(pos, '0').ToArray();
			if (s2.Length != pos)
				return false;

			for (var i = 0; i < pos; i++)
			{
				if (validation[i] != '?' && validation[i] != s2[i])
					return false;
			}

			var s3 = new char[s.Length];
			Array.Copy(s2, s3, pos);
			Array.Copy(s, pos, s3, pos, s.Length - pos);
			return true;
		}

		static Tuple<long, long> GetScoreInternal(int pos, char[] s1, char[] s2)
		{
			var d1 = s1[pos];
			var d2 = s2[pos];
			if (d1 == '?' || d2 == '?')
				throw new Exception();

			if (d1 > d2)
			{
				Fill(pos, s1, '0');
				Fill(pos, s2, '9');
			}
			else
			{
				Fill(pos, s1, '9');
				Fill(pos, s2, '0');
			}
			return new Tuple<long, long>(long.Parse(new string(s1)), long.Parse(new string(s2)));
		}
		static void Fill(int pos, char[] s, char val)
		{
			for (var i = pos + 1; i < s.Length; i++)
			{
				if (s[i] == '?')
					s[i] = val;
			}
		}
		static char[] Copy(char[] s)
		{
			char[] res = new char[s.Length];
			Array.Copy(s, res, s.Length);
			return res;
		}

	}

}
