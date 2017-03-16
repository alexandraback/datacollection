using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2015_B
{
    class Program
    {
        public static String fileIn = @"C:\Users\johnk_000\Documents\CodeJam2015\B\bigin.txt";
        public static String fileOut = @"C:\Users\johnk_000\Documents\CodeJam2015\B\bigout.txt";

        
        static void Main(string[] args)
        {
            long count;
            long maxCount;

            String inLine;
            String[] parts;

                   

            int D;
            int [] P;
            int i;
            List<int> Plist;
            int inP;

            int minTime;
            int thisTime;

            String inString;
            long inValue;

            
            
            System.IO.StreamWriter outFile = new System.IO.StreamWriter(fileOut);
            System.IO.StreamReader file = new System.IO.StreamReader(fileIn);
            String firstline = file.ReadLine();

            long.TryParse(firstline, out maxCount);

            for (count = 0; count < maxCount; count++)
            {
                inLine = file.ReadLine();
                
                int.TryParse(inLine, out D);
                //Console.WriteLine("D: " + D );

                P = new int[D];
                Plist = new List<int>();

                inString = file.ReadLine();
                parts = inString.Split(' ');

                for (int a = 0; a < D; a++ )
                {
                    int.TryParse(parts[a], out inP);
                    Plist.Add(inP);
                }

                Plist.Sort();
                Plist.Reverse();
                P = Plist.ToArray();

                int maxP = P[0];
                minTime = maxP;
                //Console.WriteLine("maxP " + maxP + " minTime: " + minTime);
                for (int ii = 0; ii < D; ii++)
                    //Console.WriteLine(ii + ":  P[i]: " + P[ii]);

                    for (int j = maxP; j > 0; j--)  // How many turns.
                    {
                        thisTime = j;
                        //Console.WriteLine("j " + j + " thisTime: " + thisTime);
                        for (int k = 0; k < D; k++)
                        {
                            //Console.WriteLine("  k " + k + " thisTime: " + thisTime);
                            int l = P[k];
                            while (l > j)
                            {
                                l -= j;
                                thisTime += 1;
                                //Console.WriteLine("    l " + l + " thisTime: " + thisTime);
                            }

                            //minTime = Math.Min(minTime, thisTime);
                        }
                        minTime = Math.Min(minTime, thisTime);
                    }


                Console.WriteLine("Case #" + (count + 1) + ": " + minTime);
                outFile.WriteLine("Case #" + (count + 1) + ": " + minTime);

            }

            outFile.Close();
            System.Console.ReadLine();


        }


    }
}
