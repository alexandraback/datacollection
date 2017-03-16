package com.fm;

import java.util.Scanner;

public class Round1CA {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long t = sc.nextLong();

        int i = 1;

        int r, c, w;
        int numChances = 0;
        while (i <= t) {
            numChances = 0;
            r = sc.nextInt();
            c = sc.nextInt();
            w = sc.nextInt();

            if (w == 1 || w == c) {
                numChances = c;
            } else {
                int res = c - (w + 1);
                numChances += (res / w);
                numChances += (w + 1);

            }

            System.out.println("Case #" + i + ": " + r * numChances);
            i++;
        }
    }
}
