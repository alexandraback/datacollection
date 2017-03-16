package com.googlerese.core;

import java.util.HashMap;
import java.util.Map;

import com.googlerese.file.FileRead;
import com.googlerese.file.FileWrite;

public class GooglereseConvertor {

    private static final char[] arr = "yhesocvxduiglbkrztnwjpfmaq".toCharArray();

    private static final String inputFileName = "C:/Documents and Settings/garan14/Desktop/input.txt";

    private static final String outputFileName = "C:/Documents and Settings/garan14/Desktop/out.txt";

    public static void main( String[] args ) {
        GooglereseConvertor convertor = new GooglereseConvertor();
        Map<Integer, String> input = FileRead.getInstance().read( inputFileName );
        int testCases = input.size();
        Map<Integer, String> output = new HashMap<Integer, String>( testCases );

        for ( int i = 1; i <= testCases; i++ ) {
            String outputStr = convertor.convert( input.get( i ) );
            System.out.println( "Output : " + outputStr );
            output.put( i, outputStr );
        }
        FileWrite.getInstance().write( outputFileName, output );
    }

    private String convert( final String input ) {
        char[] charArray = input.toCharArray();
        for ( int i = 0; i < charArray.length; i++ ) {
            if ( charArray[i] != ' ' ) {
                int j = (int) charArray[i];
                charArray[i] = arr[( j - 97 )];
            }
        }
        return String.valueOf( charArray );
    }

}
