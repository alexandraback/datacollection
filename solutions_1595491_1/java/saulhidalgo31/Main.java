import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

/**
 *
 * @author Saul Hidalgo
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File("test2.txt"));
            PrintStream ps = new PrintStream(new File("output2.txt"));

            int T = sc.nextInt();
            for ( int t = 1 ; t <= T ; t++ ){
                int n = sc.nextInt(), s = sc.nextInt(), p = sc.nextInt();

                int[] l = new int[n];
                for ( int i = 0 ; i < n ; i++ ){
                    l[i] = sc.nextInt() - p ;
                }

                int a = 0 , b = 0;

                for ( int i = 0 ; i < n ; i++ ){
                    if ( l[i] == -1 && p > 0 ){
                    }else if ( l[i] >= 2*( p - 1 ) ){
                        ++a;
                    }else if ( l[i] >= 2*( p - 2 ) ){
                        ++b;
                    }
                }
                ps.println("Case #" + t + ": " + ( a + b - Math.max(0, b - s ) ));
            }
            
        }
        catch (FileNotFoundException ex) {
            // =(
        }
    }
}
