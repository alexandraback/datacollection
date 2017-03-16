using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Codejam2ndSmall
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("input.txt");
            StreamWriter sw = new StreamWriter("output.txt");
            int testCase = Convert.ToInt32(sr.ReadLine());
            for (int i = 0; i < testCase; i++)
            {
                string inp = sr.ReadLine();
                string[] inp1 = inp.Split();
                int constent = Convert.ToInt32(inp1[0]);
                double[] score = new double[constent];
                double totalScore = 0;
                for (int j = 0; j < constent; j++)
                {
                    score[j] = Convert.ToDouble(inp1[j + 1]);
                    totalScore = totalScore + score[j];
                }
                double avg = totalScore / constent;
                List<double> req = new List<double>();
                double newSum = 0;
                for (int j = 0; j < constent; j++)
                {
                    if (score[j] <= (avg * 2))
                    {
                        req.Add(score[j]);
                        newSum = newSum + score[j];
                    }
                }
                double newAvg = (newSum + totalScore) / req.Count;
                double ans=0;
                sw.Write("Case #" + (i + 1) + ":");
                Console.Write("Case #" + (i + 1) + ":");
                for (int j = 0; j < constent; j++)
                {
                    if (score[j] <= (avg * 2))
                    {
                        ans = ((newAvg - score[j]) * 100) / totalScore;
                        sw.Write(" "+ans);
                        Console.Write(" " + ans);
                    }
                    else
                    {
                        sw.Write(" "+0);
                        Console.Write(" " + 0);
                    }

                }
                ///ToDo
                Console.WriteLine();
                sw.WriteLine();
                //sw.WriteLine("Case #" + (i + 1) + ": " + swap);
                //Console.WriteLine("Case #" + (i + 1) + ": " + swap);
            }
            sw.Close();
            Console.ReadKey();
        }
    }
}
