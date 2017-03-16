using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProjectA
{


    class Program
    {
        const string ASmall = "A-small-attempt0.in";
        const string ALarge = "A-large.in";

        static void Main(string[] args)
        {
            StreamReader readStream = new StreamReader(ASmall);
            StreamWriter writer = new StreamWriter("out.txt");

            string firstLine = readStream.ReadLine();

            int N = int.Parse(firstLine);
            for (int i = 1; i <= N; i++)
            {
                string s = readStream.ReadLine();
                int numOfClasses = int.Parse(s);
                string[] classes = new string[numOfClasses];
                for (int j = 0; j < numOfClasses; j++)
                {
                    classes[j] = readStream.ReadLine();
                }
                string result = solve(classes);
                writer.WriteLine("Case #" + i + ": " + result);
            }

            readStream.Close();
            writer.Close();
        }

        private static string solve(string[] s)
        {
            int[][] classesInfo = new int[s.Length][];
            for (int j = 0; j < s.Length; j++)
            {
                string[] classINfo = s[j].Split(' ');
                int numOfSuper = int.Parse(classINfo[0]);
                int[] classIn = new int[numOfSuper];
                for (int i = 0; i < numOfSuper; i++)
                {
                    classIn[i] = int.Parse(classINfo[i + 1]) - 1;
                }
                classesInfo[j] = classIn;
            }

            for (int i = 0; i < s.Length; i++)
            {
                if (classesInfo[i].Length > 1)
                {
                    List<int> allReaches = new List<int>();
                    allReaches.AddRange(classesInfo[i]);

                    foreach (int ints in classesInfo[i])
                    {
                        int[] reachAble = findAllReachable(classesInfo, ints);
                        foreach (int i1 in reachAble)
                        {
                            if (allReaches.Contains(i1))
                            {
                                return "Yes";
                            }

                            allReaches.Add(i1);

                        }
                    }

                }
            }

            return "No";
        }

        private static int[] findAllReachable(int[][] classesInfo, int ints)
        {
            List<int> reaches = new List<int>();
            List<int> newAdded = new List<int>();
            reaches.AddRange(classesInfo[ints]);
            newAdded.AddRange(classesInfo[ints]);

            while (newAdded.Count > 0)
            {
                List<int> tmpNew = new List<int>();
                foreach (int i in newAdded)
                {
                    reaches.AddRange(classesInfo[i]);
                    tmpNew.AddRange(classesInfo[i]);
                }
                newAdded.Clear();
                newAdded.AddRange(tmpNew);
            }

            return reaches.ToArray();
        }
    }
}
