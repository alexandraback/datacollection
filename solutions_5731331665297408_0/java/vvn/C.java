import java.io.*;
import java.util.*;

public class C {
    FastScanner in;
    PrintWriter out;

    List<Integer> result;

    public void solve() throws IOException {
        int cases = in.nextInt();
        for (int testcase = 1; testcase <= cases; testcase++) {
            out.print("Case #" + testcase + ": ");
            int n = in.nextInt();
            int m = in.nextInt();

            final List<Integer> z = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                z.add(in.nextInt());
            }

            List<Integer> sorted = new ArrayList<>(z);
            Collections.sort(sorted);

            final List<Integer> order = new ArrayList<>();
            for (Integer zip : z) {
                order.add(sorted.indexOf(zip));
            }

            List<List<Integer>> edges = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                edges.add(new ArrayList<Integer>());
            }

            for (List<Integer> edg : edges) {
                Collections.sort(edg, new Comparator<Integer>() {
                    @Override
                    public int compare(Integer a, Integer b) {
                        return Integer.compare(z.get(a), z.get(b));
                    }
                });
            }

            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                edges.get(a).add(b);
                edges.get(b).add(a);
            }

            result = null;

            int start = order.indexOf(0);
            LinkedList<Integer> current = new LinkedList<>();
            HashSet<Integer> visited = new HashSet<>();
            visited.add(start);
            current.add(z.get(start));

            backtrack(start, edges, z, visited, new HashMap<Integer, Integer>(), current);

            StringBuilder sb = new StringBuilder();
            for (int x : result) {
                sb.append(x);
            }
            out.println(sb.toString());
            out.flush();
        }
    }

    public void backtrack(int v, List<List<Integer>> edges, List<Integer> order,
                          Set<Integer> visited, Map<Integer, Integer> parent, LinkedList<Integer> current) {
        if (current.size() == edges.size()) {
            if (result == null || isLess(current, result)) {
                result = new ArrayList<>(current);
            }
            return;
        }

        int par = parent.containsKey(v) ? parent.get(v) : -1;
        for (int x : edges.get(v)) {
            if (visited.contains(x) && x != par) {
                continue;
            }
            boolean added = visited.add(x);
            if (added) {
                parent.put(x, v);
                current.addLast(order.get(x));
            }
            backtrack(x, edges, order, visited, parent, current);
            if (added) {
                visited.remove(x);
                parent.remove(x);
                current.pollLast();
            }
        }
    }

    private boolean isLess(LinkedList<Integer> current, List<Integer> result) {
        Iterator<Integer> first = current.iterator();
        Iterator<Integer> second = result.iterator();
        while (first.hasNext()) {
            int fs = first.next();
            int sc = second.next();
            if (fs < sc) {
                return true;
            }
            if (fs > sc) {
                return false;
            }
        }
        return true;
    }

    public void run() {
        try {
            in = new FastScanner(new FileInputStream("c-small-attempt0.in"));
            out = new PrintWriter(new FileOutputStream("c-small.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }


        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new C().run();
    }
}