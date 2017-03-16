import java.io.*;
import java.util.*;


public class A {
    public static void main(String[] arg) throws FileNotFoundException {
        Scanner in = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter("A-large.out");
        int T = in.nextInt();
        for (int tn = 1; tn <= T; ++tn) {
            long A = in.nextInt();
            int n = in.nextInt();
            long[] a = new long[n];
            for (int i = 0; i < a.length; ++i) {
                a[i] = in.nextInt();
            }
            Arrays.sort(a);
            int ans = n;

            if (A > 1) {
                int added = 0;
                int removed = n;
                for (long s : a) {
                    while (A <= s) {
                        A += A - 1;
                        ++added;
                    }
                    A += s;
                    --removed;
                    ans = Math.min(ans, added + removed);
                }
            }

            out.print("Case #" + tn + ": ");
            out.println(ans);
        }
        out.close();
    }
}
