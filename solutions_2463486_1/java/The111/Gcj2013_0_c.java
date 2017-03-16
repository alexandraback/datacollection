package Gcj2013_0;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Gcj2013_0_c {
    static long maxB;
    static long maxRoot;
    
    static List<Long> fairAndSquare;
    
    final static String WORK_DIR = "C:\\eclipse\\workspace\\GoogleCodeJam\\IO\\2013_0\\";

    void solve(Scanner sc, PrintWriter pw) {
        long A = sc.nextLong();
        long B = sc.nextLong();
        int count = fairAndSquare.size();
        for (int i = 0; i < fairAndSquare.size(); i++) {
            if (A > fairAndSquare.get(i)) {
                count--;
            } else {
                break;
            }
        }
        if (count == 0) {
            pw.println("0");
            return;
        }
        for (int i = fairAndSquare.size() - 1; i >= 0; i--) {
            if (B < fairAndSquare.get(i)) {
                count--;
            } else {
                break;
            }
        }
        if (count > 0) {
            pw.println(count);
            return;
        } else {
            pw.println("0");
            return;
        }
        
        
    }

    public static void main(String[] args) throws Exception {
        //maxB = 1000; // SMALL INPUT
        maxB = (long) Math.pow(10, 14); // LARGE INPUT 1
        maxRoot = (long) Math.floor(Math.sqrt(maxB));
        
        fairAndSquare = new ArrayList<Long>();
        
        for (long i = 1; i <= maxRoot; i++) {
            if (isPalindrome(Long.toString(i))) {
                if (isPalindrome(Long.toString(i*i))) {
                    fairAndSquare.add(i*i);
                }
            }
        }
        
        System.out.println("fair and square in range: " + fairAndSquare);
        
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "C-large-1.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "C-large-1.out"));
        int T = sc.nextInt();
        for (int t=0; t<T; t++) {
            System.out.println("Processing test case " + (t + 1) + " of " + T);
            pw.print("Case #" + (t+1) + ": ");
            new Gcj2013_0_c().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
    
    public static boolean isPalindrome(String s) {
        if (s.length() <= 1) {
            return true;
        }
        if (s.charAt(0) == s.charAt(s.length() - 1)) {
            return isPalindrome(s.substring(1, s.length() - 1));
        } else {
            return false;
        }
    }
}













