/* ==========================================================
 *  (C) Copyright 2007-present Facebook. All rights reserved.
 * ==========================================================
 */


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/**
 * .
 *
 * @author
 */
public class Recycle {
    public static void main( String[] args ) throws NumberFormatException,
        IOException {
        final BufferedReader in =
            new BufferedReader( new FileReader(
                    "/Users/oded/a/ttt/src/in.txt" ) );
        final int numLines = Integer.parseInt( in.readLine() );

        for( int i = 0; i < numLines; i++ ) {
            handleLine( in.readLine(), i );
        }
    }

    private static int countDigits( int a ) {
        int count = 0;

        while( a > 0 ) {
            count++;
            a = a / 10;
        }

        return count;
    }

    private static void handleLine( String readLine, int i ) {
        String[] numbers = readLine.split( " " );
        int      a       = Integer.parseInt( numbers[ 0 ] );
        int      b       = Integer.parseInt( numbers[ 1 ] );
        int      count   = 0;
        int      digits  = countDigits( a );

        if( digits > 1 ) {
            int den = 1;

            while( digits > 1 ) {
                den *= 10;
                digits--;
            }

            for( int n = a; n < b; n++ ) {
                int perm = shift( n, den );

                while( perm != n ) {
                    if( perm > n && perm <= b ) {
                        count++;
                    }

                    perm = shift( perm, den );
                }
            }
        }

        System.out.println( "Case #" + ( i + 1 ) + ": " + count );
    }

    private static int shift( int n, int den ) {
        return ( n / den ) + ( n % den ) * 10;
    }
}
