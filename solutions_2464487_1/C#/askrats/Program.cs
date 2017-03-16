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
                Console.WriteLine( "Case #" + ( t + 1 ).ToString() + ": " + Solve( rt[ 0 ], rt[ 1 ] ).ToString() );
            }
        }

        static long f( long r, long num )
        {
            return num * ( 2 * num + 2 * r - 1 );
        }

        static int f( long r, long num, long t )
        {
            if ( 2 * ( num + r ) > ( t / num + 1 ) + 1 ) return 1;
            if ( 2 * ( num + r ) < ( t / num + 1 ) - 1 ) return -1;

            long need = f( r, num );
            return need == t ? 0 : need < t ? -1 : 1;
        }

        static long Solve( long r, long t  )
        {
            long num = ( long ) 707106780;
            long dist = num / 2;
            while ( true ) {
//                System.Console.WriteLine( num.ToString() + " -> " + f( r, num ) );
                switch ( f( r, num, t ) ) {
                case 0:
                    return num;
                case -1:
                    switch ( f( r, num + 1, t ) ) {
                    case 0: return num + 1;
                    case 1: return num;
                    }
                    num += dist;
                    break;
                case 1:
                    switch ( f( r, num - 1, t ) ) {
                    case 0: return num - 1;
                    case -1: return num - 1;
                    }
                    num -= dist;
                    break;
                }
                dist /= 2;
                if ( dist < 1 ) dist = 1;
            }

#if false
            for ( long d = 1, num=0; ; d += 4, ++num ) {
                t -= 2 * r + d;
                if ( t < 0 ) return ( num ).ToString();
            }
#endif
        }
    }
}
