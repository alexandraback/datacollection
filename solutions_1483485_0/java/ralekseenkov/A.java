import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A implements Runnable {

    private static final String PROBLEM_ID = "A";

    private class TestCaseRunner {

        Map<Character, Character> mapping = new HashMap<Character, Character>();

        public void handleCase() throws IOException {
            learn("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
            learn("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
            learn("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
            if (mapping.size() != 27) {

                mapping.put('q', 'z');
                mapping.put('z', 'q');

                for (char c = 'a'; c <= 'z'; c++)
                    if (!mapping.keySet().contains(c)) {
                        System.out.println("SRC MISSING: " + c);
                    }

                for (char c = 'a'; c <= 'z'; c++)
                    if (!mapping.values().contains(c)) {
                        System.out.println("DST MISSING: " + c);
                    }

            }


            String s = in.readLine();
            for (char c : s.toCharArray()) {
                out.print(mapping.get(c));
            }
        }

        private void learn(String src, String dst) {
            if (src.length() != dst.length()) {
                throw new IllegalStateException();
            }
            for (int i = 0; i < src.length(); i++) {
                mapping.put(src.charAt(i), dst.charAt(i));
            }
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