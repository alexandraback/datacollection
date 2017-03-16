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
                var ERN = get_line_ints();
                var act = get_line_ints();
                Console.WriteLine( "Case #" + ( t + 1 ).ToString() + ": " + Solve( ERN[0], ERN[1], ERN[2], act ).ToString() );
            }
        }


        static int Solve( int E, int R, int N, int[] act  )
        {
            return solve( E, E, R, 0, act, 0 );
        }

        static int solve( int E, int e, int R, int n, int[] act, int gain )
        {
            if ( n == act.Length ) {
                return gain;
            }

            if ( E < e ) e = E;

            int max_gain = 0;

            for ( int i = 0; i <= e; ++i ) {
                int g = solve( E, e - i + R, R, n + 1, act, gain + act[ n ] * i );
                if ( max_gain < g ) max_gain = g;
            }

            return max_gain;
        }
    }
}
