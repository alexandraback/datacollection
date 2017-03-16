using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cj2013qrd
{
    class Program
    {
        static void Main(string[] args)
        {
            var fn = "D-small-attempt3.in"; //"D-sample.in";//
            using (var strIn = File.OpenText("c:\\Users\\zoli\\Downloads\\cj2013\\" + fn))
            using (var strOut = new StreamWriter("c:\\Users\\zoli\\Downloads\\cj2013\\" + fn + ".out"))
            {
                var cCase = int.Parse(strIn.ReadLine());
                for (int iCase = 0; iCase < cCase; iCase++)
                {
                    var rgstCkeyCchest = strIn.ReadLine().Split(' ');
                    var ckey = int.Parse(rgstCkeyCchest[0]);   // K
                    var cChest = int.Parse(rgstCkeyCchest[1]); // N
                    var rgkkeyStart = strIn.ReadLine().Split(' ').Select(stKkey=>int.Parse(stKkey)).ToArray();
                    var rgkkeyForChest = new int[cChest];
                    var rgrgKkeyCkeyInChest = new int[cChest][];
                    for (int iChest = 0; iChest < cChest; iChest++)
                    {
                        var rgkeydata = strIn.ReadLine().Split(' ').Select(stKkey => int.Parse(stKkey)).ToArray();
                        rgkkeyForChest[iChest] = rgkeydata[0];
                        rgrgKkeyCkeyInChest[iChest] = new int[rgkeydata[1]];
                        for (int iKeyInChest = 0; iKeyInChest < rgkeydata[1]; iKeyInChest++)
                            rgrgKkeyCkeyInChest[iChest][iKeyInChest] = rgkeydata[iKeyInChest + 2];
                    }

                    var cjqrb = new Cjqrd(rgkkeyStart, rgkkeyForChest, rgrgKkeyCkeyInChest);
                    var rgichest = cjqrb.rgichestSolve();

                    if (rgichest!=null && !cjqrb.checkSolution(rgichest))
                        Console.WriteLine("a következő szar!");

                    var stSolution = "IMPOSSIBLE";
                    if (rgichest!=null)
                        stSolution = string.Join(" ", rgichest.Select(iChest => (iChest+1).ToString()));

                    Console.WriteLine("Case #{0}: {1}", iCase + 1, stSolution);
                    strOut.WriteLine("Case #{0}: {1}", iCase + 1, stSolution);
                }
            }
            Console.ReadLine();
        }
    }

    internal class Cjqrd
    {
        public int[] RgkkeyStart { get; set; }
        public int[] RgkkeyForChest { get; set; }
        public int[][] RgrgKkeyCkeyInChest { get; set; }
        private Keyst keystStart;
        private Keyst[] rgkeystForChest;

        public Cjqrd(int[] rgkkeyStart, int[] rgkkeyForChest, int[][] rgrgKkeyCkeyInChest)
        {
            RgkkeyStart = rgkkeyStart;
            RgkkeyForChest = rgkkeyForChest;
            RgrgKkeyCkeyInChest = rgrgKkeyCkeyInChest;
            keystStart = new Keyst(RgkkeyStart, RgkkeyForChest);
            rgkeystForChest = new Keyst[rgkkeyForChest.Length];
            for (int iChest = 0; iChest < rgkeystForChest.Length; iChest++)
            {
                rgkeystForChest[iChest] = new Keyst(rgrgKkeyCkeyInChest[iChest], new int[0]);
                rgkeystForChest[iChest].decrementKey(rgkkeyForChest[iChest]);
            }
        }

        public List<int> rgichestSolve()
        {
            Keyst keyst = rgkeystForChest.Aggregate(keystStart, (current, t) => current + t);
            if (!keyst.fValid())
                return null;

            var rgichest = new SortedSet<int>();
            for (int i = 0; i < rgkeystForChest.Length; i++)
                rgichest.Add(i);

                return solveI(keystStart, new List<int>(), rgichest);
        }

        private List<int> solveI(Keyst keyst, List<int> rgichest, SortedSet<int> rgichestRemain)
        {
            if (rgichest.Count == rgkeystForChest.Length)
                return rgichest;
//            if (!keyst.HlmIchestHasKey().Any())
//                return null;

            if (keyst.KeyNeededButHaveNone(rgichestRemain, RgkkeyForChest, RgrgKkeyCkeyInChest))
                return null;

//            var eniChests = rgichestRemain.Intersect(keyst.HlmIchestHasKey());
            foreach (var iChest in rgichestRemain)
            {
                if (!keyst.fValidRemoveKey(RgkkeyForChest[iChest]))
                    continue;
//                if (!eniChests.Contains(iChest))
//                    Console.WriteLine("");
                var keystNew = keyst.AddChest(RgkkeyForChest[iChest], RgrgKkeyCkeyInChest[iChest], RgkkeyForChest);
                var rgichestRemainNew = new SortedSet<int>(rgichestRemain);
                rgichestRemainNew.Remove(iChest);
                rgichest.Add(iChest);
                var rgichestRes = solveI(keystNew, rgichest, rgichestRemainNew);
                if (rgichestRes != null)
                    return rgichestRes;
                rgichest.RemoveAt(rgichest.Count-1);
            }
            return null;
        }

        public bool checkSolution(List<int> rgichest)
        {
            var keyst = keystStart;
            for (int iiChest = 0; iiChest < rgichest.Count; iiChest++)
            {
                int iChest = rgichest[iiChest];
                if (!keyst.fValidRemoveKey(RgkkeyForChest[iChest]))
                    return false;
                keyst = keyst + rgkeystForChest[iChest];
            }
            return true;
        }
    }

    internal class Keyst
    {
        private int[] rgCkey = new int[201];
        private HashSet<int> hlmIchestHasKey = new HashSet<int>();

        private Keyst()
        {
        }

        public HashSet<int> HlmIchestHasKey()
        {
            return hlmIchestHasKey;
        }

        public Keyst(int[] rgkkeyStart, int[] rgkkeyForChest)
        {
            for (int i = 0; i < rgCkey.Length; i++)
                rgCkey[i] = 0;

            foreach (var kkey in rgkkeyStart) {
                rgCkey[kkey]++;
                for (int iChest = 0; iChest < rgkkeyForChest.Length; iChest++)
                    if (rgkkeyForChest[iChest]==kkey)
                        hlmIchestHasKey.Add(iChest);
            }
        }

        public bool fValid()
        {
            return rgCkey.All(ckey => ckey >= 0);
        }

        public void decrementKey(int kkey)
        {
            rgCkey[kkey]--;
        }

        public static Keyst operator +(Keyst keyst1, Keyst keyst2)
        {
            var keystRes = new Keyst();
            for (var i=0; i<keystRes.rgCkey.Length; i++)
                keystRes.rgCkey[i] = keyst1.rgCkey[i] + keyst2.rgCkey[i];
            return keystRes;
        }

        public static int[] expand(int[] rgi, int i)
        {
            var rgIrest = new int[rgi.Length + 1];
            Array.Copy(rgi, 0, rgIrest, 0, rgi.Length);
            rgIrest[rgi.Length] = i;
            return rgIrest;
        }

        public bool fValidRemoveKey(int kkey)
        {
            return rgCkey[kkey]>=1;
        }

        public Keyst AddChest(int kkeyForChest, int[] rgKKey, int[] rgkkeyForChest)
        {
            var keystRes = new Keyst();
            Array.Copy(this.rgCkey, keystRes.rgCkey, this.rgCkey.Length);

            keystRes.hlmIchestHasKey = new HashSet<int>(hlmIchestHasKey);

            keystRes.rgCkey[kkeyForChest]--;
            if (keystRes.rgCkey[kkeyForChest] == 0)
            {
                for (int iChest = 0; iChest < rgkkeyForChest.Length; iChest++)
                    if (rgkkeyForChest[iChest] == kkeyForChest)
                        keystRes.hlmIchestHasKey.Remove(iChest);
            }
            foreach (var kkey in rgKKey)
            {
                keystRes.rgCkey[kkey]++;
                if (keystRes.rgCkey[kkey]==1)
                    for (int iChest = 0; iChest < rgkkeyForChest.Length; iChest++)
                        if (rgkkeyForChest[iChest] == kkeyForChest)
                            keystRes.hlmIchestHasKey.Add(iChest);
            }
            

            return keystRes;
            ;
        }

        public bool KeyNeededButHaveNone(SortedSet<int> rgichestRemain, int[] rgkkeyForChest, int[][] rgrgKkeyCkeyInChest)
        {
            foreach (int iChest in rgichestRemain)
            {
                if (rgCkey[rgkkeyForChest[iChest]] == 0)
                {
                    foreach (int iChestI in rgichestRemain)
                    {
                        if (iChest != iChestI && rgrgKkeyCkeyInChest[iChestI].Contains(rgkkeyForChest[iChest]))
                            return false;
                    }
                    return true;
                }
            }
            return false;
        }
    }
}
