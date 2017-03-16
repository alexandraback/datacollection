import sun.font.FontRunIterator;

import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by slycer on 4/1/16.
 */
public class BFFs {

    public static void main ( String [] args ) throws FileNotFoundException {
        System.setOut( new PrintStream( "BFFs.in" ));
        Scanner s = new Scanner( System.in ) ;
        int tests = s.nextInt();
        for ( int  test=1; test<=tests; test++ ){
            int answer = 0;
            int n = s.nextInt();
            int [] data = new int[n];
            for ( int i=0; i<n; i++ ){
                data[i] = s.nextInt();
            }

            answer = go( new int[n], new boolean[n+1], data, 0 );

            System.err.println("Case #"+test + ": " + answer );
            System.out.println("Case #"+test + ": " + answer );
        }
    }

    public static int go( int [] state, boolean [] used, int [] data, int depth ){
        int answer = 0;
        if ( depth <= data.length ){
            // 0 pana la depth -1
            boolean valid = true;
            //System.err.println( Arrays.toString( state ) );
            for ( int i=0; i<depth; i++ ){
                int friend = data[ state[i] - 1 ];
                int MOD = depth;
                if ( state[(i-1+MOD)%MOD] == friend || state[(i+1)%MOD] == friend ){
                    // ok
                } else {
                    valid = false;
                    break;
                }
            }
            if ( valid ){
                answer = depth;
            }
        }
        if ( depth < data.length ){
            for ( int i=1; i<=data.length; i++ ){
                if ( !used[i] ){
                    used[i] = true;
                    state[depth] = i;
                    int partial = go( state, used, data, depth + 1 );
                    answer = Math.max( answer, partial );
                    used[i] = false;
                }
            }
        }
        return answer;
    }
}
