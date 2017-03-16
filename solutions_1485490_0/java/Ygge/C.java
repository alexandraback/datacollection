import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class C {

    private static final String FILE_NAME = "C-small-attempt2";

    private static Map<LongPair, Long> dp;

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
        BufferedWriter out = new BufferedWriter(new FileWriter(FILE_NAME + ".out"));

        int t = Integer.parseInt(in.readLine());
        for (int c = 1; c <= t; ++c) {
            String[] split = in.readLine().split(" ");
            int n = Integer.parseInt(split[0]);
            int m = Integer.parseInt(split[1]);
            List<Long> first = createFromRow(in.readLine(), 2 * n);
            List<Long> second = createFromRow(in.readLine(), 2 * m);
            dp = new HashMap<LongPair, Long>();
            long a = check(first, second, false);
            long b = check(first, second, true);
            String s = String.format("Case #%d: %d", c, a > b ? a : b);
            System.out.println(s);
            out.write(s);
            out.write("\n");
        }
        out.close();
    }

    private static long check(List<Long> f, List<Long> s, boolean removeFirst) {
        if (f.isEmpty() || s.isEmpty()) {
            return 0;
        }
        LongPair longPair = createLongPair(f, s, removeFirst);
        if (dp.containsKey(longPair)) {
            return dp.get(longPair);
        }
        List<Long> first = new ArrayList<Long>(f);
        List<Long> second = new ArrayList<Long>(s);
        long ans = 0;
        if (first.get(1).equals(second.get(1))) {
            long use = Math.min(first.get(0), second.get(0));
            ans += use;
            if (first.get(0).equals(use)) {
                first.remove(1);
                first.remove(0);
            } else {
                first.set(0, first.get(0) - use);
            }
            if (second.get(0).equals(use)) {
                second.remove(1);
                second.remove(0);
            } else {
                second.set(0, second.get(0) - use);
            }
        } else if (removeFirst) {
            first.remove(1);
            first.remove(0);
        } else {
            second.remove(1);
            second.remove(0);
        }
        long a = check(first, second, true);
        long b = check(first, second, false);
        ans += a > b ? a : b;
        dp.put(longPair, ans);
        return ans;
    }

    private static LongPair createLongPair(List<Long> f, List<Long> s, boolean removeFirst) {
        long a = 0;
        for (int i = 0; i < f.size(); i += 2) {
            a += f.get(i);
        }
        long b = 0;
        for (int i = 0; i < s.size(); i += 2) {
            b += s.get(i);
        }
        return new LongPair(a, b, removeFirst);
    }

    private static List<Long> createFromRow(String row, int max) {
        String[] split = row.split(" ");
        List<Long> res = new ArrayList<Long>();
        for (int i = 0; i < max; ++i) {
            res.add(Long.parseLong(split[i]));
        }
        return res;
    }

    private static class LongPair {
        long a;
        long b;
        private final boolean removeFirst;

        private LongPair(long a, long b, boolean removeFirst) {
            this.a = a;
            this.b = b;
            this.removeFirst = removeFirst;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            LongPair longPair = (LongPair) o;

            if (a != longPair.a) return false;
            if (b != longPair.b) return false;
            if (removeFirst != longPair.removeFirst) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = (int) (a ^ (a >>> 32));
            result = 31 * result + (int) (b ^ (b >>> 32));
            result = 31 * result + (removeFirst ? 1 : 0);
            return result;
        }
    }
}
