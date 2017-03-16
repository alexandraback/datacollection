using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    
    public class Program
    {

        public static void Main(string[] args)
        {
            string[] testCases = null;

            if (!ValidateArgsAndGetCases(args, out testCases))
            {
                Console.WriteLine("could not get test cases");
                return;
            }

            RunProgramA_Round1C(testCases);
            
        }

        private static void RunProgramA_Round1C(string[] testcases)
        {
            int caseNumber = 1;
            for (int i = 0; i < testcases.Length; i++)
            {
                int numClasses = Convert.ToInt32(testcases[i]);
                int[][] classInheritance = GetClassInheritance(testcases, i + 1, numClasses);
                

                visited = new bool[numClasses];
                for (int j = 0; j < numClasses; j++)
                {
                    visited[j] = false;
                }

                string result = "No";
                for (int j = 0; j < numClasses; j++)
                {
                    if (visited[j] == false)
                    {
                        if (findDiamondInheritance(classInheritance, j))
                        {
                            result = "Yes";
                            break;
                        }
                    }
                }

                Console.WriteLine("Case #{0}: {1}", caseNumber, result);

                i += numClasses;
                caseNumber++;
            }
        }

        private static bool[] visited;

        private static bool findDiamondInheritance(int[][] classInheritance, int i)
        {
            
            //a set of everything this class inherits from
            HashSet<int> inheritedFrom = new HashSet<int>();

            //check all the possibilities until we find a collision
            Queue<int> parents = new Queue<int>();
            for (int j = 0; j < classInheritance[i].Length; j++)
            {
                parents.Enqueue(classInheritance[i][j]);
            }

            while (parents.Count > 0)
            {
                int parent = parents.Dequeue();

                if (!inheritedFrom.Contains(parent))
                {
                    inheritedFrom.Add(parent);
                }
                else
                {
                    //found diamond inheritance
                    return true;
                }

                for (int j = 0; j < classInheritance[parent-1].Length; j++)
                {
                    parents.Enqueue(classInheritance[parent-1][j]);
                }
            }

            //nothing in here has diamond inherits
            foreach (int classNumebr in inheritedFrom)
            {
                visited[classNumebr-1] = true;
            }

            return false;
        }

        private static int[][] GetClassInheritance(string[] input, int beginIndex, int numClasses)
        {
            int[][] classInheritance = new int[numClasses][];
            for (int j = 0; j < numClasses; j++)
            {
                string[] fields = input[beginIndex + j].Split(new char[] { ' ' });
                classInheritance[j] = new int[Convert.ToInt32(fields[0])];
                for (int k = 0; k < classInheritance[j].Length; k++)
                {
                    classInheritance[j][k] = Convert.ToInt32(fields[k + 1]);
                }
            }

            return classInheritance;
        }

        
        public static bool ValidateArgsAndGetCases(string[] args, out string[] testCases)
        {
            testCases = null;
            if (ValidateArgs(args))
            {
                testCases = GetTestCases(args[0]);
            }

            return (testCases != null);
        }


        public static bool ValidateArgs(string[] args)
        {
            
            //first read in the test cases
            if (args.Length < 0)
            {
                Console.WriteLine("please specify a file to read from");
            }
            string fileName = args[0];

            if (!File.Exists(fileName))
            {
                Console.WriteLine("file '{0}' does not exist", fileName);
                return false;
            }

            return true;
        }

        public static string[] GetTestCases(string fileName)
        {

            using (StreamReader sr = new StreamReader(fileName))
            {
                string firstLine = sr.ReadLine();
                int numCases = Convert.ToInt32(firstLine);

                List<string> testCases = new List<string>();
                while (sr.Peek() > 0)
                {
                    testCases.Add(sr.ReadLine());
                }
                
                return testCases.ToArray();
            }
        }

    }

}