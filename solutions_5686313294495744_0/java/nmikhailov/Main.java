import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Nikita Mikhailov
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
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        private HashMap<String, Integer> firstMap;
        private HashMap<String, Integer> secondMap;
        private ArrayList<HashSet<Integer>> firstG;
        private ArrayList<HashSet<Integer>> secondG;
        private ArrayList<Pair<Integer, Integer>> edges;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            firstMap = new HashMap<>();
            secondMap = new HashMap<>();
            int fId = 0;
            int sId = 0;

            firstG = new ArrayList<>();
            secondG = new ArrayList<>();
            edges = new ArrayList<>();

            int n = in.readInt();

            for (int i = 0; i < n; i++) {
                String first = in.readToken();
                String second = in.readToken();

                int id1 = -1, id2 = -1;
                if (!firstMap.containsKey(first)) {
                    firstMap.put(first, fId++);
                    firstG.add(new HashSet<>());
                }
                id1 = firstMap.get(first);

                // second

                if (!secondMap.containsKey(second)) {
                    secondMap.put(second, sId++);
                    secondG.add(new HashSet<>());
                }
                id2 = secondMap.get(second);
                //

                firstG.get(id1).add(id2);
                secondG.get(id2).add(id1);

                edges.add(new Pair<Integer, Integer>(id1, id2));
            }


            TreeSet<Pair<Integer, Integer>> queue = new TreeSet<>((o1, o2) -> {
                if (o1.getFirst() - o2.getFirst() == 0) {
                    return o1.getSecond() - o2.getSecond();
                }
                return o1.getFirst() - o2.getFirst();
            });
            for (int i = 0; i < fId; i++) {
                queue.add(new Pair<Integer, Integer>(firstG.get(i).size(), i));
            }
            for (int i = 0; i < sId; i++) {
                queue.add(new Pair<Integer, Integer>(secondG.get(i).size(), i + fId));
            }

            boolean[] used = new boolean[fId + sId];

            HashSet<Pair<Integer, Integer>> usedEdges2 = new HashSet<>();
            while (!queue.isEmpty()) {
                Pair<Integer, Integer> current = queue.pollFirst();
                int id = current.getSecond();

                if (used[id]) continue;

                used[id] = true;
                // get s

                int lastTo = -1;
                if (id < fId) {
                    for (Integer to : firstG.get(id)) {
                        lastTo = to + fId;
                        if (!used[to + fId]) {
                            break;
                        }
                    }
                } else {
                    for (Integer to : secondG.get(id - fId)) {
                        lastTo = to;
                        if (!used[to]) {
                            break;
                        }
                    }
                }

                used[lastTo] = true;
                queue.remove(new Pair<Integer, Integer>(id < fId ? firstG.get(id).size() : secondG.get(id - fId).size(), id));

                usedEdges2.add(new Pair<Integer, Integer>(Math.min(id, lastTo), Math.max(id, lastTo) - fId));
            }


            int res = 0;
            for (Pair<Integer, Integer> edge : edges) {
                if (firstG.get(edge.getFirst()).size() > 1 && secondG.get(edge.getSecond()).size() > 1) {
                    if (!usedEdges2.contains(edge))
                        res++;
                }
            }

            out.println("Case #" + testNumber + ": " + res);
        }

    }

    static class Pair<K, V> {
        private final K key;
        private final V value;

        public Pair(K k, V v) {
            key = k;
            value = v;
        }

        public Pair(Pair<? extends K, ? extends V> entry) {
            this(entry.getKey(), entry.getValue());
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        public K getFirst() {
            return key;
        }

        public V getSecond() {
            return value;
        }


        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (!(o instanceof Pair)) {
                return false;
            } else {
                Pair<?, ?> oP = (Pair<?, ?>) o;
                return (key == null ?
                        oP.key == null :
                        key.equals(oP.key)) &&
                        (value == null ?
                                oP.value == null :
                                value.equals(oP.value));
            }
        }


        public int hashCode() {
            int result = key == null ? 0 : key.hashCode();

            final int h = value == null ? 0 : value.hashCode();
            result = 37 * result + h ^ (h >>> 16);

            return result;
        }


        public String toString() {
            return "[" + getKey() + ", " + getValue() + "]";
        }

    }

    static class FastScanner {
        private StringTokenizer st;
        private BufferedReader in;

        public FastScanner(final InputStream in) {
            this.in = new BufferedReader(new InputStreamReader(in));
        }

        public String readToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(in.readLine());
                } catch (final IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        public int readInt() {
            return Integer.parseInt(readToken());
        }

        public String next() {
            return readToken();
        }

    }
}

