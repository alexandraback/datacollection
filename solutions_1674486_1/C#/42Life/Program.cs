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
            //Do("A-small-attempt0", false);
            //Do("A-large-practice", false);
            Do("A-large", false);
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

        //B
        //private static string Process(StreamReader input)
        //{
        //    string[] inString = input.ReadLine().Split(' ');
        //    double d = double.Parse(inString[0]);
        //    int N = int.Parse(inString[1]);
        //    int A = int.Parse(inString[2]);
        //    double[,] otherCarsPosition = new double[N, 2];//time,position
        //    for (int i = 0; i < N; ++i)
        //    {
        //        inString = input.ReadLine().Split(' ');
        //        otherCarsPosition[i, 0] = double.Parse(inString[0]);
        //        otherCarsPosition[i, 1] = double.Parse(inString[1]);
        //    }
        //    double[] accelerations = new double[A];
        //    inString = input.ReadLine().Split(' ');
        //    double fastestAcceleration = 0;
        //    for (int i = 0; i < A; ++i)
        //    {
        //        accelerations[i] = double.Parse(inString[i]);
        //        if (accelerations[i] > fastestAcceleration)
        //        {
        //            fastestAcceleration = accelerations[i];
        //        }
        //    }

        //    double velocity = 0;
        //    double acceleration = 0;
        //    double distanceTravelled = 0;
        //    double time;
        //    for (int i = 1; i <= N; ++i)
        //    {
        //        time = otherCarsPosition[i - 1,0] - otherCarsPosition[i,0];
        //        distanceTravelled += velocity * time + 0.5 * fastestAcceleration * Math.Pow(time,2);
        //        if (distanceTravelled > otherCarsPosition[i, 1])
        //        {
                    
        //        }
        //    }
        //    throw new NotImplementedException();
        //}

        //C
        //private static string Process(StreamReader input)
        //{
        //    string[] inString = input.ReadLine().Split(' ');
        //    int N = int.Parse(inString[0]);
        //    int M = int.Parse(inString[1]);
        //    inString = input.ReadLine().Split(' ');
        //    int[] NBoxes = new int[N];
        //    int[] NType = new int[N];
        //    for (int i = 0; i < N; ++i)
        //    {
        //        NBoxes[i] = int.Parse(inString[i*2]);
        //        NType[i] = int.Parse(inString[i*2+1]);
        //    }
        //    inString = input.ReadLine().Split(' ');
        //    int[] MToys = new int[M];
        //    int[] MType = new int[M];
        //    for (int i = 0; i < M; ++i)
        //    {
        //        MToys[i] = int.Parse(inString[i * 2]);
        //        MType[i] = int.Parse(inString[i * 2 + 1]);
        //    }
        //    int boxedToys = 0;
        //    //start 
        //    //find weather holding onto box or toy is better
        //    int currentBoxType = NType[0];
        //    int currentToyType = MType[0];
        //    int countToysDroped;
        //    do
        //    {

        //    } while (true);
        //    throw new NotImplementedException();
        //    return boxedToys.ToString();
        //}

        //A
        private static string Process(StreamReader input)
        {
            int N = int.Parse(input.ReadLine());
            int[][] classes = new int[N][];
            string[] line;
            for (int i = 0; i < N; ++i)
            {
                line = input.ReadLine().Split(' ');
                classes[i] = new int[int.Parse(line[0])];
                for (int j = 0; j < classes[i].Length; ++j)
                {
                    classes[i][j] = int.Parse(line[1 + j]) - 1;
                }
            }
            for (int i = 0; i < N; ++i)
            {
                BitArray inherits = new BitArray(N, false);
                if (inherit(classes, i, inherits))
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



        

        
    }
}
