package com.googlerese.core;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

import com.googlerese.file.FileRead;
import com.googlerese.file.FileWrite;

public class NumberRecycler {

    private static final String inputFileName = "C:/Documents and Settings/garan14/Desktop/input.txt";

    private static final String outputFileName = "C:/Documents and Settings/garan14/Desktop/out.txt";

    private static int divider = 1;


    public static void main( String[] args ) {
        NumberRecycler convertor = new NumberRecycler();
        Map<Integer, String[]> input = FileRead.getInstance().read( inputFileName );
        int testCases = input.size();
        Map<Integer, String> output = new HashMap<Integer, String>( testCases );

        for ( int i = 1; i <= testCases; i++ ) {
            String[] arr = input.get( i );
            String outputStr = convertor.convert( Integer.parseInt( arr[0] ), Integer.parseInt( arr[1] ) );
            System.out.println( "Output : " + outputStr );
            output.put( i, outputStr );
        }
        FileWrite.getInstance().write( outputFileName, output );
    }

    private String convert( final int start, final int end ) {
        int count = 0;
        for ( int i = start; i <= end; i++ ) {
            if ( i > 0 && i < 10 ) {
                divider = 1;
            } else if ( i > 9 && i < 100 ) {
                divider = 10;
            } else if ( i > 99 && i < 1000 ) {
                divider = 100;
            } else if ( i > 999 & i < 10000 ) {
                divider = 1000;
            } else if ( i > 9999 & i < 100000 ) {
                divider = 10000;
            } else if ( i > 99999 & i < 1000000 ) {
                divider = 100000;
            }
            int num = i;
            do {
                int rem = num % 10;
                num = num / 10;
                num = rem * divider + num;
                if ( num > i && num <= end ) {
                    count++;
                }
            } while ( i != num );
        }
        return "" + count;
    }
}
