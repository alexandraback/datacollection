package com.smart.autoserver;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class MainClass {
    static Scanner scan;
    public static void main(String[] args) {
//        int c = 3;
//        int d = 3;
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
        File file = new File("D-small-attempt0.in");
        try {
            PrintWriter writer = new PrintWriter("D-small-attempt0.out", "UTF-8");
            scan = new Scanner(file);
            int test = scan.nextInt();
            for(int k=0;k<test;k++) {
                int a = scan.nextInt();
                int b = scan.nextInt();
                int c = scan.nextInt();
                writer.print("Case #" + (k + 1) + ":");
                for(int i=1;i <= a;i++)
                    writer.print(" " + i);
                writer.println();
            }
            writer.close();
        } catch (Exception e1) {
            e1.printStackTrace();
        }
    }

    static String xuly() {
        int dem =0;
        boolean b = false;
        String s = scan.nextLine();
        //String s = "-+--+--+";
        int j = s.lastIndexOf("-");
        while(j > -1) {
            int i;
            if(b)
                i = s.indexOf("+");
            else
                i = s.indexOf("-");
            if(i > 0) {
                dem++;
                s = new StringBuilder(s.substring(i, j+1)).reverse().toString();
                b = !b;
            } else {
                s = new StringBuilder(s.substring(i, j+1)).reverse().toString();
                b = !b;
            }
            dem++;
            if(b) {
                j = s.lastIndexOf("+");
            } else
                j = s.lastIndexOf("-");
        }
        return String.valueOf(dem);
    }
}
