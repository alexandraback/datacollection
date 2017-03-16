
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.logging.Level;
import java.util.logging.Logger;


/**
 *
 * @author Saul Hidalgo
 */
public class Round1BC {
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File("test.txt"));
            PrintStream ps = new PrintStream(new File("output.txt"));

            int T = sc.nextInt();
            double top = 0.0;

            for ( int t = 1 ; t <= T ; t++ ){
                int n = sc.nextInt();
                double[] a = new double[n];
                double sum = 0 ;
                for (int i = 0; i < a.length; i++) {
                    a[i] = sc.nextDouble();
                    sum += a[i];
                }
                double avg = sum * 2 / a.length;
                System.out.println("avg = " + avg );
                top = avg ;
                double[] r = new double[n];
                double sum2 = 0;
                boolean isBad = false;
                for (int i = 0; i < r.length ; i++) {
                    if ( (top - a[i])/sum < 0 ){
                        isBad = true;
                    }
                    r[i] = Math.abs((top - a[i])/sum);
                    sum2 +=  Math.max((top - a[i])/sum, 0);
                    System.out.println("r[i] = " + r[i]);
                }
                System.out.println("sum = " + sum);
                ps.print("Case #" + t + ": ");
                /*if ( isBad ){
                    for (int i = 0; i < r.length-1; i++) {
                        ps.print(".0 ");
                    }
                    ps.println(".0");
                }else{*/
                    double test = 0;
                    for (int i = 0; i < r.length; i++) {
                        test += r[i]/sum2;
                    }
                    System.out.println("Test============ = " + test);
                    for( int i = 0 ; i < n - 1 ; i++ ){
                        ps.printf("%.10f " ,  100.0*r[i]/sum2 );
                    }
                    ps.printf("%.10f\n", 100.0*r[n-1]/sum2);
                //}
            }

        } catch (FileNotFoundException ex) {
            Logger.getLogger(ExerciseA.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
