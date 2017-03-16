package com.vahid.google.codejam.round1c2014;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: 8
 * Date: 5/11/14
 * Time: 11:22 AM
 * To change this template use File | Settings | File Templates.
 */
public class C {
    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner((C.class.getClassLoader().getResourceAsStream("data.txt")));

        PrintWriter out = new PrintWriter("C.out");

        int lines = scanner.nextInt();
        scanner.nextLine();

        for (int i = 1; i<= lines; i++){
            int m = scanner.nextInt();
            int n = scanner.nextInt();
            int k = scanner.nextInt();

            if (m<n){
                int tmp = m;
                m = n;
                n = tmp;
            }

            out.println("Case #" + i + ": " + minStone(m, n, k));
        }

        scanner.close();
        out.close();
    }

    private static int minStone(int m, int n, int k) {
        if (n<3) return k;
        if (n==3){
            if (k<5) return k;
            if (m==4){
                if (k<8) return k-1;
                return k-2;
            }
            if (m==5){
                if (k<8) return k-1;
                if (k<11) return k-2;
                return k-3;
            }
            if (m==6){
                if (k<8) return k-1;
                if (k<11) return k-2;
                if (k<14) return k-3;
                return k-4;
            }
        }

        if (n==4){
            if (k<5) return k;
            if (m==4){
                if (k<8) return k-1;
                if (k<10) return k-2;
                if (k<12) return k-3;
                return k-4;
            }
            if (m==5){
                if (k<8) return k-1;
                if (k<10) return k-2;
                if (k<12) return k-3;
                if (k<14) return k-4;
                if (k<16) return k-5;
                return k-6;
            }
        }

        return 0;

    }
}
