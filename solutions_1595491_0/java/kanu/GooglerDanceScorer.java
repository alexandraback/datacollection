package com.googlerese.core;

import java.util.HashMap;
import java.util.Map;

import com.googlerese.file.FileRead;
import com.googlerese.file.FileWrite;
import com.googlerese.file.GooglersBean;

public class GooglerDanceScorer {

    private static final String inputFileName = "C:/Documents and Settings/garan14/Desktop/input.txt";

    private static final String outputFileName = "C:/Documents and Settings/garan14/Desktop/out.txt";

    public static void main( String[] args ) {
        GooglerDanceScorer convertor = new GooglerDanceScorer();
        Map<Integer, GooglersBean> input = FileRead.getInstance().read( inputFileName );
        int testCases = input.size();
        Map<Integer, String> output = new HashMap<Integer, String>( testCases );

        for ( int i = 1; i <= testCases; i++ ) {
            String outputStr = convertor.convert( input.get( i ) );
            System.out.println( "Output : " + outputStr );
            output.put( i, outputStr );
        }
        FileWrite.getInstance().write( outputFileName, output );
    }

    private String convert( final GooglersBean input ) {

        int[] scores = input.getScores();
        int numGooglers = input.getNumGooglers();
        int surprising = input.getSurprising();
        int maxResult = input.getResult();
        int max = 0;
        for ( int i = 0; i < numGooglers; i++ ) {
            int score = scores[i];

            int score1 = score / 3;
            score = score - score1;

            int score2 = score / 2;
            score = score - score2;
            int score3 = score;

            if ( score3 >= maxResult ) {
                max++;
            } else if ( surprising > 0 ) {
                if ( score3 > 0 && ( score3 == score2 ) && ( score3 == ( maxResult - 1 ) ) ) {
                    max++;
                    surprising--;
                }
            }

        }

        return "" + max;
    }
}
