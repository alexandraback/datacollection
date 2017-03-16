using System;
using System.Collections.Generic;
using System.Data;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
	class Program
	{
		static void Main(string[] args)
		{
			var inputStream = new StreamReader(@"..\..\input.txt");
			var outputStream = new StreamWriter(@"..\..\output.txt");
			new Program().Solve(inputStream, outputStream);
			inputStream.Close();
			outputStream.Close();
		}

		private void Solve(StreamReader inputStream, StreamWriter outputStream)
		{
			int T = int.Parse(inputStream.ReadLine());
			for (int t = 0; t < T; t++)
			{
				string line = inputStream.ReadLine();
				int len = int.Parse(line.Split(' ').Last());
				var keys = inputStream.ReadLine();
				var word = inputStream.ReadLine();

				outputStream.Write("Case #{0}: ", t + 1);
				Solve(len, keys, word, outputStream);
			}
		}


		void Solve(int fullLength, string keyboard, string word, StreamWriter outputStream)
		{
			int mx = CalcMaximum(word, fullLength);
			
			Dictionary<char, BigInteger> keys = new Dictionary<char, BigInteger>();
			foreach (var k in keyboard)
			{
				if (!keys.ContainsKey(k))
					keys.Add(k, 0);
				keys[k]++;
			}

			BigInteger[,,] dp = new BigInteger[fullLength + 1, mx + 1, word.Length + 1];
			dp[0, 0, 0] = 1;

			for (int pos = 0; pos < fullLength; pos++)
				for (int comm = 0; comm < word.Length; comm++)
					for (int has = 0; has <= mx; has++)
					{
						if (dp[pos, has, comm] == 0)
							continue;

						foreach (KeyValuePair<char, BigInteger> pair in keys)
						{
							string s2 = word.Substring(0, comm) + pair.Key;
							var ways = dp[pos, has, comm]*pair.Value;
							int comm2 = CalcCross(s2, word);
							int has2 = has;
							if (s2 == word)
								has2++;

							dp[pos + 1, has2, comm2] += ways;
						}
					}

			BigInteger sum = 0;
			for (int comm = 0; comm < word.Length; comm++)
				for (int has = 0; has <= mx; has++)
					sum += dp[fullLength, has, comm]*has;

			BigInteger all = 1;
			for (int i = 0; i < fullLength; i++)
				all *= keyboard.Length;

			//sum / all
			BigInteger dop = BigInteger.Parse("1000000000000000");
			sum *= dop;
			sum /= all;

			double dd = (double) sum;
			dd /= 1000000000000000;
			dd = mx - dd;

			foreach (var c in word)
			{
				if (!keys.ContainsKey(c))
					dd = 0;
			}

			outputStream.WriteLine(dd.ToString("n10"));
		}

		private int CalcCross(string a, string b)
		{
			for (int cross = Math.Min(a.Length, b.Length - 1); cross >= 0; cross--)
			{
				if (a.Substring(a.Length - cross) == b.Substring(0, cross))
				{
					return cross;
				}
			}
			return -1;
		}

		private int CalcMaximum(string word, int fullLength)
		{
			string cur = "";
			int answer = 0;

			while (cur.Length < fullLength)
			{
				int cross = CalcCross(cur, word);
				cur += word.Substring(cross);
				
				if (cur.Length <= fullLength)
					answer++;
			}

			return answer;
		}
	}
}
