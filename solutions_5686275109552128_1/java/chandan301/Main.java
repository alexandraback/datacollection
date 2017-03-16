package codejam.y2015.qual.pancakes;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static String BASE = "/Users/chandangiri/contest/src/main/java/codejam/y2015/qual/pancakes/";
    public static void main(String args[]) throws FileNotFoundException {
        InputStream inputStream = new FileInputStream(new File(BASE + "in1.txt"));
        OutputStream outputStream = new FileOutputStream(new File(BASE + "out1.txt"));
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        int testCount = in.nextInt();
        for (int i = 1; i <= testCount; i++) {
            out.printf("Case #%d: ", i);
            solver.solve(in, out);
        }
        out.close();
    }

    private static class Solver {

        public void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();

            List<Integer> a = new ArrayList<>();
            for (int i=0; i<n; i++) {
                a.add(in.nextInt());
            }
            Collections.sort(a, Collections.reverseOrder());

//            int sol = fun(copy(a));
//            int sol2 = fun2(copy(a));
            int sol3 = fun3(copy(a));

//            if (sol > sol3) {
//                System.out.println("WA : " + a);
//                out.print("WA ");
//            }

            out.println(sol3);
        }

        private List<Integer> copy(final List<Integer> a) {
            List<Integer> l1 = new ArrayList<>();
            for (Integer i : a) {
                l1.add(i);
            }
            return l1;
        }

        private int fun3(final List<Integer> a) {
            int max = a.get(0);

            int sol = max;
            for (int i=1; i<=max; i++) {
                int ts = i;
                for (int x : a) {
                    ts += (x - 1) / i;
                }
                sol = Math.min(sol, ts);
            }
            return sol;
        }

        private int fun2(final List<Integer> a) {
            Collections.sort(a, Collections.reverseOrder());

            int max = a.get(0);
            if (max <= 3) {
                return max;
            }

            List<Integer> ta = new ArrayList<>();
            for (int i=0; i<a.size(); i++) {
                int num = a.get(i);

                if (num > 1) {
                    ta.add(num - 1);
                }
            }

            a.set(0, max - 3);
            a.add(3);

            int s1 = fun2(a);
            int s2 = fun2(ta);
            int sol = min(s1 + 1, s2 + 1, max);
            return sol;
        }

        private int min(final int ... a) {
            int ret = Integer.MAX_VALUE;
            for (int x : a) {
                ret = Math.min(ret, x);
            }
            return ret;
        }

        private int fun(final List<Integer> a) {
            int sol = a.get(0);
            int special = 0;
            while (true) {
                sol = Math.min(sol, special + a.get(0));

                if (a.get(0) <= 3) {
                    break;
                }

                a.set(0, a.get(0) - 3);
                a.add(3);
                Collections.sort(a, Collections.reverseOrder());
                special++;
            }
            return sol;
        }
    }

    private static class InputReader {
        private final BufferedReader reader;
        private StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}
