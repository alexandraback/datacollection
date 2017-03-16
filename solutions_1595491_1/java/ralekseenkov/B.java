import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class B implements Runnable {

    private static final String PROBLEM_ID = "B";

    private class TestCaseRunner {

        class Triple {
            int a, b, c;

            public Triple(int a, int b, int c) {
                this.a = a;
                this.b = b;
                this.c = c;
            }

            int worst() {
                return Math.min(Math.min(a, b), c);
            }

            int best() {
                return Math.max(Math.max(a, b), c);
            }

            int total() {
                return a + b + c;
            }

            boolean isValid() {
                return best() - worst() <= 2;
            }

            boolean isSurprising() {
                return best() - worst() == 2;
            }

        }

        int[] bestSurprising, bestNonSurprising;

        private void precalc() {
            bestSurprising = new int[31];
            Arrays.fill(bestSurprising, -1);

            bestNonSurprising = new int[31];
            Arrays.fill(bestNonSurprising, -1);

            for (int a = 0; a <= 10; a++)
                for (int b = 0; b <= 10; b++)
                    for (int c = 0; c <= 10; c++) {
                        Triple t = new Triple(a, b, c);
                        if (!t.isValid()) {
                            continue;
                        }

                        if (t.isSurprising()) {
                            bestSurprising[t.total()] = t.best();
                        } else {
                            bestNonSurprising[t.total()] = t.best();
                        }
                    }
        }

        public void handleCase() throws IOException {
            precalc();

            int n = nextInt();
            int s = nextInt();
            int p = nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }

            int[][] d = new int[n + 1][s + 2];
            for (int[] v : d) {
                Arrays.fill(v, -1);
            }

            d[0][0] = 0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j <= s; j++)
                    if (d[i][j] >= 0) {
                        // use a non-surprising triple
                        {
                            if (bestNonSurprising[a[i]] >= 0) {
                                int v = bestNonSurprising[a[i]] >= p ? 1 : 0;
                                d[i + 1][j] = Math.max(d[i + 1][j], d[i][j] + v);
                            }
                        }

                        // take a surprising triple
                        {
                            if (bestSurprising[a[i]] >= 0) {
                                int v = bestSurprising[a[i]] >= p ? 1 : 0;
                                d[i + 1][j + 1] = Math.max(d[i + 1][j + 1], d[i][j] + v);
                            }
                        }
                    }

            out.print(Math.max(d[n][s], 0));
        }

    }

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tokenizer = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(new B()).start();
    }

    public void run() {
        File[] all = new File(".").listFiles();
        Arrays.sort(all, new Comparator<File>() {
            public int compare(File a, File b) {
                return a.getName().toLowerCase().compareTo(b.getName().toLowerCase());
            }
        });

        int processed = 0;
        for (File inFile : all)
            if (inFile.isFile()) {
                String name = inFile.getName().toLowerCase();
                if (name.startsWith(PROBLEM_ID.toLowerCase()) && name.endsWith(".in")) {
                    try {
                        runFile(inFile);
                        processed++;
                    } catch (Throwable t) {
                        throw new IllegalStateException("Fatal error", t);
                    }
                }
            }

        if (processed > 0) {
            System.out.println("Processed " + processed + " files for problem " + PROBLEM_ID);
        } else {
            System.err.println("No input files found for problem " + PROBLEM_ID);
        }
    }

    private void runFile(File inFile) throws IOException {
        in = new BufferedReader(new FileReader(inFile));
        out = new PrintWriter(new FileWriter(inFile.getName() + ".out"));
        long startTime = System.currentTimeMillis();

        System.out.println("Processing file: " + inFile.getName());
        int tc = nextInt();
        for (int p = 0; p < tc; p++) {
            long nowTime = System.currentTimeMillis();
            System.out.print("Running test case #" + (p + 1) + " out of " + tc);
            if (p > 0) {
                System.out.print(" (remaining time: " + remainingTime(p, tc, startTime, nowTime) + ")");
            }
            System.out.println();

            out.print("Case #" + (p + 1) + ": ");
            new TestCaseRunner().handleCase();
            out.println();
        }

        in.close();
        out.close();
    }


    private String remainingTime(int p, int tc, long startTime, long nowTime) {
        double secondsPerTestCase = 1.0e-3 * (nowTime - startTime) / p;
        double secondsRemaining = (tc - p) * secondsPerTestCase;
        double minutesRemaining = secondsRemaining / 60;

        int minutes = (int) Math.floor(minutesRemaining);
        int seconds = (int) Math.round(secondsRemaining - minutes * 60);
        return minutes + " min " + seconds + " sec";
    }

    private String nextToken() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private BigInteger nextBigInt() throws IOException {
        return new BigInteger(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

}