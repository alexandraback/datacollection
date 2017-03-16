using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
namespace DiamondInheritance
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader(args[0]);
            int nbCase = int.Parse(reader.ReadLine());
            for (int i = 0; i < nbCase; i++)
            {
                string line = reader.ReadLine();
                int n = int.Parse(line);
                List<List<int>> directInheritance = new List<List<int>>();
                Dictionary<int, HashSet<int>> agregatation = new Dictionary<int, HashSet<int>>();
                for (int j = 0; j < n; j++)
                {
                    //agregatation.Add(j + 1, null);
                    List<int> temp = new List<int>();
                    line = reader.ReadLine();
                    var t1 = line.Split(' ');
                    int m = int.Parse(t1[0]);
                    for (int k = 0; k < m; k++)
                    {
                        temp.Add(int.Parse(t1[k + 1]));
                    }
                    directInheritance.Add(temp);
                }

                int l = 0;
                bool res = true;
                while (l < n && res)
                {
                    HashSet<int> b;
                    res = TryGetInheritance(directInheritance, agregatation, l+1, out b);
                    l++;
                }

                Console.WriteLine("Case #{0}: {1}", i + 1, res ? "No" : "Yes");

            }
            Console.ReadLine();
        }

        private static bool TryGetInheritance(List<List<int>> direct, Dictionary<int, HashSet<int>> agregatation, int index, out HashSet<int> res)
        {
            if (agregatation.TryGetValue(index, out res))
            {
                return true;
            }
            var current = direct[index - 1];
            res = new HashSet<int>();
            res.Add(index);
            for (int i = 0; i < current.Count; i++)
            {
                int currentCount = res.Count;
                HashSet<int> fathers;
                if (!TryGetInheritance(direct, agregatation, current[i], out fathers))
                {
                    return false;
                }
                foreach (var item in fathers)
                {
                    if (!res.Add(item))
                    {
                        return false;
                    }
                }
            }
            agregatation[index] = res;
            return true;
        }
    }
}
