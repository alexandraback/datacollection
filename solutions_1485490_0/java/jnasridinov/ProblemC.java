package codejam2012;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by IntelliJ IDEA.
 * User: Jimmy
 * Date: 5/6/12
 * Time: 4:04 PM

 */
public class ProblemC implements Runnable {

    Scanner scanner;
    PrintWriter pw;

    public static void main(String arguments[]) {
        new Thread(new ProblemC()).start();
    }

    int n;
    int m;
    long a[];
    long c[];
    long b[];
    long d[];
    long f[][];


    public void solution() {
        int t = scanner.nextInt();

        for(int l = 1; l <= t; l++) {
            n = scanner.nextInt();
            m = scanner.nextInt();

            f = new long[n + 1][m + 1];

            a = new long[n];
            c = new long[n];

            b = new long[m];
            d = new long[m];

            for(int i = 0; i < n; i++) {
                c[i] = scanner.nextLong();
                a[i] = scanner.nextLong();
            }

            for(int i = 0; i < m; i++) {
                d[i] = scanner.nextLong();
                b[i] = scanner.nextLong();
            }

            long result = 0;

            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    f[i][j] = Math.max(f[i - 1][j], Math.max(f[i][j - 1], f[i - 1][j - 1]));
                    long x = 0;
                    for(int p = j - 1; p >= 0; p--) {
                        if(b[p] == b[j - 1]) {
                            x += d[p];
                            long sum = 0;
                            long temp = x;
                            for(int k = i - 1; k >= 0; k--) {
                                if(a[k] == b[j - 1] && x > 0) {
                                    long min = Math.min(c[k], x);
                                    sum += min;
                                    if(f[i][j] < f[k][p] + sum) {
                                        f[i][j] = f[k][p] + sum;
                                    }
                                    x -= min;
                                }
                            }
                            x = temp;
                        }
                    }
                    if(result < f[i][j]) {
                        result = f[i][j];
                    }
                }
            }

            pw.println("Case #" + l + ": " + result);
        }
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
