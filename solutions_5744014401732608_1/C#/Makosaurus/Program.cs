using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Slides
{
    class Program
    {
        private static long sCurCase = 1;

        static void Main(string[] args)
        {
            string inputFilepath = args[0];
            string outputFilepath = inputFilepath.Replace(".in", ".out");

            if (File.Exists(outputFilepath))
            {
                try
                {
                    File.Delete(outputFilepath);
                }
                catch (Exception ex)
                {
                    throw new Exception("Couldn't clear output file! is it held by another program?", ex);
                }
            }

            using (StreamReader reader = new StreamReader(File.OpenRead(inputFilepath)))
            {
                long numCases = long.Parse(reader.ReadLine().Trim());
                using (StreamWriter writer = new StreamWriter(File.OpenWrite(outputFilepath)))
                {
                    for (long i = 0; i < numCases; i++)
                    {
                        handleCase(reader, writer);
                    }
                }
            }
        }

        private static void WriteCaseResult(StreamWriter writer, string res)
        {
            writer.WriteLine("Case #{0}: {1}", sCurCase++, res);
        }

        private static void handleCase(StreamReader reader, StreamWriter writer)
        {
            string input = reader.ReadLine();
            string[] inputParts = input.Split(' ');
            int b = int.Parse(inputParts[0]);
            ulong m = ulong.Parse(inputParts[1]);


            if (Math.Pow(2, b - 2) < m)
            {
                WriteCaseResult(writer, "IMPOSSIBLE");
                return;
            }

            StringBuilder sb = new StringBuilder(1000);
            sb.AppendLine("POSSIBLE");

            int[,] ans = new int[b, b];
            initializeAns(ans);

            int nodeIndex = b - 2;

            if (Math.Pow(2, b - 2) == m)
            {
                for (int i = 1; i < ans.GetLength(0); i++)
                {
                    ans[0, i] = 1;
                }
            }
            else {

                ulong temp = m;
                while (temp != 0)
                {
                    if (nodeIndex == 0)
                    {
                        if (temp == 1)
                        {
                            ans[0, ans.GetLength(0) - 1] = 1;
                            temp--;
                        }
                    }

                    if ((temp & 1) == 1)

                    {
                        ans[0, nodeIndex] = 1;
                    }

                    nodeIndex--;
                    temp = temp >> 1;
                }
            }

            for (int i = 0; i < ans.GetLength(0); i++)
            {
                for (int j = 0; j < ans.GetLength(0); j++)
                {
                    sb.Append(ans[i, j]);
                }
                if (i != ans.GetLength(0) - 1)
                {
                    sb.AppendLine();
                }
            }

            WriteCaseResult(writer, sb.ToString());
        }

        private static void initializeAns(int[,] ans)
        {

            for (int srcIndex = 1; srcIndex < ans.GetLength(0) - 1; srcIndex++)
            {
                for (int dstIndex = srcIndex + 1; dstIndex < ans.GetLength(0); dstIndex++)
                {
                    ans[srcIndex, dstIndex] = 1;
                }
            }
        }



    }
}
