import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Round 1C. Problem B.
 */
public class ProblemB {

    public static void main(String[] args) throws Exception {
        new ProblemB().run();
    }

    public static class Pair {
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;

            Pair pair = (Pair) o;

            if (x != pair.x) return false;
            if (y != pair.y) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            return result;
        }
    }

    private void run() throws Exception {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int testCount = in.nextInt();
        int maxL = 100;
        for (int test = 1; test <= testCount; test++) {
            int x = in.nextInt();
            int y = in.nextInt();
            Map<Pair, String> s = new HashMap<Pair, String>();
            s.put(new Pair(0, 0), "");
            int step = 0;
            do {
                step++;
                Map<Pair, String> ss = s;
                s = new HashMap<Pair, String>();
                for (Pair p : ss.keySet()) {
                    String val = ss.get(p);
                    if (Math.abs(p.x + step) <= maxL) {
                        s.put(new Pair(p.x + step, p.y), val + "E");
                    }
                    if (Math.abs(p.x - step) <= maxL) {
                        s.put(new Pair(p.x - step, p.y), val + "W");
                    }
                    if (Math.abs(p.y + step) <= maxL) {
                        s.put(new Pair(p.x, p.y + step), val + "N");
                    }
                    if (Math.abs(p.y - step) <= maxL) {
                        s.put(new Pair(p.x, p.y - step), val + "S");
                    }
                }
            } while (s.get(new Pair(x, y)) == null);

            out.print("Case #" + test + ": " + s.get(new Pair(x, y)));
            if (test < testCount) {
                out.println();
            }
        }

        in.close();
        out.close();
    }
}
