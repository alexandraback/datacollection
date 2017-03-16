using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static bool checkDiamond(bool[,] inherit)
        {
            // for all nodes, find children
            for (int i = 0; i < inherit.GetLength(0); i++)
            {
                // only if it doesn't inherit from any other class
                bool root = true;
                for (int j=0; j < inherit.GetLength(0); j++)
                    if (inherit[i, j])
                    {
                        root = false;
                        break;
                    }
                if (root)
                {
                    if (search(inherit, i, new List<int>(), new string[inherit.GetLength(0), inherit.GetLength(0)]))
                        return true;
                }
            }

            return false;
        }

        static bool search(bool[,] inherit,int node, List<int> history, string[,] diamondTracker)
        {
            bool diamondFound = false;

            history.Add(node);

            // for all children recurse
            bool childrenFound = false;
            for (int i=0; i<inherit.GetLength(0); i++)
                if (inherit[i, node])
                {
                    childrenFound = true;
                    diamondFound = search(inherit, i, history, diamondTracker);
                    if (diamondFound)
                        return true;
                }


            if ((history.Count > 1) && (!childrenFound))
            {
                // check if any paths already found
                for (int k = 0; k < history.Count - 1; k++)
                    for (int t = k + 1; t < history.Count; t++)
                    {
                        StringBuilder sb = new StringBuilder();
                        for (int q = k; q <= t; q++)
                        {
                            sb.Append(history[q]);
                            sb.Append(";");
                        }
                        string path = sb.ToString();
                        //Console.WriteLine("found {0} -> {1}   via {2}", history[k], history[t], path);
                        if (!string.IsNullOrEmpty(diamondTracker[history[k], history[t]]))
                        {
                            if (diamondTracker[history[k], history[t]] != path)
                            {
                                //Console.WriteLine("DIAMOND!!");
                                return true;
                            }
                        }
                        diamondTracker[history[k], history[t]] = path;
                    }
            }


            history.Remove(node);

            return diamondFound;


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

                        int N = int.Parse(str);

                        bool[,] inherit = new bool[N, N];

                        // read inheritance matrix
                        for (int j = 0; j < N; j++)
                        {
                            str = sr.ReadLine();
                            string[] valuesStr = str.Split(' ');
                            int parentsCount = int.Parse(valuesStr[0]);
                            if (parentsCount > 0)
                            {
                                for (int k = 0; k < parentsCount; k++)
                                {
                                    int par = int.Parse(valuesStr[k + 1]) - 1;
                                    inherit[j, par] = true;

                                }

                            }
                        }


                        // check for diamont inheritance
                        bool diamond = checkDiamond(inherit);


                        string result = string.Format("Case #{0}: {1}", i, diamond?"Yes":"No");
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
