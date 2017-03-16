using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Numerics;

namespace Google.CodeJam2013
{
#if _ONLINE_JUDGE_
	[OnlineJudge.Task("CodeJam13 02A")]
#endif
	class Task02A
	{
		private class Solver
		{
			private InputTokenizer input = new InputTokenizer();
			private TextWriter output = Console.Out;

			public static BigInteger CalculateInk(long rings, long rad)
			{
				// (r + 2i + 1) ^ 2 - (r + 2i) ^ 2
				// 2(r + 2i) + 1
				// 2r + 4i + 1
				// Sum (2r + 4i + 1), i = 0, 1, ... n
				// ((n + 1) * (2r + 1) + 4 Sum (i)), i = 0, 1, ... n
				// ((n + 1) * (2r + 1) + 2 n * (n - 1))), i = 0, 1, ... n
				return new BigInteger((rings + 1)) * (2 * rad + 1) + new BigInteger(2) * rings * (rings + 1);
			}

			private class Comparer : IComparer<long>
			{
				public long rad;

				public int Compare(long x, long y)
				{
					return CalculateInk(x, rad).CompareTo(CalculateInk(y, rad));
				}
			}

			public void Solve()
			{
				int T;
				input.Line().Read(out T);

				long r, t;
				for (int _T = 0; _T < T; ++_T)
				{
					input.Line().Read(out r).Read(out t);

					var precalculatedInk = new BigInteger[23572];
					var values = new long[23572];

					for (long i = 0, j = 0; i <= 707106780 + 30000; i += 30000, ++j) {
						precalculatedInk[j] = CalculateInk(i, r);
						values[j] = i;
					}

					long low, high;

					int index = Array.BinarySearch(precalculatedInk, t);
					low = values[index >= 0 ? index : ~index - 1];
					high = low + 30000;

					long best = low;
					for (long i = low; i <= high; ++i)
					{
						if (CalculateInk(i, r) > t) break;
						best = i;
					}

					output.WriteLine("Case #{0}: {1}", _T + 1, best + 1);
				}
			}
		}

		#region
		public static void Main()
		{
			var obj = new Solver();
			obj.Solve();
		}

		private class InputTokenizer
		{
			private List<string> _tokens = new List<string>();
			private int _offset = 0;

			public InputTokenizer()
			{
			}

			public InputTokenizer String(String s)
			{
				_tokens.AddRange(s.Split(new char[] { ' ', '\n', '\t', '\r' }, StringSplitOptions.RemoveEmptyEntries));
				return this;
			}

			public InputTokenizer Line()
			{
				return String(Console.In.ReadLine());
			}

			public String ReadLine()
			{
				return Console.In.ReadLine();
			}

			public InputTokenizer Read(out int v)
			{
				v = int.Parse(_tokens[_offset++]);
				return this;
			}

			public InputTokenizer Read(int n, out int[] v)
			{
				v = new int[n];
				for (int i = 0; i < n; ++i) Read(out v[i]);
				return this;
			}

			public InputTokenizer Read(out long v)
			{
				v = long.Parse(_tokens[_offset++]);
				return this;
			}

			public InputTokenizer Read(int n, out long[] v)
			{
				v = new long[n];
				for (int i = 0; i < n; ++i) Read(out v[i]);
				return this;
			}

			public InputTokenizer Read(out ulong v)
			{
				v = ulong.Parse(_tokens[_offset++]);
				return this;
			}

			public InputTokenizer Read(int n, out ulong[] v)
			{
				v = new ulong[n];
				for (int i = 0; i < n; ++i) Read(out v[i]);
				return this;
			}

			public InputTokenizer Read(out double v)
			{
				v = double.Parse(_tokens[_offset++].Replace('.', ','));
				return this;
			}

			public InputTokenizer Read(int n, out double[] v)
			{
				v = new double[n];
				for (int i = 0; i < n; ++i) Read(out v[i]);
				return this;
			}

			public InputTokenizer Read(out string v)
			{
				v = _tokens[_offset++];
				return this;
			}

			public InputTokenizer Read(int n, out string[] v)
			{
				v = new string[n];
				for (int i = 0; i < n; ++i) Read(out v[i]);
				return this;
			}
		}
		#endregion
	}
}
