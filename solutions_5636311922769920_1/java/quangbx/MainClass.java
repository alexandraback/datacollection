package com.smart.autoserver;

import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.Timer;
import java.util.TimerTask;

public class MainClass {
    static Scanner scan;
    static int[] A = new int[80000];
    static int dem = 2;
    static int i;

    static boolean snt(int x) {
        int t = (int)Math.sqrt(x);
        for(int j=0;j<dem;j++) {
            if(x%A[j]==0) return false;
            if(A[j] > t) {
                A[dem] = x;
                dem++;
                return true;
            }
        }
        A[dem] = x;
        x++;
        return true;
    }

    //static int KQ[][] = new int[50][11];
    static int ii = 0;
    static PrintWriter writer;

    public static void main(String[] args) {
//        int c = 4; //k
//        int d = 2; //cap so
//        int n = 1<<c;
//        String[] A = new String[n];
//        for(int i =n-1; i>=0; i--) {
//            String s = Integer.toBinaryString(i);
//            if(s.length() < n) {
//                String a = "";
//                for (int j = 0; j < c - s.length(); j++)
//                    a += "0";
//                s = a + s;
//            }
//            String tmp = "";
//            for(int j=0;j<s.length();j++)
//                tmp += "1";
//            String kq = s;
//            for(int k=0;k<d;k++) {
//                A[i] = kq;
//                kq = "";
//                for (int j = 0; j < A[i].length(); j++) {
//                    if (A[i].charAt(j) == '1')
//                        kq += tmp;
//                    else kq += s;
//                }
//            }
//        }
//        for(int i=n-1;i>=0;i--)
//            System.out.println(A[i]);

//        for(int i=2;i<10;i++) {
//            doiCoSo(5, i);
//            System.out.println();
//        }
//            PrintWriter writer = new PrintWriter("D-small-attempt0.out", "UTF-8");

        File file = new File("D-large.in");
        try {
            writer = new PrintWriter("D-large.out", "UTF-8");
            scan = new Scanner(file);
            int test = scan.nextInt();
            for(int i=0;i<test;i++) {
                int k = scan.nextInt();
                int c = scan.nextInt();
                int s = scan.nextInt();
                writer.print("Case #" + (i + 1) + ":");
                xuly(k, c, s);
                writer.println();
            }
            writer.close();
        } catch (Exception e1) {
            e1.printStackTrace();
        }
    }

    static void xuly(int k, int c, int s) {
        if(c==1) {
            if(s < k) {
                writer.print(" IMPOSSIBLE");
                return;
            }
            else if(s >= k) {
                for(int i=1; i<=k; i++ )
                    writer.print(" " + i);
                return;
            }
        } else {
            if (s >= (k + c - 1) / c) {
                long x = 1;
                int kk = k;
                int bit = 1;
                while (kk > 0) {
                    for (int i = 1; i <= c; i++) {
                        x = k * (x - 1) + bit;
                        bit++;
                        kk--;
                        if (kk == 0) {
                            break;
                        }
                    }
                    writer.print(" " + x);
                    x = bit = k + 1 - kk;
                    if (kk == 1) {
                        x = k * (x - 1) + bit;
                        writer.print(" " + x);
                    }
                    bit++;
                    kk--;
                }
            } else {
                writer.print(" IMPOSSIBLE");
            }
        }
    }
}
