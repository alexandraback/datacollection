using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace DiamondInheritance
{
    class Program
    {
        protected static bool Traverse(int[][] classes, int cls, HashSet<int> allFound)
        {
            int[] parents = classes[cls];
            foreach (int parent in parents)
            {
                if (allFound.Contains(parent))
                    return true;
                allFound.Add(parent);
                if (Traverse(classes, parent, allFound))
                    return true;
            }
            return false;
        }

        protected static string Calculate(int [][]classes)
        {
            bool bFoundDiamond = false;

            //doesn't matter if right side up or upside down.

            //roots (top parents) have 0 parents of their own.

            //leaves have no classes pointing to them.  (one-pass through classes to eliminate)

            //only leaves or roots need to be followed for duplicate check

            List<int> leaves = new List<int>();
            for (int i = 0; i < classes.Length; ++i)
                leaves.Add(i);
            for (int i = 0; i < classes.Length; ++i)
            {
                for (int j = 0; j < classes[i].Length; ++j)
                {
                    leaves.Remove(classes[i][j]);
                }
            }

            foreach (int leaf in leaves)
            {
                //fastest tree traversal of classes...
                if( Traverse(classes, leaf, new HashSet<int>()) )
                {
                    bFoundDiamond = true;
                    break;
                }
            }

            return bFoundDiamond ? "Yes" : "No";
        }

        static void Main(string[] args)
        {
            string inFileName = args[0];
            string outFileName = inFileName.Split('.')[0] + ".out";
            StreamReader inFile = new StreamReader(inFileName);
            StreamWriter outFile = new StreamWriter(outFileName);

            DateTime start = DateTime.Now;

            List<string> lines = new List<string>();
            int nCases = int.Parse(inFile.ReadLine());
            for (int iCase = 0; iCase < nCases; ++iCase)
            {
                int N = int.Parse(inFile.ReadLine());
                int[][] classes = new int[N][];
                for (int i = 0; i < classes.Length; ++i)
                {
                    string[] line = inFile.ReadLine().Split(' ');
                    classes[i] = new int[int.Parse(line[0])];
                    for (int j = 0; j < classes[i].Length; ++j)
                    {
                        classes[i][j] = int.Parse(line[j + 1]) - 1;
                    }
                }

                string result = Calculate(classes);

                outFile.WriteLine("Case #{0}: {1}", iCase + 1, result);
                outFile.Flush();
            }
            inFile.Close();
            outFile.Close();

            Console.WriteLine("Elapsed Time: {0:t}", DateTime.Now - start);
        }
    }
}
