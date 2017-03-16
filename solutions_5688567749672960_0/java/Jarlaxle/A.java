import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class A {
    private static final String inFile = "A-small-attempt0.in";
    private static final String outFile = "A-out.txt";

    public static void main(String args[]) throws IOException {
        Scanner scanner = new Scanner(new FileReader(inFile));
        int T = scanner.nextInt();
        FileWriter fw = new FileWriter(outFile);

        for (int t = 1; t <= T; ++t) {
            long n = scanner.nextLong();
            fw.write(String.format("Case #%d: %s\n", t, solve(n)));
        }
        fw.close();
    }

    static class Pos {
        public long x;
        public int steps;
        public Pos prev;

        public Pos(long x, int steps, Pos prev) {
            this.x = x;
            this.steps = steps;
            this.prev = prev;
        }

        public Pos next0() {
            return new Pos(x + 1, steps + 1, this);
        }

        public Pos next1() {
            long nx = 0, c = x;
            while (c > 0) {
                nx = nx * 10 + c % 10;
                c /= 10;
            }
            return new Pos(nx, steps + 1, this);
        }
    }


    private static long solve(long n) {
        Set<Long> vis = new HashSet<Long>();
        Queue<Pos> q = new LinkedList<Pos>();
        add(q, vis, new Pos(1, 1, null));

        while (true) {
            Pos curr = q.remove();
            if (curr.x == n) {
                long res = curr.steps;
                //while (curr.prev != null) {
                //    System.out.print(curr.x);
                //    System.out.print(" <- ");
                //    curr = curr.prev;
                //}
                //System.out.println();
                return res;
            }
            add(q, vis, curr.next0());
            add(q, vis, curr.next1());
        }
    }

    private static void add(Queue<Pos> q, Set<Long> vis, Pos p) {
        if (vis.contains(p.x)) return;
        vis.add(p.x);
        q.add(p);
    }
}
