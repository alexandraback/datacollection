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
            int K = s.nextInt();
            int C = s.nextInt();
            long S = s.nextLong();


            int n = K;
            String [] data = new String[n];
            for ( int i=0; i<n; i++ ){
                String base = "";
                for ( int j=0; j<n; j++ ){
                    if ( i==j ){
                        base += "G";
                    } else {
                        base += "L";
                    }
                }
                data[i] = expand( base, 2 );
                //System.err.println( data[i] );
            }
//            GGGGLLGLL
//                    LGLGGGLGL
//            LLGLLGGGG
//            Case #1: 2 3


            if (C == 1) {
                if ( S < K ){
                    answer = " IMPOSSIBLE";
                } else {
                    for (int i = 1; i <= K; i++) {
                        answer += " " + i;
                    }
                }
            } else {
                for ( int i=0; i<n-1; i+=2 ){
                    for ( int j=0; j<data[i].length(); j++ ){
                        if ( data[i].charAt(j) == 'G' && data[i+1].charAt(j) == 'G' ){
                            S--;
                            answer += " " + ( j+1 );
                            break;
                        }
                    }
                }
                if ( n%2==1 ){
                    for ( int j=0; j<data[n-1].length(); j++ ){
                        if ( data[n-1].charAt(j) == 'G' ){
                            S--;
                            answer += " " + (j+1);
                            break;
                        }
                    }
                }
            }

            if ( S < 0 ){
                answer = " IMPOSSIBLE";
            }

            System.err.println("Case #"+test + ":" + answer );
            System.out.println("Case #"+test + ":" + answer );
        }
    }

    public static String expand( String str, int k ){
        for ( int i=1; i<k; i++ ){
            str = expand( str );
        }
        return str;
    }
    public static String expand( String str ){
        String ret = "";
        String g = "";
        for ( int i=0; i<str.length(); i++ ){
            g += "G";
        }
        for ( int i=0; i<str.length(); i++ ){
            if ( str.charAt( i ) == 'L' ){
                ret += str;
            } else {
                ret += g;
            }
            if ( ret.length() >= 11000 ){
                return ret;
            }
        }
        return ret;
    }

}
