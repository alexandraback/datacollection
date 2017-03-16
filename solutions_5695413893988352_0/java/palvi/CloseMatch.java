/**
 * Created by pallavi on 30/4/16.
 */

import java.io.*;
import java.util.*;

public class CloseMatch {
    static char[] a;
    static char[] b;
    static long diff;
    static long ra;
    static long rb;
    public static void f(int i, long as, long bs) {
        if (i == -1) {
            if (Math.abs(as-bs)<diff) {
                diff = Math.abs(as-bs);
                ra=as;
                rb=bs;
            } else if (Math.abs(as-bs) == diff && as < ra) {
                diff = Math.abs(as-bs);
                ra=as;
                rb=bs;
            } else if (Math.abs(as-bs) == diff && as == ra && bs < rb) {
                diff = Math.abs(as-bs);
                ra=as;
                rb=bs;
            }
            return;
        }
        long p = (long) Math.pow(10, a.length-i-1);
        if (a[i] != '?' && b[i] != '?') {
            int ai = a[i] - '0';
            int bi = b[i] - '0';
            as += p*ai;
            bs += p*bi;
            f(i-1, as, bs);
            return;
        }
        if (a[i] == '?' && b[i] == '?') {
            f(i-1, as, bs+p);
            f(i-1, as, bs);
            f(i-1, as+p, bs);
            f(i-1, as+9*p, bs);
            f(i-1, as, bs+9*p);
            return;
        }
        if (a[i] == '?') {
            int d = b[i]-'0';
            f(i-1, as+((d-1+10)%10)*p, bs+d*p);
            f(i-1, as+d*p, bs+d*p);
            f(i-1, as+((d+1+10)%10)*p, bs+d*p);
            f(i-1, as, bs+d*p);
            f(i-1, as+9*p, bs+d*p);
            return;
        }
        int d = a[i]-'0';
        f(i-1, as+d*p, bs+((d-1+10)%10)*p);
        f(i-1, as+d*p, bs+d*p);
        f(i-1, as+d*p, bs+((d+1+10)%10)*p);
        f(i-1, as+d*p, bs);
        f(i-1, as+d*p, bs+9*p);
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new BufferedReader(new FileReader("in.txt")));
        PrintWriter writer = new PrintWriter("out.txt");
        int t = scanner.nextInt();
        for (int i = 1; i <= t; i++) {
            a = scanner.next().toCharArray();
            b = scanner.next().toCharArray();
            diff = Long.MAX_VALUE;
            f(a.length-1, 0, 0);
            writer.println("Case #" + i + ": "
                    + String.format("%0"+a.length+"d",ra) + " " + String.format("%0"+a.length+"d",rb));
        }
        writer.close();
        scanner.close();
    }
}
