package de.jaki.codejam.two015.round0;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {


    private static final String PATTERN = "CASE #%d: %s";
    //private static final String NAME = "a.in";
    //private static final String NAME = "A-small-attempt1.in";
    private static final String NAME = "A-large.in";
    //private static final String OUT = "a.out";
    //private static final String OUT = "A-small-attempt1.out";
    private static final String OUT = "A-large.out";

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(NAME));
        PrintWriter pw = new PrintWriter(OUT);
        int testCount = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < testCount; i++) {
            String sol = solve(sc);
            System.out.println(String.format(PATTERN, i + 1, sol));
            pw.println(String.format(PATTERN, i + 1, sol));
        }
        pw.flush();
        pw.close();
    }

    private static String solve(Scanner sc) {
        String s = sc.nextLine();
        int x = Integer.valueOf(s.split(" ")[0]);
        String s2 = s.split(" ")[1];
        int backup = 0;
        int needed = 0;
        for (int i = 0; i <= x; i++) {
            int r = s2.charAt(i) - '0';
            if (r == 0 && backup == 0) needed++;
            if (r == 0 && backup > 0) backup--;
            if (r > 1) backup += (r - 1);
        }
        return "" + needed;
    }
}
