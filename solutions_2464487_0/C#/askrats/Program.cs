using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CGJT
{
    class Program
    {
        static void Main(string[] args)
        {
            TextReader input = Console.In;
            Func<string> get_line = () => {
                string line = input.ReadLine();
                return line == null ? "" : line.Trim();
            };
            Func<int[]> get_line_ints = () => get_line().Split( ' ' ).Select( s => int.Parse( s ) ).ToArray();
            Func<long[]> get_line_longs = () => get_line().Split( ' ' ).Select( s => long.Parse( s ) ).ToArray();
            Func<string[]> get_line_strings = () => get_line().Split( ' ' ).Select( s => s.Trim() ).ToArray();

            var Tests = get_line_ints()[ 0 ];

            for ( int t = 0; t < Tests; ++t ) {
                var rt = get_line_longs();
                Console.WriteLine( "Case #" + ( t + 1 ).ToString() + ": " + Solve( rt[ 0 ], rt[ 1 ] ) );
            }
        }

        static string Solve( long r, long t  )
        {
            for ( long d = 1, num=0; ; d += 4, ++num ) {
                t -= 2 * r + d;
                if ( t < 0 ) return ( num ).ToString();
            }
        }
    }
}
