package gcj_2012;

/**
 * Time: 3:59:11 PM, Apr 13, 2012
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
    static String taskname = "A-small-attempt1";
    
    public static String solve() {
        String googleres = in.nextLine();
        String hint = "|ay|bh|ce|ds|eo|fc|gv|hx|id|ju|ki|lg|ml|nb|ok|pr|qz|rt|sn|tw|uj|vp|wf|xm|ya|zq|  |";
        String english = "";
        
        for (int i=0; i< googleres.length(); i++) {
            int ind = hint.indexOf("|" + googleres.charAt(i));
            english += hint.charAt(ind+2); 
        }        
        return english;
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
                in.nextLine();
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
