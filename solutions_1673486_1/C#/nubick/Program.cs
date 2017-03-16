using System;
using System.Globalization;
using System.IO;
using System.Linq;

namespace ProblemA
{
	class Program
	{
		static void Main(string[] args)
		{
			TextReader tr = new StreamReader("input.in");
			TextWriter tw = new StreamWriter("output.out");
			int N = int.Parse(tr.ReadLine());
			for (int t = 1; t <= N; t++)
			{
				int[] values = tr.ReadLine().Split(' ').Select(ch => int.Parse(ch)).ToArray();
				int A = values[0];
				int B = values[1];
				
				float[] probs = tr.ReadLine().Split(' ').Select(ch => float.Parse(ch, CultureInfo.InvariantCulture.NumberFormat)).ToArray();
				float res = Calculate(A, B, probs);
				tw.WriteLine(string.Format("Case #{0}: {1}", t, res.ToString(CultureInfo.InvariantCulture.NumberFormat)));
			}
			tw.Close();
			tr.Close();
		}

		private static float Calculate(int A, int B, float[] probs)
		{
			float[] probs_calc = GetProbFirstNCorrect(A, probs);
			float min = float.MaxValue;
			for (int back = 0; back <= A;back++ )
			{
				float p = probs_calc[A - back];
				min = Math.Min(min, p*(back + (B - (A - back)) + 1) + (1 - p)*(back + (B - (A - back)) + 1 + B + 1));
			}
			min = Math.Min(min, 1 + B + 1);
			return min;
		}

		private static float[] GetProbFirstNCorrect(int n, float[] probs)
		{
			float[] res = new float[n + 1];
			float mult = 1f;
			res[0] = mult;
			for (int i = 0; i < n; i++)
			{
				mult *= probs[i];
				res[i + 1] = mult;
			}
			return res;
		}
	}
}
