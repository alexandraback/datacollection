package gcj_2012;

/**
 * Time: 6:00:08 PM, Apr 27, 2012
 * @author Maya is the best :-)
 */
import java.util.Scanner;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class A {
    
    static Scanner in;
    static String path = "src/gcj_2012/";
    static String taskname = "A-small-attempt0";
    
    public static String solve() {
        int A = in.nextInt();
        int B = in.nextInt();
        double prob = 1;
        
        double p[]=new double[A];
        double pro[]=new double[A+1];
        double average[]=new double[A+1];
        for (int i=0; i<A; i++) {
            p[i] = in.nextDouble(); 
        }
        
        // index is how many should delete
        for (int i=0; i<A; i++) {
            pro[A-i] = (1 - p[i]) * prob;
            prob *= p[i];
        }
        pro[0] = prob;
        
        // i - needs delete
        for(int i=0; i<=A; i++) {
            // j - we delete
            for(int j=0; j<=A; j++) {
                double Keystrokes = 2*j + 1 + B - A;
                if ( j < i ) 
                    Keystrokes += B + 1;
         //       System.out.print(Keystrokes + "  ");
                average[j] += pro[i] * Keystrokes;
                
            }
        }
        // if we just give up
        double min = 2+B;
        for (int i=0; i<=A; i++)
            if (min > average[i])
                min = average[i];
        
        return "" + min;
    }
    
    public static void main(String[] args) {
        PrintWriter pW = null;
        
        try {
            pW = new PrintWriter(new FileOutputStream(path
                    + taskname + ".out"));
            try {
                in = new Scanner(new FileInputStream(path
                        + taskname + ".in"));
                int T = in.nextInt();
                for (int caseNumber = 1; caseNumber <= T; caseNumber++) {
                    pW.println("Case #" + caseNumber + ": " + solve());
                }
                in.close();
                pW.close();
            } catch (IOException e) {
                System.out.println("Can not find file " + taskname + ".in");
            }
        } catch (IOException e) {
            System.out.println("Open or create exception with "
                    + taskname + ".out");
        }
    }
}
