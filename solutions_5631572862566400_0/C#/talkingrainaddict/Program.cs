using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamAPC
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = new StreamReader(@"C:\Users\lincha\Documents\CodeJam1A\c-small.in");
            List<string> output = new List<string>();
            int numtestcases = int.Parse(input.ReadLine());
            for (int testcase = 1; testcase <= numtestcases; testcase++)
            {
                int N = int.Parse(input.ReadLine());
                var m = input.ReadLine().Split(new char[] { ' ' });
                List<int> f = m.Select(s => int.Parse(s) - 1).ToList();
                List<List<int>> in_nodes = new List<List<int>>(new List<int>[N]);
                Initialize(in_nodes, f);
                int maxCycle = ProcessInput(N, f);
                List<int> components = new List<int>();
                HashSet<int> seen = new HashSet<int>();
                for (int node = 0; node < N; node++ )
                {
                    if (f[f[node]] != node)
                    {
                        continue;
                    }
                    if (seen.Contains(node))
                    {
                        continue;
                    }
                    seen.Add(node);
                    seen.Add(f[node]);

                    int left_height = GetHeight(node, in_nodes, f);
                    int right_height = GetHeight(f[node], in_nodes, f);
                    components.Add(left_height + right_height);
                }
                int sum_components = components.Sum();
                int answer = sum_components > maxCycle ? sum_components : maxCycle;
                output.Add(String.Format("Case #{0}: {1}", testcase, answer));
            }
            File.WriteAllLines(@"C:\Users\lincha\Documents\CodeJam1A\c-small.txt", output.ToArray());

        }

        static int GetHeight(int node, List<List<int>> in_nodes, List<int> f)
        {
            var children = GetChildren(node, in_nodes, f);
            if (children.Count == 0)
            {
                return 1;
            }
            return 1 + children.Select(s => GetHeight(s, in_nodes, f)).Max();
        }

        static List<int> GetChildren(int node, List<List<int>> in_nodes, List<int> f)
        {
            return in_nodes[node].Where(s => f[node] != s).ToList();
        }

        static void Initialize(List<List<int>> in_nodes, List<int> f)
        {
            for (int i = 0; i < in_nodes.Count; i++)
            {
                in_nodes[i] = new List<int>();
            }
            for (int i = 0; i < f.Count; i++)
            {
                in_nodes[f[i]].Add(i);
            }
        }

        static int ProcessInput(int N, List<int> f)
        {
            if (N != f.Count)
            {
                throw new Exception(String.Format("N {0} != size of f {1}", N, f.Count));
            }
            HashSet<int> covered = new HashSet<int>();
            int maxCycle = 0;
            for (int i = 0; i < N; i++)
            {
                int best = floyd(i, f, covered);
                if (best > maxCycle)
                {
                    maxCycle = best;
                }
            }
            return maxCycle;
        }

        static int floyd(int x0, List<int> f, HashSet<int> covered)
        {
            HashSet<int> explored = new HashSet<int>();
            explored.Add(x0);

            try
            {
                int tortoise = f[x0];
                int hare = f[f[x0]];
                while (tortoise != hare)
                {
                    explored.Add(tortoise);
                    if (covered.Contains(tortoise))
                    {
                        return 0;
                    }
                    tortoise = f[tortoise];
                    hare = f[f[hare]];
                }
                int mu = 0;
                tortoise = x0;

                while (tortoise != hare)
                {
                    tortoise = f[tortoise];
                    hare = f[hare];
                    mu += 1;
                }

                int lam = 1;
                hare = f[tortoise];
                while (tortoise != hare)
                {
                    hare = f[hare];
                    lam += 1;
                }

                return lam;
            }
            finally
            {
                foreach (int num in explored)
                {
                    covered.Add(num);
                }
            }
        }
    }
}
