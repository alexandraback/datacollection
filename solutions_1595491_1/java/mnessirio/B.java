package gcj_2012;

/**
 * Time: 5:10:03 PM, Apr 13, 2012
 * @author Maya is the best :-)
 */
import java.util.Scanner;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class B {
    
    static Scanner in;
    static String path = "src/gcj_2012/";
    static String taskname = "B-large";
    
    public static String solve() {
        int N = in.nextInt();
        int S = in.nextInt();
        int p = in.nextInt();
        int y = 0;
        int t[] = new int[N];
        for (int i =0; i<N; i++) 
            t[i] = in.nextInt();
        
        for(int i=0; i<N; i++) {
            if ( t[i] >= (3*p - 2) )
                y++;
            else if ( t[i] >= (3*p - 4)  && S>0 && t[i]!=0) 
            {
                y++;
                S--;
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
