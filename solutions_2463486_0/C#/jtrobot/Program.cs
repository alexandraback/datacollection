using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace QualA
{
    class Program
    {
        static void Main(string[] args)
        {
            string fileIn = "..\\..\\..\\C-small-attempt0.in";
            string fileOut = "..\\..\\..\\fileOut.txt";
            using (StreamReader sr = new StreamReader(fileIn))
            using (StreamWriter sw = new StreamWriter(fileOut))
            {

                int cases = int.Parse(sr.ReadLine());


                for (int i = 1; i <= cases; i++)
                {
                    string lineIn = sr.ReadLine();
                    int lower = Convert.ToInt32(lineIn.Split(' ').ElementAt(0));
                    int upper = Convert.ToInt32(lineIn.Split(' ').ElementAt(1));

                    int fairSquareCount = 0;
                    for (int j = lower; j <= upper; j++)
                    {
                        bool qualifies = true;
                        int square = 0;
                        //Palindrome self test
                        string s = j.ToString();
                        for (int k = 0; k< s.Length / 2; k++)
                            if (s[k] != s[s.Length - k - 1])
                            {
                                qualifies = false;
                                break;
                            }

                        if (qualifies)
                        {
                            //Is a square test
                            if (!int.TryParse(Math.Sqrt(j).ToString(), out square))
                                qualifies = false;
                        }

                        if (qualifies)
                        {
                            //Square is a palindrome test
                            string sq = square.ToString();
                            for (int k = 0; k < sq.Length / 2; k++)
                                if (sq[k] != sq[sq.Length - k - 1])
                                {
                                    qualifies = false;
                                    break;
                                }
                        }
                        if (qualifies)
                        {
                            fairSquareCount++;
                            Console.WriteLine("---" + j);
                        }
                    }

                    string answer = "Case #" + i + ": " + fairSquareCount;
                    sw.WriteLine(answer);
                    Console.WriteLine(answer);
                }
            }
            Console.ReadLine();
        }
    }
}
