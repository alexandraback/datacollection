package y2015.contest.r1c;

import java.io.*;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * @author ashevenkov on 10.05.15.
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
            int k = scanner.nextInt();
            int l = scanner.nextInt();
            int s = scanner.nextInt();
            String keyboard = scanner.next();
            String target = scanner.next();
            out.write("Case #" + (i + 1) + ": " + solveCase(k, l, s, keyboard, target));
            out.newLine();
        }
    }

    private String solveCase(int k, int l, int s, String keyboard, String target) {
        double result = 0.0;
        boolean possible = isPossible(keyboard, target);
        if(possible) {
            double max = findMax(target, s);
            int sum = findSum(keyboard, target, s);
            result = max - (double)sum / Math.pow(keyboard.length(), s);
            return Double.toString(result);
        }
        return Double.toString(result);
    }

    private int findSum(String keyboard, String target, int s) {
        int result = 0;
        char[] str = new char[s];
        int count = (int)Math.pow(keyboard.length(), s);
        for(int i = 0; i < count; i++) {
            int dec = 1;
            int l = keyboard.length();
            for(int j = 0; j < s; j++) {
                int curIndex = (i / dec) % l;
                str[j] = keyboard.charAt(curIndex);
                dec *= l;
            }
            String curS = new String(str);
            result += findSubs(curS, target);
        }
        return result;
    }

    private int findSubs(String curS, String target) {
        int result = 0;
        int pointer = 0;
        while(pointer < curS.length()) {
            int findIndex = curS.indexOf(target, pointer);
            if(findIndex >= 0) {
                result++;
                pointer = findIndex + 1;
            } else {
                break;
            }
        }
        return result;
    }

    private int findMax(String target, int s) {
        StringBuilder sb = new StringBuilder();
        while(sb.length() + target.length() <= s) {
            sb.append(target);
        }
        if(sb.length() < s) {
            sb.append(target.substring(0, s - sb.length()));
        }
        String maxString = sb.toString();
        return findSubs(maxString, target);
    }

    private boolean isPossible(String keyboard, String target) {
        Set<Character> alph = new HashSet<>();
        for (char c : keyboard.toCharArray()) {
            alph.add(c);
        }
        for (char c : target.toCharArray()) {
            if(!alph.contains(c)) {
                return false;
            }
        }
        return true;
    }
}
