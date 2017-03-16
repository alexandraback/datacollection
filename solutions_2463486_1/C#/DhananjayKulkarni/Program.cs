using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace codeJam2013QRnd
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int cx = 1; cx <= Xfile.TotalNumofCases; cx++)
            {
                
                Xfile.ReadNextCase();

                var items = from itm in Xfile.FarePalindromes
                            where itm >= Xfile.Min && itm <= Xfile.Max
                            select itm;

                int ans = items.Count();

                Xfile.WriteNextcase(ans.ToString());
                
            }

            Console.WriteLine("finished");
            Console.Read();
        }
    }



   public static class Xfile
    {
        public static int TotalNumofCases;
        static int CurrPTR = 0;
        static string fileInPath = @"C:\Users\dkulkarni1\Downloads\C-large-1.in";
        static string fileOutPath = @"C:\Users\dkulkarni1\Downloads\testout.txt";
        static int outCunter = 1;
        static string[] AllLines;
        public static long  Min;
        public static long  Max;
        public static List<double> FarePalindromes;
        static long pMax = 100000000000000;
        

        static Xfile()
        {
            AllLines = File.ReadAllLines(fileInPath);
            TotalNumofCases = Convert.ToInt32(ReadNextLine());

            //find palindrome fare from 1-1000;
            FarePalindromes = new List<double>();
            double tm = 1;
            double sqrt = Math.Sqrt(pMax);
            for (long i = 1; i <= sqrt; i++)
            {
                if (isPlindrome(i))
                {

                    tm = Math.Pow(i,2);
                    if (isPlindrome(tm))
                    {
                        FarePalindromes.Add(tm);
                    }
                }
            }

        }

        static bool isPlindrome(object num)
        {
            string snum = num.ToString();
            int cnt = snum.Count();

            for (int l = 0; l <= cnt / 2 -1 ;l++ )
            {
                if (!(snum[l] == snum[cnt - l - 1]))
                    return false;

            }

            return true;
        }

        public static string ReadNextLine()
        {
            return AllLines[CurrPTR++];
        }

        public static void ReadNextCase()
        {
            string[] line = ReadNextLine().Split(' ');

            Min = Convert.ToInt64(line[0]);
            Max = Convert.ToInt64(line[1]);
        }

        public static void WriteNextcase(string ans)
        {

            string[] ot = new string[] { "Case #" + outCunter.ToString() + ": " + ans };

            if (outCunter == 1)
                File.WriteAllLines(fileOutPath, ot);
            else if (!(outCunter == TotalNumofCases))
                File.AppendAllLines(fileOutPath, ot);
            else
                File.AppendAllText(fileOutPath, "Case #" + outCunter.ToString() + ": " + ans);

            outCunter++;

        }
    }

}
