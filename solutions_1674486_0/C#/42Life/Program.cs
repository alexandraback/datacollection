/* C# Program
 * Google Code Jam 2012
 * Round 1C
 * 
 * Copyright Craig A Maher - 2012
 */
using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Diagnostics;

namespace CodeJamRound1C
{
    class Program
    {
        static void Main(string[] args)
        {
            Do("A-small-attempt0", false);
            //Do("A-large-practice", false);
            //Do("test", false);

            Console.ReadLine();
        }

        static void Do(string FileName, bool comp)
        {
            Console.WriteLine("Doing: " + FileName);
            StreamReader input;
            StreamWriter output;
            input = new StreamReader(FileName + ".in");
            output = new StreamWriter(FileName + ".out");

            StreamReader compare = null;
            if (comp)
            {
                compare = new StreamReader(FileName + ".compare");
            }

            //if it fails porgram needs to exit anyway
            int TestCases = int.Parse(input.ReadLine());
            string outString;
            for (int i = 1; i <= TestCases; ++i)
            {
                outString = Process(input);
                outString = string.Format("Case #{0}: {1}", i, outString);
                output.WriteLine(outString);

                if (!comp || outString != compare.ReadLine())
                {
                    Console.WriteLine(outString);
                }
            }
            Console.WriteLine("Fin");
            if (comp)
            {
                compare.Close();
            }
            input.Close();
            output.Close();
        }

        //A
        private static string Process(StreamReader input)
        {
            int N = int.Parse(input.ReadLine());
            int[][] classes= new int[N][];
            string[] line;
            for (int i = 0; i < N; ++i)
            {
                line = input.ReadLine().Split(' ');
                classes[i] = new int[int.Parse(line[0])];
                for (int j = 0; j < classes[i].Length; ++j)
                {
                    classes[i][j] = int.Parse(line[1+j])-1;
                }
            }
            for (int i = 0; i < N; ++i)
            {
                BitArray inherits = new BitArray(N, false);
                if(inherit(classes, i, inherits))
                {
                        return "Yes"; ;
                }
            }
            
            //loop through all classes and check if class x inherits from the same class twice
            //throw new NotImplementedException();
            return "No";
        }

        private static bool inherit(int[][] classes, int classI, BitArray inherits)
        {
            for (int j = 0; j < classes[classI].Length; ++j)
            {
                if (inherits[classes[classI][j]])
                {
                    return true;
                }
                else
                {
                    inherits[classes[classI][j]] = true;
                    if (inherit(classes, classes[classI][j], inherits))
                    {
                        return true;
                    }
                }
                
            }
            return false;
        }



        //B
        //private static string Process(StreamReader input)
        //{
        //    throw new NotImplementedException();
        //}

        //C
        //private static string Process(StreamReader input)
        //{
        //    throw new NotImplementedException();
        //}
    }
}
