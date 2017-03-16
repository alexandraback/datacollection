using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TheRepeater
{
    class Program
    {
        static void Main(string[] args)
        {
            var strL = File.ReadAllLines("data_in.txt");
            List<string> res = new List<string>();
            int nCases = int.Parse(strL[0]);
            int cLines = 1;
            for (int cCases = 0; cCases < nCases; ++cCases)
            {
                int nStrings = int.Parse(strL[cLines++]);
                List<string> strings = new List<string>();
                for (int cStr = 0; cStr < nStrings; ++cStr)
                {
                    strings.Add(strL[cLines++]);
                }
                int resu = new Calc(strings).Calculate();
                    // another way...
                    int resu2 = Calc2(strings);

                if (resu!=resu2)
                {
                    Debugger.Break();
                }
                string answer = "Case #" + (cCases + 1) + ": " + (resu == -1 ? "Fegla Won" : resu.ToString());
                res.Add(answer);
                Console.WriteLine(answer);
            }
            File.WriteAllLines("data_out.txt", res);
        }

        private static int Calc2(List<string> strings)
        {
            {
                int pos1 = 0;
                int pos2 = 0;
                int curSum = 0;
                while (true)
                {
                    if (pos1 >= strings[0].Length || pos2 >= strings[1].Length)
                    {
                        if (pos1 >= strings[0].Length && pos2 >= strings[1].Length)
                            return curSum;
                        return -1;
                    }
                    char curChar = strings[0][pos1];
                    int count1 = 0;
                    int count2 = 0;
                    while ((pos1<strings[0].Length) && (strings[0][pos1]==curChar))
                    {
                        ++count1;
                        ++pos1;
                    }
                    while ((pos2 < strings[1].Length) && (strings[1][pos2] == curChar))
                    {
                        ++count2;
                        ++pos2;
                    }
                    if (count2 == 0)
                        return -1;
                    curSum += Math.Abs(count1 - count2);
                }
                return curSum;
            }

        }
    }
}
