using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            const string inputFile = @"D:\Projects\C#\GoogleCodeJam\2016\Round1B\CodeJam\CodeJam\B-small-attempt2.in";
            const string outputFile = @"D:\Projects\C#\GoogleCodeJam\2016\Round1B\CodeJam\CodeJam\B-small2.out";

            var sr = new StreamReader(inputFile);
            var sw = new StreamWriter(outputFile);

            int testCases = int.Parse(sr.ReadLine());
            for (int i = 1; i <= testCases; i++)
            {
                var testCase = ProblemB.ParseCase(sr);
                var result = "Case #" + i + ": " + testCase.SolveCase();
                sw.WriteLine(result);
            }
            sw.Flush();
            sw.Close();
        }
    }

    public class Result
    {
        public int Coders { get; set; }
        public int Jammers { get; set; }
        public int Score { get; set; } 
    }

    public class ProblemB
    {
        public string C { get; set; }
        public string J { get; set; }

        const int JAMMERS = 1;
        const int CODERS = 2;
        const int TIED = 3;

        public static ProblemB ParseCase(StreamReader sr)
        {
            var parameters = sr.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            
            return new ProblemB { C = parameters[0], J=parameters[1] };
        }


        public String SolveCase()
        {
            var digC = C.ToList();
            var digJ = J.ToList();

            var result = Search(digC, digJ, 0, 0);
            return result.Coders.ToString().PadLeft(C.Length, '0') + " " + result.Jammers.ToString().PadLeft(C.Length, '0');
        }

        public Result Search(List<char> digC, List<char> digJ, int c, int j)
        {
            if(digC.Count() == 0)
            {
                return new Result { Coders = c, Jammers = j, Score = Math.Abs(c - j) };
            }
            
            var coders = new List<int>();
            var jammers = new List<int>();
            coders = Enumerable.Range(0, 10).ToList();
            jammers = Enumerable.Range(0, 10).ToList();

            if (digC[0] != '?')
                coders = new List<int>() { int.Parse(digC[0].ToString()) };

            if (digJ[0] != '?')
                jammers = new List<int>() { int.Parse(digJ[0].ToString()) };

            /*
            if (digC[0] == '?' && digJ[0] == '?')
            {
                coders.AddRange(new List<int>() { 0, 1, 9 });
                jammers.AddRange(new List<int>() { 0, 1, 9 });
            }
            else
            {
                if (digC[0] != '?')
                    coders.Add(int.Parse(digC[0].ToString()));
                else
                    coders.AddRange(new List<int>() { 0, 1, 9, int.Parse(digJ[0].ToString()) });

                if (digJ[0] != '?')
                    jammers.Add(int.Parse(digJ[0].ToString()));
                else
                    jammers.AddRange(new List<int>() { 0, 1, 9, int.Parse(digC[0].ToString()) });
            }*/

            var nextDigC = digC.Skip(1).ToList();
            var nextDigJ = digJ.Skip(1).ToList();

            Result bestSoFar = null;
            foreach (var nc in coders)
            {
                var cc = 10 * c + nc;
                foreach (var nj in jammers)
                {
                    var jj = 10 * j + nj;
                    var next = Search(nextDigC, nextDigJ, cc, jj);
                    if (bestSoFar == null)
                        bestSoFar = next;
                    else if (next.Score < bestSoFar.Score)
                        bestSoFar = next;
                    else if (next.Score == bestSoFar.Score)
                    {
                        if (next.Coders < bestSoFar.Coders)
                            bestSoFar = next;
                        else if (next.Coders == bestSoFar.Coders && next.Jammers < bestSoFar.Jammers)
                            bestSoFar = next;
                    }
                }
            }

            return bestSoFar;

        }

        public String SolveCase1()
        {
            var whoswinning = TIED;
            var coders = new List<char>();
            var jammers = new List<char>();

            var willwin = TIED;
            for(int i=0; i<C.Length; i++)
            {
                var c = C[i];
                var j = J[i];
                if (c != '?' && j != '?')
                {
                    if (c > j)
                    {
                        willwin = CODERS;
                    }              
                    else if(j > c)
                    {
                        willwin = JAMMERS;
                    }
                    if (c != j)
                        break;
                }
            }

            var lastchance = 0;
            for (int i = 0; i < C.Length; i++)
            {
                var c = C[i];
                var j = J[i];
                if (c == '?' && j == '?')
                    lastchance = i;

                if (c != '?' && j != '?' && c != j)
                    break;
            }

            for (int i=0; i< C.Length; i++)
            {
                var c = C[i];
                var j = J[i];
                if (c != '?')
                {
                    coders.Add(c);
                }
                else if(whoswinning == TIED && j != '?')
                {
                    coders.Add(j);
                }
                else if(whoswinning == TIED && j == '?')
                {

                    coders.Add('0');
                }
                else if(whoswinning == CODERS)
                {
                    coders.Add('0');
                }
                else if(whoswinning == JAMMERS)
                {
                    coders.Add('9');
                }

                if (j != '?')
                {
                    jammers.Add(j);
                }
                else if (whoswinning == TIED && c != '?')
                {
                    jammers.Add(c);
                }
                else if (whoswinning == TIED && c == '?')
                {
                    jammers.Add('0');
                }
                else if (whoswinning == CODERS)
                {
                    jammers.Add('9');
                }
                else if (whoswinning == JAMMERS)
                {
                    jammers.Add('0');
                }

                if(whoswinning == TIED)
                {
                    if(coders.Last() > jammers.Last())
                    {
                        whoswinning = CODERS;
                    }
                    if (coders.Last() < jammers.Last())
                    {
                        whoswinning = JAMMERS;
                    }
                }
            }
            return String.Join("", coders.Select(i => i.ToString())) + " " + String.Join("", jammers.Select(i => i.ToString()));
        }
    }
}
