
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
public class C {
    
    public static int mult(int i, int j) {
        int[][] t = {
            { 0, 1, 2, 3 },
            { 1, 4, 3, 6 },
            { 2, 7, 4, 1 },
            { 3, 2, 5, 4 }
        };
        
        return (t[i%4][j%4] + 4 * ((i/4 + j/4)%2)) % 8;
    }
    
    public static int encode(char c) {
        return c - 'i' + 1;
    }
    
    public static void solveCase(Scanner in, PrintStream out) {
        
        int L = in.nextInt();
        long X = in.nextLong();
        String str = in.next();
        
        int current = 0;
        for (int i = 0; i < L; i++) {
            current = mult(current, encode(str.charAt(i)));
        }
        int series = current;
        current = 0;
        for (int i = 0; i < (int)(X%4); i++) {
            current = mult(current, series);
        }
       System.out.printf("%d\n", current);
        
        if (current != 4) {
            out.println("NO");
            return;
        }
        

        int minPre = -1;
        current = 0;
        for (int i = 0; i < Math.min(4, X) * L; i++) {
            current = mult(current, encode(str.charAt(i%L)));
            //System.out.printf("pre %c: %d\n", str.charAt(i%L), current);
            if (current == 1) {
                minPre = i+1;
                break;
            }
        }
        
        int minPost = -1;
        current = 0;
        for (int i = (int)Math.min(4, X) * L - 1; i >= 0; i--) {
            current = mult(encode(str.charAt(i%L)), current);
            //System.out.printf("post %c: %d\n", str.charAt(i%L), current);
            if (current == 3) {
                minPost = (int)Math.min(4, X) * L - i;
                break;
            }
        }

        //System.out.printf("%d %d %d\n", minPre, minPost, L*X);

        if (minPre > 0 && minPost > 0 && minPre + minPost < L * X) {
            out.println("YES");
        }
        else {
            out.println("NO");
        }
    }
    
    public static void main(String[] args) throws FileNotFoundException {
        String prefix = "C";
        //prefix += "-small-attempt0";
        prefix += "-large";
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
