using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemB
{
    class Program
    {
        const string InputPath = @"d:\Work\Current\CodeJam\2012-1A\2\B-small-attempt3.in";
        const string OutputPath = @"d:\Work\Current\CodeJam\2012-1A\2\B-small-attempt3.out";


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

        private static string GetCaseSolutionString(string result, int n)
        {
            return string.Format("Case #{0}: {1}", n, result);
        }

        private static string SolveNextInput(StreamReader sr)
        {
            string l1 = sr.ReadLine();
            int A = int.Parse(l1);
            var lst = new List<TDGame>();
            Dictionary<TDGame, int> dict= new Dictionary<TDGame, int>();
            for (int i = 0; i < A; i++)
            {
                l1 = sr.ReadLine();
                var t = l1.Split(' ').Select(x => int.Parse(x)).ToList();
                var tdGame = new TDGame() {Done = 0, T1 = t[0], T2 = t[1]};
                lst.Add(tdGame);
                dict.Add(tdGame, 0);
            }

            var list1 = lst.OrderBy(t => (t.T1 * 10000 - t.T2)).ToList();
            var list2 = lst.OrderBy(t => (t.T2 * 10000 - t.T1)).ToList();
            var list21 = new List<TDGame>();
            int moves = 0;
            int stars = 0;

            while (true)
            {
                bool foundMove = false;
                for (int i = 0; i < list21.Count; i++)
                {
                    var tdGame = list21[i];

                    if (tdGame.Done == 1)
                    {
                        if (stars >= tdGame.T2)
                        {
                            foundMove = true;
                            moves++;
                            stars += 1;
                            tdGame.Done = 2;
                            list21.RemoveAt(i);
                            break;
                        }

                    }
                    else
                    {
                        list21.RemoveAt(i);
                        i--;
                    }
                }
                if (foundMove)
                {
                    continue;
                }

                for (int i = 0; i < list2.Count; i++)
                {
                    var td = list2[i];
                    if (td.Done == 0)
                    {
                        if (td.T2 <= stars)
                        {
                            foundMove = true;
                            moves++;
                            stars += 2;
                            td.Done = 2;
                            list2.RemoveAt(i);
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        list2.RemoveAt(i);
                        i--;
                    }
                }


                if (foundMove)
                {
                    continue;
                }
                // else only 21 moves
                for (int i = 0; i < list21.Count; i++)
                {
                    var tdGame = list21[i];

                    if (tdGame.Done == 1)
                    {
                        if (stars >= tdGame.T2)
                        {
                            foundMove = true;
                            moves++;
                            stars += 1;
                            tdGame.Done = 2;
                            list21.RemoveAt(i);
                            break;
                        }

                    }
                    else
                    {
                        list21.RemoveAt(i);
                        i--;
                    }
                }
                if (foundMove)
                {
                    continue;
                }
                // else - no 2 stars moves
                while (list1.Count > 0)
                {
                    TDGame tdGame = list1[0];
                    if (tdGame.Done == 0)
                    {
                        if(stars >= tdGame.T1)
                        {
                            foundMove = true;
                            moves++;
                            stars += 1;
                            tdGame.Done = 1;
                            list1.RemoveAt(0);
                            list21.Add(tdGame);
                        }
                        break;
                    }
                    else
                    {
                        list1.RemoveAt(0);
                    }
                }
                if (foundMove)
                {
                    continue;
                }

                break;
            }

            bool solved = true;
            foreach (var tdGame in lst)
            {
                if (tdGame.Done < 2)
                {
                    solved = false;
                    break;
                }
            }

            string result;
            if (solved)
            {
                result = moves.ToString();
            }
            else
            {
                result = "Too Bad";
            }
            return result;
        }

    }

    public class TDGame
    {
        public int T1 { get; set; }
        public int T2 { get; set; }
        public int Done { get; set; }
    }

}
