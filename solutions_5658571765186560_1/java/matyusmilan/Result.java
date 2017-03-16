package hu.mmatyus.D;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;

public class Result {
  public static void writeToFile( String text ) {
    try {
      BufferedWriter bw = new BufferedWriter( new FileWriter( new File( "/home/milan/codeJam2015/D/D-large.out" ), true ) );
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
      FileInputStream fstream = new FileInputStream( "/home/milan/codeJam2015/D/D-large.in" );
      DataInputStream in = new DataInputStream( fstream );
      BufferedReader br = new BufferedReader( new InputStreamReader( in ) );
      String[] line;
      String theWinnerIs = "MILAN";
      int T = Integer.valueOf( br.readLine() );
      int i = 1;
      int x, r, c, mincord;
      while( i <= T ) {
        line = br.readLine().split( " " );
        x = Integer.parseInt( line[0] );
        r = Integer.parseInt( line[1] );
        c = Integer.parseInt( line[2] );
        if( ( r * c ) % x == 0 ) {
          if( x < 7 ) {
            if( 3 <= x ) {
              mincord = ( r < c ? r : c );
              //System.out.println( "Case #" + i + ": " + mincord + " ---- " + x );
              switch( x ) {
                case 3:
                  theWinnerIs = ( mincord >= 2 ? "GABRIEL" : "RICHARD" );
                  break;
                case 4:
                  theWinnerIs = ( mincord >= 3 ? "GABRIEL" : "RICHARD" );
                  break;
                case 5:
                  theWinnerIs = ( mincord >= 4 ? "GABRIEL" : "RICHARD" );
                  break;
                case 6:
                  theWinnerIs = ( mincord >= 4 ? "GABRIEL" : "RICHARD" );
                  break;
                default:
                  break;
              }
            } else {
              theWinnerIs = "GABRIEL";
            }
          } else {
            theWinnerIs = "RICHARD";
          }
        } else {
          theWinnerIs = "RICHARD";
        }
        writeToFile( "Case #" + i + ": " + theWinnerIs );
        theWinnerIs = "";
        i++;
      }
      br.close();
    }
    catch( Exception e ) {//Catch exception if any
      System.err.println( "Error: " + e.getMessage() );
    }
  }
}
