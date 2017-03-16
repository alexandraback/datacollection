package com.forthgo.contest.g2013r0;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;


public class ProblemD {
    public static void main(String[] args) {
            try {
            Scanner in = new Scanner(new File("D.in"));
            PrintWriter out = new PrintWriter(new FileWriter("D.out"));
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
            throw new RuntimeException();
        }
    }

    static private Set<BitSet> failure;
    private static void solve(Scanner in, PrintWriter out) {
        int t = in.nextInt();
        int n = in.nextInt();
        KeyList keys = new KeyList(in, t);
        int[] chestOpener = new int[n];
        KeyList[] chestInside = new KeyList[n];
        BitSet visited = new BitSet(n);
        BitSet unvisited = new BitSet(n);
        for (int i = 0; i < n; i++) {
            chestOpener[i] = in.nextInt();
            int nn = in.nextInt();
            chestInside[i] = new KeyList(in, nn);
            unvisited.set(i);
        }
        failure = new HashSet<BitSet>();
        int [] path = new int[n];
        if (findPath(keys, chestOpener, chestInside, path, 0, visited, unvisited)) {
            for (int i = 0; i < n; i++) {
                if (i != 0)
                    out.print(" ");
                out.print(path[i] + 1);

            }
        }
        else
            out.print("IMPOSSIBLE");
    }

    private static boolean findPath(KeyList keys, int[] chestOpener, KeyList [] chestInside, int[] path, int next, BitSet visited, BitSet unvisited) {
        if (failure.contains(visited))
            return false;
        if (next == path.length)
            return true;
        for (int i = unvisited.nextSetBit(0); i >= 0; i = unvisited.nextSetBit(i + 1)) {
            // operate on index i here
            if (keys.contains(chestOpener[i])) {
                keys.remove(chestOpener[i]);
                keys.add(chestInside[i]);
                visited.set(i);
                unvisited.clear(i);
                path[next] = i;
                if (findPath(keys, chestOpener, chestInside, path, next + 1, visited, unvisited))
                    return true;
                unvisited.set(i);
                visited.clear(i);
                keys.add(chestOpener[i]);
                keys.remove(chestInside[i]);
            }
        }
        failure.add(visited);
        return false;
    }

    static final int MAX_KEY = 200;

    static class KeyList {
        public int[] count = new int[MAX_KEY + 1];
        //public int[] keys;
        public BitSet uniqueKeys = new BitSet();


        public KeyList(Scanner in, int n) {
            //keys = new int[n];
            for (int i = 0; i < n; i++) {
                int key = in.nextInt();
                count[key]++;
                uniqueKeys.set(key);
            }
        }

        public boolean contains(int i) {
            return count[i] != 0;
        }

        public void remove(int i) {
            count[i]--;
            if (count[i] == 0) {
                uniqueKeys.clear(i);
            }
        }

        public void add(KeyList a) {
            for (int i = a.uniqueKeys.nextSetBit(0); i >= 0; i = a.uniqueKeys.nextSetBit(i + 1)) {
                if (count[i] == 0)
                    uniqueKeys.set(i);
                count[i] += a.count[i];
            }
        }

        public void add(int i) {
            if (count[i] == 0)
                uniqueKeys.set(i);
            count[i]++;
        }

        public void remove(KeyList a) {
            for (int i = a.uniqueKeys.nextSetBit(0); i >= 0; i = a.uniqueKeys.nextSetBit(i + 1)) {
                count[i] -= a.count[i];
                if (count[i] == 0)
                    uniqueKeys.clear(i);
            }
        }

    }


}

