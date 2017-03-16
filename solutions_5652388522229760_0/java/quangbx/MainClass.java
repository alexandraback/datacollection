package com.smart.autoserver;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class MainClass {
    static Scanner scan;
    public static void main(String[] args) {
        File file = new File("A-small-attempt0.in");
        try {
            PrintWriter writer = new PrintWriter("A-small-attempt0.txt", "UTF-8");
            scan = new Scanner(file);
            int test = scan.nextInt();
            for(int k=0;k<test;k++) {
                reset();
                writer.println("Case #" + (k + 1) + ": " + xuly());
            }
            writer.close();
        } catch (Exception e1) {
            e1.printStackTrace();
        }
    }

    static String xuly() {
        int n = scan.nextInt();
        if(n==0)
            return "INSOMNIA";
        int i = 0;
        while(true) {
            i = i + 1;
            long t = n*i;
            if(check(String.valueOf(t))) {
                return String.valueOf(t);
            }
        }
    }

    static void reset() {
        for(int i=0;i<10;i++) {
            A[i] = false;
        }
        dem = 0;
    }

    static boolean[] A = new boolean[10];
    static int dem = 0;
    static boolean check(String s) {
        for(int i=0;i<s.length();i++) {
            if(!A[s.charAt(i)-'0']) {
                A[s.charAt(i)-'0'] = true;
                dem++;
                if(dem == 10) {
                    return true;
                }
            }
        }
        return false;
    }
}
