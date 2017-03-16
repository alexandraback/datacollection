package com.google.codejam2015.qualification;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicReferenceArray;

public class OminousOmino implements Closeable {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    private final Object readLock = new Object();

    OminousOmino() throws IOException {
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
                int X, R, C;

                @Override
                protected String solve() {
                    String richard = "Richard".toUpperCase();
                    String gabriel = "Gabriel".toUpperCase();
                    if(X >= 7 || R * C % X != 0) {
                        return richard;
                    }
                    class Utils {
                        int[][] omino = new int[X][X];
                        {
                            omino[X / 2][X / 2] = 1;
                        }
                        Set<List<Integer>> visited = new HashSet<>();

                        boolean richardWins(int k) {
                            if(k == X) {
                                //check
                                List<Integer> encoded = new ArrayList<>();
                                int fr = -1, fc = -1;
                                for(int i = 0; i < X; i++) {
                                    for(int j = 0; j < X; j++) {
                                        if(omino[i][j] == 1) {
                                            if(fr == -1) {
                                                fr = i;
                                                fc = j;
                                            } else {
                                                encoded.add(i - fr);
                                                encoded.add(j - fc);
                                            }
                                        }
                                    }
                                }
                                if(visited.contains(encoded)) {
                                    return false;
                                }
                                visited.add(encoded);
                                return !gabrielSucceeds(R, C) && !gabrielSucceeds(C, R);
                            }
                            for(int i = 0; i < X; i++) {
                                for(int j = 0; j < X; j++) {
                                    if(canExpand(i, j)) {
                                        omino[i][j] = 1;
                                        if(richardWins(k + 1)) {
                                            return true;
                                        }
                                        omino[i][j] = 0;
                                    }
                                }
                            }
                            return false;
                        }

                        int[] d = {-1, 0, 1, 0};
                        private boolean canExpand(int i, int j) {
                            if(omino[i][j] == 1) {
                                return false;
                            }
                            for(int k = 0; k < 4; k++) {
                                int r = i + d[k];
                                int c = j + d[k + 1 & 3];
                                if(r >= 0 && c >= 0 && r < X && c < X && omino[r][c] == 1) {
                                    return true;
                                }
                            }
                            return false;
                        }

                        boolean[][] used = new boolean[22][22];

                        boolean gabrielSucceeds(int r, int c) {
                            int minR = X, minC = X, maxR = 0, maxC = 0;
                            for(int i = 0; i < X; i++) {
                                for(int j = 0; j < X; j++) {
                                    if(omino[i][j] == 1) {
                                        minR = Math.min(i, minR);
                                        maxR = i;
                                        minC = Math.min(j, minC);
                                        maxC = Math.max(j, maxC);
                                    }
                                }
                            }
                            int rows = maxR - minR + 1;
                            int cols = maxC - minC + 1;
                            if(rows + 2 <= r && cols + 2 <= c) {
                                return true;
                            }
                            for(int di = 0; di < 2; di++) {
                                for(int dj = 0; dj < 2; dj++) {
                                    if(di + maxR - minR >= r || dj + maxC - minC >= c) {
                                        continue;
                                    }
                                    for (boolean[] row : used) {
                                        Arrays.fill(row, true);
                                    }
                                    for(int i = 1; i <= r; i++) {
                                        for(int j = 1; j <= c; j++) {
                                            used[i][j] = false;
                                        }
                                    }
                                    for(int i = 0; i < rows; i++) {
                                        for(int j = 0; j < cols; j++) {
                                            if(omino[minR + i][minC + j] == 1) {
                                                used[1 + i + di][1 + j + dj] = true;
                                            }
                                        }
                                    }
                                    if(dfsOK(r, c)) {
                                        return true;
                                    }
                                }
                            }
                            return false;
                        }

                        private boolean dfsOK(int r, int c) {
                            int er = -1, ec = -1;
                            for(int i = 1; i <= r && er == -1; i++) {
                                for(int j = 1; j <= c && ec == -1; j++) {
                                    if(!used[i][j]) {
                                        er = i;
                                        ec = j;
                                    }
                                }
                            }
                            if(er == -1) {
                                return true;
                            }
                            dfs(er, ec);
                            for(int i = 1; i <= r; i++) {
                                for(int j = 1; j <= c; j++) {
                                    if(!used[i][j]) {
                                        return false;
                                    }
                                }
                            }
                            return true;
                        }

                        void dfs(int i, int j) {
                            used[i][j] = true;
                            for(int k = 0; k < 4; k++) {
                                int r = i + d[k];
                                int c = j + d[k + 1 & 3];
                                if(!used[r][c]) {
                                    dfs(r, c);
                                }
                            }
                        }
                    }
                    return new Utils().richardWins(1) ? richard : gabriel;
                }

                @Override
                protected void readInput() throws IOException {
                    X = nextInt();
                    R = nextInt();
                    C = nextInt();
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
        try(OminousOmino a = new OminousOmino()) {
            a.run();
        }
    }

    @Override
    public void close() throws IOException {
        reader.close();
        writer.close();
    }
}
