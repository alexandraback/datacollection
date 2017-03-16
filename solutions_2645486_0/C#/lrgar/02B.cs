using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace Google.CodeJam2013
{
#if _ONLINE_JUDGE_
	[OnlineJudge.Task("CodeJam13 02B")]
#endif
	class Task02B
	{
		private class Solver
		{
			private InputTokenizer input = new InputTokenizer();
			private TextWriter output = Console.Out;

			public void Solve()
			{
				int T;
				input.Line().Read(out T);

				int E, R, N;
				int[] v;

				for (int _T = 0; _T < T; ++_T)
				{
					input.Line().Read(out E).Read(out R).Read(out N)
							 .Line().Read(N, out v);

					int[,] dp = new int[N + 1, E + 1];
					for (int i = 0; i < E; ++i) dp[0, i] = -10000000;
					dp[0, E] = 0;

					for (int i = 1; i <= N; ++i)
						for (int j = 0; j <= E; ++j)
							for (int k = 0; k <= j; ++k)
							{
								dp[i, Math.Min(j - k + R, E)] = Math.Max(dp[i, Math.Min(j - k + R, E)], dp[i - 1, j] + v[i - 1] * k);
							}

					int best = -1;
					for (int i = 0; i <= E; ++i) best = Math.Max(best, dp[N, i]);
					output.WriteLine("Case #{0}: {1}", _T + 1, best);
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
