package com.cuteants.problems.codejam.y2013.round1A;

import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class A {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("/home/aurel/projects/cuteants/problems/src/com/cuteants/problems/codejam/y2013/round1A/A-small-attempt0.in"));
//        Scanner in = new Scanner(
//            "5\n" +
//            "1 9\n" +
//            "1 10\n" +
//            "3 40\n" +
//            "1 1000000000000000000\n" +
//            "10000000000000000 1000000000000000000"
//        );
        BufferedWriter out = new BufferedWriter(new FileWriter("/home/aurel/projects/cuteants/problems/src/com/cuteants/problems/codejam/y2013/round1A/A-small-out.txt"));
        //BufferedWriter out = new BufferedWriter(new FileWriter("C:\\Users\\aurel\\Downloads\\A-large.txt"));

        int tc = in.nextInt();
        for (int ti = 1; ti <= tc; ti++) {
            long r = in.nextLong();
            long t = in.nextLong();

            long le = 0;
            long ri = 4000000000L;
            long mid;
            long j = -1;
            while (le <= ri) {
                mid = (ri - le) / 2 + le;
                BigInteger val = BigInteger.valueOf(mid).add(BigInteger.ONE).multiply(
                    BigInteger.valueOf(mid).multiply(BigInteger.valueOf(2)).add(
                        BigInteger.valueOf(r).multiply(BigInteger.valueOf(2))
                    ).add(BigInteger.ONE)
                );

                if (val.compareTo(BigInteger.valueOf(t)) < 0) {
                    le = mid + 1;
                } else if (val.compareTo(BigInteger.valueOf(t)) > 0) {
                    ri = mid - 1;
                } else {
                    j = mid + 1;
                    break;
                }
            }
            if (j == -1) {
                j = le;
            }

            out.write("Case #" + ti + ": " + j + "\n");
        }

        in.close();
        out.close();
    }
}
