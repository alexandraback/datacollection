using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace R1CP1
{
    class Program
    {

        static List<int>[] inp;

        static List<int>[] allInh;

        static void Main(string[] args)
        {
            Console.WriteLine(DateTime.Now);

            String[] input = File.ReadAllText("input.txt").Split('\n');
            String output = "";

            int curent = 1;

            for (int iter = 0; iter < Int32.Parse(input[0]); iter++)
            {
                int numCases = Int32.Parse(input[curent++]);

                inp = new List<int>[numCases];
                allInh = new List<int>[numCases];


                for (int i = 0; i < numCases; i++)
                {
                    int inher = Int32.Parse(input[curent].Split(' ')[0]);
                    inp[i] = new List<int>();
                    for (int c = 0; c < inher; c++)
                    {
                        inp[i].Add(Int32.Parse(input[curent].Split(' ')[1+c]));
                    }
                    curent++;
                }

                bool res = false;
                for (int i = 0; i < numCases; i++)
                {
                    if (checkedDiamond(i))
                    {
                        res = true;
                        break;
                    }
                }

                output += "Case #" + (iter + 1).ToString() + ": " + (res?"Yes":"No") + "\n";
                Console.WriteLine("Case #" + (iter + 1).ToString() + ": " + (res?"Yes":"No") + "\n");
            }


            File.WriteAllText("output.txt", output.Trim());
            Console.ReadLine();
        }

        private static List<int> AllChildren(int subj, List<int> visited)
        {
            List<int> ret = new List<int>();

            if (visited.Contains(subj))
            {
                return (new List<int>());
            }

            if (allInh[subj] != null)
            {
                return (allInh[subj]);
            }
            else
            {
                ret.AddRange(inp[subj]);
                visited.Add(subj);
                foreach (int i in inp[subj])
                {
                    ret.AddRange(AllChildren(i - 1, visited));
                }
                allInh[subj] = ret;
                visited.Remove(subj);
                return (ret);
            }
        }

        private static bool checkedDiamond(int subj)
        {
            List<int> data = AllChildren(subj, new List<int>());

            foreach (int elem in data)
            {
                int count = 0;
                foreach (int iter in data)
                {
                    if (elem == iter)
                    {
                        count++;
                    }
                }
                if (count > 1)
                {
                    return (true);
                }
            }
            return(false);
        }
        
    }
}
