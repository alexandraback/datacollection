package com.google.codejam2015.qualification;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicReferenceArray;

public class Dijkstra implements Closeable {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    private final Object readLock = new Object();

    Dijkstra() throws IOException {
        reader = new BufferedReader(new FileReader("input.txt"));
        writer = new PrintWriter(new FileWriter("output.txt"));
    }

    StringTokenizer stringTokenizer;

    String next() throws IOException {
        synchronized (readLock) {
            while (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
                stringTokenizer = new StringTokenizer(reader.readLine());
            }
            return stringTokenizer.nextToken();
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static enum Quaternion {
        ONE(0, 0), I(1, 0), J(2, 0), K(3, 0),
        MINUS_ONE(0, 1), MINUS_I(1, 1), MINUS_J(2, 1), MINUS_K(3, 1);

        int ordinal;
        int negative;
        static char[] ch = "1IJK".toCharArray();

        @Override
        public String toString() {
            return (negative == 1 ? "-" : "") + ch[ordinal];
        }

        private Quaternion(int ordinal, int negative) {
            this.negative = negative;
            this.ordinal = ordinal;
        }

        Quaternion multiply(Quaternion that) {
            if(ordinal * that.ordinal == 0) {
                return values()[ordinal + that.ordinal + 4 * (negative + that.negative) & 7];
            }
            if(that.ordinal == this.ordinal) {
                return values()[4 * (negative + that.negative + 1) & 7];
            }
            int ordinal = 6 - this.ordinal - that.ordinal;
            int negative = this.negative + that.negative;
            if((that.ordinal - this.ordinal + 3) % 3 == 2) {
                negative++;
            }
            return values()[ordinal + 4 * negative & 7];
        }

        static void debugPrint() {
            for (Quaternion q1 : values()) {
                for (Quaternion q2 : values()) {
                    System.out.println(String.format("%s x %s = %s", q1, q2, q1.multiply(q2)));
                }
            }
        }
    }

    void run() throws IOException, InterruptedException {
        final int testsNumber = nextInt();
        final AtomicReferenceArray<String> answers = new AtomicReferenceArray<>(testsNumber);
        final AtomicInteger currentTest = new AtomicInteger(-1);
        abstract class Solver implements Runnable {
            @Override
            public final void run() {
                int testNumber;
                synchronized (readLock) {
                    testNumber = currentTest.incrementAndGet();
                    try {
                        readInput();
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                }
                answers.set(testNumber, solve());
                System.out.println("Test " + testNumber + " complete");
            }

            abstract protected String solve();

            abstract protected void readInput() throws IOException;
        }
        final int availableProcessors = Runtime.getRuntime().availableProcessors();
        System.out.println("Number of available processors: " + availableProcessors);
        final ExecutorService executorService = Executors.newFixedThreadPool(availableProcessors + 1);
        for (int i = 0; i < testsNumber; i++) {
            executorService.execute(new Solver() {
                int L;
                long X;
                char[] S;

                @Override
                protected String solve() {
                    class Utils {
                        Quaternion pow(Quaternion q, long k) {
                            Quaternion result = Quaternion.ONE;
                            while(k > 0) {
                                if(k % 2 == 1) {
                                    result = result.multiply(q);
                                }
                                q = q.multiply(q);
                                k /= 2;
                            }
                            return result;
                        }
                    }
                    Quaternion[] ijk = {Quaternion.I, Quaternion.J, Quaternion.K};
                    Quaternion product = Quaternion.ONE;
                    for (char s : S) {
                        product = product.multiply(ijk[s - 'i']);
                    }
                    product = new Utils().pow(product, X);
                    if(product != Quaternion.MINUS_ONE) {
                        return "NO";
                    }
                    int prefixI = -1;
                    Quaternion q = Quaternion.ONE;
                    for(int k = 0; k < 8 && prefixI == -1; k++) {
                        for(int i = 0; i < L && prefixI == -1; i++) {
                            q = q.multiply(ijk[S[i] - 'i']);
                            if (q == Quaternion.I) {
                                prefixI = k * L + i + 1;
                            }
                        }
                    }
                    int suffixK = -1;
                    q = Quaternion.ONE;
                    for(int k = 0; k < 8 && suffixK == -1; k++) {
                        for(int i = 0; i < L && suffixK == -1; i++) {
                            q = ijk[S[L - 1 - i] - 'i'].multiply(q);
                            if(q == Quaternion.K) {
                                suffixK = k * L + i + 1;
                            }
                        }
                    }
                    return prefixI == -1 || suffixK == -1 || prefixI + suffixK >= X * L ? "NO" : "YES";
                }

                @Override
                protected void readInput() throws IOException {
                    L = nextInt();
                    X = nextLong();
                    S = next().toCharArray();
                }
            });
        }
        executorService.shutdown();
        executorService.awaitTermination(10, TimeUnit.MINUTES);
        for (int i = 0; i < testsNumber; i++) {
            writer.println(String.format("Case #%d: %s", i + 1, answers.get(i)));
        }
    }

    public static void main(String[] args) throws IOException, InterruptedException {
        try (Dijkstra a = new Dijkstra()) {
            a.run();
        }
    }

    @Override
    public void close() throws IOException {
        reader.close();
        writer.close();
    }
}
