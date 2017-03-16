import javafx.util.Pair;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * @author Aydar Gizatullin a.k.a. lightning95, aydar.gizatullin@gmail.com
 *         Created on 4/18/15.
 */

public class ProbC {
    RW rw;

    class RW {
        private boolean eof;
        StringTokenizer st;
        PrintWriter out;
        BufferedReader br;

        RW(String inputFile, String outputFile) {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(new OutputStreamWriter(System.out));

            File f = new File(inputFile);
            if (f.exists() && f.canRead()) {
                try {
                    br = new BufferedReader(new FileReader(inputFile));
                    out = new PrintWriter(new FileWriter(outputFile));
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    eof = true;
                    return "-1";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        void println() {
            out.println();
        }

        void println(Object o) {
            out.println(o);
        }

        void print(Object o) {
            out.print(o);
        }

        void close() {
            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            out.close();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new ProbC().run();
    }

    private void run() {
        rw = new RW("input.txt", "output.txt");
        solve();
        rw.close();
    }

    private void solve() {
        int t_num = rw.nextInt();
        for (int t_id = 0; t_id < t_num; ++t_id) {
            int n = rw.nextInt();
            List<Pair<Integer, Integer>> p = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                int x = rw.nextInt();
                int y = rw.nextInt();
                int z = rw.nextInt();
                for (int j = 0; j < y; ++j) {
                    p.add(new Pair<>(x, z + j));
                }
            }

            int ans = 0;
            if (p.size() == 1) {
            } else if (p.size() == 2) {
                Pair<Integer, Integer> p1 = p.get(0);
                Pair<Integer, Integer> p2 = p.get(1);
                double t1 = 1. * (360 - p1.getKey()) / 360 * p1.getValue();
                double t2 = 1. * (360 - p2.getKey()) / 360 * p2.getValue();

                if (t1 < t2) {
                    if (t1 + p1.getValue() <= t2) {
                        ans = 1;
                    }
                } else if (t2 < t1) {
                    if (t2 + p2.getValue() <= t1) {
                        ans = 1;
                    }
                } else {
                }

            }

            rw.println("Case #" + (t_id + 1) + ": " + ans);
        }
    }
}

