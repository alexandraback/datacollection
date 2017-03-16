using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace FacebookHackerCup2012
{
    class RecycledNumbers
    {
        Dictionary<String, List<String>> pairs = new Dictionary<String, List<String>>();
        int cases;
        string line;
        string [] lines;
        public RecycledNumbers()
        {

            StreamWriter output = new StreamWriter("recyclednumbersoutput.txt");
            StreamReader file = new StreamReader("recyclednumbers.txt");
            cases = Convert.ToInt32(file.ReadLine());
            int max = 0;
            lines = new string[cases];
            for (int i = 0; i < cases; i++)
            {
                line = file.ReadLine();
                lines[i] = line;
                string[] parts = line.Split(' ');
                if (Convert.ToInt32(parts[1]) > max) max = Convert.ToInt32(parts[1]);
            }
            for (int i = 1; i <= max; i++)
            {
                String a = i.ToString();
                if (a.Length > 1)
                {
                    String b = a;
                    List<String> permutations = new List<String>();
                    permutations.Add(a);
                    for (int j = 0; j < (a.Length - 1); j++)
                    {
                            String temp = b.Substring(1) + b[0];
                            if (temp != b)
                            {
                                b = temp;
                                if(b[0] != '0' && !permutations.Contains(b)) permutations.Add(b);
                            }
                    }
                    if (permutations.Count > 1)
                    {
                        if (!pairs.ContainsKey(permutations[0]))
                        {
                            foreach (String permutation in permutations)
                            {
                                pairs.Add(permutation, permutations);
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < cases; i++)
            {
                string[] parts = lines[i].Split(' ');
                int start = Convert.ToInt32(parts[0]);
                int end = Convert.ToInt32(parts[1]);
                int pairsCount = 0;
                for (int j = start; j <= end; j++)
                {
                    if(pairs.ContainsKey(j.ToString()))
                    {
                        foreach (String s in pairs[j.ToString()])
                        {
                            if (s != j.ToString())
                            {
                                int temp = Convert.ToInt32(s);
                                if (temp <= end && temp > j)
                                {
                                    pairsCount++;
                                }
                            }
                        }
                    }
                }
                output.WriteLine("Case #" + (i + 1) + ": " + pairsCount);
                Console.WriteLine("Case #" + (i + 1) + ": " + pairsCount);
            }
            file.Close();
            output.Close();
        }
    }
}
