import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by slycer on 4/1/16.
 */
public class CoinJam {

    public static void main ( String [] args ) throws FileNotFoundException {
        System.setOut( new PrintStream( "CoinJam.out" ));
        Scanner s = new Scanner( System.in ) ;
        int tests = s.nextInt();
        for ( int  test=1; test<=tests; test++ ){
            int answer = 0; 
            int n = s.nextInt();
            int j = s.nextInt();
            System.out.println("Case #"+test + ":");
            for ( long i=(1l<<(n-1)); i<= ( 1l<<n); i++ ){
                if ( i % 100000 == 0 ){
                    System.err.println( i );
                }
                    String str="";
                    for ( int k=n-1; k>=0; k--){
                        if ( ( ( 1<<k )& i )>0 ){
                            str += "1";
                        } else {
                            str += "0";
                        }
                    }
                    List<BigInteger> answers = new ArrayList<>();
                    for ( int base=2; base<=10; base++ ){
                        BigInteger x = isJamCoin( str, base );
                        if ( x != null ){
                            answers.add( x );
                        } else {
                            break;
                        }
                    }
                if ( answers.size() == 9 ){
                    System.err.print( str );
                    System.out.print( str );

                    for ( BigInteger div : answers ){
                        System.err.print( " " + div );
                        System.out.print( " " + div );
                    }
                    System.out.println( );
                    System.err.println( );
                    j--;
                    if ( j == 0 ){
                        break;
                    }
                }
            }

           // System.err.println("Case #"+test + ": " + answer );
           // System.out.println("Case #"+test + ": " + answer );
        }
    }

    public static BigInteger isJamCoin( String str, int base ){
        if ( str.length() < 2 ){
            return null;
        }
        if ( str.charAt(0)!='1' || str.charAt( str.length() - 1) != '1' ){
            return null;
        }
        BigInteger p = BigInteger.ONE;
        BigInteger result = BigInteger.ZERO;
        for ( int i=str.length()-1; i>=0; i-- ){
            if ( str.charAt(i) == '1' ){
                result = result.add( p );
            }
            p = p.multiply( BigInteger.valueOf( base ) );
        }

        //System.err.println( str + " " +  result + " " + base );
        int count = 0;
        for ( BigInteger i = BigInteger.valueOf( 2 ); i.multiply(i).compareTo(result)<=0; i=i.add( BigInteger.ONE ) ){
            if ( result.mod( i ).equals( BigInteger.ZERO )){
                return i;
            }
            count ++;
            if ( count >= 10000 ){
                break;
            }
        }
        return null;
    }

}
