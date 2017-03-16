package com.elders.code.jam;

import java.io.*;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
    final String file = "B-small-attempt0";

    FastScanner in;
    PrintWriter out;

    void solve() {
        long tc = in.nextLong();
        System.out.println("tc = " + tc);
        for (long t = 0; t < tc; t++) {
            out.print("Case #" + (t + 1) + ":");

            int N = in.nextInt();

            Set<Integer> oddHeights = new TreeSet<>();

            for (int i = 0; i < 2*N-1; i++) {
                for (int j = 0; j < N; j++) {
                    int num = in.nextInt();
                    if (oddHeights.contains(num)) {
                        oddHeights.remove(num);
                    } else {
                        oddHeights.add(num);
                    }
                }
            }

            for (Integer num: oddHeights) {
                out.print(" " + num);
            }
            out.print("\n");
        }
    }

    void run() {
        try {
            in = new FastScanner(new File(file + ".in"));
            out = new PrintWriter(new File(file + ".out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !(st.hasMoreTokens())) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null) {
                    return null;
                }
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(this.next());
        }

        long nextLong() {
            return Long.parseLong(this.next());
        }

        double nextDouble() {
            return Double.parseDouble(this.next());
        }


    }

    public static void main(String ... args) {
        System.out.println("Starting...");
        new Main().run();
    }
}
