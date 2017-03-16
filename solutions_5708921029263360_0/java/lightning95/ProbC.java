import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

/**
 * @author Aydar Gizatullin a.k.a. lightning95, aydar.gizatullin@gmail.com
 *         Created on 4/16/16.
 */

public class ProbC {
    private RW rw;

    public static void main(String[] args) {
        new ProbC().run();
    }

    private void run() {
        rw = new RW("input.txt", "output.txt");
        solve();
        rw.close();
    }

    private class RW {
        private StringTokenizer st;
        private PrintWriter out;
        private BufferedReader br;
        private boolean eof;

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

        private String nextLine() {
            String s = "";
            try {
                s = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return s;
        }

        private String next() {
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

        private int nextInt() {
            return Integer.parseInt(next());
        }

        private void println() {
            out.println();
        }

        private void println(Object o) {
            out.println(o);
        }

        private void print(Object o) {
            out.print(o);
        }

        private void close() {
            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            out.close();
        }
    }

    class Pair {
        int x, id;

        Pair(int x, int id) {
            this.x = x;
            this.id = id;
        }
    }

    class Triple {
        int a, b, c;

        Triple(int x, int y, int z) {
            a = x;
            b = y;
            c = z;
        }
    }

    boolean[] best;
    int bestN;

    private void solve() {
        int testNum = rw.nextInt();
        main:
        for (int testId = 1; testId <= testNum; ++testId) {
            rw.print("Case #" + testId + ": ");
            System.err.println(testId);
            int a = rw.nextInt();
            int b = rw.nextInt();
            int c = rw.nextInt();
            int rep = rw.nextInt();

            List<Triple> list = new ArrayList<>();
            for (int i = 0; i < a; ++i) {
                for (int j = 0; j < b; ++j) {
                    for (int k = 0; k < c; ++k) {
                        list.add(new Triple(i + 1, j + 1, k + 1));
                    }
                }
            }
            if (rep >= 3) {
                rw.println(list.size());
                for (Triple t : list) {
                    rw.println(t.a + " " + t.b + " " + t.c);
                }
                continue;
            }
            best = new boolean[list.size()];
            bestN = 0;
            boolean[] us = new boolean[list.size()];
            HashMap<Integer, Integer> map = new HashMap<>();
            rec(list, rep, us, map, -1, 0);

            rw.println(bestN);
            for (int i = 0; i < list.size(); ++i) {
                if (best[i]) {
                    Triple t = list.get(i);
                    rw.println(t.a + " " + t.b + " " + t.c);
                }
            }
        }
    }

    private void rec(List<Triple> list, int rep, boolean[] us, HashMap<Integer, Integer> map, int last, int kol) {
        if (bestN < kol) {
            System.arraycopy(us, 0, best, 0, list.size());
            bestN = kol;
        }
        for (int i = last + 1; i < list.size(); ++i) {
            if (!us[i]) {
                Triple t = list.get(i);
                int c1 = map.getOrDefault(t.a * 10000 + t.b * 100, 0);
                int c2 = map.getOrDefault(t.a * 10000 + t.c, 0);
                int c3 = map.getOrDefault(t.b * 100 + t.c, 0);
                if (c1 < rep && c2 < rep && c3 < rep) {
                    map.put(t.a * 10000 + t.b * 100, c1 + 1);
                    map.put(t.a * 10000 + t.c, c2 + 1);
                    map.put(t.b * 100 + t.c, c3 + 1);
                    us[i] = true;

                    rec(list, rep, us, map, i, kol + 1);

                    map.put(t.a * 10000 + t.b * 100, c1);
                    map.put(t.a * 10000 + t.c, c2);
                    map.put(t.b * 100 + t.c, c3);
                    us[i] = false;
                }
            }
        }
    }

}
