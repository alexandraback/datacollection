package com.googlerese.core;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

import com.googlerese.file.FileRead;
import com.googlerese.file.FileWrite;

public class NumberRecycler {

    private static final String inputFileName = "C:/Documents and Settings/garan14/Desktop/input.txt";

    private static final String outputFileName = "C:/Documents and Settings/garan14/Desktop/out.txt";

    private static long divider = 1;

    public static void main( String[] args ) {
        NumberRecycler convertor = new NumberRecycler();
        Map<Integer, String[]> input = FileRead.getInstance().read( inputFileName );
        int testCases = input.size();
        Map<Integer, String> output = new HashMap<Integer, String>( testCases );

        for ( int i = 1; i <= testCases; i++ ) {
            String[] arr = input.get( i );
            String outputStr = convertor.convert( Long.parseLong( arr[0] ), Long.parseLong( arr[1] ) );
            output.put( i, outputStr );
        }
        System.out.println("Done");
        FileWrite.getInstance().write( outputFileName, output );
    }

    private String convert( final long start, final long end ) {
        long count = 0;
        for ( long i = start; i <= end; i++ ) {
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
            } else if ( i > 999999 & i <= 2000000 ) {
                divider = 1000000;
            }
            long num = i;
            do {
                long rem = num % 10;
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
