import java.io.*;
import java.math.*;
import java.util.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class A {

    void solve() {
        int n = inp.nextInt();
        //int n = 1000;
        ArrayList<Integer> E[] = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            int m = inp.nextInt();
            E[i] = new ArrayList<>();
            for (int j = 0; j < m; j++) {
                E[i].add(inp.nextInt()-1);
            }
            /*for (int j = i+1; j < n; j++) {
                E[i].add(j);
            }*/
        }
        LinkedList<Integer> Q;
        boolean found = false;
        for (int i = 0; i < n; i++) {
            Q = new LinkedList<>();
            Q.add(i);
            boolean D[] = new boolean[n];
            D[i] = true;
            while (!Q.isEmpty()) {
                int q = Q.poll();
                for (int v : E[q]) {
                    if (!D[v]) {
                        D[v] = true;
                        Q.add(v);
                    } else {
                        //found = true;
                        out.print("Yes");
                        return;
                    }
                }
            }
        }
        //if (found) out.print("Yes");
        //else
        out.print("No");
    }

    Scanner inp;
    PrintWriter out;
    static String _prob = "A";
    void run() throws Exception {
        inp = new Scanner(new File(_prob + ".in"));
        out = new PrintWriter(new File(_prob+".out"));
        int T = inp.nextInt();
        for (int I = 0; I < T; I++) {
            out.printf("Case #%d: ", I + 1);
            solve();
            out.println();
        }
        out.close();
    }
    public static void main(String[] args) throws Exception {
        _prob = args.length>0 ? args[0].replaceAll(".in", "") : "A";
        new A().run();
    }
    static <TA extends Comparable<TA>, TB extends Comparable<TB>> Pair<TA, TB> pair(TA a, TB b) {
        return new Pair<TA, TB>(a,b);
    }
    static class Pair<TA extends Comparable<TA>, TB extends Comparable<TB>> implements Comparable<Pair<TA,TB>> {
        TA a;
        TB b;
        public Pair(TA a, TB b) {
            this.a = a; this.b = b;
        }
        public int compareTo(Pair<TA, TB> o) {
            int r = a.compareTo(o.a);
            if (r!=0) return r;
            r = b.compareTo(o.b);
            return r;
        }
        public String toString() {
            return "("+a+","+b+")";
        }
    }
}
