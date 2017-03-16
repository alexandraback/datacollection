package com.smart.autoserver;

import java.io.File;
import java.io.PrintWriter;
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

    static int KQ[][] = new int[50][11];
    static int ii = 0;

    public static void main(String[] args) {
//        int c = 4; //k
//        int d = 3; //c
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

        File file = new File("E:\\C-small-attempt0.in");
        try {
            PrintWriter writer = new PrintWriter("E:\\C-small-attempt0.out", "UTF-8");
            scan = new Scanner(file);
            int test = scan.nextInt();
            scan.nextInt();
            test = scan.nextInt();
            xuly(test);
            writer.println("Case #1:");
            for(int i=0; i<test; i++) {
                String ss = "1";
                String sss = Integer.toBinaryString(KQ[i][0]);
                for(int j=0;j<14-sss.length();j++)
                    ss += "0";
                ss = ss+sss+"1";
                writer.print(ss);
                for(int j=2;j<11;j++)
                    writer.print(" " + KQ[i][j]);
                writer.println();
            }
            writer.close();
        } catch (Exception e1) {
            e1.printStackTrace();
        }
    }
    static int lasnt(long x) {
        for(int j=0;j<dem;j++) {
            if(x%A[j] == 0)
                return A[j];
            if(A[j] > Math.sqrt(x))
                return 0;
        }
        return 0;
    }

    static long mu(long x, int n) {
        for(int j = 1;j < n;j++)
            x = x*x;
        return x;
    }

    static void xuly(int test) {
        A[0] = 2;A[1] = 3;
        for(i=4;i<100000;i++) {
            snt(i);
        }
        long[] B = new long[11];
        for(int i=2;i<11;i++) {
            B[i] = 1;//16384
            for(int j=0;j<15;j++)
                B[i] = B[i]*i;
            B[i]++;
        }
        for(i = 0; i < 16384; i++) {
            int num=0;
            char[] C = Integer.toBinaryString(i).toCharArray();
            for(int j = 0; j < C.length; j++) {
                C[j] = (char) (C[j] - '0');
                System.out.print((int)C[j]);
            }
            System.out.println();
            for(int j = 2; j < 11;j++) {
                long x = 0;
                for(int k=0;k < C.length; k++) {
                    x = x*j + C[k];
                }
                x=x*j;
                x = x+B[j];
                int q = lasnt(x);
                if(q != 0) {
                    num++;
                    KQ[ii][j] = q;
                    if(num > 8) {
                        KQ[ii][0] = i;
                        ii++;
                        if(ii >= test)
                            return;
                    }
                } else break;
            }
        }
    }
}
