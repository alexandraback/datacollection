using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace C
{
    class Program
    {
        static void Main(string[] args)
        {
            using (FileStream fileInputStream = new FileStream("C-large.in", FileMode.Open, FileAccess.Read))
            using (TextReader fileInputReader = new StreamReader(fileInputStream))
            using (FileStream fileOutputStream = new FileStream("output.txt", FileMode.Create, FileAccess.Write))
            using (TextWriter fileOutputWriter = new StreamWriter(fileOutputStream))
            {
                int caseNumber = int.Parse(fileInputReader.ReadLine());

                for (int caseCounter = 1; caseCounter <= caseNumber; ++caseCounter)
                {
                    string[] caseBuffer = fileInputReader.ReadLine().Split(' ');
                    int c = int.Parse(caseBuffer[0]);
                    int d = int.Parse(caseBuffer[1]);
                    int v = int.Parse(caseBuffer[2]);

                    List<int> originalCoinBuffer = new List<int>();
                    string[] coinBuffer = fileInputReader.ReadLine().Split(' ');
                    for (int i = 0; i < d; ++i)
                    {
                        originalCoinBuffer.Add(int.Parse(coinBuffer[i]));
                    }
                    originalCoinBuffer.Sort();

                    int minNewDenom = 0;
                    if (originalCoinBuffer[0] != 1)
                    {
                        ++minNewDenom;
                        originalCoinBuffer.Add(1);
                        originalCoinBuffer.Sort();
                    }

                    int nextCoinPos = 1;
                    long currentEnsuredAmount = c;
                    while (currentEnsuredAmount < v)
                    {
                        if (nextCoinPos < originalCoinBuffer.Count)
                        {
                            if (originalCoinBuffer[nextCoinPos] <= currentEnsuredAmount + 1)
                            {
                                currentEnsuredAmount = originalCoinBuffer[nextCoinPos] * c + currentEnsuredAmount;
                                ++nextCoinPos;
                                continue;
                            }
                        }
                        ++minNewDenom;
                        currentEnsuredAmount = (currentEnsuredAmount + 1) * c + currentEnsuredAmount;
                    }

                    fileOutputWriter.WriteLine(string.Format("Case #{0}: {1}", caseCounter, minNewDenom));
                }

                fileOutputWriter.Close();
                fileOutputStream.Close();

                fileInputReader.Close();
                fileInputStream.Close();
            }
        }
    }
}
