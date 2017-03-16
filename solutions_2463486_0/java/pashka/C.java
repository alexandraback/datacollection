
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class C {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(C.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(C.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new C().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        BigInteger a = new BigInteger(in.next());
        BigInteger b = new BigInteger(in.next());
        return "" + (calc(b) - calc(a.subtract(BigInteger.ONE)));
    }


    int[] a = new int[100];
    BigInteger max;

    private long calc(BigInteger max) {
        this.max = max;
        res = 0;
        bt(0, 0);
        System.out.println(max + " " + res);
        return res;
    }

    long res;

    private void bt(int n, int s) {
        if (s > 9) return;
        if (n > 25) return;
        if (n > 0) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                sb.append(a[i]);
            }
            for (int i = n - 1; i >= 0; i--) {
                sb.append(a[i]);
            }
            BigInteger q = new BigInteger(sb.toString());
            q = q.multiply(q);
            if (q.compareTo(max) <= 0) {
//                System.out.println(q);
                res++;
            }
        }
        for (int x = 0; x < 10; x++) {
            if (s + x * x < 10) {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < n; i++) {
                    sb.append(a[i]);
                }
                sb.append(x);
                for (int i = n - 1; i >= 0; i--) {
                    sb.append(a[i]);
                }
                BigInteger q = new BigInteger(sb.toString());
                q = q.multiply(q);
                if (q.compareTo(max) <= 0) {
//                    System.out.println(q);
                    res++;
                }
            }
        }
        for (int x = 0; x < 10; x++) {
            if (n == 0 && x == 0) continue;
            a[n] = x;
            if (s + 2 * x * x < 10) {
                bt(n + 1, s + 2 * x * x);
            }
        }
    }
}