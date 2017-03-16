import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * Created by slycer on 4/1/16.
 */
public class Fractiles {

    public static void main ( String [] args ) throws FileNotFoundException {
        System.setOut( new PrintStream( "Fractiles.out" ));
        Scanner s = new Scanner( System.in ) ;
        int tests = s.nextInt();
        for ( int  test=1; test<=tests; test++ ){
            String answer = "";
            long K = s.nextLong();
            long C = s.nextLong();
            long S = s.nextLong();

            for ( int i=1; i<=S; i++ ){
                answer += " " + i;
            }

            System.err.println("Case #"+test + ":" + answer );
            System.out.println("Case #"+test + ":" + answer );

        }
    }

}
