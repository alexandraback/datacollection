import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.ArrayDeque;
import java.util.LinkedHashSet;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lebegio
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
        MyReader in = new MyReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, MyReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] F = new int[n];
            int edges = 0;
            ArrayList<Integer>[] graph = new ArrayList[n];
            ArrayList<Integer>[] revGraph = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                graph[i] = new ArrayList<>();
                revGraph[i] = new ArrayList<>();
            }

            for (int i = 0; i < n; i++) {
                int bff = in.nextInt() - 1;
                edges += bff;
                graph[i].add(bff);
                revGraph[bff].add(i);
                F[i] = bff;
            }

            int twoCount = 0;
            int maxLen = 0;
            HashSet<Long> pairz = new HashSet<>();
            for (int i = 0; i < n; i++) {
                LinkedHashSet<Integer> path = new LinkedHashSet<>();
                int curr = i;
                int len = 0;
                while (!path.contains(curr)) {
                    path.add(curr);
                    curr = F[curr];
                }
                ArrayList<Integer> list = new ArrayList<>();
                boolean found = false;
                for (int v : path) {
                    found = found || v == curr;
                    if (found) list.add(v);
                }
                if (list.size() == 2) {
                    int first = list.get(0);
                    int sec = list.get(1);
                    pairz.add(Math.min(first, sec) + 1010L * Math.max(first, sec));
                }
                maxLen = Math.max(maxLen, list.size());
            }

            int count = 0;
            for (long v : pairz) {
                int v1 = (int) (v % 1010);
                int v2 = (int) (v / 1010);
                count += countForV(v1, v2, revGraph) + countForV(v2, v1, revGraph) + 2;
            }
            out.println("Case #" + testNumber + ": " + Math.max(count, maxLen));
        }

        int countForV(int v, int u, ArrayList<Integer>[] graph) {
            boolean[] checked = new boolean[graph.length];
            checked[u] = true;
            checked[v] = true;
            int[] lenz = new int[checked.length];
            int len = 0;
            ArrayDeque<Integer> queue = new ArrayDeque<>();
            queue.add(v);
            while (!queue.isEmpty()) {
                int curr = queue.poll();
                checked[curr] = true;
                for (int adj : graph[curr]) {
                    if (!checked[adj]) {
                        queue.add(adj);
                        lenz[adj] = lenz[curr] + 1;
                        len = Math.max(len, lenz[adj]);
                    }
                }
            }
            return len;
        }

    }

    static class MyReader {
        private BufferedReader buffReader;
        private StringTokenizer strTokenizer;
        private static final int SIZE = 32768;

        public MyReader(InputStream inputStream) {
            buffReader = new BufferedReader(new InputStreamReader(inputStream), SIZE);
        }

        public String next() {
            if (strTokenizer == null || !strTokenizer.hasMoreTokens()) {
                try {
                    strTokenizer = new StringTokenizer(buffReader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return strTokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

