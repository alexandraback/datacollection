using System;
using System.Collections;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Numerics;

namespace CodeChefNet
{
    class Program
    {
        private static bool fromFile = true;
        private static TextReader tmpReader;
        private static TextWriter tmpWriter;


        static void Main(string[] args)
        {
            if (fromFile)
            {
                tmpWriter = Console.Out;
                tmpReader = Console.In;
                Console.SetIn(new StreamReader(@"in.txt"));
                Console.SetOut(new StreamWriter(@"out.txt"));
            }

            var T = GetInt();

            for (var i = 0; i < T;i++ )
            {
                var rt = GetLongs();
                long r = rt[0];
                long t = rt[1];
                long tot = 0;
                long j = 0;

                while(tot <= t)
                {
                    j++;
                    tot += 2*r + 4*j - 3;
                }
                Console.WriteLine(string.Format("Case #{0}: {1}",(i+1),(j-1)));
            }


                if (fromFile)
                {
                    Console.Out.Flush();
                    Console.Out.Close();
                    Console.SetOut(tmpWriter);
                    Console.SetIn(tmpReader);

                    //Console.WriteLine("TIME: " + DateTime.Now.Subtract(st).TotalMilliseconds);
                    //Console.ReadKey();
                }
        }

        #region Getting stuff from console

        static string GetLine()
        {
            var line = Console.ReadLine();
            while (string.IsNullOrEmpty(line))
            {
                line = Console.ReadLine();
            }
            return line;
        }

        static int GetInt()
        {
            return int.Parse(GetLine());
        }

        static List<int> GetInts()
        {
            return GetLine().Split(' ').Select(x => int.Parse(x)).ToList();
        }

        static long GetLong()
        {
            return long.Parse(GetLine());
        }

        static List<long> GetLongs()
        {
            return GetLine().Split(' ').Select(x => long.Parse(x)).ToList();
        }

        static string GetString()
        {
            return GetLine();
        }

        static string[] GetStrings()
        {
            return GetLine().Split(' ').ToArray();
        }

        #endregion
    }
}
