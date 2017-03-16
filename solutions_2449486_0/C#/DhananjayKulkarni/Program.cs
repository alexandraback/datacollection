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
                bool possibleRow = true, possibleClm = true; bool possibleCase = true;
                //for small input 
                for (int r = 0; r < Xfile.N; r++)
                { 
                    for (int c = 0; c < Xfile.M; c++)
                    {
                        possibleRow = true; possibleClm = true;

                        if (Xfile.curcase[r, c] == 1)
                        {
                            #region dk
                            //check all in row
                            for (int sc = 0; sc < Xfile.M; sc++)
                            {
                                if (Xfile.curcase[r, sc] != 1)
                                    possibleRow = false;
                            }

                            //check all in column
                            for (int sc = 0; sc < Xfile.N; sc++)
                            {
                                if (Xfile.curcase[sc, c] != 1)
                                    possibleClm = false;
                            }
#endregion 

                        }

                        if (possibleRow == false && possibleClm == false)
                        {
                            possibleCase = false;
                            break;
                        }
                    }
                    if (possibleCase == false)
                    {
                        Xfile.WriteNextcase("NO");
                        break;
                    }
                }
                if (possibleCase)
                {
                    Xfile.WriteNextcase("YES");
                }



            }

            Console.WriteLine("finished");
            Console.Read();
        }
    }

   public static class Xfile
    {
        public static int TotalNumofCases;
        static int CurrPTR = 0;
        static string fileInPath = @"C:\Users\dkulkarni1\Downloads\B-small-attempt0.in";
        static string fileOutPath = @"C:\Users\dkulkarni1\Downloads\testout.txt";
        static int outCunter = 1;
        public static int N, M;
        public static int[,] curcase;
        static string[] AllLines;

        static Xfile()
        {
            AllLines = File.ReadAllLines(fileInPath);
            TotalNumofCases = Convert.ToInt32(ReadNextLine());
        }

        public static string ReadNextLine()
        {
            return AllLines[CurrPTR++];
        }

        public static void ReadNextCase()
        {
            string[] line = ReadNextLine().Split(' ');
            N = Convert.ToInt16(line[0]);
            M = Convert.ToInt16(line[1]);

            curcase = new int[N, M];

            for (int r = 0; r < N; r++)
            {
                line = ReadNextLine().Split(' ');

                for (int c = 0; c < M; c++)
                {
                    curcase[r, c] = Convert.ToInt16( line[c]);
                }
            }
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
