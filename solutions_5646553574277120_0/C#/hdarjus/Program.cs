using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam {
    class Program {
        static void Main ( string[] args ) {
            using ( StreamWriter output = new StreamWriter ( @"output.txt" ) ) {
                using ( StreamReader input = new StreamReader ( @"A-small-attempt0.in" ) ) {
                //using ( StreamReader input = new StreamReader ( @"input.txt" ) ) {
                    string line;
                    line = input.ReadLine ();
                    long T = Int64.Parse ( line );
                    for ( long i = 1; i <= T; i++ ) {
                        output.WriteLine ( "Case #{0}: {1}", i, solve ( input ) );
                    }
                }
            }
        }

        static string solve(StreamReader input) {
            string line =  input.ReadLine ();
            string[] cdv = line.Split ( ' ' );
            long C = Int64.Parse(cdv[0]);
            long D = Int64.Parse(cdv[1]);
            long V = Int64.Parse(cdv[2]);
            string[] dsString = input.ReadLine ().Split ( ' ' );
            long[] ds = new long[D];
            List<long> foundNums = new List<long> ();
            bool[] isFound = new bool[V+10];
            for ( int i = 0; i < V + 10; i++ ) {
                isFound[i] = false;
            }
            isFound[0] = true;
            for ( int i = 0; i < D; i++ ) {
                ds[i] = Int64.Parse ( dsString[i] );
            }
            for ( int i = 0; i < D; i++ ) {
                fill ( isFound, foundNums, ds[i] );
            }
            long count = 0;
            for (int i = 1; i <= V; i++) {
                if ( !isFound[i] ) {
                    fill ( isFound, foundNums, i );
                    count++;
                }
            }
            return count.ToString ();
        }

        private static void fill ( bool[] isFound, List<long> foundNums, long n ) {
            for ( int i = isFound.Length - (int)n - 1; i >= 0; i-- ) {
                if ( isFound[i] && !isFound[i + n] ) {
                    isFound[i + n] = true;
                    foundNums.Add ( i + n );
                }
            }
        }

        static string solveB (StreamReader input) {
            string line =  input.ReadLine ();
            string[] kls = line.Split ( ' ' );
            long K = Int64.Parse(kls[0]);
            long L = Int64.Parse(kls[1]);
            long S = Int64.Parse(kls[2]);
            string keyboard = input.ReadLine ();
            string target = input.ReadLine ();
            List<string> wordsA = new List<string> ();
            List<string> wordsB = new List<string> ();
            for ( int i = 0; i < K; i++ ) {
                wordsB.Add(keyboard[i].ToString ());
            }
            for ( int i = 1; i < S; i++ ) {
                wordsA = wordsB;
                wordsB = new List<string> ();
                for ( int j = 0; j < wordsA.Count; j++ ) {
                    for ( int k = 0; k < K; k++ ) {
                        wordsB.Add(string.Concat ( new string[] { wordsA[j], keyboard[k].ToString () } ));
                    }
                }
            }
            long sum = 0;
            long max = 0;
            for ( int i = 0; i < wordsB.Count; i++ ) {
                long subC = subCount ( wordsB[i], target );
                sum += subC;
                if ( subC > max ) {
                    max = subC;
                }
            }
            return ( ( (double)( wordsB.Count * max - sum ) ) / ( (double)wordsB.Count ) ).ToString ();
        }

        static bool equalFrom ( int from, string target, string s ) {
            if ( from + target.Length <= s.Length ) {
                return s.Substring ( from, target.Length ) == target;
            }
            return false;
        }

        static long subCount ( string a, string b ) {
            long c = 0;
            for ( int i = 0; i < a.Length; i++ ) {
                if ( equalFrom ( i, b, a ) ) {
                    c++;
                }
            }
            return c;
        }
    }
}
