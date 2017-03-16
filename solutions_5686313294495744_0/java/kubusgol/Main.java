import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Set;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "C-(small|large).*[.]in";
            File directory = new File(".");
            File[] candidates = directory.listFiles(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.matches(regex);
                }
            });
            File toRun = null;
            for (File candidate : candidates) {
                if (toRun == null || candidate.lastModified() > toRun.lastModified())
                    toRun = candidate;
            }
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("c.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        Map<String, Integer> countsFirst = new HashMap<>();
        Map<String, Integer> countsSecond = new HashMap<>();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int N = in.nextInt();
            TreeSet<Pair> set = new TreeSet<>();
            String ff[] = new String[N];
            String ss[] = new String[N];
            countsFirst = new HashMap<>();
            countsSecond = new HashMap<>();
            for (int i = 0; i < N; i++) {
                String f = in.next();
                String s = in.next();
                countsFirst.compute(f, (k, v) -> v == null ? 1 : v + 1);
                countsSecond.compute(s, (k, v) -> v == null ? 1 : v + 1);
                ff[i] = f;
                ss[i] = s;
            }
            TreeSet<Pair> singles = new TreeSet<>();
            for (int i = 0; i < N; i++) {
                if (countsFirst.get(ff[i]) > 1 && countsSecond.get(ss[i]) > 1) {
                    set.add(new Pair(ff[i], ss[i], i));
                } else {
                    singles.add(new Pair(ff[i], ss[i], i));
                }
            }

            Set<String> currentFirst = new HashSet<>();
            Set<String> currentSecond = new HashSet<>();
            int ans = 0;
            while (!singles.isEmpty()) {
                Pair p = singles.pollLast();
                currentFirst.add(p.first);
                currentSecond.add(p.second);
                countsFirst.compute(p.first, (k, v) -> v - 1);
                countsSecond.compute(p.second, (k, v) -> v - 1);
            }

            while (!set.isEmpty()) {
                Pair p = set.pollLast();
                if (currentFirst.contains(p.first) && currentSecond.contains(p.second)) {
                    ans++;
                }
                currentFirst.add(p.first);
                currentSecond.add(p.second);
                countsFirst.compute(p.first, (k, v) -> v - 1);
                countsSecond.compute(p.second, (k, v) -> v - 1);
                TreeSet<Pair> set2 = new TreeSet<>();
                for (Pair q : set) {
                    set2.add(q);
                }
                set = set2;
            }
            out.println("Case #" + testNumber + ": " + ans);
        }

        private class Pair implements Comparable<Pair> {
            private String first;
            private String second;
            private int idx;

            public Pair(String first, String second, int idx) {
                this.first = first;
                this.second = second;
                this.idx = idx;
            }


            public int compareTo(Pair o) {
                int f1 = countsFirst.get(first);
                int s1 = countsSecond.get(second);
                int f2 = countsFirst.get(o.first);
                int s2 = countsSecond.get(o.second);
                if (f1 == f2) {
                    if (s1 == s2) {
                        return this.idx - o.idx;
                    }
                    return s1 - s2;
                }
                return f1 - f2;
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
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

    }
}

