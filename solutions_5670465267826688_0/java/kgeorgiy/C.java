package info.kgeorgiy.contests.codejam.y2015.qualification;

import java.io.*;
import java.net.URL;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C {
    static int O = 1, I = 2, J = 3, K = 4;
    int[][] q = new int[][]{
            {O, I, J, K},
            {I, -O, K, -J},
            {J, -K, -O, I},
            {K, J, -I, -O}
    };

    int multiply(int a, int b) {
        if (a < 0) {
            return -multiply(-a, b);
        }
        if (b < 0) {
            return -multiply(a, -b);
        }
        return q[a - 1][b - 1];
    }

    Object test() {
        int l = nextInt();
        int n = in.nextInt();
        char[] chars = in.next().toCharArray();
        int[] d = new int[l * n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < l; j++) {
                d[i * l + j] = chars[j] - 'i' + I;
            }
        }

        int[] s = new int[n * l + 1];
        s[n * l] = O;
        for (int i = l * n - 1; i >= 0; i--) {
            s[i] = multiply(d[i], s[i + 1]);
        }

        int p1 = O;
        for (int b1 = 0; b1 < l * n; b1++) {
            int p2 = O;
            for (int b2 = b1; b2 < l * n; b2++) {
                int p3 = s[b2];
                if (p1 == I && p2 == J && p3 == K) {
                    return "YES";
                }
                p2 = multiply(p2, d[b2]);
            }
            p1 = multiply(p1, d[b1]);
        }

        return "NO";
    }

    // ========================================================================================
    // Stub follows
    // ========================================================================================
    static final String PROBLEM = C.class.getSimpleName();

    static Scanner in;
    static PrintWriter out;

    private static void run() {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            out.println("Case #" + (i + 1) + ": " + new C().test());
        }
    }

    public static void main(String[] args) throws IOException {
        final URL url = C.class.getResource(C.class.getSimpleName() + ".class");
        final File dir = new File(substringAfter(url.toString().replaceFirst("\\/out\\/production\\/[^/]+\\/", "/src/"), "file:/")).getParentFile();
        for (final String suffix : new String[]{"example", "small", "large"}) {
            String testName = getTest(dir, suffix);
            final File inputFile = new File(dir, testName + ".in");
            final File outputFile = new File(dir, testName + ".out");
            final File answerFile = new File(dir, testName + ".ans");

            if (inputFile.exists()) {
                System.out.println("===================== Running on " + inputFile.getName());
                in = new Scanner(inputFile);
                out = new PrintWriter(outputFile);
                try {
                    run();
                } finally {
                    out.close();
                }
                if (answerFile.exists()) {
                    compareFiles(answerFile, outputFile);
                }
            }
        }
    }

    private static String getTest(File dir, String suffix) {
        String last = PROBLEM + "-" + suffix;
        int i = 0;
        while (true) {
            final String f = PROBLEM + "-" + suffix + "-attempt" + i;
            if (new File(dir, f + ".in").exists()) {
                last = f;
                i++;
            } else {
                return last;
            }
        }
    }

    private static List<String> readLines(final File file) throws IOException {
        final BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(file), Charset.forName("UTF-8")));

        try {
            final List<String> result = new ArrayList<String>();
            String line;
            while ((line = reader.readLine()) != null) {
                result.add(line);
            }
            return result;
        } finally {
            reader.close();
        }
    }

    private static void compareFiles(final File answerFile, final File outputFile) throws IOException {
        final List<String> answerLines = readLines(answerFile);
        final List<String> outputLines = readLines(outputFile);
        final int common = Math.min(answerLines.size(), outputLines.size());
        boolean ok = true;
        for (int i = 0; i < common; i++) {
            final String answerLine = answerLines.get(i).trim();
            final String outputLine = outputLines.get(i).trim();
            if (!answerLine.equals(outputLine)) {
                System.out.println("????????????????????? Expected: " + answerLine + "\n????????????????????? Found:    " + outputLine);
                ok = false;
            }
        }
        for (int i = common; i < answerLines.size(); i++) {
            System.out.println("????????????????????? Extra line in answer: " + answerLines.get(i));
            ok = false;
        }
        for (int i = common; i < outputLines.size(); i++) {
            System.out.println("????????????????????? Extra line in output: " + outputLines.get(i));
            ok = false;
        }
        if (ok) {
            System.out.println("===================== ok");
        }
    }

    public static String substringAfter(final String string, final String pattern) {
        final int index = string.indexOf(pattern);
        return index < 0 ? "" : string.substring(index + pattern.length());
    }

    private static char nextChar() {
        final String next = in.next();
        if (next.length() != 1) {
            throw new AssertionError("Single character expected instead of " + next);
        }
        return next.charAt(0);
    }

    private static int nextInt() {
        return in.nextInt();
    }

    private String nextToken() {
        return in.next();
    }

    private int[] nextIntArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        return a;
    }
}
