package com.company;


import jdk.internal.util.xml.impl.Pair;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String... args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.println("Case #" + i + ": " + go(s));
        }
    }

    static String go(Scanner s) {
        String c = s.next();
        String j = s.next();

//        int cMin = Integer.valueOf(c.replaceAll("?", "0"));
//        int cMax = Integer.valueOf(c.replaceAll("?", "9"));
//        int jMin = Integer.valueOf(j.replaceAll("?", "0"));
//        int jMax = Integer.valueOf(j.replaceAll("?", "9"));
//
//        if (cMax < jMin) {
//            return "" + cMax + " " + jMin;
//        }
//
//        if (jMax < cMin) {
//            return "" + cMin + " " + jMax;
//        }

        long[] cs = populate(c);
        long[] js = populate(j);

//        for (long i : cs) {
//            System.out.println(i);
//        }

        long length = c.length();

        List<Long> p = solve(cs, js);


        long a = p.get(0);
        long b = p.get(1);

        String x = String.format("%0" + length + "d", a);
        String y = String.format("%0" + length + "d", b);

        return x + " " + y;
    }

    private static List<Long> solve(long[] cs, long[] js) {
        long c;
        long j;

        int a = 0;
        int b = 0;

        long bc = 0;
        long bj = 0;

        long best = Long.MAX_VALUE;

        while (a < cs.length && b < js.length) {
            c = cs[a];
            j = js[b];
            long s = Math.abs(c - j);
            if (s < best) {
                best = s;
                bc = c;
                bj = j;
            }

            if (j < c) {
                b++;
            } else {
                a++;
            }
        }

        ArrayList<Long> x = new ArrayList<>();
        x.add(bc);
        x.add(bj);
        return x;
    }

    private static long[] populate(String c) {
        char[] arr = c.toCharArray();


        ArrayList<Integer> locations = new ArrayList<>();
        for (int i = c.length() - 1; i >= 0; i--) {
            if (arr[i] == '?') {
                locations.add(i);
                arr[i] = 0;
            } else {
                arr[i] -= '0';
            }
        }

        int z = (int) Math.pow(10, locations.size());

        long[] ret = new long[z];

        for (int w = 0; w < z; w++) {
//            System.err.println("w = " + w);
            for (int i = 0; i < locations.size(); i++) {
                arr[locations.get(i)] = (char) ((w / (Math.pow(10, i))) % 10);
            }
            long n = 0L;
            for (int i = 0; i < arr.length; i++) {
                n = 10 * n + arr[i];
            }
            ret[w] = n;
        }

        return ret;
    }
}
