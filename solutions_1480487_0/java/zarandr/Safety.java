import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Andrey Zarubin
 */
public class Safety {
    public static void main(String... args) throws IOException {
        String fileName = "A-small-attempt1.in";
//        String fileName = "safety-test.in.txt";
        BufferedReader r = new BufferedReader(new FileReader(fileName));
        PrintWriter w = new PrintWriter(fileName.split("\\.")[0] + ".out.txt");
        int T = Integer.parseInt(r.readLine());
        for (int X = 0; X < T; X++) {
            Scanner sc = new Scanner(r.readLine());
            int n = sc.nextInt();
            int[] s = new int[n];
            int x = 0;
            for (int i = 0; i < n; i++) {
                s[i] = sc.nextInt();
                x += s[i];
            }
            boolean[] skip = new boolean[n];
            int k = n;
            for (int i = 0; i < n; i++) {
                if (2 * x < s[i] * n) {
                    skip[i] = true;
                    k--;
                }
            }
            int x2 = 0;
            for (int i = 0; i < n; i++) {
                if (!skip[i])
                    x2 += s[i];
            }
            double[] m = new double[n];
            for (int i = 0; i < n; i++) {
                if (!skip[i])
                    m[i] = 100d * (x2 + x - s[i] * k) / (k * x);
            }
            w.print("Case #" + (X + 1) + ": ");
            for (int i = 0; i < n; i++) {
                w.printf("%.6f", m[i]);
                if (i < n - 1)
                    w.print(' ');
            }
            w.println();
        }
        r.close();
        w.close();
    }
}
