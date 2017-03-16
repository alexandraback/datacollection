using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Codejam2015
{
    class Program
    {
        static List<int> audienceList = new List<int>();
        static void Main(string[] args)
        {
            FileStream fs = new FileStream("A-large.in", FileMode.Open, FileAccess.Read);
            FileStream fs2 = new FileStream("output.out", FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(fs2);
            StreamReader sr = new StreamReader(fs);

            int T = int.Parse(sr.ReadLine());
            int ans = 0;
            for (int i = 0; i < T; i++)
            {
                audienceList.Clear();
                string[] items = sr.ReadLine().Split(' ');
                int[] resultArray = new int[items[1].Length];

                foreach (char c in items[1])
                {
                    audienceList.Add(int.Parse(c.ToString()));
                }

                for (int j = audienceList.Count - 1; j >= 0; j--)
                {
                    if (j <= Audience(j))
                    {
                        resultArray[j] = 0;
                    }
                    else
                    {
                        resultArray[j] = j - Audience(j);
                    }
                }

                int result = resultArray.Max();
                sw.WriteLine(string.Format("Case #{0}: {1}", i + 1, result));
            }
            sr.Close();
            sw.Close();
            fs.Close();
            fs2.Close();
        }

        private static int Audience(int maxIndex)
        {
            int sumOfShyness = 0;

            for (int i = 0; i < maxIndex; i++)
            {
                sumOfShyness += audienceList[i];
            }
            return sumOfShyness;
        }
    }
}
