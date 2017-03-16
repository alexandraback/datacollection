using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Recycling
{
    class Program
    {
        const string InputPath = @"d:\Work\Current\CodeJam\2012\Recycling\C-small-attempt0.in";
        const string OutputPath = @"d:\Work\Current\CodeJam\2012\Recycling\C-small-attempt0.out";


        static void Main(string[] args)
        {

            var sr = new StreamReader(InputPath);
            var sw = new StreamWriter(OutputPath);

            int N = Int32.Parse(sr.ReadLine());
            for (int n = 1; n <= N; n++)
            {
                var x = SolveNextInput(sr);

                sw.WriteLine(GetCaseSolutionString(x, n));

            }
            sr.Close();
            sw.Close();
        }

        private static string GetCaseSolutionString(int result, int n)
        {
            return string.Format("Case #{0}: {1}", n, result);
        }

        private static int xxx = 0;
        private static int SolveNextInput(StreamReader sr)
        {
            string phrase = sr.ReadLine();
            var nums = phrase.Split(' ').Select(x => Int32.Parse(x));
            int A = nums.First();
            int B = nums.Skip(1).First();

            if (B < A)
            {
                var x = A;
                A = B;
                B = x;
            }
            int result = 0;

            bool[] numbers = new bool[B + 1];
            for (int i = 0; i <= B; i++)
            {
                if (i < A)
                    numbers[i] = false;
                else
                {
                    numbers[i] = true;
                }
            }

            
            //var sw = new StreamWriter(OutputPath + "test" + xxx++);
            for (int j = A; j <= B; j++)
            {
                List<int> rn = CalcAllRecycledNumbers(j).Where(x => (x >= A && x <= B)).Distinct().ToList();
                if (numbers[j])
                {
                    numbers[j] = false;
                    var cnt = rn.Count;
                    result += cnt*(cnt - 1)/2;
                    foreach (var r in rn)
                    {
                        numbers[r] = false;
                    }
                }
                
                //bool notFoundYet = true;
                ////sw.Write("" + j + ": ");
                //foreach (var r in rn)
                //{
                //    if (r > j && r <= B && numbers[r])
                //    {
                //        numbers[r] = false;
                //        if (notFoundYet)
                //        {
                //            //notFoundYet = false;
                //            result++;
                //            //for (int i = 0; i < rn.Count; i++)
                //            //{
                //                //sw.Write("" + rn[i] + " ");
                //            //}

                //        }
                //    }
                //}
                ////sw.WriteLine();
            }
            //sw.Close();
            
            

            return result;
        }

        private static List<int> CalcAllRecycledNumbers(int n)
        {
            var s = n.ToString();
            int l = s.Length;
            var res = new List<int>();
            var ls = new List<string>();
            string last = n.ToString();
            ls.Add(last);
            for (int i = 1; i < l; i++)
            {
                last = ShiftNumber(last);
                ls.Add(last);
            }
            res = ls.Select(x => int.Parse(x)).ToList();

            return res;
        }

        private static string ShiftNumber(string s)
        {
            var s1 = s.Substring(1) + s[0];
            return s1;
        }
    }
}
