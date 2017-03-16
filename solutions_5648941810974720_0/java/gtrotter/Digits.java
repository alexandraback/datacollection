package codejam;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created by lubo on 09/04/2016.
 */
public class Digits {
    BufferedReader in;
    PrintWriter out;
    String s;
    char[] cnts;
    char[] uniqLets;
    String[] words = new String[]{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};


    public static void main(String[] args) throws IOException {
        new Digits().solveAll();
    }

    public Digits() throws IOException {
        in = new BufferedReader(new FileReader("/Users/lubo/IdeaProjects/Algorithms/src/codejam/A-small-attempt0.in"));
        out = new PrintWriter(new BufferedWriter(new FileWriter("/Users/lubo/IdeaProjects/Algorithms/src/codejam/output")));
    }

    void solveAll() throws IOException {
        uniqLets = new char[]{'Z', 'O', 'W', 'H', 'U', 'F', 'X', 'V', 'G', 'I'};

        int t = getAnInt();
        for (int i = 1; i <= t; i++) {
            cnts = new char[27];
            s = in.readLine();
            for (int j = 0; j < s.length(); j++) {
                cnts[s.charAt(j) - 'A']++;
            }
            out.println("Case #" + i + ": " + solve());
        }

        out.close();
    }

    private String solve() {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < 10; i += 2) {
            int numDigit = cnts[uniqLets[i] - 'A'];
            for (int j = 0; j < numDigit; j++)
                res.append(i);
            remove(i, numDigit);
        }

        for (int i = 1; i < 10; i += 2) {
            int numDigit = cnts[uniqLets[i] - 'A'];
            for (int j = 0; j < numDigit; j++)
                res.append(i);
            remove(i, numDigit);
        }

        char[] asarr = res.toString().toCharArray();
        Arrays.sort(asarr);
        return new String(asarr);
    }

    private void remove(int digit, int numDigit) {
        for (int i = 0; i < words[digit].length(); i++) {
            cnts[words[digit].charAt(i) - 'A'] -= numDigit;
        }
    }

    private int getAnInt() throws IOException {
        return Integer.parseInt(new StringTokenizer(in.readLine()).nextToken());
    }

    private long getALong() throws IOException {
        return Long.parseLong(new StringTokenizer(in.readLine()).nextToken());
    }

    private int[] getALineOfInts(int numExpected) throws IOException {
        int[] res = new int[numExpected];
        StringTokenizer st = new StringTokenizer(in.readLine());
        for (int i = 0; i < numExpected; i++)
            res[i] = Integer.parseInt(st.nextToken());
        return res;
    }

}
