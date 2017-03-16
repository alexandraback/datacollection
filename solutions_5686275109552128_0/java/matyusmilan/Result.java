package hu.mmatyus.B;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.Arrays;

// Infinite House of Pancakes
public class Result {
  public static void writeToFile( String text ) {
    try {
      BufferedWriter bw = new BufferedWriter( new FileWriter( new File( "/home/milan/codeJam2015/B/B-small-attempt0.out" ), true ) );
      bw.write( text );
      bw.newLine();
      bw.close();
    }
    catch( Exception e ) {
      System.err.println( "Error: " + e.getMessage() );
    }
  }

  public static int max( int[] intArray ) {
    int max = 0;
    for( int i = 0; i < intArray.length; i++ ) {
      if( intArray[i] > max )
        max = intArray[i];
    }
    return max;
  }

  public static void main( String[] args ) {
    try {
      FileInputStream fstream = new FileInputStream( "/home/milan/codeJam2015/B/B-small-attempt0.in" );
      DataInputStream in = new DataInputStream( fstream );
      BufferedReader br = new BufferedReader( new InputStreamReader( in ) );
      int plates = 0;
      int T = Integer.valueOf( br.readLine() );
      for( int i = 1; i <= T; i++ ) {
        plates = Integer.valueOf( br.readLine() );
        String[] strArray = new String[plates];
        strArray = br.readLine().split( " " );
        int[] pancakes = new int[plates];
        for( int j = 0; j < strArray.length; j++ ) {
          pancakes[j] = Integer.parseInt( strArray[j] );
        }
        Arrays.sort( pancakes );
        int minStep = pancakes[plates - 1];
        for( int currHeight = 1; currHeight <= pancakes[plates - 1]; currHeight++ ) {
          int sumSlice = 0;
          for( int k = pancakes.length - 1; 0 <= k; k-- ) {
            sumSlice += Math.floor( pancakes[k] / currHeight );
            if( pancakes[k] % currHeight == 0 ) {
              sumSlice--;
            }
          }
          if( ( sumSlice + currHeight ) < minStep )
            minStep = ( sumSlice + currHeight );

          if( currHeight == minStep )
            break;
        }
        //System.out.println( "Case #" + i + ": " + minStep );
        writeToFile( "Case #" + i + ": " + minStep );
      }
      br.close();
    }
    catch( Exception e ) {//Catch exception if any
      System.err.println( "Error: " + e.getMessage() );
    }
  }
}
