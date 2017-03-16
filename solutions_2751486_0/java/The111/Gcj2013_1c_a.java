package Gcj2013_1c;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Gcj2013_1c_a {
    final static String WORK_DIR = "C:\\eclipse\\workspace\\GoogleCodeJam\\IO\\2013_1c\\";

    void solve(Scanner sc, PrintWriter pw) {
        String name = sc.next(); 
        int n = sc.nextInt();
        int L = name.length();
        
        int nValue = 0;
        for (int i = 0; i <= L - n; i++) {
            for (int j = i + n - 1; j < L; j++) {
                int count = 0;
                for (int k = i; k <= j; k++) {
                    if (count == n) {
                       break;
                    }
                    if (isConsanant(name.charAt(k))) {
                        count++;
                    } else {
                        count = 0;
                    }
                }
                if (count == n) {
                    nValue++;
                 }
            }
        }

        pw.println(nValue);
    }
    
    static boolean isConsanant(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return false;
        } else {
            return true;
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "A-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "A-small-attempt0.out"));
        int T = sc.nextInt();
        for (int t=0; t<T; t++) {
            System.out.println("Processing test case " + (t + 1) + " of " + T);
            pw.print("Case #" + (t+1) + ": ");
            new Gcj2013_1c_a().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
