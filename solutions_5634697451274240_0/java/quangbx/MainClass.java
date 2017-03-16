package com.smart.autoserver;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class MainClass {
    static Scanner scan;
    public static void main(String[] args) {
        File file = new File("B-small-attempt0.in");
        try {
            PrintWriter writer = new PrintWriter("B-small-attempt0.out", "UTF-8");
            scan = new Scanner(file);
            int test = scan.nextInt();
            scan.nextLine();
            for(int k=0;k<test;k++) {
                writer.println("Case #" + (k + 1) + ": " + xuly());
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
