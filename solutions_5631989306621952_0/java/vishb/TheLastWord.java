package gcj.v2016;

/**
 * Created by vbhavsar on 4/15/16.
 */

import java.util.Arrays;
import java.util.Scanner;

public class TheLastWord {

    private static boolean debug = false;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        sc.nextLine();

        for (int _t = 1; _t <= t; _t++) {

            String s = sc.nextLine();
            String result = doit(s);
            System.out.printf("Case #%d: %s%n", _t, result);
        }
    }

    private static String doit(String s) {

        char ichar = s.charAt(0);
        StringBuilder sb = new StringBuilder();
        sb.append(ichar);

        char left = ichar;

        for (int i=1; i<s.length(); i++) {
            if (s.charAt(i) >= left) {
                sb.insert(0, s.charAt(i));
                left = s.charAt(i);
            } else {
                sb.append(s.charAt(i));
            }
        }



        return sb.toString();
    }

    private static void debug(String str) {
        if (debug) {
            System.out.println(str);
        }
    }
}