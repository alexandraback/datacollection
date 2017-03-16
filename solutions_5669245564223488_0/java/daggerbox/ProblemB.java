package com.forthgo.contest.g2014.r1c;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class ProblemB {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("B.in.txt"));
            PrintWriter out = new PrintWriter(new FileWriter("B.out.txt"));
//            PrintWriter out = new PrintWriter(System.out);
            int n = in.nextInt();
            in.nextLine();
            for (int i = 0; i < n; i++) {
                out.printf("Case #%d: ", i + 1);
                solve(in, out);
                out.println();
                out.flush();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }

    private static void solve(Scanner in, PrintWriter out) {
        int N = in.nextInt();
        String[] cars = new String[N];
        int[] first = new int[N];
        int[] last = new int[N];
        long[] dup = new long[N];
        int n = N;
        for (int i = 0; i < n; i++) {
            cars[i] = in.next();
            first[i] = cars[i].charAt(0);
            last[i] = cars[i].charAt(cars[i].length() - 1);
            dup[i] = 1;
//            for (int j = 0; j < i; j++) {
//                if (cars[i] == cars[j]) {
//                    dup[j]++;
//                    i--;
//                    n--;
//                }
//            }
        }
        long M = 1000000007L;

        List<Integer>[] start = new List[200];
        List<Integer>[] middle = new List[200];
        List<Integer>[] end = new List[200];
        for (int i = 'a'; i <= 'z'; i++) {
            start[i] = new ArrayList<Integer>();
            middle[i] = new ArrayList<Integer>();
            end[i] = new ArrayList<Integer>();
        }
        boolean impossible = false;
        for (int i = 0; i < n; i++) {
            start[first[i]].add(i);
            end[last[i]].add(i);
            int s = 1;
            int e = cars[i].length() - 1;
            for (; s < e && cars[i].charAt(s) == cars[i].charAt(s - 1); s++)
                ;
            for (; s < e && cars[i].charAt(e - 1) == cars[i].charAt(e); e--)
                ;
            if (s < e && dup[i] > 1) {
                impossible = true;
            }
            if (s != e && first[i] == last[i])
                impossible = true;
            for (int j = s; j < e; j++) {
                if (cars[i].charAt(j) != cars[i].charAt(j - 1))
                    middle[cars[i].charAt(j)].add(i);
            }
        }
        // check for impossible middles
        for (int i = 0; i < n; i++) {
            int s = 1;
            int e = cars[i].length() - 1;
            for (; s < e && cars[i].charAt(s) == cars[i].charAt(s - 1); s++)
                ;
            for (; s < e && cars[i].charAt(e - 1) == cars[i].charAt(e); e--)
                ;
            if (s < e && dup[i] > 1) {
                impossible = true;
            }
            boolean [] seen = new boolean[200];
            for (int j = s; j < e; j++) {
                char c = cars[i].charAt(j);
                if (c == cars[i].charAt(j - 1))
                    continue;
                if (seen[c])
                    impossible = true;
                if (middle[c].size() > 1)
                    impossible = true;
                if (start[c].size() > 0)
                    impossible = true;
                if (end[c].size() > 0)
                    impossible = true;
                seen[c] = true;
            }
        }

        long count = 0;
        if (!impossible) {
            long rem = n;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (dup[j] > 0 && first[i] == last[i] && first[i] == first[j] && last[i] == last[j]) {
                        dup[i] += dup[j];
                        dup[j] = 0;
                        rem --;
                    }
                }
            }
            int[] chainFirst = new int[n];
            int[] chainLast = new int[n];
            long[] chainWays = new long[n];
            int nc = 0;

            long[] startCount = new long[200];
            long[] endCount = new long[200];
            for (int i = 0; i < n; i++) {
                if (dup[i] > 0 && first[i] != last[i]) {
                    startCount[first[i]]++;
                    endCount[last[i]]++;
                    if (startCount[first[i]] > 1)
                        impossible = true;
                    if (endCount[last[i]] > 1)
                        impossible = true;
                }
            }
            while (!impossible && rem > 0) {
                for (int i = 0; i < n; i++) {
                    if (dup[i] > 0 /* && first[i] != last[i] */) {
                        // new chain
                        chainFirst[nc] = first[i];
                        chainLast[nc] = last[i];
                        chainWays[nc] = factorialMod(dup[i], M);
                        boolean progress = true;
                        while (progress) {
                            progress = false;
                            for (int j = 0; j < n; j++) {
                                if (dup[j] == 0 || i == j) {
                                    continue;
                                }
                                if (first[j] == chainLast[nc] && first[j] == last[j]) {
                                    chainWays[nc] = (chainWays[nc] * factorialMod(dup[j], M)) % M;
                                    dup[j] = 0;
                                    rem--;
                                    progress = true;
                                }
                                if (last[j] == chainFirst[nc] && first[j] == last[j]) {
                                    chainWays[nc] = (chainWays[nc] * factorialMod(dup[j], M)) % M;
                                    dup[j] = 0;
                                    progress = true;
                                    rem--;
                                }
                            }
                            for (int j = 0; j < n; j++) {
                                if (dup[j] == 0 || i == j) {
                                    continue;
                                }
                                if (first[j] == chainLast[nc]) {
                                    chainWays[nc] = (chainWays[nc] * factorialMod(dup[j], M)) % M;
                                    chainLast[nc] = last[j];
                                    dup[j] = 0;
                                    rem--;
                                    progress = true;
                                }
                                if (last[j] == chainFirst[nc]) {
                                    chainWays[nc] = (chainWays[nc] * factorialMod(dup[j], M)) % M;
                                    chainFirst[nc] = first[j];
                                    dup[j] = 0;
                                    progress = true;
                                    rem--;
                                }
                            }
                        }

                        rem --;
                        nc++;
                    }
                }
            }
            for (int i = 0; i < nc; i++) {
                for (int j = 0; j < i - 1; j++) {
                    if (chainFirst[i] == chainFirst[j] || chainLast[i] == chainLast[j]) {
                        impossible = true;
                    }
                }
            }
            if (!impossible) {
                count = factorialMod(nc, M);
                for (int i = 0; i < nc; i++) {
                    count = (count * chainWays[i]) % M;
                }
            }
        }

        out.print(count);
    }

    public static long factorialMod(long n, long m) {
        long f = 1;
        for (int i = 2; i <= n; i++) {
            f = f * i % m;
        }
        return f;
    }


}


