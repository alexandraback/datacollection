package com.elders.code.jam;

import java.io.*;
import java.util.StringTokenizer;

public class Main {
    final String file = "A-small-attempt0";

    FastScanner in;
    PrintWriter out;

    void solve() {
        long tc = in.nextLong();
        System.out.println("tc = " + tc);
        for (long t = 0; t < tc; t++) {
            out.print("Case #" + (t + 1) + ": ");

            String S = in.next();
            String frontHalf = "";
            String backHalf = "";

            int finalIndex = S.length() - 1;
            while (finalIndex >= 0) {
                char lastGreatestChar = 'A';
                int indexOfLastGreatestChar = 0;
                for (int i = 0; i <= finalIndex; i++) {
                    if (S.charAt(i) >= lastGreatestChar) {
                        indexOfLastGreatestChar = i;
                        lastGreatestChar = S.charAt(i);
                    }
                }

                frontHalf = frontHalf + lastGreatestChar;
                if (indexOfLastGreatestChar != finalIndex) {
                    backHalf = S.substring(indexOfLastGreatestChar + 1, finalIndex + 1) + backHalf;
                }
                finalIndex = indexOfLastGreatestChar - 1;
            }

            out.println(frontHalf + backHalf);
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
