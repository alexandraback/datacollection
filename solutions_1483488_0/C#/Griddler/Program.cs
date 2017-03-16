using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Q3
{
	class Program
	{
		static void Main(string[] args)
		{
			string[] aLines = File.ReadAllLines(args[0]);

			int nLineCount = System.Convert.ToInt32(aLines[0]);

			for (int nLine = 1; nLine <= nLineCount; nLine++)
			{
				string strLine = aLines[nLine];
				string strOutLine = "Case #" + nLine + ": ";

				string[] astrValues = strLine.Split(" ".ToCharArray());
				int A = System.Convert.ToInt32(astrValues[0]);
				int B = System.Convert.ToInt32(astrValues[1]);

				int nSuccessCount = 0;
				for (int n = A; n < B; n++)
				{
					Dictionary<int, bool> Results = new Dictionary<int, bool>();

					string strN = n.ToString();

					for (int i = strN.Length - 1; i > 0; i--)
					{
						string strNMod = strN.Substring(i) + strN.Substring(0, i);
						int nMod = System.Convert.ToInt32(strNMod);
						if (nMod > n && nMod <= B)
						{
							Results[nMod] = true;
						}
					}

					//for (int m = n + 1; m <= B; m++)
					//{
					//    string strM = m.ToString();

					//    if (IsRecycledNumber(strN, strM))
					//    {
					//        Results2 += strM + ",";
					//    }
					//}

					nSuccessCount += Results.Count;
				}

				strOutLine += nSuccessCount;

				Console.WriteLine(strOutLine);
			}
		}

		static bool IsRecycledNumber(string strN, string strM)
		{
			for (int i = 0; i < strM.Length - 1; i++)
			{
				int j = strM.Length - i - 1;
				string strMMod = strM.Substring(j) + strM.Substring(0, j);
				if (strMMod == strN) return true;
			}

			return false;
		}
	}
}
