using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Googlers
{
    class Program
    {
        static bool ReachP(ref int surprising, int p, int score)
        {
            if (p == 0)
            {
                return true;
            }
            else if (score > 0)
            {
                int m = (int)score / 3;
                if (score % 3 > 0)
                {
                    m++;
                }
                int[] n = new int[3] { m, m, m };

                int i = 0;
                while ((n[0] + n[1] + n[2]) != score)
                {
                    n[i]--;
                    i++;
                }

                if (n.Max() >= p)
                {
                    return true;
                }
                else
                {
                    if (surprising > 0)
                    {
                        if (Math.Abs(n[0] - n[2]) == 0)
                        {
                            n[0]--;
                            n[2]++;

                            surprising--;

                            if (n.Max() < p)
                            {
                                surprising++;
                            }
                        }
                        else if ((Math.Abs(n[0] - n[2]) == 1) && (Math.Abs(n[1] - n[2]) == 0))
                        {
                            n[1]--;
                            n[2]++;

                            surprising--;

                            if (n.Max() < p)
                            {
                                surprising++;
                            }
                        }
                    }

                    if (n.Max() >= p)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                return false;
            }
        }

        static int CountGooglers(int surprising, int p, int[] scores)
        {
            int result = 0;

            foreach (int score in scores)
            {
                if (ReachP(ref surprising, p, score))
                {
                    result++;
                }
            }

            return result;
        }

        static void Main(string[] args)
        {
            string fileName = "B-Small";

            // Load file
            TextReader tr = new StreamReader(@"D:\Kiguti\Google Code Jam\2012\Qualification\B. Dancing With the Googlers\Input\" + fileName + ".in");
            string sCases = tr.ReadLine();

            // create a writer and open the file
            TextWriter tw = new StreamWriter(@"D:\Kiguti\Google Code Jam\2012\Qualification\B. Dancing With the Googlers\Output\" + fileName + ".out");

            int Cases = Int32.Parse(sCases);

            char[] delim = { ' ' };

            // Run cases
            for (int k = 1; k <= Cases; k++)
            {
                string[] information = tr.ReadLine().Split(delim);

                // N
                int googlers = int.Parse(information[0]);
                // S
                int surprising = int.Parse(information[1]);
                // P
                int p = int.Parse(information[2]);

                // Scores of Googlers
                int[] scores = new int[googlers];
                for (int x = 0; x < googlers; x++)
                {
                    scores[x] = int.Parse(information[x+3]);
                }

                int count = CountGooglers(surprising, p, scores);

                tw.WriteLine(string.Format("Case #{0}: {1}", k.ToString(), count.ToString()));
            }

            // close the stream
            tw.Close();
            tr.Close();
        }
    }
}
