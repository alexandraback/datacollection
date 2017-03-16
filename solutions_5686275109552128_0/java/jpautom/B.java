
package qualification;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author jesus
 */
public class B {
    public static void solveCase(Scanner in, PrintStream out) {
        int D = in.nextInt();
        int[] P = new int[D];
        for (int i = 0; i < P.length; i++) {
            P[i] = in.nextInt();

        }
        Arrays.sort(P);
        int minTime = P[P.length - 1];
        for (int thres = P[P.length - 1]; thres >= 1; thres--) {
            int moves = 0;
            for (int i = 0; i < P.length; i++) {
                moves += Math.max(0, (P[i]-1) / thres);
            }
            if (thres + moves < minTime) {
                minTime = thres + moves;
            }
        }
        
        out.println(minTime);
    }
    
    public static void main(String[] args) throws FileNotFoundException {
        String prefix = "B-small-attempt0";
        FileInputStream fis = new FileInputStream(prefix + ".in");
        Scanner sc = new Scanner(fis);
        //PrintStream pw = System.out;
        PrintStream pw = new PrintStream(new FileOutputStream(prefix + ".out"));
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            pw.printf("Case #%d: ", i);
            solveCase(sc, pw);
        }
    }
}
