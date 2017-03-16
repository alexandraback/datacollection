using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CJ2012Round1Prob2
{





    public class Prob1
    {


        Dictionary<int, List<int>>  mappings;
        public int numberOfPoints;


        public bool getAllChildren(int i,out List<int> _children)
        {
            _children = new List<int>();
            List<int> children;
            foreach (int c in mappings[i]) 
            {
                _children.Add(c);
            }

            foreach (int c in mappings[i]) 
            {
                if (getAllChildren(c,out children))
                {
                    return true;
                }
                else
                {
                    foreach (int d in children)
                    {
                        if (_children.Contains(d))
                        { return true; }

                    }
                    _children.AddRange(children);

                }
            }

            return false;
        }


        public string solveLines(List<string> _lines)
        {
            string temp = "";
            int sum = 0;
            mappings = new Dictionary<int, List<int>>();
            int bottom = 0;
            int top = 0;
            string[] split;
            int point = 1;
            foreach (string line in _lines)
            {

                split = line.Split(' ');
                sum += Int32.Parse(split[0]);
                mappings.Add(point,new List<int>());
                if (Int32.Parse(split[0]) == 0)
                {
                    top = point;
                }
                for (int i = 1; i <= Int32.Parse(split[0]); i++)
                {
                    mappings[point].Add(Int32.Parse(split[i]));

                }
                point += 1;
            }
           
            
            
            List<int> children;
            foreach (KeyValuePair<int, List<int>> pair in mappings)
            {
                    if (getAllChildren(pair.Key,out children))
                    {
                        return "Yes";
                    }
            }
            
           
            return "No";
        }
    }


    class Program
    {
        public static void solve()
        {
            StreamReader sr = new StreamReader("in.txt");
            StreamWriter sw = new StreamWriter("out.txt");
            
            Prob1 prob = new Prob1();
            int numCases = Int32.Parse(sr.ReadLine());
            string[] split;
            int lineNum = 0;
            string line;
            List<string> lines = new List<string>();

            while ((line = sr.ReadLine()) != null)
            {

                split = line.Split(' ');
                prob.numberOfPoints = int.Parse(line);
                
                for (int i = 0; i < prob.numberOfPoints; i++)
                {
                    lines.Add(sr.ReadLine());
                }

                lineNum++;
                sw.Write("Case #" + lineNum.ToString() + ": ");
                sw.Write(prob.solveLines(lines));
                lines.Clear();
                sw.WriteLine();
            }

            sw.Close();
            sr.Close();
        }


        static void Main(string[] args)
        {
            solve();
        }
    }
}
