package r1c;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by fatminmin on 5/8/16.
 */
public class C {
//    Scanner sc = new Scanner(System.in);
//    PrintWriter pw = new PrintWriter(System.out);
    Scanner sc = new Scanner(new File("r1c_tc/C-small-attempt1.in"));
    PrintWriter pw = new PrintWriter("r1c_tc/C-small-attempt1.out");
    public C() throws FileNotFoundException {
    }

    static class Node {
        int a, b, c;
        public Node(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        @Override
        public int hashCode() {
            return toString().hashCode();
        }

        @Override
        public boolean equals(Object o) {
            Node others = (Node) o;
            return a == others.a && b == others.b && c == others.c;
        }

        @Override
        public String toString() {
            return a + " " + b + " " + c;
        }
    }

    private boolean check(List<Node> sol, int d) {
        Map<Node, Integer> map = new HashMap<>();
        for(Node node : sol) {
            Node x = new Node(node.a, node.b, 0);
            Node y = new Node(node.a, 0, node.c);
            Node z = new Node(0, node.b, node.c);
            map.put(x, map.getOrDefault(x, 0) + 1);
            map.put(y, map.getOrDefault(y, 0) + 1);
            map.put(z, map.getOrDefault(z, 0) + 1);
            if(map.get(x) > d || map.get(y) > d || map.get(z) > d) return false;
        }
        return true;
    }
    private void solve() {
        int a, b, c, d;
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        d = sc.nextInt();
        List<Node> all = new ArrayList<>();
        for(int i = 1; i <= a; i++) {
            for(int j = 1; j <= b; j++) {
                for(int k = 1; k <= c; k++) {
                    all.add(new Node(i, j, k));
                }
            }
        }
        int n = all.size();
        List<Node> sol = new ArrayList<>();
        for(int i = (1 << n) - 1; i >= 0; i--) {
            int tmp = i;
            sol.clear();
            for(int j = 0; tmp > 0; j++) {
                if((tmp & 1) == 1) sol.add(all.get(j));
                tmp >>= 1;
            }
            if(check(sol, d)) break;
        }
        pw.println(sol.size());
        for(Node node : sol) {
            pw.println(node);
        }
    }

    public void run() {
//        Node x = new Node(0, 0, 1);
//        Set<Node> s = new HashSet<>();
//        s.add(new Node(0, 0, 1));
//        s.add(new Node(0, 0, 1));
//        System.out.println(s.size());
        int t = sc.nextInt();
        for(int cs = 1; cs <= t; cs++) {
            pw.print(String.format("Case #%d: ", cs));
            solve();
        }
        pw.flush();
    }

    public static void main(String[] args) throws FileNotFoundException {
        new C().run();
    }
}
