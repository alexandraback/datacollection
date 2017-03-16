using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Dancing_With_the_Googlers
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputtext = @"E:\Document\JamCode\Dancing_With_the_Googlers\B-large.in";
           readLine(inputtext);
        }

        static void readLine(string path)
        {
            int N = 0;
            int G = 0;
            int S = 0;
            int P = 0;
            
            // Read the file and display it line by line.
            System.IO.StreamReader file = new System.IO.StreamReader(path);
            StreamWriter testfile = File.CreateText(@"E:\Document\JamCode\Dancing_With_the_Googlers\C-large.txt");
            N = Convert.ToInt32(file.ReadLine());
           
            for (int i = 0; i < N; i++)
            {
                List<int> GS = new List<int>();
                var str = file.ReadLine().Split(' ');
                G = Convert.ToInt32(str[0]);
                S = Convert.ToInt32(str[1]);
                P = Convert.ToInt32(str[2]);
                for (int num = 1; num <= G; num++)
			    {
                    GS.Add(Convert.ToInt32(str[2 + num]));
                }

                var number = 0;
                if (P > 1)
                {
                    var mins = (P - 2) * 3 + 2;
                    var maxs = (P - 1) * 3;
                    var mustSnumber = GS.Where(a => a >= mins && a <= maxs).Count();

                    if (mustSnumber < S)
                    {
                        number = GS.Where(a => a >= mins).Count();
                    }
                    else
                        number = GS.Where(a => a > maxs).Count() + S;
                }
                else if (P == 1)
                {
                    number = GS.Where(a => a != 0).Count();
                }
                if (P == 0)
                {
                    number = GS.Count();
                }

                testfile.WriteLine(String.Format("Case #{0}: {1}", i + 1, number));
            }
            testfile.Flush();
            testfile.Close();
            file.Close();
            Console.WriteLine("GOOD");
            Console.ReadKey();
        }
    }
}
