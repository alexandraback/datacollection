package hu.mmatyus.A;

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
      BufferedWriter bw = new BufferedWriter( new FileWriter( new File( "/home/milan/codeJam2015/A/A-small-attempt1.out" ), true ) );
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
      FileInputStream fstream = new FileInputStream( "/home/milan/codeJam2015/A/A-small-attempt1.in" );
      DataInputStream in = new DataInputStream( fstream );
      BufferedReader br = new BufferedReader( new InputStreamReader( in ) );
      String strLine;
      int T = Integer.valueOf( br.readLine() );
      int i = 1, shynessLevel, peopleInOvation, length, friendRequired;
      String[] line;
      String audience;
      while( i <= T ) {
        strLine = br.readLine();

        line = strLine.split( " " );
        length = Integer.valueOf( line[0] );
        friendRequired = 0;
        if( 0 < length ) {
          audience = line[1];
          //System.out.println( audience.charAt( 0 ) );
          peopleInOvation = Character.getNumericValue( audience.charAt( 0 ) );

          shynessLevel = 1;
          while( shynessLevel <= length ) {
            //System.out.println( friendRequired + " --- " + peopleInOvation );
            //System.out.println( peopleInOvation );
            if( peopleInOvation < shynessLevel ) {
              friendRequired += ( shynessLevel - peopleInOvation );
              peopleInOvation += ( shynessLevel - peopleInOvation );
            }
            peopleInOvation += Character.getNumericValue( audience.charAt( shynessLevel ) );
            shynessLevel++;
          }
        }
        //System.out.println( "----" );
        writeToFile( "Case #" + i + ": " + friendRequired );
        i++;
      }
      br.close();
    }
    catch( Exception e ) {//Catch exception if any
      System.err.println( "Error: " + e.getMessage() );
    }
  }
}
