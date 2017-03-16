import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class LastWord {

  private static String findLastWord( String s ) {
    List<Character> lastWordChars = new ArrayList<Character>();

    for ( char ch : s.toCharArray() ) {
      if ( lastWordChars.size() == 0 ) {
        lastWordChars.add( ch );
      } else if ( ch >= lastWordChars.get( 0 ) ) {
        lastWordChars.add( 0, ch );
      } else {
        lastWordChars.add( ch );
      }
    }

    StringBuilder builder = new StringBuilder( lastWordChars.size() );
    for ( char ch : lastWordChars ) {
      builder.append( ch );
    }

    return builder.toString();
  }

  public static void main( String[] args ) {
    Scanner in = new Scanner( System.in );
    int t = in.nextInt();

    for ( int testCase = 1; testCase <= t; testCase++ ) {
      String s = in.next();
      String result = findLastWord( s );

      System.out.format( "Case #%d: %s\n", testCase, result );
    }
  }

}
