using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Q2
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

				string[] astrCells = strLine.Split(" ".ToCharArray());
				int nPersonCount = System.Convert.ToInt32(astrCells[0]);
				int nSurprisingCount = System.Convert.ToInt32(astrCells[1]);
				int nTargetBestScore = System.Convert.ToInt32(astrCells[2]);

				int nResultCount = 0;
				for (int nResult = 0; nResult < nPersonCount; nResult++)
				{
					int nThisPersonScore = System.Convert.ToInt32(astrCells[3 + nResult]);

					bool bSuccess = false;
					bool bSurprisingSuccess = false;

					for (int nFirstJudgeScore = 10; nFirstJudgeScore >= nTargetBestScore; nFirstJudgeScore--)
					{
						int nScore = nThisPersonScore - nFirstJudgeScore;
						if (nScore < 0) continue;
						int nSecondJudgeScore = nScore / 2 + (nScore % 2);
						int nThirdJudgeScore = nScore / 2;

						int nDiff1 = Math.Abs(nFirstJudgeScore - nSecondJudgeScore);
						int nDiff2 = Math.Abs(nThirdJudgeScore - nSecondJudgeScore);
						int nDiff3 = Math.Abs(nFirstJudgeScore - nThirdJudgeScore);
						int nHighestDiff = Math.Max(Math.Max(nDiff1, nDiff2), nDiff3);

						if (nHighestDiff <= 1)
						{
							// Allowed.
							bSuccess = true;
							bSurprisingSuccess = false;
							break;
						}
						else if (nHighestDiff <= 2 && nSurprisingCount > 0)
						{
							// Allowed.
							bSurprisingSuccess = true;
						}
					}

					if (bSurprisingSuccess && nSurprisingCount > 0)
					{
						bSuccess = true;
						nSurprisingCount--;
					}

					if (bSuccess)
					{
						nResultCount++;
					}
				}

				strOutLine += nResultCount;

				Console.WriteLine(strOutLine);
			}
		}
	}
}
