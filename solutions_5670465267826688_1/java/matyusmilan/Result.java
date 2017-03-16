package hu.mmatyus.C;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;

// Dijkstra
public class Result {
  public static void writeToFile( String text ) {
    try {
      BufferedWriter bw = new BufferedWriter( new FileWriter( new File( "/home/milan/codeJam2015/C/C-large.out" ), true ) );
      // BufferedWriter bw = new BufferedWriter( new FileWriter( new File( "/home/milan/codeJam2015/C/debug.out" ), true ) );
      bw.write( text );
      bw.newLine();
      bw.close();
    }
    catch( Exception e ) {
      System.err.println( "Error: " + e.getMessage() );
    }
  }

  public static final int I_VAL  = 2;
  public static final int J_VAL  = 3;
  public static final int K_VAL  = 4;

  public static int[][]   mTable = { //
                                 //
      { 0, 0, 0, 0, 0 }, //
      { 0, 1, 2, 3, 4 }, //
      { 0, 2, -1, 4, -3 }, //
      { 0, 3, -4, -1, 2 }, //
      { 0, 4, 3, -2, -1 }       };

  public static int decodeChar( char c ) {
    return c - 'i' + 2;
  }

  public static int mul( int left, int right ) {
    int lidx = Math.abs( left );
    int lsgn = left / lidx;
    int ridx = Math.abs( right );
    int rsgn = right / ridx;
    return lsgn * rsgn * mTable[lidx][ridx];
  }

  public static void main( String[] args ) throws Exception {
    FileInputStream fstream = new FileInputStream( "/home/milan/codeJam2015/C/C-large.in" );
    // FileInputStream fstream = new FileInputStream( "/home/milan/codeJam2015/C/debug.in" );
    DataInputStream in = new DataInputStream( fstream );
    BufferedReader br = new BufferedReader( new InputStreamReader( in ) );
    int T = Integer.valueOf( br.readLine() );
    for( int i = 1; i <= T; ++i ) {
      String[] line = br.readLine().split( " " );
      int len = Integer.parseInt( line[0] );
      long origRepeat = Long.parseLong( line[1] );
      String input = br.readLine();
      long repeat = origRepeat % 4;
      if( repeat == 0 ) {
        writeToFile( "Case #" + i + ": NO" );
        continue;
      }
      if( origRepeat > 4 ) {
        repeat += 4;
      }

      int rightPos = (int) ( len * repeat - 1 );
      {
        int prod = 1;
        for( int currPos = 0; currPos <= rightPos; ++currPos ) {
          prod = mul( prod, decodeChar( input.charAt( currPos % len ) ) );
        }
        if( -1 != prod ) {
          writeToFile( "Case #" + i + ": NO" );
          continue;
        }
      }

      int leftPos = 0;
      {
        boolean findI = false;
        int prod = 1;
        while( leftPos + 2 <= rightPos ) {
          prod = mul( prod, decodeChar( input.charAt( leftPos % len ) ) );
          if( prod == I_VAL ) {
            findI = true;
            break;
          }
          leftPos++;
        }
        if( !findI ) {
          writeToFile( "Case #" + i + ": NO" );
          continue;
        }
      }

      {
        boolean findK = false;
        int prod = 1;
        while( leftPos + 2 <= rightPos ) {
          //System.out.println( "char: " + str.charAt( rightPos % l ) );
          prod = mul( decodeChar( input.charAt( rightPos % len ) ), prod );
          if( prod == K_VAL ) {
            findK = true;
            break;
          }
          rightPos--;
        }
        if( !findK ) {
          writeToFile( "Case #" + i + ": NO" );
          continue;
        }
      }

      writeToFile( "Case #" + i + ": YES" );
    } // for i in [1,T]
    br.close();
  }
}
