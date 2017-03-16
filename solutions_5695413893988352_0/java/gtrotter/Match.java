package codejam;

import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by lubo on 09/04/2016.
 */
public class Match {
    BufferedReader in;
    PrintWriter out;

    int cmin, jmin;
    int minAbs;

    public static void main(String[] args) throws IOException {
        new Match().solveAll();
    }

    public Match() throws IOException {
        in = new BufferedReader(new FileReader("/Users/lubo/IdeaProjects/Algorithms/src/codejam/B-small-attempt0.in"));
        out = new PrintWriter(new BufferedWriter(new FileWriter("/Users/lubo/IdeaProjects/Algorithms/src/codejam/output")));
    }

    void solveAll() throws IOException {
        int t = getAnInt();
        for (int i = 1; i <= t; i++) {
            String[] data = getTwoStrings();
            cmin = jmin = -1;
            minAbs = -1;
            solve(data[0], data[1], new StringBuilder(), new StringBuilder(), 0, 0);
            out.println("Case #" + i + ": " + padWith0s(cmin, data[0].length()) + " " + padWith0s(jmin, data[0].length()));
        }

        out.close();
    }

    private String padWith0s(int num, int length) {
        String asString = Integer.toString(num);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < length - asString.length(); i++) {
            sb.append(0);
        }
        return sb.append(asString).toString();
    }

    private void solve(String c, String j, StringBuilder cb, StringBuilder jb, int cnext, int jnext) {
        for (int i = 0; i < 1000; i++) {
            String asString = padWith0s(i, c.length());
            if (fits(asString, c)) {
                for (int k = 0; k < 1000; k++) {
                    String asString1 = padWith0s(k, c.length());
                    if (fits(asString1, j)) {
                        int currMin = Math.abs(i - k);
                        if (minAbs == -1) {
                            minAbs = currMin;
                            cmin = i;
                            jmin = k;
                        } else {
                            if (currMin < minAbs) {
                                minAbs = currMin;
                                cmin = i;
                                jmin = k;
                            } else if (currMin == minAbs) {
                                if (i < cmin) {
                                    cmin = i;
                                    jmin = k;
                                } else if (i == cmin) {
                                    if (k < jmin)
                                        jmin = k;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    private boolean fits(String cand, String to) {
        if(cand.length() != to.length())
            return false;

        for (int i = 0; i < to.length(); i++) {
            if (to.charAt(i) != '?' && cand.charAt(i) != to.charAt(i))
                return false;
        }
        return true;
    }

    private String[] getTwoStrings() throws IOException {
        StringTokenizer st = new StringTokenizer(in.readLine());
        return new String[]{st.nextToken(), st.nextToken()};
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
