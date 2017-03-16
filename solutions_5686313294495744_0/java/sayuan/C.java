import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class C {

    // Disjoint Set
    public static class DS { // {{{
        int[] parent;
        int[] rank;
        public DS(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i=0;i<n ;i++) parent[i] = i;
        }
        int find(int x) {
            if (parent[x]==x) return x;
            return (parent[x] = find(parent[x]));
        }
        int union(int x, int y) {
            int xRoot = find(x);
            int yRoot = find(y);
            if (rank[xRoot]>rank[yRoot]) {
                parent[yRoot] = xRoot;
                return xRoot;
            } else if (xRoot!=yRoot) {
                parent[xRoot] = yRoot;
                if (rank[xRoot]==rank[yRoot]) {
                    rank[yRoot]++;
                }
            }
            return yRoot;
        }
    } // }}}

    void solve(int caseNum) {
        int n = in.nextInt();

        List<String> first = new ArrayList<>();
        List<String> second = new ArrayList<>();
        DS ds = new DS(n);

        for (int i=0; i<n; i++) {
            String f = in.next();
            String s = in.next();
            first.add(f);
            second.add(s);
        }

        for (int i=0; i<n; i++) {
            String f1 = first.get(i);
            String s1 = second.get(i);
            for (int j=i+1; j<n; j++) {
                String f2 = first.get(j);
                String s2 = second.get(j);
                if (f1.equals(f2) || s1.equals(s2)) {
                    ds.union(i, j);
                }
            }
        }

        Set<String>[] fset = new Set[n];
        Set<String>[] sset = new Set[n];
        for (int i=0; i<n; i++) {
            fset[i] = new HashSet();
            sset[i] = new HashSet();
        }

        for (int i=0; i<n; i++) {
            String f = first.get(i);
            String s = second.get(i);
            int r = ds.find(i);

            fset[r].add(f);
            sset[r].add(s);
        }

        int real = 0;
        for (int i=0; i<n; i++) {
            real += max(fset[i].size(), sset[i].size());
        }
        out.println(n-real);
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public C() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);
            solve(caseNum);
        }
    }
    public static void main(String[] args) throws Exception {
        new C();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
