using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProjectA
{


    class Program
    {
        const string ASmall = "A-small-attempt4.in";
        const string ALarge = "A-large.in";

        static void Main(string[] args)
        {
            StreamReader readStream = new StreamReader(ASmall);
            StreamWriter writer = new StreamWriter("out.txt");

            string firstLine = readStream.ReadLine();

            int N = int.Parse(firstLine);
            for (int i = 1; i <= N; i++)
            {
                string s = readStream.ReadLine();
                string result = solve(s);
                writer.WriteLine("Case #" + i + ": " + result);
            }

            readStream.Close();
            writer.Close();
        }

        private static string solve(string s)
        {
            string result = string.Empty;
            string[] line = s.Split(' ');
            int NumofCand = int.Parse(line[0]);

            List<int> candis = new List<int>();
            List<int> sortedCandi = new List<int>();
            int sum = 0;
            for (int i = 1; i <= NumofCand; i++)
            {
                int candi = int.Parse(line[i]);
                sum += candi;
                candis.Add(candi);
                sortedCandi.Add(candi);
            }
            sortedCandi.Sort();
            sortedCandi.Reverse();

            bool isMinus = false;
            int tempNum = NumofCand;
            int newSum = sum * 2;
            while (!isMinus)
            {                
                double meanValue = newSum / (double)tempNum;

                if (sortedCandi[0] > meanValue)
                {
                    isMinus = false;
                    newSum -= sortedCandi[0];
                    tempNum -= 1;
                    sortedCandi.RemoveAt(0);
                }
                else
                {
                    isMinus = true;
                    for (int i = 0; i < NumofCand; i++)
                    {
                        if (sortedCandi.Contains(candis[i]))
                        {
                            if (sum != 0)
                                result += (meanValue - candis[i]) / (double)sum * 100 + " ";
                            else
                            {
                                result += 100d / tempNum  + " ";
                            }
                        }
                        else
                        {
                            result += 0 + " ";
                        }

                    }
                }
            }

            string newResult = result.Replace(',', '.');

            return newResult;
        }
    }
}
