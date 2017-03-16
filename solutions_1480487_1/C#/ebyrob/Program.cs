using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace SafetyInNumbers
{
    class Program
    {   
        //X = sum of Ji
        //Ji judges score for i
        //Yi audience % for i
        //Ji+X*Yi

        //find Yi for each contestant that prevents them from being single lowest score.
        protected static string Calculate(int []scores)
        {
            double[] minPercents = new double[scores.Length];

            //at min elim: all scores are tied up...  Find that score...
            
            //bring all scores to highest score.  If leftovers, distribute evenly.
            
            //2*sum / N = avg score.  
            double Jsum = 0;
            for (int i = 0; i < scores.Length; ++i)
            {
                Jsum += scores[i];
            }

            double Tsum = 2 * Jsum;
            double avg = Tsum / scores.Length;

            //ans = (avg - Ji)/N
            for (int i = 0; i < scores.Length; ++i)
            {
                minPercents[i] = (avg - scores[i]) / Jsum;
            }

            //doesn't handle Ji values above avg...

            //distribute points only to values below average.  drop 2*sum for avg calc by points above avg

            int N = scores.Length;
            bool changed = true;
            while (changed)
            {
                changed = false;
                for (int i = 0; i < scores.Length; ++i)
                {
                    if (avg < scores[i] && minPercents[i] != 0)
                    {
                        changed = true;
                        Tsum -= scores[i];
                        minPercents[i] = 0;
                        --N;
                    }
                }
                avg = Tsum / N;
            }

            for (int i = 0; i < scores.Length; ++i)
            {
                if (avg >= scores[i])
                    minPercents[i] = (avg - scores[i]) / Jsum;
            }

            string strResult = "";
            for (int i = 0; i < scores.Length; ++i)
            {
                strResult += string.Format("{0:0.000000} ", 100 * minPercents[i]);
            }
            return strResult.Trim();
        }

        static void Main(string[] args)
        {
            string inFileName = args[0];
            string outFileName = inFileName.Split('.')[0] + ".out";
            StreamReader inFile = new StreamReader(inFileName);
            StreamWriter outFile = new StreamWriter(outFileName);

            DateTime start = DateTime.Now;

            List<string> lines = new List<string>();
            int nCases = int.Parse(inFile.ReadLine());
            for (int iCase = 0; iCase < nCases; ++iCase)
            {
                string []line = inFile.ReadLine().Split(' ');
                int[] scores = new int[int.Parse(line[0])];
                for (int i = 0; i < scores.Length; ++i)
                {
                    scores[i] = int.Parse(line[i + 1]);
                }

                string result = Calculate(scores);

                outFile.WriteLine("Case #{0}: {1}", iCase + 1, result);
                outFile.Flush();
            }
            inFile.Close();
            outFile.Close();

            Console.WriteLine("Elapsed Time: {0:t}", DateTime.Now - start);
        }
    }
}
