import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class A implements Runnable {

    private static final String PROBLEM_ID = "a";

    private class TestCaseRunner {

        int n = 4;
        char[][] c;

        public void handleCase() throws IOException {
            c = new char[n][];
            boolean space = false;
            for (int i = 0; i < n; i++) {
                while (c[i] == null || c[i].length <= 0) {
                    c[i] = nextToken().toCharArray();
                }
                for (int j = 0; j < n; j++)
                    if (c[i][j] == '.') {
                        space = true;
                        break;
                    }
            }

            boolean xWon = check('X');
            boolean oWon = check('O');
            if (xWon) {
                out.print("X won");
            } else if (oWon) {
                out.print("O won");
            } else if (space) {
                out.print("Game has not completed");
            } else {
                out.print("Draw");
            }

        }

        private boolean check(char x) {
            boolean result = false;
            for (int i = 0; i < n; i++) {
                result |= check(i, 0, x, 0, 1);
            }
            for (int j = 0; j < n; j++) {
                result |= check(0, j, x, 1, 0);
            }
            result |= check(0, 0, x, 1, 1);
            result |= check(0, n - 1, x, 1, -1);
            return result;
        }

        private boolean check(int i, int j, char x, int dI, int dJ) {
            int cX = 0;
            int cT = 0;
            for (int k = 0; k < 4; k++) {
                int nI = i + dI * k;
                int nJ = j + dJ * k;
                if (c[nI][nJ] == x) {
                    cX++;
                } else if (c[nI][nJ] == 'T') {
                    cT++;
                }
            }
            if (cX == 4) {
                return true;
            }
            if (cX == 3 && cT == 1) {
                return true;
            }
            return false;
        }

    }

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tokenizer = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(new A()).start();
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