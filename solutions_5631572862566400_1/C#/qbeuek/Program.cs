using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem3
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var input = new StreamReader("../../input.txt"))
            using (var output = new StreamWriter("../../output.txt"))
            {
                int caseCount = int.Parse(input.ReadLine());
                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    input.ReadLine();
                    var iLike = input.ReadLine().Split().Select(s => int.Parse(s) - 1).ToArray();
                    var imLiked = new int[iLike.Length][];
                    for (var i = 0; i < imLiked.Length; i++)
                    {
                        imLiked[i] = iLike.Select((who, me) => new { who = who, me = me }).Where(wm => wm.who == i).Select(wm => wm.me).ToArray();
                    }

                    var usedForChains = new HashSet<int>();
                    for (var i = 0; i < iLike.Length; i++)
                    {
                        if (usedForChains.Contains(i))
                        {
                            continue;
                        }

                        if (usedForChains.Contains(iLike[i]))
                        {
                            continue;
                        }

                        if (imLiked[i].Contains(iLike[i]))
                        {
                            buildChain(iLike, imLiked, i, usedForChains);
                        }
                    }

                    var longestLoop = 0;
                    for (var i = 0; i < iLike.Length; i++)
                    {
                        var loopLength = countLoopLength(iLike, i);
                        longestLoop = Math.Max(longestLoop, loopLength);
                    }

                    var topKidsInCircle = Math.Max(longestLoop, usedForChains.Count);

                    output.WriteLine("Case #{0}: {1}", caseNumber, topKidsInCircle);
                }
            }
        }

        private static void buildChain(int[] iLike, int[][] imLiked, int start, HashSet<int> usedForChains)
        {
            var first = start;
            var second = iLike[first];
            usedForChains.Add(first);
            usedForChains.Add(second);
            buildLongestChainFrom(first, iLike, imLiked, usedForChains);
            buildLongestChainFrom(second, iLike, imLiked, usedForChains);
        }

        private static void buildLongestChainFrom(int start, int[] iLike, int[][] imLiked, HashSet<int> usedForChains)
        {
            var bestHashSet = new HashSet<int>();
            foreach (var likedBy in imLiked[start])
            {
                if (!usedForChains.Contains(likedBy))
                {
                    var currentHashSet = gatherLongestUnusedFrom(likedBy, imLiked, usedForChains);
                    if (currentHashSet.Count > bestHashSet.Count)
                    {
                        bestHashSet = currentHashSet;
                    }
                }
            }
            foreach (var item in bestHashSet)
            {
                usedForChains.Add(item);
            }
        }

        private static HashSet<int> gatherLongestUnusedFrom(int start, int[][] imLiked, HashSet<int> usedForChains)
        {
            var result = new HashSet<int>();
            result.Add(start);
            var bestHashSet = new HashSet<int>();
            foreach (var likedBy in imLiked[start])
            {
                if (!usedForChains.Contains(likedBy))
                {
                    var currentHashSet = gatherLongestUnusedFrom(likedBy, imLiked, usedForChains);
                    if (currentHashSet.Count > bestHashSet.Count)
                    {
                        bestHashSet = currentHashSet;
                    }
                }
            }
            foreach (var item in bestHashSet)
            {
                result.Add(item);
            }
            return result;
        }

        private static int countLoopLength(int[] iLike, int start)
        {
            var visited = new HashSet<int>();
            var current = start;
            while (true)
            {
                visited.Add(current);
                current = iLike[current];
                if (visited.Contains(current))
                {
                    if (current == start)
                    {
                        return visited.Count;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
    }
}
