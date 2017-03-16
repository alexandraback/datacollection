using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Google.CodeJam2012
{
#if _ONLINE_JUDGE_
	[OnlineJudge.Task("CodeJam12 01B")]
#endif
	class Task01B
	{
		private InputTokenizer input = new InputTokenizer();
		private TextWriter output = Console.Out;

		private void Solve()
		{
			int T, N, S, p;
			int[] t, normal = new int[31], surprising = new int[31];

			for (int i = 0; i <= 30; ++i) normal[i] = (i + 2) / 3;

			for (int i = 2; i <= 28; ++i) surprising[i] = (i + 4) / 3;

			input.Line().Read(out T);
			for (int _T = 0; _T < T; ++_T) {
				input.Line().Read(out N).Read(out S).Read(out p).Read(N, out t);

				int answer = 0, maybe = 0;
				for (int i = 0; i < N; ++i)
					if (normal[t[i]] >= p)
						++answer;
					else if (normal[t[i]] < p && 2 <= t[i] && t[i] <= 28 && surprising[t[i]] >= p)
						++maybe;
				answer += Math.Min(maybe, S);

				output.WriteLine("Case #{0}: {1}", _T + 1, answer);
			}
		}

		public static void Main()
		{
			var obj = new Task01B();
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
