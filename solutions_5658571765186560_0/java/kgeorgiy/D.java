package info.kgeorgiy.contests.codejam.y2015.qualification;

import java.io.*;
import java.net.URL;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class D {
    Object test() {
        int n = nextInt();
        int w = nextInt();
        int h = nextInt();

        return solve(n, Math.max(w, h), Math.min(w, h)) ? "RICHARD" : "GABRIEL";
    }

    private boolean solve(int n, int w, int h) {
        if (n >= 7) {
            return true;
        }
        if (w * h % n != 0) {
            return true;
        }
        if (2 * h + 1 <= n) {
            return true;
        }
        if (n >= w) {
            for (int i = 0; i <= n - w; i++) {
                boolean ok = true;
                for (int j = i; j < h - (n - w - i); j++) {
                    ok &= (w * j - i) % n != 0;
                }
                if (ok) {
                    return true;
                }
            }
        }

        return false;
    }

    // ========================================================================================
    // Stub follows
    // ========================================================================================
    static final String PROBLEM = D.class.getSimpleName();

    static Scanner in;
    static PrintWriter out;

    private static void run() {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            out.println("Case #" + (i + 1) + ": " + new D().test());
        }
    }

    public static void main(String[] args) throws IOException {
        final URL url = D.class.getResource(D.class.getSimpleName() + ".class");
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

    private void assertEquals(Object expected, Object actual) {
        assert actual.equals(expected) : "Expected " + expected + ", found " + actual;
    }
}
