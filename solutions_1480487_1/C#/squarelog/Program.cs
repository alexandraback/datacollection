using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Round1bSafety
{
    class Program
    {
        static void Main(string[] args)
        {
            int count = int.Parse(Console.ReadLine());
            TextWriter tw = new StreamWriter("C:\\Users\\Aaron\\Documents\\Visual Studio 2010\\Projects\\CodeJame2012\\Round1bSafety\\largeoutput.txt");
         ;
            int curr = 0;

            while (curr++ < count)
            {
                string input = Console.ReadLine();
                int num = int.Parse(input.Split(' ')[0]);
                int[] scores = new int[200];
                int judgestotal = 0;
                for (int i = 0; i < num; i++)
                {
                    scores[i] = int.Parse(input.Split(' ')[i+1]);
                    judgestotal += scores[i];
                }

                int overall = judgestotal * 2;
                bool[] skip = new bool[200];
                
                double min = overall / num;
                int newNum = num;
                double left = 0;
                for (int i = 0; i < num; i++)
                {
                    if (scores[i] > min)
                    {
                        skip[i] = true;
                        newNum--;
                    }
                    else
                    {
                        skip[i] = false;
                        left += scores[i];
                    }
                }
                left += judgestotal;                
                min = left / newNum;
                double[] percents = new double[200];
                StringBuilder sb = new StringBuilder();
                double total = 0;
                for (int i = 0; i < num; i++)
                {
                    double amt = 0.0;
                    if (!skip[i])
                    {
                        //if (newNum != num)
                        //    amt = ((min - (double)scores[i]) / (double)left) * 100;
                        //else 
                            amt = ((min - (double)scores[i]) / (double)judgestotal) * 100;
                    }
                    total += amt;
                    sb.AppendFormat(" {0:0.000000}", amt);
                }
                
                tw.WriteLine("Case #{0}:{1}", curr,sb.ToString() );
                Console.WriteLine("Case #{0}:{1}  -- Total:{2}", curr, sb.ToString(), total);
            }

            tw.Close();
        }
    }
}
