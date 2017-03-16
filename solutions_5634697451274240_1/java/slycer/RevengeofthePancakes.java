import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * Created by slycer on 4/1/16.
 */
public class RevengeofthePancakes {

    public static void main ( String [] args ) throws FileNotFoundException {
        System.setOut( new PrintStream( "RevengeofthePancakes.out" ));
        Scanner s = new Scanner( System.in ) ;
        int tests = s.nextInt();
        s.nextLine();
        for ( int  test=1; test<=tests; test++ ){
            char [] state = s.nextLine().toCharArray();
            int answer = 0;
            while (!done(state) ) {
                answer++;
                int i=0;
                while ( i+1<state.length && state[i+1]  == state[i ] ){
                    i++;
                }
                for ( int j=0; j<=i; j++ ){
                    if ( state[j] == '+' ){
                        state[j] = '-';
                    } else {
                        state[j] = '+';
                    }
                }
            }
            System.err.println("Case #"+test + ": " + answer );
            System.out.println("Case #"+test + ": " + answer );
        }
    }

    public static boolean done( char [] str ){
        for ( int i=0; i<str.length; i++ ){
            if ( str[ i ] != '+' ){
                return false;
            }
        }
        return true;
    }

}
