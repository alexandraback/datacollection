/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javatest;

/**
 *
 * @author cainiao2hao
 */
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class JavaTest {

    /**
     * @param args the command line arguments
     */
    public static boolean ok(long x, long R, long T) {
        BigInteger a, b, c;
        a = BigInteger.valueOf(x);
//        System.out.println(a.toString());
        a = a.multiply(a);
//        System.out.println(a.toString());
        a = a.multiply(BigInteger.valueOf(2));
//        System.out.println(a.toString());
        b = BigInteger.valueOf(x);
//        System.out.println(b.toString());
        c = b;
//        System.out.println(c.toString());
        c = c.multiply(BigInteger.valueOf(R));
//        System.out.println(c.toString());
        c = c.multiply(BigInteger.valueOf(2));
//        System.out.println(c.toString());
        a = a.subtract(b);
        a = a.add(c);
//        System.out.println(a.toString());
        int flag = a.compareTo(BigInteger.valueOf(T));
        if (flag <= 0) {
            return true;
        }
        return false;
    }

    public static long fen(long l, long R, long r) {
        long mid, T = r;
        while (r - l > 1) {
            mid = (r + l) / 2;
            if (ok(mid, R, T)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (ok(r, R, T)) {
            return r;
        }
        return l;
    }

    public static void main(String[] args) {
        // TODO code application logic here

//        File outf = new File("D:\\data.out");
        try {
            File inf = new File("D:\\data.in");
            FileWriter fw = new FileWriter("D:\\data.out");
            Scanner cin = new Scanner(inf);
//            Scanner cin = new Scanner(System.in);
            int cas;
            cas = cin.nextInt();
            for (int t = 1; t <= cas; t++) {
                long R, T, ans;
                R = cin.nextLong();
                T = cin.nextLong();
//                System.out.println(R);
//                System.out.println(T);
                ans = fen(1, R, T);
                String tt;
                tt = "Case #";
                tt = tt + String.valueOf(t);
                tt += ": ";
                tt += String.valueOf(ans);
                tt += "\n";
                fw.write(tt);
            }
            fw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
