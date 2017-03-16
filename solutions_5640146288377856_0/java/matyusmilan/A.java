package hu.mmatyus;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;

public class A {
  public static void writeToFile( String text ) {
    try {
      BufferedWriter bw = new BufferedWriter( new FileWriter( new File( "/home/milan/codeJam2015/r1c/A/out" ), true ) );
      bw.write( text );
      bw.newLine();
      bw.close();
    }
    catch( Exception e ) {
      System.err.println( "Error: " + e.getMessage() );
    }
  }

  public static void main( String[] args ) {
    try {
      FileInputStream fstream = new FileInputStream( "/home/milan/codeJam2015/r1c/A/in" );
      DataInputStream in = new DataInputStream( fstream );
      BufferedReader br = new BufferedReader( new InputStreamReader( in ) );
      int T = Integer.valueOf( br.readLine() );
      int i = 1;
      String strLine;
      String[] line;
      while( i <= T ) {
        strLine = br.readLine();
        line = strLine.split( " " );
        int R, C, W, res = -1;
        R = Integer.valueOf( line[0] );
        C = Integer.valueOf( line[1] );
        W = Integer.valueOf( line[2] );
        if( W == C )
          res = R - 1 + W;
        else if( C % W == 0 )
          res = R * ( C / W ) + W - 1;
        else
          res = R * ( C / W ) + W;
        //System.out.println( "Case #" + i + ": " + res );
        writeToFile( "Case #" + i + ": " + res );
        i++;
      }
      br.close();
    }
    catch( Exception e ) {//Catch exception if any
      System.err.println( "Error: " + e.getMessage() );
    }
  }
}
