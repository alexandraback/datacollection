#region using directives

using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

#endregion

namespace ProblemA
{
    internal class Program
    {
        private static readonly Dictionary<string,List<int>> Paths = new Dictionary<string, List<int>>();
        private static void Main()
        {
            string[] input = File.ReadAllLines("input.txt");
            int testCaseCount = Int32.Parse(input[0]);
            bool success = false;

            int lineNr = 1;

            var sb = new StringBuilder();
            
            for (int i = 1; i <= testCaseCount; i++)
            {
                sb.Append("Case #" + i + ": ");
                //Console.WriteLine("Case #" + i + ": ");

                success = false;
                Paths.Clear();

                int classCount = Int32.Parse(input[lineNr]);
                lineNr++;

                var classes = new List<List<int>>();

                for (int c = 0; c < classCount; c++)
                {
                    var inheritsFrom = input[lineNr].Split(new[] { ' ' }).Skip(1).Select(x => Int32.Parse(x)-1).ToList();
                    classes.Add(inheritsFrom);
                    lineNr++;
                }
                
                for (int c = 0; c < classCount; c++)
                {
                    if(Solve(classes, c, new List<int> { c }))
                    {
                        success = true;
                        break;
                    }
                }

                sb.AppendLine(success ? "Yes" : "No");
            }

            Console.Write(sb.ToString());
            File.WriteAllText("ouput.txt", sb.ToString().Trim());
        }

        private static bool Solve(List<List<int>> classes, int c, List<int> path)
        {
            foreach (var inheritsFrom in classes[c])
            {
                if (path.Contains(inheritsFrom))
                    continue;


                var newPath = path.ToList();
                newPath.Add(inheritsFrom);
                string key = newPath.First() + "-" + newPath.Last();
                
                if(Paths.ContainsKey(key))
                {
                    if (AreDifferent(newPath, Paths[key]))
                        return true;
                }
                else
                {
                    Paths.Add(key, newPath);
                }

                if (Solve(classes, inheritsFrom, newPath))
                    return true;
            }

            return false;
        }

        private static bool AreDifferent(List<int> a, List<int> b)
        {
            if(a.Count != b.Count)
            {
                //Debug(a);
                //Debug(b);
                //Console.WriteLine();
                return true;
            }

            for (int i = 0; i < a.Count; i++)
            {
                if (a[i] != b[i])
                {
                    //Debug(a);
                    //Debug(b);
                    //Console.WriteLine();
                    return true;
                }
            }

            return false;
        }

        private static void Debug(IEnumerable<int> list)
        {
            foreach (var i in list)
            {
                Console.Write((i+1) + " ");
            }
            Console.WriteLine();
        }
    }
}