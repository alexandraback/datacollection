
package qualification;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

/**
 *
 * @author jesus
 */
public class A {
    public static void solveCase(Scanner in, PrintStream out) {
        int S = in.nextInt();
        String s = in.next();
        int current = 0, needed = 0;
        for (int i = 0; i <= S; i++) {
            int people = s.charAt(i) - '0';
            if (people > 0) {
                int neededNow = Math.max(0, i-current);
                needed += neededNow;
                current = current + neededNow + people;
            }
        }
        out.println(needed);
    }
    
    public static void main(String[] args) throws FileNotFoundException {
        String fileIn = "A-large.in";
        FileInputStream fis = new FileInputStream(fileIn);
        Scanner sc = new Scanner(fis);
        //PrintStream pw = System.out;
        PrintStream pw = new PrintStream(new FileOutputStream("A.out"));
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            pw.printf("Case #%d: ", i);
            solveCase(sc, pw);
        }
    }
    
}
