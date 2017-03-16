/* ==========================================================
 *  (C) Copyright 2007-present Facebook. All rights reserved.
 * ==========================================================
 */


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * .
 *
 * @author
 */
public class Dancers {
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

    private static void handleLine( String readLine, int lineNumber ) {
        String[] numbers       = readLine.split( " " );
        int      n             = Integer.parseInt( numbers[ 0 ] );
        int      s             = Integer.parseInt( numbers[ 1 ] );
        int      p             = Integer.parseInt( numbers[ 2 ] );
        int      results       = 0;
        int      thresholdNotS = p * 3 - 3 > 0 ? p * 3 - 3 : 0;
        int      thresholdS    = p * 3 - 5 > 0 ? p * 3 - 5 : 0;

        for( int i = 3; i < n + 3; i++ ) {
            int score = Integer.parseInt( numbers[ i ] );

            if( p == 0 ) {
                results++;
            } else if( score > ( thresholdNotS ) ) {
                results++;
            } else if( s > 0 && score > thresholdS ) {
                results++;
                s--;
            }
        }

        System.out.println( "Case #" + ( lineNumber + 1 ) + ": " + results );
    }
}
