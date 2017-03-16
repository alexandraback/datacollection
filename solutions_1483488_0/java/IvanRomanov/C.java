import java.io.*;
import java.util.*;

/**
 * @author Ivan Romanov
 */
public class C {

    private String solve() throws IOException {
        int a = nextInt();
        int b = nextInt();
        int ans = 0;
        for (int i = a; i < b; i++) {
            if (recycle.containsKey(i)) {
                for (int j : recycle.get(i)) {
                    if (j <= b) {
                        ans++;
                        // System.out.println(i + " " + j);
                    }
                }
            }
        }
        return "" + ans;
    }

    private Map<Integer, Set<Integer>> recycle = new HashMap<Integer, Set<Integer>>();

    private void prepare() {
        int mul = 1;
        int dig = 1;
        for (int x = 10; x <= 2000000; x++) {
            if (mul * 10 == x) {
                mul *= 10;
                dig++;
            }
            Set<Integer> recs = new HashSet<Integer>();
            int t = x;
            for (int i = 1; i < dig; i++) {
                int last = t % 10;
                t /= 10;
                t += last * mul;
                if (t > x) {
                    recs.add(t);
                }
            }
            if (!recs.isEmpty()) {
                recycle.put(x, recs);
            }
        }
    }

    private BufferedReader reader;

    private StringTokenizer tt = new StringTokenizer("");

    private String nextToken() throws IOException {
        while (!tt.hasMoreTokens()) {
            tt = new StringTokenizer(reader.readLine());
        }
        return tt.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private void run() throws IOException {
        String problem = "C-small-attempt0";
        reader = new BufferedReader(new FileReader(problem + ".in"));
        PrintWriter writer = new PrintWriter(new File(problem + ".out"));
        try {
            prepare();
            int cases = nextInt();
            int tc = 1;
            while (tc <= cases) {
                writer.print("Case #" + tc + ": ");
                writer.println(solve());
                tc++;
            }
        } finally {
            reader.close();
            writer.close();
        }
    }

    public static void main(String[] args) {
        try {
            new C().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}