/**
 * Created by pallavi on 30/4/16.
 */

import java.io.*;
import java.util.*;

public class TechnoBabble {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new BufferedReader(new FileReader("in.txt")));
        PrintWriter writer = new PrintWriter("out.txt");
        int t = scanner.nextInt();
        for (int i = 1; i <= t; i++) {
            int n = scanner.nextInt();
            String[] a = new String[n];
            String[] b = new String[n];
            for (int j = 0; j < n; j++) {
                a[j] = scanner.next();
                b[j] = scanner.next();
            }
            int l = 1<<n;
            int mc = 0;
            for (long j = 0; j < l; j++) {
                Set<String> al = new HashSet<>();
                Set<String> bl = new HashSet<>();
                for (long k = 0; k < n; k++) {
                    if (((1<<k)&j) != 0) {
                        al.add(a[((int) k)]);
                        bl.add(b[((int) k)]);
                    }
                }
                boolean fl = true;
                int c = 0;
                for (long k = 0; k < n; k++) {
                    if (((1<<k)&j) == 0) {
                        c++;
                        if (!al.contains(a[((int) k)]) || !bl.contains(b[((int) k)])) {
                            fl = false;
                            break;
                        }
                    }
                }
                if (fl) mc = Math.max(mc, c);
            }
            writer.println("Case #" + i + ": " + mc);
        }
        writer.close();
        scanner.close();
    }
}
