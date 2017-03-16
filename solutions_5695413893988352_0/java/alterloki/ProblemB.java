package y2016.contest.r1b;

import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * @author ashevenkov 30.04.16 18:49.
 */
public class ProblemB {

    public static final String TITLE = "B-small-attempt0";
    private static BufferedReader in = prodIn();
    private static BufferedWriter out = prodOut();

    private static BufferedWriter prodOut() {
        try {
            return new BufferedWriter(new FileWriter("codejam/output/" + TITLE + ".out"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    private static BufferedReader prodIn() {
        try {
            return new BufferedReader(new FileReader("codejam/input/" + TITLE + ".in"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return null;
    }


    private static BufferedWriter testOut() {
        return new BufferedWriter(new OutputStreamWriter(System.out));
    }

    private static BufferedReader testIn() {
        return new BufferedReader(new InputStreamReader(System.in));
    }

    public static void main(String[] args) throws Exception {
        new ProblemB().solve(in, out);
        out.flush();
        out.close();
    }

    //implement
    private void solve(BufferedReader in, BufferedWriter out) throws Exception {
        Scanner scanner = new Scanner(in);
        int t = scanner.nextInt();
        for(int i = 0; i < t; i++) {
            String s1 = scanner.next();
            String s2 = scanner.next();
            out.write("Case #" + (i + 1) + ": " + solveCase(s1, s2));
            out.newLine();
        }
    }

    private String solveCase(String s1, String s2) {
        int min = Integer.MAX_VALUE;
        int max = fromLen(s1);
        int max1 = max;
        int max2 = max;
        for(int i = 0; i <= max; i++) {
            if(matches(Integer.toString(i), s1)) {
                for (int j = 0; j <= max; j++) {
                    if(matches(Integer.toString(j), s2)) {
                        int delta = Math.abs(i - j);
                        if(delta < min) {
                            min = delta;
                            max1 = i;
                            max2 = j;
                        }
                    }
                }
            }
        }
        return addZeroes(Integer.toString(max1), s1) + " " + addZeroes(Integer.toString(max2), s1);
    }

    private boolean matches(String s, String s1) {
        s = addZeroes(s, s1);
        for(int i = 0; i < s1.length(); i++) {
            if(s1.charAt(i) != '?' && s1.charAt(i) != s.charAt(i)) {
                return false;
            }
        }
        return true;
    }

    private String addZeroes(String s, String s1) {
        String add = "";
        for(int i = 0; i < s1.length() - s.length(); i++) {
            add += "0";
        }
        return add + s;
    }

    private int fromLen(String s1) {
        int res = 9;
        for(int i = 1; i < s1.length(); i++) {
            res *= 10;
            res += 9;
        }
        return res;
    }

    private String solveCase1(String s1, String s2) {
        char[] r1 = new char[s1.length()];
        char[] r2 = new char[s2.length()];
        for(int i = 0; i < s1.length(); i++) {
            char c1 = s1.charAt(i);
            char c2 = s2.charAt(i);
            if(c1 == '?' && c2 == '?') {
                r1[i] = '0';
                r2[i] = '0';
            } else if(c1 == '?') {

            } else if(c2 == '?') {

            } else {
                r1[i] = c1;
                r2[i] = c2;
            }
        }
        return null;
    }

}
