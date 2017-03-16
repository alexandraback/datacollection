import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.TreeMap;

public class B2C {
    static final int LIMIT = 1000;

    static class Pair implements Comparable<Pair> {

        public final int x;
        public final int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Pair o) {
            if (this.x != o.x) return this.x - o.x;
            return this.y - o.y;
        }
    }

    static TreeMap<Pair, Integer> mp = new TreeMap<Pair, Integer>();

    public static void main(String... args) throws FileNotFoundException {
        String name = "B-small-attempt2";
        System.setIn(new FileInputStream(name + ".in"));
        System.setOut(new PrintStream(new FileOutputStream(name + ".out")));
        prepareMap();
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int ti = 0; ti < t; ti++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            StringBuilder sb = solve(x, y);
            System.out.println("Case #" + (ti + 1) + ": " + sb.toString());
        }
    }

    private static void prepareMap() {
        long start = System.currentTimeMillis();
        Pair key = new Pair(0, 0);
        Queue<Pair> p = new LinkedList<Pair>();
        p.add(key);
        mp.put(key, 0);
        while (!p.isEmpty()) {
            Pair poll = p.poll();
            int v = mp.get(poll) + 1;
            add(poll.x + v,     poll.y,     v, p);
            add(poll.x - v,     poll.y,     v, p);
            add(poll.x,         poll.y + v, v, p);
            add(poll.x,         poll.y - v, v, p);
        }

//        System.out.println("Ready: " + (System.currentTimeMillis() - start) + " ms");
    }

    private static void add(int x, int y, int v, Queue<Pair> p) {
        Pair keyAdd = new Pair(Math.abs(x), Math.abs(y));
        if (keyAdd.x > LIMIT || keyAdd.y > LIMIT)
            return;
        if (!mp.containsKey(keyAdd)) {
            mp.put(keyAdd, v);
            p.add(keyAdd);
        }
    }

    private static StringBuilder solve(int x, int y) {
        StringBuilder sb = new StringBuilder();
        while (x != 0 || y != 0) {
            Integer val = mp.get(new Pair(Math.abs(x), Math.abs(y)));
            {
                Pair k1 = new Pair(Math.abs(x + val), Math.abs(y));
                if (mp.containsKey(k1) && mp.get(k1) == val - 1) {
                    sb.append("W");
                    x += val;
                    continue;
                }
            }
            {
                Pair k2 = new Pair(Math.abs(x - val), Math.abs(y));
                if (mp.containsKey(k2) && mp.get(k2) == val - 1) {
                    sb.append("E");
                    x -= val;
                    continue;
                }
            }
            {
                Pair k3 = new Pair(Math.abs(x), Math.abs(y + val));
                if (mp.containsKey(k3) && mp.get(k3) == val - 1) {
                    sb.append("S");
                    y += val;
                    continue;
                }
            }
            {
                Pair k4 = new Pair(Math.abs(x), Math.abs(y - val));
                if (mp.containsKey(k4) && mp.get(k4) == val - 1) {
                    sb.append("N");
                    y -= val;
                    continue;
                }
            }
            throw new RuntimeException("Not reacheable");
        }
        return sb.reverse();
    }
}
