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
        static string fileInPath = @"C:\Users\dkulkarni1\Downloads\C-small-attempt0.in";
        static string fileOutPath = @"C:\Users\dkulkarni1\Downloads\testout.txt";
        static int outCunter = 1;
        static string[] AllLines;
        public static int Min;
        public static int Max;
        public static List<double> FarePalindromes;
        static int pMax = 1000;
        

        static Xfile()
        {
            AllLines = File.ReadAllLines(fileInPath);
            TotalNumofCases = Convert.ToInt32(ReadNextLine());

            //find palindrome fare from 1-1000;
            FarePalindromes = new List<double>();
            double tm = 1;

            for (int i = 1; i <= Math.Sqrt(pMax); i++)
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

            Min = Convert.ToInt32(line[0]);
            Max = Convert.ToInt32(line[1]);
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
