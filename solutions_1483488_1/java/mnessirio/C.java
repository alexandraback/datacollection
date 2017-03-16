package gcj_2012;

/**
 * Time: 6:31:53 PM, Apr 13, 2012
 * @author Maya is the best :-)
 */
import java.util.Scanner;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class C {
    
    static Scanner in;
    static String path = "src/gcj_2012/";
    static String taskname = "C-large";
    
    public static String solve() {
        int A = in.nextInt();
        int B = in.nextInt();
        int y = 0;
        int digits = 1;
        int n = A;
        int tens;
        while ( n > 9) {
            digits++;
            n /= 10;
        }
        tens = (int)Math.pow(10, digits-1);
            
        for (int i=A; i<B; i++) {
            int m[]=new int[digits];
            m[0] = i;
            for (int j=1; j<digits; j++ ) {
                m[j] = m[j-1]/10 + tens * (m[j-1]%10) ;               
                if ( i < m[j] && m[j] <= B ) {
                    // check
                    boolean b = true;
                    for(int k = 1; k<j; k++)
                        if (m[j]==m[k])
                            b=false;                    
                    if (b) y++;
                }
            } 
        }
        
        return "" + y;
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
