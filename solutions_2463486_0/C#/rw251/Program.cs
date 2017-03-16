using System;
using System.Collections;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Collections.Generic;

namespace CodeChefNet
{

    class Program
    {
        private static bool fromFile = true;
        private static TextReader tmpReader;
        private static TextWriter tmpWriter;

        static bool ispal(long l)
        {
            var s = l.ToString();
            while(s.Length>=2)
            {
                if(s[0]!=s[s.Length-1]) return false;
                s = s.Substring(1, s.Length - 2);
            }
            return true;
        }

        static void Main(string[] args)
        {
            if (fromFile)
            {
                tmpWriter = Console.Out;
                tmpReader = Console.In;
                Console.SetIn(new StreamReader(@"in.txt"));
                Console.SetOut(new StreamWriter(@"out.txt"));
            }

            var n = new List<long>();
            var nsq = new List<long>();


            //enough for long 1
            for(long i =0; i < 10000000;i++)
            {
                if(ispal(i) && ispal(i*i))
                {
                    n.Add(i); nsq.Add(i*i);
                }
            }

            var T = GetInt();
            for(var i = 0; i < T; i++)
            {
                Console.Write(string.Format(@"Case #{0}: ",i+1));
                var ab = GetLongs();
                var A = ab[0];
                var B = ab[1];

                var total = 0;
                for(var j =0; j < nsq.Count; j++)
                {
                    if (nsq[j] >= A && nsq[j] <= B) total++;
                }

                Console.WriteLine(total);

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
