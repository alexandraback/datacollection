using System;
using System.Collections;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Collections.Generic;
//using System.Numerics;

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

            for (var i = 0; i < T; i++)
            {
                int answer = int.MaxValue;
                int moves = 0;

                var An = GetLongs();
                var A = An[0];
                var N = An[1];
                var motes = GetLongs();
                motes.Sort();

                if (A == 1)
                {
                    answer = motes.Count;
                }
                else
                {
                    while (motes.Count > 0)
                    {
                        while (motes.Count > 0 && motes[0] < A)
                        {
                            A += motes[0];
                            motes.RemoveAt(0);
                        }

                        answer = Math.Min(answer, moves + motes.Count);
                        if (motes.Count > 0)
                        {
                            A += A - 1;
                            moves++;
                        }
                        if(moves>answer) break;
                    }
                }

                Console.WriteLine(string.Format("Case #{0}: {1}", i+1, answer));
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
