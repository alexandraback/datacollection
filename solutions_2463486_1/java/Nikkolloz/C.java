
import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;


public class C {
    
    private static int sz = 0;
    private static Set<String> w = new TreeSet<>();
    private static BigInteger b;
    private static String s;
    private static String d;
    private static BigInteger[] asd;
    
    private static void f(int[] a) {
        char[] c = new char[sz+sz+1];
        int k = 0;
        for (int i = sz; i > 0; i--)
            c[k++] = (char) (a[i]+'0');
        for (int i = 0; i <= sz; i++)
            c[k++] = (char) (a[i]+'0');
        b = new BigInteger(new String(c));
        b = b.multiply(b);
        s = b.toString();
        d = new StringBuffer(s).reverse().toString();
        if (d.equals(s))
            w.add(s);
        c = new char[sz+sz+2];
        k = 0;
        for (int i = sz; i >= 0; i--)
            c[k++] = (char) (a[i]+'0');
        for (int i = 0; i <= sz; i++)
            c[k++] = (char) (a[i]+'0');
        b = new BigInteger(new String(c));
        b = b.multiply(b);
        s = b.toString();
        d = new StringBuffer(s).reverse().toString();
        if (d.equals(s))
            w.add(s);
    }

    public static void pre(int lim) throws Exception {
        int[] a = new int[27];
        w.add("9");
        while (true) {
            a[0] ++;
            int i = 0;
            while (a[i] > 1) {
                a[i] = 0;
                i++;
                sz = Math.max(sz, i);
                a[i] ++;
            }
            if (a[lim] > 0)
                break;
            int cnt = 0;
            for (int j = 0; j <= sz; j++)
                cnt += a[j];
            if (cnt > 8)
                continue;
            f(a);
            if (a[0] == 1) {
                a[0] = 2;
                f(a);
                a[0] = 1;
            }
            a[sz] = 2;
            f(a);
            a[sz] = 1;
        }
        System.out.println(w.size());
        Object[] q = w.toArray();
        asd = new BigInteger[q.length];
        for (int i = 0; i < q.length; i++)
            asd[i] = new BigInteger((String)q[i]);
    }
    
    public static void main(String args[]) throws Exception {
        pre(20);
        Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter(new File("output.txt"));
        int tc = in.nextInt();
        BigInteger L, R;
        for (int tn = 0; tn < tc; tn++) {
            L = new BigInteger(in.next());
            R = new BigInteger(in.next());
            int res = 0;
            for (int i = 0; i < asd.length; i++)
                if (L.compareTo(asd[i]) <= 0 && R.compareTo(asd[i]) >= 0)
                    res ++;
            out.print(String.format("Case #%d: %d\n", tn+1, res));
        }
        in.close();
        out.close();
    }
    
}
