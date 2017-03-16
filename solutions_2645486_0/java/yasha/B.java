import java.io.*;
import java.math.BigDecimal;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class B {

    private static List<Integer>[] m;
    private static long e;
    private static long r;
    private static long[] values;
    private static Map<Long, Long>[] c;

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("b.in")));
        PrintStream out = new PrintStream(new FileOutputStream("b.out"));
        long testCaseNumber = readInt(in);
        for (int cas = 0; cas < testCaseNumber; cas++) {
            String[] d = in.readLine().split(" ");
            e = Long.parseLong(d[0]);
            r = Long.parseLong(d[1]);
            d = in.readLine().split(" ");
            values = new long[d.length];
            c = new Map[values.length];
            for (int i = 0; i < values.length; i++) {
                values[i] = Long.parseLong(d[i]);
                c[i] = new HashMap<Long, Long>();
            }

            out.print("Case #" + (cas + 1) + ": ");
            out.print(process(0, e));
            out.println();
        }

        out.flush();
        out.close();
    }

    static long process(int pos, long energy) {
        if (energy > e) {
            energy = e;
        }
        if (pos >= values.length) {
            return 0;
        }
        if (c[pos].containsKey(energy)) {
            return c[pos].get(energy);
        }

        long ans = 0;

        for (int i = 0; i <= energy; i++) {
            long next = i * values[pos] + process(pos + 1, energy - i + r);
            if (next > ans) {
                ans = next;
            }
        }

        c[pos].put(energy, ans);
        return ans;
    }


    private static long readInt(BufferedReader in) {
        try {
            return Long.parseLong(in.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
