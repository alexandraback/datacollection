/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package gcjb;

import java.util.Scanner;

/**
 *
 * @author Me
 */
public class Main {

    public static Scanner s = new Scanner(System.in);

    public static void main(String[] args) {
        long t = s.nextLong();
        for (long i = 1; i <= t; i++) {
            System.out.print("Case #" + i + ": ");
            start();
        }
    }

    public static long[] ta;
    public static long[] na;
    public static long[] tb;
    public static long[] nb;

    private static void start() {
        int n = s.nextInt();
        int m = s.nextInt();
        ta = new long[n];
        na = new long[n];
        tb = new long[m];
        nb = new long[m];
        for (int i = 0; i < n; i++) {
            na[i] = s.nextLong();
            ta[i] = s.nextLong();
        }
        for (int i = 0; i < m; i++) {
            nb[i] = s.nextLong();
            tb[i] = s.nextLong();
        }
        System.out.println(go(0, 0, 0, na[0], nb[0]));
    }

    private static long go(long score, int a, int b, long ca, long cb) {
        if (ta[a] == tb[b]) {
            //System.out.println("Matching on "+a+"!");
            if (ca < cb) {
                a++;
                cb -= ca;
                score += ca;
                if (a < na.length) {
                    ca = na[a];
                } else {
                    return score;
                }
            } else if (cb < ca) {
                b++;
                ca -= cb;
                score += cb;
                if (b < nb.length) {
                    cb = nb[b];
                } else {
                    return score;
                }

            } else {
                a++;
                b++;
                score += ca;
                if (a < na.length) {
                    ca = na[a];
                } else {
                    return score;
                }
                if (b < nb.length) {
                    cb = nb[b];
                } else {
                    return score;
                }
            }
            return go(score,a,b,ca,cb);
        }else{
            long s1 = score;
            long s2 = score;
            if(a < na.length-1){
                s1 = go(score,a+1,b,na[a+1],cb);
            }
            if(b < nb.length-1){
                s2 = go(score,a,b+1,ca,nb[b+1]);
            }
            return Math.max(s1, s2);
        }
    }
}
