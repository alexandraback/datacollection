using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;

namespace GoogleJam
{
    public static class AA
    {
        public static bool Solve(int N, int[][] inheritance)
        {
            var childs = new List<int>[N];
            var totalParents = new HashSet<int>[N];
            var curGen = new HashSet<int>();
            for (int i = 0; i < N; i++)
            {
                childs[i] = new List<int>();
                totalParents[i] = new HashSet<int>();
            }
            for (int i = 0; i < N; i++)
            {
                foreach (var parent in inheritance[i])
                {
                    childs[parent-1].Add(i);
                }
                if (inheritance[i].Length == 0)
                {
                    curGen.Add(i);
                }
            }
            var markedIndexes = new HashSet<int>(curGen);
            while (curGen.Count > 0)
            {
                var curGenParentsByChild = (from cur in curGen
                              from child in childs[cur]
                              select new {cur, child}
                              into pair
                              group pair by pair.child).ToArray();
                curGen.Clear();
                foreach (var parentsByChild in curGenParentsByChild)
                {
                    var curChild = parentsByChild.Key;
                    foreach (var curGenParent in parentsByChild)
                    {
                        if (!MergeAndNoEqual(totalParents[curChild], totalParents[curGenParent.cur], curGenParent.cur))
                            return true;
                    }
                    if (markedIndexes.Add(curChild))
                        curGen.Add(curChild);
                }
            }
            return false;
        }

        private static bool MergeAndNoEqual(HashSet<int> childParents, HashSet<int> parnetParents, int parent)
        {
            foreach (var parnetParent in parnetParents)
            {
                if (!childParents.Add(parnetParent))
                    return false;
            }
            return childParents.Add(parent);
        }
    }


    class Program
    {


        static void Main(string[] args)
        {

            var tr = new StreamReader(@"C:\GJ\input.in");
            using (var tw = new StreamWriter(@"C:\GJ\output.out"))
            {
                int testCount = int.Parse(tr.ReadLine());
                for (int i = 0; i < testCount; i++)
                {
                    int N = int.Parse(tr.ReadLine());
                    int [][] inheritance = Enumerable.Range(0, N).Select(jj => tr.ReadLine().Split().Skip(1).Select(int.Parse).ToArray()).ToArray();
                    bool result = AA.Solve(N, inheritance);
                    // var ints = tr.ReadLine().Split().Select(int.Parse);
                    // var strs = tr.ReadLine().Split();
                    // CultureInfo.InvariantCulture

                    tw.WriteLine(string.Format("Case #{0}: {1}", i + 1, result ? "Yes" : "No"));
                }
            }
        }

    }
}
