using System;
using System.IO;
using System.Linq;

namespace Lawnmower
{
    class Program
    {
        static void Main(string[] args)
        {
            int lawnsCount;
            var lawns = FileReader.GetLawns(args[0], out lawnsCount);
            var resultString = string.Empty;
            for (int index = 0; index < lawns.Count; index++)
            {
                var lawn = lawns[index];
                if (!string.IsNullOrEmpty(resultString))
                    resultString += "\r\n";
                resultString += string.Format("Case #{0}: {1}", index + 1, CheckLawnMatrix(lawn) ? "YES" : "NO");
                //Console.WriteLine("Case #{0}: {1}", index, CheckLawnMatrix(lawn) ? "YES" : "NO");
            }
            File.WriteAllText("result1.txt", resultString);
            Console.WriteLine(resultString);
            Console.ReadKey();
        }

        private static bool CheckLawnMatrix(byte[,] lawnMatrix)
        {
            //var passed = true;
            var columns = lawnMatrix.GetLength(0);
            var rows = lawnMatrix.GetLength(1);

            for (int i = 0; i < columns; i++)
            {
                var maxColumnValue = Enumerable.Range(0, rows).Select(n => lawnMatrix[i, n]).Max();
                for (int j = 0; j < rows; j++)
                {
                    var currentValue = lawnMatrix[i, j];
                    if (currentValue >= maxColumnValue)
                        continue;

                    var minRowValue = Enumerable.Range(0, columns).Select(n => lawnMatrix[n, j]).Max();
                    if (minRowValue > currentValue)
                        return false;
                }
            }
            return true;
        }
    }
}
