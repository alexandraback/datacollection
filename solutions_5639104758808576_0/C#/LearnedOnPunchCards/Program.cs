using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2015_A
{
    class Program
    {
        public static String fileIn = @"C:\Users\johnk_000\Documents\CodeJam2015\A\smallin.txt";
        public static String fileOut = @"C:\Users\johnk_000\Documents\CodeJam2015\A\smallout.txt";

        static void Main(string[] args)
        {
            long count;
            long maxCount;
            String inLine;
            String[] parts;

            long maxS;
            long standing;
            long willStand;
            long needMore;
            long needNow;

            System.IO.StreamWriter outFile = new System.IO.StreamWriter(fileOut);
            System.IO.StreamReader file = new System.IO.StreamReader(fileIn);
            String firstline = file.ReadLine();

            long.TryParse(firstline, out maxCount);

            for (count=0; count < maxCount; count++)
            {
                inLine = file.ReadLine();
                parts = inLine.Split(' ');

                long.TryParse(parts[0], out maxS);
                standing = 0;
                needMore = 0;

                for (int i=0; i <= maxS; i++)
                {
                    if (standing < i)
                        needNow = (i - standing);
                    else
                        needNow = 0;

                    long.TryParse(parts[1].Substring(i, 1), out willStand);
                    standing = standing + needNow + willStand;
                    needMore += needNow;

                    
                }

                Console.WriteLine("Case #" + (count + 1) + ": " + needMore);
                outFile.WriteLine("Case #" + (count + 1) + ": " + needMore);
        
            }

            outFile.Close();
            System.Console.ReadLine();


        }
    }
}
