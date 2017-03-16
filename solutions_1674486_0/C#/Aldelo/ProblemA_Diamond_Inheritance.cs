using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamQualificationRound2012Console
{
    class ProblemA_Diamond_Inheritance
    {

        public static void Run(string fname, string ofname)
        {
            string[] solution = ReadProblemA(fname);

            string[] output = new string[solution.Length];
            for (int i = 0; i < solution.Length; i++)
            {
                output[i] = String.Format("Case #{0}: {1}", i + 1, solution[i]);

                Console.Out.WriteLine(output[i]);

            }
            Helpers.IO.WriteOutput(ofname, output.Length, output);

            //Console.ReadLine();
        }

        public static string[] ReadProblemA(string fname)
        {
            /*
             *  3
                1 2
                1 3
                0 
             */
            string[] outputStr = null;
            int inputlength = 0;
            int count = 0;
            StreamReader fr = new StreamReader("..\\..\\" + fname);
            while (!fr.EndOfStream)
            {
                if (inputlength == 0)
                {
                    string s = fr.ReadLine();
                    inputlength = Convert.ToInt32(s);
                    outputStr = new string[inputlength];
                }
                else
                {
                    int line = Convert.ToInt32(fr.ReadLine());
                    DiamondInheritanceCase input = new DiamondInheritanceCase();
                    for (int i = 0; i < line; i++)
                    {
                        string[] caseInput = fr.ReadLine().Split(' ');
                        int index = -1;
                        input.Total.Add(new DiamondClass { Index = i });
                        foreach (var item in caseInput)
                        {
                            
                            if (index < 0)
                            {
                            }
                            else
                            {
                                input.Total[i].inherit.Add(Convert.ToInt32(item) - 1);
                            }
                            ++index;
                        }
                    }
                   

                    outputStr[count] = AnswerOfCase(input);
                    Console.Out.WriteLine(": " +  outputStr[count]);
                    ++count;
                }
            }
            fr.Close();
            return outputStr;
        }

        public class DiamondInheritanceCase
        {            
            public List<DiamondClass> Total = new List<DiamondClass>();
        }

        public class DiamondClass
        {
            public int Index;
            public List<int> inherit = new List<int>();
        }

        private static string AnswerOfCase(DiamondInheritanceCase c)
        {
            string ret = "No";

            for (int i = 0; i < c.Total.Count; i++)
            {
                Dictionary<int, int> temp = exploreInheritence(new Dictionary<int, int>(), c.Total, c.Total[i]);
                foreach (var item in temp.Keys)
                {
                    if (temp[item] > 1)
                    {
                        return "Yes";
                    }
                }
            }
          
            return ret;
        }

        private static Dictionary<int, int> exploreInheritence(Dictionary<int, int> map, List<DiamondClass> list, DiamondClass cur)
        {
            if (cur.inherit.Count <= 0)
            {
                if (!map.ContainsKey(cur.Index))
                {
                    map[cur.Index] = 0;
                }
                map[cur.Index]++;
            }
            foreach (var item in cur.inherit)
	        {
                DiamondClass temp = list[item];
                map = exploreInheritence(map, list, temp);
	        }    
            return map;
        }
        
    }
}
