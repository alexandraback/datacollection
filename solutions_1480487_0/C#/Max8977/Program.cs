using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {

        static double[] FindResults(int[] points)
        {
            List<double> res = new List<double>();

            // Find total judge score X
            int X = points.Sum();

            for (int i = 0; i < points.Length; i++)
            {
                // Do a binary search for the min audience vote
                double min = 0;
                double max = 100;
                bool done = false;

                while (!done)
                {
                    double mid = (min + max) / 2;

                    // check if the midpoint is safe
                    double audiencePoints = (double)X;
                    double myAudiencePoints = (mid / 100.0) * audiencePoints;
                    audiencePoints = audiencePoints - myAudiencePoints;
                    double finalScore = ((double)points[i]) + myAudiencePoints;

                    // can all other candidates bypass?
                    bool safe = false;
                    for (int j = 0; j < points.Length; j++)
                    {
                        if (j == i)
                            continue; 

                        // if necessary, give this guys audience points to bypass
                        if (points[j] < finalScore)
                        {
                            double diff = finalScore - points[j];
                            audiencePoints = audiencePoints - diff;
                            if (audiencePoints < 0)
                            {
                                safe = true;
                                break;
                            }

                        }

                    }

                    // update interval
                    if (safe)
                    {
                        max = mid;
                    }
                    else
                    {
                        min = mid;
                    }

                    // check if interval now small enough
                    const double CONFIDENCE = 0.000000001;
                    double intervalSize = (max - min);
                    if (intervalSize<CONFIDENCE)
                    {
                        done = true;

                    }


 

                }

                res.Add(min);

            }

            return res.ToArray();
        }

        static void Main(string[] args)
        {

            // remove to run from command line
            args = new string[] { "", "input.txt", "output.txt" };
            // --

            if (args.Length < 3)
            {
                Console.WriteLine("Provide input and output file names as parameter.");
                return;
            }

            // first param = name of input file
            string inputFileName = args[1];
            string outputFileName = args[2];

            if (!File.Exists(inputFileName))
            {
                Console.WriteLine("File not found: {0}", inputFileName);
                Console.ReadKey();
                
                return;
            }

            if (File.Exists(outputFileName))
            {
                File.Delete(outputFileName);
            }


            using (StreamReader sr = File.OpenText(inputFileName))
            {
                using (StreamWriter sw = File.CreateText(outputFileName))
                {
                    string testCasesStr = sr.ReadLine();
                    int T = 0;
                    int.TryParse(testCasesStr, out T);

                    Console.WriteLine("T = {0}", T);

                    for (int i = 1; i <= T; i++)
                    {
                        Console.WriteLine("Looking at Case #{0}...", i);
                        string str = sr.ReadLine();
                        Console.WriteLine(str);
                        string[] vals = str.Split(' ');

                        // N = number of contestants
                        int N = int.Parse(vals[0]);

                        int[] points = new int[N];
                        for (int j = 0; j < N; j++)
                            points[j] = int.Parse(vals[j + 1]);

                        // Find result for each contestant
                        double[] results = FindResults(points);
                        string numbers = string.Join(" ", results);
                                                                        
                        string result = string.Format("Case #{0}: {1}", i, numbers);
                        Console.WriteLine(result);
                        sw.WriteLine(result);

                    }

                    sw.Close();
                }


                sr.Close();
            }

            Console.WriteLine("Done!");
            Console.ReadKey();

        }
    }
}
