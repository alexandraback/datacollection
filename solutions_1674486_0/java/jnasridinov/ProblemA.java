package codejam2012;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by IntelliJ IDEA.
 * User: Jimmy
 * Date: 5/6/12
 * Time: 2:59 PM
 */
public class ProblemA implements Runnable {

    Scanner scanner;
    PrintWriter pw;

    public static void main(String arguments[]) {
        new Thread(new ProblemA()).start();
    }

    int n;
    int a[][];

    public void solution() {
        int t = scanner.nextInt();

        for(int l = 1; l <= t; l++) {
            n = scanner.nextInt();
            a = new int[n][n];
            c = new boolean[n];

            int b[] = new int[n];

            for(int i = 0; i < n; i++) {
                int m = scanner.nextInt();
                for(int j = 0; j < m; j++) {
                    int classNumber = scanner.nextInt() - 1;
                    a[i][classNumber] = 1;
                    b[classNumber]++;
                }
            }

            boolean is = false;

            for(int i = 0; i < n; i++) {
                if(b[i] == 0) {
                    Arrays.fill(c, false);
                    if(isDiamond(i)) {
                        pw.println("Case #" + l + ": " + "Yes");
                        is = true;
                        break;
                    }
                }
            }
            if(!is)
                pw.println("Case #" + l + ": " + "No");
        }

        //System.out.println("******************************************************");
        //pw.println("Case #" + i + ": " + (Math.min(s, sum1) + sum2));
    }

    boolean c[];

    public boolean isDiamond(int i) {
        c[i] = true;

        for(int j = 0; j < n; j++) {
            if(a[i][j] == 1) {
                if(!c[j]) {
                    boolean is = isDiamond(j);
                    if(is) return is;
                } else {
                    return true;
                }
            }
        }

        return false;
    }

    public void run() {
        scanner = new Scanner(System.in);
        try {
            //pw = new PrintWriter(new File("output.txt"));
            pw = new PrintWriter(System.out);
        } catch (Exception e) {
            e.printStackTrace();
        }

        solution();

        pw.close();
        scanner.close();
    }
}
