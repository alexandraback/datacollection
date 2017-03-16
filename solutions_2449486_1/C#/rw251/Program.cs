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
            for(var i = 0; i < T; i++)
            {
                Console.Write(string.Format(@"Case #{0}: ",i+1));
                var nm = GetInts();
                var N = nm[0];
                var M = nm[1];
                var rowMax = new int[N];
                var colMax = new int[M];
                var lawn = new int[N,M];
                for (var j = 0; j < N; j++ )
                {
                    var line = GetInts();
                    for(var k = 0; k < M ; k++)
                    {
                        if (rowMax[j] == 0 || line[k] > rowMax[j]) rowMax[j] = line[k];
                        if (colMax[k] == 0 || line[k] > colMax[k]) colMax[k] = line[k];
                        lawn[j, k] = line[k];
                    }
                }

                var isPoss = true;

                for (var j = 0; j < N; j++)
                {
                    for (var k = 0; k < M; k++)
                    {
                        if(lawn[j,k]!=Math.Min(rowMax[j],colMax[k]))
                        {
                            isPoss = false;
                            break;
                        }
                    }
                    if(!isPoss) break;
                }
                if(isPoss) Console.WriteLine("YES");
                else Console.WriteLine("NO");
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
