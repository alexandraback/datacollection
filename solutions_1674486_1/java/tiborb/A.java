import java.io.File;
import java.io.PrintWriter;
import java.util.*;

/**
 * Code Jam
 *
 * @author: Tibor Blenessy blenessy@gmail.com
 */
public class A {

//    static String FILE = "A-test";
//    static String FILE = "A-small-attempt0";
    static String FILE = "A-large";

    static Scanner sc;

    static PrintWriter out;

    public static void main(String[] args) throws Exception {

        sc = new Scanner(new File(FILE + ".in"));
        out = new PrintWriter(new File(FILE + ".out"));

        int t = sc.nextInt();


        for (int i = 0; i < t; i++) {
            Object result = solve();
            String format = String.format("Case #%d: %s\n", i + 1, String.valueOf(result));
            out.print(format);
            System.out.print(format);
        }

        sc.close();
        out.close();
    }

    static Object solve() {
        int n = sc.nextInt();
        Map<Integer, Clazz> g = new HashMap<Integer, Clazz>();
        for (int i = 0; i < n; i++) {
            Clazz c = new Clazz(i+1);
            g.put(c.idx, c);
            int m = sc.nextInt();
            for (int j = 0; j < m; j++) {
                c.e.add(sc.nextInt());
            }
        }
        Set<Integer> stack = new HashSet<Integer>();
        for (Clazz c : g.values()) {
            clear(g);
            stack.add(c.idx);
            while (!stack.isEmpty()) {
                Iterator<Integer> it = stack.iterator();
                Clazz current = g.get(it.next());
                it.remove();
                List<Integer> neighs = current.e;
                for (Integer i: neighs) {
                    Clazz neigh = g.get(i);
                    if (containsAny(neigh.parent, current.parent, current.idx)) {
                        return "Yes";
                    }
                    g.get(i).parent.add(current.idx);
                    g.get(i).parent.addAll(current.parent);
                }
                stack.addAll(neighs);
            }
        }
        return "No";
    }

    static boolean containsAny(Collection<Integer> c, Collection<Integer> t, Integer t2) {
        if (c.contains(t2)) {
            return true;
        }
        for (Integer i: t) {
            if (c.contains(i)) {
                return true;
            }
        }
        return false;
    }

    private static void clear(Map<Integer, Clazz> g) {
        for (Clazz c: g.values()) {
            c.parent.clear();
        }
    }

    static class Clazz {
        int idx;
        Set<Integer> parent = new HashSet<Integer>();
        List<Integer> e = new LinkedList<Integer>();

        Clazz(int idx) {
            this.idx = idx;
        }

        @Override
        public String toString() {
            return "Clazz{" +
                    "idx=" + idx +
                    ", parent=" + parent +
                    ", e=" + e +
                    '}';
        }
    }

}