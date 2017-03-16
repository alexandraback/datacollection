using System;
using System.Collections.Generic;
using System.IO;

namespace gcj2012
{
    public static class QRB
    {
        public const string Round = "QR";

        public const string Problem = "B";
        //public const string Type = "sample";
        //public const string Type = "small";
        public const string Type = "large";

        public static void Solve()
        {
            const string inputFile = Round + Problem + "-" + Type + ".in";
            const string outputFile = Round + Problem + "-" + Type + ".out";

            var reader = new StreamReader(inputFile);
            TextWriter tw = new StreamWriter(outputFile);

            string line = reader.ReadLine();

            String[] valoriInput = line.Split(' ');

            int T = int.Parse(valoriInput[0]);

            for (int i = 0; i < T; i++)
            {
                line = reader.ReadLine();
                valoriInput = line.Split(' ');
                int N = int.Parse(valoriInput[0]);
                int S = int.Parse(valoriInput[1]);
                int p = int.Parse(valoriInput[2]);

                var lst = new List<int>();
                for (int j = 1; j <= N; j++)
                {
                    lst.Add(int.Parse(valoriInput[j + 2]));
                }

                int res = 0;

                for (int j = 0; j < lst.Count; j++)
                {
                    int g = lst[j];
                    int r = g%3;
                    int d = g/3;
                    if (r > 0) d++;
                    if (g==0 && p>0) continue;
                    if (d >= p)
                    {
                        res++;
                    }
                    else if (d+1 == p)
                    {
                        if (S>0 && r!=1){
                            S--;
                            res++;
                        }
                    }
                }


                

                String Case = "Case #" + (i + 1).ToString() + ": " + res;
                tw.WriteLine(Case);

            }

            tw.Close();
            reader.Close();




        }

    }


}
