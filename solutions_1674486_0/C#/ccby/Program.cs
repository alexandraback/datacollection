using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Round1C.ProblemA
{
    class Program
    {

        

        static void Main(string[] args)
        {
            string file = "A-small-attempt0";
            StreamReader sr = new StreamReader(new FileStream(file + ".in", FileMode.Open, FileAccess.Read));
            StreamWriter sw = new StreamWriter(new FileStream(file + ".out", FileMode.OpenOrCreate, FileAccess.Write));

            int maxCase = Convert.ToInt32(sr.ReadLine());

            for (int i = 0; i < maxCase; i++)
            {
                string[] para = sr.ReadLine().Split(new Char[] { ' ' });
                int numOfClasses = Convert.ToInt32(para[0]);

                Dictionary<int,List<int>> classNodes = new Dictionary<int,List<int>>();
                for (int j = 0; j < numOfClasses; j++)
                {
                    para = sr.ReadLine().Split(new Char[] { ' ' });
                    int num = Convert.ToInt32(para[0]);

                    int classNum = j + 1;
                    List<int> inheritClasses = new List<int>();
                    for (int k = 0; k < num; k++) {
                        inheritClasses.Add(Convert.ToInt32(para[k+1]));
                    }
                    classNodes.Add(classNum, inheritClasses);
                }



                string result = Solve(classNodes);

                //output
                Console.WriteLine("Case #{0}: {1}", i + 1, result);
                sw.WriteLine("Case #{0}: {1}", i + 1, result);
            }


            //close
            sr.Close();
            sw.Close();
        }

        private static string Solve(Dictionary<int, List<int>> classNodes)
        {

            for (int i = 1; i < classNodes.Count + 1; i++) {
                for (int j = 1; j < classNodes.Count + 1; j++) {
                    if (i == j)
                    {
                        continue;
                    }
                    else {
                        int numOfPath = PathResult(i, j, classNodes);
                        if (numOfPath >= 2)
                        {
                            return "Yes";
                        }
                        
                    }
                }
            }

            return "No";
        }

        private static int PathResult(int i, int j, Dictionary<int, List<int>> classNodes)
        {
            int numOfPath = 0;

            foreach (int classNo in classNodes[i]) {
                if (classNo == j)
                {
                    numOfPath++;
                }
                else {
                    numOfPath += PathResult(classNo, j, classNodes);
                }

            }

            return numOfPath;

            
        }
    }
}
