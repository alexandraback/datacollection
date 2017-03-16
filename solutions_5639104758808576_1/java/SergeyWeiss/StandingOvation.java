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

public class StandingOvation implements Closeable {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    private final Object readLock = new Object();

    StandingOvation() throws IOException {
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

    void run() throws IOException, InterruptedException {
        int testsNumber = nextInt();
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
        for(int i = 0; i < testsNumber; i++) {
            executorService.execute(new Solver() {
                char[] s;

                @Override
                protected String solve() {
                    int standing = 0;
                    int answer = 0;
                    for(int i = 0; i < s.length; i++) {
                        if(s[i] > '0') {
                            answer += Math.max(0, i - standing);
                            standing += Math.max(0, i - standing);
                            standing += s[i] - '0';
                        }
                    }
                    return Integer.toString(answer);
                }

                @Override
                protected void readInput() throws IOException {
                    next();
                    s = next().toCharArray();
                }
            });
        }
        executorService.shutdown();
        executorService.awaitTermination(10, TimeUnit.MINUTES);
        for(int i = 0; i < testsNumber; i++) {
            writer.println(String.format("Case #%d: %s", i + 1, answers.get(i)));
        }
    }

    public static void main(String[] args) throws IOException, InterruptedException {
        try(StandingOvation a = new StandingOvation()) {
            a.run();
        }
    }

    @Override
    public void close() throws IOException {
        reader.close();
        writer.close();
    }
}
