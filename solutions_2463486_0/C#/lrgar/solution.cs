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
	[OnlineJudge.Task("CodeJam13 01C")]
#endif
	class Task01C
	{
		private class Solver
		{
			private InputTokenizer input = new InputTokenizer();
			private TextWriter output = Console.Out;

			public void Solve()
			{
				int T;
				input.Line().Read(out T);

				var fairAndSquaresList = new List<long>();
				foreach (var n in GetPalindromes())
				{
					var square = n * n;
					if (square == Invert(square)) fairAndSquaresList.Add(square);
				}

				for (int _T = 0; _T < T; ++_T)
				{
					long A, B;
					input.Line().Read(out A).Read(out B);

					int left = fairAndSquaresList.BinarySearch(A);
					if (left < 0) left = ~left;

					int right = fairAndSquaresList.BinarySearch(B);
					if (right < 0) right = ~right; else ++right;

					output.WriteLine("Case #{0}: {1}", _T + 1, right - left);
				}
			}

			private int Invert(int n)
			{
				int m = 0;
				for (int k = n; k != 0; k /= 10) m = m * 10 + k % 10;
				return m;
			}

			private long Invert(long n)
			{
				long m = 0;
				for (long k = n; k != 0; k /= 10) m = m * 10 + k % 10;
				return m;
			}

			private IEnumerable<long> GetPalindromes()
			{
				for (int i = 1; i < 10; ++i) yield return i;

				for (int i = 1; i < 10; ++i) yield return i * 10 + i;

				for (int i = 10; i < 10000; i *= 10)
				{
					for (int j = i; j < i * 10; ++j)
						yield return j * i + Invert(j / 10);

					for (int j = i; j < i * 10; ++j)
						yield return j * i * 10 + Invert(j);
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
