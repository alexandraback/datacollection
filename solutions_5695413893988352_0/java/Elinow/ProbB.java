import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

import org.apache.commons.lang3.ObjectUtils;

import com.google.common.collect.ComparisonChain;

public class ProbB {

    private static final String INPUT_FILE = "e:/downloads/B-small-attempt0.in";
    private static final String OUTPUT_FOLDER = "C:/workspaces/algo/GCJ/src/";
    private static final String OUTPUT_FILE = "B-small.out";

    private static class ValidResult implements Comparable<ValidResult> {

        private int c;
        private int j;

        public ValidResult(int c, int j) {
            this.c = c;
            this.j = j;
        }

        @Override
        public int compareTo(ValidResult o) {
            return ComparisonChain.start()
                    .compare(diff(), o.diff())
                    .compare(c, o.c)
                    .compare(j, o.j)
                    .result();
        }

        public int diff() {
            return Math.abs(c - j);
        }

        @Override
        public String toString() {
            return "ValidResult [c=" + c + ", j=" + j + "]";
        }

    }

    public static void main(String[] args) throws Exception {
        InputReader in = new InputReader(new FileInputStream(INPUT_FILE));
        PrintWriter pw = new PrintWriter(new File(OUTPUT_FOLDER, OUTPUT_FILE));
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            String stC = in.next().replace('?', '.');
            String stJ = in.next().replace('?', '.');
            ValidResult bestRes = null;
            for (int i = 0; i <= 999; i++) {
                if (!isPatternMatched(i, stC)) {
                    continue;
                }
                for (int j = 0; j <= 999; j++) {
                    if (!isPatternMatched(j, stJ)) {
                        continue;
                    }
                    if (bestRes == null) {
                        bestRes = new ValidResult(i, j);
                    } else {
                        bestRes = ObjectUtils.min(bestRes, new ValidResult(i, j));
                    }
                }
            }
            int n = stC.length();
            String res = String.format("Case #%d: %0" + n + "d %0" + n + "d", t, bestRes.c, bestRes.j);
            pw.println(res);
            System.out.println(res);
        }
        pw.close();
    }

    private static boolean isPatternMatched(int num, String pattern) {
        String st = String.format("%0" + pattern.length() + "d", num);
        return st.matches(pattern);
    }

    public static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }

}
