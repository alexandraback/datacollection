import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
    public static void main(String[] args) throws FileNotFoundException {
        FileInputStream fin = new FileInputStream("B-small-attempt0.in.txt");
        Scanner scanner = new Scanner(fin);
        FileOutputStream fout = new FileOutputStream("B-small-attempt0.out.txt");
        PrintWriter writer = new PrintWriter(fout);
        int testCount = scanner.nextInt();
        for (int testCase = 1; testCase <= testCount; ++testCase) {
            String a = scanner.next();
            String b = scanner.next();
            writer.printf("Case #%d: %s\n", testCase, solve(a, b));
        }
        writer.close();
    }

    private static int diff = Integer.MAX_VALUE;
    private static int ai;
    private static int bi;
    private static String asc = "";
    private static String bsc = "";
    private static char[] c;
    private static int n;

    private static String solve(String as, String bs) {
        n = as.length();
        c = new char[2*n];
        for (int i = 0; i < n; ++i) {
            c[i] = as.charAt(i);
            c[i + n] = bs.charAt(i);
        }
        diff = Integer.MAX_VALUE;
        go(0);
        return asc + " " + bsc;
    }

    private static void go(int i) {
        if (i >= c.length) {
            String a = "";
            String b = "";
            int an = 0;
            int bn = 0;
            for (int j = 0; j < n; ++j) {
                a += c[j];
                an = 10 * an + c[j] - '0';
                b += c[j + n];
                bn = 10 * bn + c[j + n] - '0';
            }
            int d = Math.abs(an - bn);
            if ((d < diff) ||
                (d == diff && an < ai) ||
                (d == diff && an == ai && bn < bi)) {
                ai = an;
                bi = bn;
                asc = a;
                bsc = b;
                diff = d;
            }
            return;
        }
        if (c[i] != '?') {
            go(i + 1);
            return;
        }
        for (char x = '0'; x <= '9'; ++x) {
            c[i] = x;
            go(i + 1);
            c[i] = '?';
        }
    }
}
