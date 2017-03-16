import java.util.*;

public class Techno
{
    static class Edge {
        int u, v;
        Edge(int u, int v) {
            this.u = u;
            this.v = v;
        }
        @Override
        public String toString() {
            return u + "->" + v;
        }
    }

    @SuppressWarnings("unchecked")
    static void solve(int c, Scanner s) {
        int n = s.nextInt();
        Map<String, Integer> n2c = new HashMap<>();
        int nc = 0;
        List<Edge> E = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String f = s.next();
            String t = s.next();
            if (!n2c.containsKey(f))
                n2c.put(f, nc++);
            if (!n2c.containsKey(t))
                n2c.put(t, nc++);
            int u = n2c.get(f);
            int v = n2c.get(t);
            E.add(new Edge(u, v));
        }
        // System.out.println(E);
        List<Integer> [] adj = new List[nc];
        List<Integer> [] radj = new List[nc];
        for (int i = 0; i < nc; i++) {
            adj[i] = new ArrayList<Integer>();
            radj[i] = new ArrayList<Integer>();
        }

        final int [] in = new int[nc];
        final int [] out = new int[nc];
        Comparator<Edge> COMP = new Comparator<Edge>() {
            public int compare(Edge e1, Edge e2) {
                int k1 = Math.min(out[e1.u], in[e1.v]);
                int k2 = Math.min(out[e2.u], in[e2.v]);
                int r = Integer.compare(k2, k1);
                if (r != 0) return r;
                else return Integer.compare(System.identityHashCode(e1), System.identityHashCode(e2));
            }
        };

        PriorityQueue<Edge> EP = new PriorityQueue<Edge>(COMP);
        for (Edge e : E) {
            adj[e.u].add(e.v);
            radj[e.v].add(e.u);
            in[e.v]++;
            out[e.u]++;
            EP.add(e);
        }
        //System.err.println("G: " + Arrays.toString(adj));

        int answer = 0;
        while (true) {
            //System.err.println("edges left: " + EP);
            // can edge be removed?
            Edge e = EP.poll();
            if (!(out[e.u] > 1 && in[e.v] > 1))
                break;

            //System.err.println("removing: " + e + " left: " + EP.size());
            answer++;
            out[e.u]--;
            in[e.v]--;
            //System.err.println("in  " + Arrays.toString(in));
            //System.err.println("out " + Arrays.toString(out));

            // crap, let's just resort all edges. O(n^2), but n is only 1000
            PriorityQueue<Edge> EP2 = new PriorityQueue<Edge>(COMP);
            for (Edge _e : EP)
                EP2.offer(_e);

            EP = EP2;
        }

        System.out.printf("Case #%d: %d%n", c, answer);
    }

    public static void main(String []av) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        for (int c = 1; c <= T; c++) {
            solve(c, s);
        }
    }
}
