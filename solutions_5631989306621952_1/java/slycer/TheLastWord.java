import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * Created by slycer on 4/1/16.
 */
public class TheLastWord {

    public static void main ( String [] args ) throws FileNotFoundException {
        System.setOut( new PrintStream( "TheLastWord.out" ));
        Scanner s = new Scanner( System.in ) ;
        int tests = s.nextInt();
        for ( int  test=1; test<=tests; test++ ){
            String answer = "";
            String S = s.next();
            answer = S.charAt(0)+"";
            for ( int i=1; i<S.length(); i++ ){
                char current = S.charAt(i);
                if ( current >= answer.charAt(0) ){
                    answer = current + answer;
                } else {
                    answer = answer + current;
                }
            }

            System.err.println("Case #"+test + ": " + answer );
            System.out.println("Case #"+test + ": " + answer );
        }
    }

}
