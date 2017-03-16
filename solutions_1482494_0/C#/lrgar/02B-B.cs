using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Google.CodeJam2012
{
#if _ONLINE_JUDGE_
	[OnlineJudge.Task("CodeJam12 02B-B")]
#endif
	class Task02B_B
	{
		private InputTokenizer input = new InputTokenizer();
		private TextWriter output = Console.Out;

		private void Solve()
		{
			int T;
			input.Line().Read(out T);

			for (int _T = 0; _T < T; ++_T) {
				int N;
				input.Line().Read(out N);

				int[] a = new int[N], b = new int[N];
				for (int i = 0; i < N; ++i) {
					input.Line().Read(out a[i]).Read(out b[i]);
				}

				int p = 1;
				for (int i = 0; i < N; ++i) p *= 3;

				int[,] dp = new int[40, p];
				for (int t = 0; t < 40; ++t) {
					for (int i = 0; i < p; ++i) {
						dp[t, i] = 0x3f3f3f3f;
					}
				}

				dp[0, 0] = 0;

				for (int t = 0; t <= 20; ++t) {
					for (int i = 0; i < p; ++i) {
						if (dp[t, i] > 100) continue;

						int[] tmp = new int[N];
						for (int j = 0, k = i; j < N; ++j, k /= 3) tmp[j] = k % 3;
						for (int j = 0; j < N; ++j) {
							if (tmp[j] == 0 && a[j] <= t) {
								tmp[j] = 1;
								int r = 0;
								for (int s = 0; s < N; ++s) r = r * 3 + tmp[s];
								dp[t + 1, r] = Math.Min(dp[t + 1, r], dp[t, i] + 1);
								tmp[j] = 0;
							}

							if (tmp[j] == 1 && b[j] <= t) {
								tmp[j] = 2;
								int r = 0;
								for (int s = 0; s < N; ++s) r = r * 3 + tmp[s];
								dp[t + 1, r] = Math.Min(dp[t + 1, r], dp[t, i] + 1);
								tmp[j] = 1;
							}

							if (tmp[j] == 0 && b[j] <= t) {
								tmp[j] = 2;
								int r = 0;
								for (int s = 0; s < N; ++s) r = r * 3 + tmp[s];
								dp[t + 2, r] = Math.Min(dp[t + 2, r], dp[t, i] + 1);
								tmp[j] = 0;
							}
						}
					}
				}

				int v = 0;
				for (int i = 0; i < N; ++i) v = v * 3 + 2;

				if (dp[N * 2, v] < 100)
					output.WriteLine("Case #{0}: {1}", _T + 1, dp[N * 2, v]);
				else
					output.WriteLine("Case #{0}: Too Bad", _T + 1);
			}
		}

		public static void Main()
		{
			var obj = new Task02B_B();
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
				v = double.Parse(_tokens[_offset++].Replace('.', '.'));
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
