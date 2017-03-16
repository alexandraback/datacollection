package com.polarnick.codejam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Polyarnyi Nikolay
 */
public class ProblemB {

    private static final long MOD = 1_000_000_007L;
    private static final char MIN = 'a';
    private static final int COUNT = 'z' - 'a' + 1;

    private void solve() throws IOException {
        int t = nextInt();
        for (int testNum = 1; testNum <= t; testNum++) {
            out.print("Case #" + testNum + ": ");
            int n = nextInt();

            String[] ss = new String[n];
            long res = 1;
            boolean fail = false;
            int[] color = new int[COUNT];
            for (int i = 0; i < COUNT; i++) {
                color[i] = i + 1;
            }
            int next = 1;
            int[] usedNotWhole = new int[n];
            long wholeCountUsed = 0;
            long chunksCount = 0;

            for (int i = 0; i < n; i++) {
                ss[i] = nextWord();
            }

            int[] cWhole = new int[COUNT];
            int[] cMiddle = new int[COUNT];
            int[] cStart = new int[COUNT];
            int[] cEnd = new int[COUNT];

            int[] startInd = new int[COUNT];
            int[] endInd = new int[COUNT];

            for (int sIndex = 0; sIndex < ss.length; sIndex++) {
                String s = ss[sIndex];
                boolean[] was = new boolean[COUNT];
                char prevC = 'z' + 1;
                for (int i = 0; i < s.length(); i++) {
                    char cur = s.charAt(i);
                    if (cur == prevC) {
                        continue;
                    }
                    if (was[cur - MIN]) {
                        fail = true;
                        break;
                    }
                    was[cur - MIN] = true;
                    if (i > 0 && s.charAt(s.length() - 1) != cur) {
                        cMiddle[cur - MIN]++;
                    }
                    prevC = cur;
                }
                if (fail) {
                    break;
                }
                if (s.charAt(0) == s.charAt(s.length() - 1)) {
                    cWhole[s.charAt(0) - MIN]++;
                } else if (s.charAt(0) != s.charAt(s.length() - 1)) {
                    cStart[s.charAt(0) - MIN]++;
                    startInd[s.charAt(0) - MIN] = sIndex;
                    cEnd[s.charAt(s.length() - 1) - MIN]++;
                    endInd[s.charAt(s.length() - 1) - MIN] = sIndex;
                }
            }
            if (!fail) {
                for (int i = 0; i < COUNT; i++) {
                    if (cWhole[i] > 0) {
                        if (cMiddle[i] != 0 || cStart[i] > 1 || cEnd[i] > 1) {
                            fail = true;
                            break;
                        }
                        for (long j = 2; j <= cWhole[i]; j++) {
                            res = (res * j) % MOD;
                        }
                        if (cStart[i] == 1 && cEnd[i] == 1) {
                            String st = ss[startInd[i]];
                            String en = ss[endInd[i]];
                            if (st.charAt(st.length() - 1) == en.charAt(en.length() - 1)) {
                                fail = true;
                            }
                        }

                        wholeCountUsed += cWhole[i];
                        boolean chunkAlready = false;
                        if (cStart[i] == 1) {
                            String st = ss[startInd[i]];
                            union(color, st.charAt(0) - MIN, st.charAt(st.length() - 1) - MIN);
                            chunkAlready = chunkAlready | (usedNotWhole[startInd[i]] > 0);
                            usedNotWhole[startInd[i]] = next;
                        }
                        if (cEnd[i] == 1) {
                            String en = ss[endInd[i]];
                            union(color, en.charAt(0) - MIN, en.charAt(en.length() - 1) - MIN);
                            chunkAlready = chunkAlready | (usedNotWhole[endInd[i]] > 0);
                            usedNotWhole[endInd[i]] = next;
                        }
                        next++;
                        if (!chunkAlready) {
                            chunksCount++;
                        }
                    }
                }
                for (int i = 0; i < COUNT; i++) {
                    if (cMiddle[i] > 0) {
                        if (cWhole[i] > 0 || cStart[i] > 0 || cEnd[i] > 0 || cMiddle[i] > 1) {
                            fail = true;
                            break;
                        }
                    }
                }
                for (int i = 0; i < COUNT; i++) {
                    if (cStart[i] > 0) {
                        if (cStart[i] > 1) {
                            fail = true;
                        }
                        if (cWhole[i] == 0) {
                            if (cEnd[i] > 1) {
                                fail = true;
                            } else if (cEnd[i] == 1) {
                                String st = ss[startInd[i]];
                                String en = ss[endInd[i]];
                                if (st.charAt(st.length() - 1) == en.charAt(0)) {
                                    fail = true;
                                }
                                union(color, st.charAt(st.length() - 1) - MIN, en.charAt(0) - MIN);
                                if (usedNotWhole[startInd[i]] == 0 && usedNotWhole[endInd[i]] == 0) {
                                    chunksCount++;
                                } else if (usedNotWhole[startInd[i]] == usedNotWhole[endInd[i]]) {
                                    fail = true;
                                }
                                usedNotWhole[startInd[i]] = next;
                                usedNotWhole[endInd[i]] = next;
                                next++;
                            }
                        }
                    }
                    if (cEnd[i] > 0) {
                        if (cEnd[i] > 1) {
                            fail = true;
                        }
                        if (cWhole[i] == 0) {
                            if (cStart[i] > 1) {
                                fail = true;
                            }
                        }
                    }
                }
                long unusedCount = 0;
                for (int us : usedNotWhole) {
                    if (us == 0) {
                        unusedCount++;
                    }
                }
                unusedCount -= wholeCountUsed;
                for (long j = 2; j <= chunksCount + unusedCount; j++) {
                    res = (res * j) % MOD;
                }
            }
            if (fail) {
                res = 0;
            }
            out.println(res);
        }
    }

    private void union(int[] color, int i, int j) {
        int colI = color[i];
        int colJ = color[j];
        if (colI == colJ) {
            return;
        }
        for (int k = 0; k < color.length; k++) {
            if (color[k] == colJ) {
                color[k] = colI;
            }
        }
    }

    private static final String filename = ProblemB.class.getSimpleName();

    public static void main(String[] args) throws IOException {
        ProblemB solution = new ProblemB();
        solution.solve();
        solution.close();
    }

    BufferedReader in;
    PrintWriter out;
    String curLine = null;
    StringTokenizer tok = null;

    public ProblemB() throws IOException {
        in = new BufferedReader(new FileReader(filename + ".in"));
        out = new PrintWriter(filename + ".out");
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextWord());
    }

    private String nextWord() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            curLine = in.readLine();
            if (curLine == null) {
                return null;
            }
            tok = new StringTokenizer(curLine);
        }
        return tok.nextToken();
    }

    private void close() throws IOException {
        in.close();
        out.close();
    }


}
