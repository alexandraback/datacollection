using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJR1AB {
    class Program {
        int ngames;
        int[][] starsneeded;
        int starshave;
        bool[][] issolved;
        int stillneed;
        int solve2stars() {
            int nsolved = 0;
            stillneed = int.MaxValue;
            for (int i = 0; i < ngames; ++i) {
                if (issolved[i][1]) continue;
                if (starsneeded[i][1] <= starshave) {
                    starshave += 2;
                    issolved[i][1] = true;
                    nsolved++;
                }
                else {
                    int a = starsneeded[i][1] - starshave;
                    if (stillneed > a) stillneed = a;
                }
            }
            if (nsolved > 0) stillneed = 0;
            return nsolved;
        }
        int solve1stars(int need) {
            int nsolved = 0;
            while (true) {
                bool anysolved = false;
                for (int i = 0; i < ngames; ++i) {
                    if (!issolved[i][0] && starsneeded[i][0] <= starshave) {
                        issolved[i][0] = true;
                        nsolved++; starshave++;
                        anysolved = true;
                        if (nsolved == need) return nsolved;
                    }
                }
                if (!anysolved) break;
            }
            return nsolved;
        }
        int solve() {
            starshave = 0;
            issolved = new bool[ngames][];
            for (int i = 0; i < ngames; ++i) {
                issolved[i] = new bool[2];
            }
            int n1solved = 0, n2solved = 0;
            while (true) {
                while (true) {
                    int nsolved = solve2stars();
                    if (nsolved == 0) {
                        if (n1solved == ngames && n2solved < ngames) return -1;
                        break;
                    }
                    n2solved += nsolved;
                    if (n2solved == ngames) return n1solved + n2solved;
                }
                if (n1solved < ngames) {
                    int nsolved = solve1stars(stillneed);
                    if (nsolved < stillneed) return -1;
                    System.Diagnostics.Debug.Assert(nsolved == stillneed);
                    n1solved += nsolved;
                }
            }
        }
        Program() {
            int n = int.Parse(Console.ReadLine());
            for (int dd = 0; dd < n; ++dd) {
                ngames = int.Parse(Console.ReadLine());
                starsneeded = new int[ngames][];
                for (int i = 0; i < ngames; ++i) {
                    starsneeded[i] = Console.ReadLine().Split().Select(a => int.Parse(a.Trim())).ToArray();
                }
                int result = solve();
                Console.WriteLine("Case #{0}: {1}", dd + 1, result == -1 ? "Too Bad" : result.ToString());
            }
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
