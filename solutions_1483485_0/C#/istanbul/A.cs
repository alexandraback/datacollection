using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

// ONEMLI!
// Large input'lar icin cogunlukla overflow olusuyor.
// long yerine BigInteger kullan!
// double yerine decimal kullan!

namespace codejam.QualificationRound2012
{
	class A
	{
		static IOHelper io;
		static void Main(string[] args)
		{
			Dictionary<char, char> dic = new Dictionary<char, char>();

			var a = @"our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give upqz";
			var b = @"ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jvzq";

			for (var i = 0; i < a.Length; i++)
			{
				dic[b[i]] = a[i];
			}

			
			
			using (io = new IOHelper("A-small-0"))
			{
				int nCases = io.ReadInt();
				for (int _case = 1; _case <= nCases; _case++)
				{
					var str = io.ReadLine().ToCharArray();
					for (int i = 0; i < str.Length; i++)
					{
						str[i] = dic[str[i]];
					}
					io.WriteLine("Case #{0}: {1}", _case, new string(str));
				}
			}
		}
	}
}
