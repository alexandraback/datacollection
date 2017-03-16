using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam_2016_R1A_3
{
    class Chain {
        public int num;
        public List<int> chained = new List<int>();
        public HashSet<int> items = new HashSet<int>();
    }

    class Cycle
    {
        public List<int> cycle = new List<int>();

    }

    class Program
    {
        static String Solve(String s)
        {
            int[] links = s.Trim().Split(new char[] { ' ' }).Select(Int32.Parse).ToArray();

            Chain[] chains = new Chain[links.Length];
            //            Dictionary<int, Cycle> cycles = new Dictionary<int, Cycle>();
            Dictionary<int, List<Chain>> itemToChain = new Dictionary<int, List<Chain>>();

            int result = 0;

            for (int i = 0; i < links.Length; i++)
            {
                int current = i + 1;
                Chain chain = new Chain() { num = current };
                Dictionary<int, int> cycles = new Dictionary<int, int>();

                int num = 0;
                while (!chain.items.Contains(current))
                {
                    num++;
                    chain.chained.Add(current);
                    chain.items.Add(current);
                    cycles.Add(current, num);
                    if (!itemToChain.ContainsKey(current)) { itemToChain[current] = new List<Chain>(); }
                    itemToChain[current].Add(chain);

                    current = links[current - 1];
                }
                chains[i] = chain;
                int cycleLen = chain.items.Count - cycles[current] + 1;
                if (cycleLen > result) result = cycleLen;
            }

            /*            foreach(Chain c in chains)
                        {
                            if (c.items.Count > result) result = c.items.Count;
                        }*/

/*            var remove = itemToChain.Keys.Where(x => links[links[x - 1] - 1] != x).ToList();
            foreach(var item in remove) { itemToChain.Remove(item); }*/

            foreach (var kv in itemToChain)
            {
                int current = kv.Key;
                List<Chain> currentChains = kv.Value;
                for (int i = 0; i < currentChains.Count - 1; i++)
                {
                    for (int b = i + 1; b < currentChains.Count; b++)
                    {
                        int num = 0;
                        HashSet<int> total = new HashSet<int>();
                        foreach (var item in currentChains[i].chained)
                        {
                            if (item != current) num++; else break;
                            total.Add(item);
                        }
                        bool bad = false;
                        foreach (var item in currentChains[b].chained)
                        {
                            if (total.Contains(item))
                            {
                                bad = true;
                                break;
                            }
                            if (item != current) num++; else break;
                        }
                        if (bad) continue;
                        num++;
                        if (num > result) result = num;
                    }
                }

            }


            return result.ToString();
        }

        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"Z:\Projects\Соревнования\CodeJam 2016\Round1A\Task3_input\C-small-attempt1.in");
            Int32 count = Int32.Parse(lines[0].Trim());
            for (Int32 i = 0; i < count; i++)
            {
                String res = Solve(lines[i*2 + 2]);
                Console.WriteLine("Case #{0}: {1}", i + 1, res);
            }
        }

    }
}
