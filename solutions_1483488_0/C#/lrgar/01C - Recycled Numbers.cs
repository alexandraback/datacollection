using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Google.CodeJam2012
{
#if _ONLINE_JUDGE_
	[OnlineJudge.Task("CodeJam12 01C")]
#endif
	class Task01C
	{
		private InputTokenizer input = new InputTokenizer();
		private TextWriter output = Console.Out;

		struct Pair : IComparable<Pair>
		{
			public int n, m;

			public int CompareTo(Pair other)
			{
				if (m != other.m) return m - other.m;
				return n - other.n;
			}
		}

		private void Solve()
		{
			int T, A, B;
			input.Line().Read(out T);

			SortedSet<Pair> pairs = new SortedSet<Pair>();
			for (int p = 10, k = 1; p <= 10000000; p *= 10, ++k)
				for (int i = p / 10, h = Math.Min(2000001, p); i < h; ++i)
					for (int j = 0, t = i; j < k; ++j) {
						if (i < t) pairs.Add(new Pair { n = i, m = t });
						t = t % 10 * p / 10 + t / 10;
					}

			for (int _T = 0; _T < T; ++_T) {
				input.Line().Read(out A).Read(out B);
				output.WriteLine("Case #{0}: {1}", _T + 1, pairs.Count(pair => A <= pair.n && pair.m <= B));
			}
		}

		public static void Main()
		{
			var obj = new Task01C();
			obj.Solve();
		}

		#region
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
