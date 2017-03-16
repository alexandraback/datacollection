package gcj2015_Qualification;

import java.util.Scanner;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class A {

    static Scanner in;
//    static String taskname = "A-small";
//    static String taskname = "A-small-attempt0";
//    static String taskname = "A-small-attempt1";
    static String taskname = "A-large";
//    static String taskname = "A-small-practice";

    public static String solve() {
        int Smax = in.nextInt();
        String audience = in.next();
        int friends_needed = 0;
        int clapping = 0;

        for (int k=0; k < Smax + 1; k++) {
            // people with shyness level k
            int shy_people = audience.charAt(k) - '0';
            if ( clapping < k ) {
                friends_needed += k - clapping;
                clapping = k + shy_people;
            }
            else {
                clapping += shy_people;
            }
        }

        return "" + friends_needed;
    }

    public static void main(String[] args) {

        try {
            PrintWriter pW = new PrintWriter(new FileOutputStream("output/"
                    + taskname + ".out"));
            try {
                in = new Scanner(new FileInputStream("input/"
                        + taskname + ".in"));
                int T = in.nextInt();
                for (int caseNumber = 1; caseNumber <= T; caseNumber++) {
                    pW.println("Case #" + caseNumber + ": " + solve());
                }
                in.close();
                pW.close();
            } catch (IOException e) {
                System.out.println("Can not find file " + taskname + ".in");
            }
        } catch (IOException e) {
            System.out.println("Open or create exception with "
                    + taskname + ".out");
        }
    }
}

