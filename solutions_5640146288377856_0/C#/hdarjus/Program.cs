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

        static string solve (StreamReader input) {
            string[] line =  input.ReadLine ().Split(' ');
            long R = Int64.Parse(line[0]);
            long C = Int64.Parse(line[1]);
            long W = Int64.Parse(line[2]);
            long sum = W + (C * R) / W - 1;
            long rem = C - W * ( C / W );
            if (rem > 0)
                sum++;
            return sum.ToString ();
        }
    }
}
