import java.io.File;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: vors
 * Date: 4/14/12
 * Time: 6:03 PM
 * To change this template use File | Settings | File Templates.
 */
public class C {

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("c.in"));
        PrintWriter out = new PrintWriter(new File("c.out"));


        int TT = in.nextInt();
        metka:
        for (int cas=1; cas<=TT; cas++) {
            int n = in.nextInt();
            long[] a = new long[n];
            HashMap<Long, Long> map = new HashMap<Long, Long>();
            for (int i=0; i<n; i++) {
                a[i] = in.nextLong();
            }
            out.printf("Case #%d:\n", cas);
            for (long mask=1; mask < (1L << n); mask++) {
                long sum = 0;
                for (int i=0; i<n; i++) {
                    if ((mask & (1 << i)) != 0) {
                        sum += a[i];
                    }
                }
                Long oldmask = map.get(sum);
                if (oldmask != null) {
                    printmask(mask, a, out);
                    printmask(oldmask, a, out);
                    continue metka;
                } else {
                    map.put(sum, mask);
                }
            }
            out.println("Impossible");
        }
        out.close();
    }

    private static void printmask(Long mask, long[] a, PrintWriter out) {
        for (int i=0; i<a.length; i++) {
            if ((mask & (1 << i)) != 0) {
                out.print(a[i] + " ");
            }
        }
        out.println();
    }

}
