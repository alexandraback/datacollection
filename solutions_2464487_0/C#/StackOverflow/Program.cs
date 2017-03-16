using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SpeakingInTongues
{
	class Program
	{
		static void Main(string[] args)
		{
			char[] alpha = new char[26];
			bool[] read = new bool[26];

			Train(alpha, read, "our language is impossible to understand", "ejp mysljylc kd kxveddknmc re jsicpdrysi");
			Train(alpha, read, "there are twenty six factorial possibilities", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
			Train(alpha, read, "so it is okay if you want to just give up", "de kr kd eoya kw aej tysr re ujdr lkgc jv");
			Train(alpha, read, "aoz", "yeq");
			for (int i = 0; i < 26; i++)
			{
				if (!read[i])
				{
					alpha[25] = (char)('a' + i);
				}
			}



			int N = int.Parse(Console.ReadLine());
			for (int i = 0; i < N; i++)
			{
				string s = Console.ReadLine();

				Console.Write("Case #{0}: ", i + 1);
				for (int j = 0; j < s.Length; j++)
				{
					if (s[j] == ' ')
						Console.Write(' ');
					else
						Console.Write(alpha[s[j] - 'a']);
				}

				Console.WriteLine();
			}
		}

		private static void Train(char[] alpha, bool[] read, string p1, string p2)
		{
			for (int i = 0; i < p1.Length; i++)
			{
				if (p2[i] != ' ')
				{
					alpha[p2[i] - 'a'] = p1[i];
					read[p1[i] - 'a'] = true;
				}
			}
		}
	}
}
