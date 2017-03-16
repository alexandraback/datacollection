import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.StringTokenizer;

public class C implements Runnable {

    private static final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;

    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer tok = new StringTokenizer("");

    private void init() throws FileNotFoundException {
        Locale.setDefault(Locale.US);
        String fileName = "";
        if (ONLINE_JUDGE && fileName.isEmpty()) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else {
            if (fileName.isEmpty()) {
                in = new BufferedReader(new FileReader("input.txt"));
                out = new PrintWriter("output.txt");
            } else {
                in = new BufferedReader(new FileReader(fileName + ".in"));
                out = new PrintWriter(fileName + ".out");
            }
        }
    }

    String readString() {
        while (!tok.hasMoreTokens()) {
            try {
                tok = new StringTokenizer(in.readLine());
            } catch (Exception e) {
                return null;
            }
        }
        return tok.nextToken();
    }

    int readInt() {
        return Integer.parseInt(readString());
    }

    long readLong() {
        return Long.parseLong(readString());
    }

    double readDouble() {
        return Double.parseDouble(readString());
    }

    int[] readIntArray(int size) {
        int[] a = new int[size];
        for (int i = 0; i < size; i++) {
            a[i] = readInt();
        }
        return a;
    }

    public static void main(String[] args) {
        //new Thread(null, new _Solution(), "", 128 * (1L << 20)).start();
        new C().run();
    }

    long timeBegin, timeEnd;

    void time() {
        timeEnd = System.currentTimeMillis();
        System.err.println("Time = " + (timeEnd - timeBegin));
    }

    @Override
    public void run() {
        try {
            timeBegin = System.currentTimeMillis();
            init();
            solve();
            out.close();
            time();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }

    String caseNum(int number) {
        return "Case #" + number + ": ";
    }

    class Combination {
        int x, y, z;

        public Combination(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    boolean[][][] used;

    int j, p, s, k;
    int iterations = 0;

    int getNum(int x, int y, int z) {
        return 10000 * x + 100 * y + z;
    }

    List<Combination> bestAns = new ArrayList<>();

    void dfs(int x, int y, int z, int[] count, List<Combination> combinations) {
        used[x][y][z] = true;
        count[getNum(x, y, 0)]++;
        count[getNum(x, 0, z)]++;
        count[getNum(0, y, z)]++;
        combinations.add(new Combination(x + 1, y + 1, z + 1));


        if (bestAns.size() == 27 || iterations > 1000000) {
            return;
        }

        if (combinations.size() > bestAns.size()) {
            bestAns.clear();
            bestAns.addAll(combinations);
        }

        for (int toX = 0; toX < j; toX++) {
            for (int toY = 0; toY < p; toY++) {
                for (int toZ = 0; toZ < s; toZ++) {
                    iterations++;
                    if (!used[toX][toY][toZ]) {
                        if (count[getNum(toX, toY, 0)] < k && count[getNum(0, toY, toZ)] < k && count[getNum(toX, 0, toZ)] < k) {
                            dfs(toX, toY, toZ, count, combinations);
                        }
                    }
                }
            }
        }
        used[x][y][z] = false;
        count[getNum(x, y, 0)]--;
        count[getNum(x, 0, z)]--;
        count[getNum(0, y, z)]--;
        combinations.remove(combinations.get(combinations.size() - 1));
    }

    private void solve() {
        int T = readInt();
        for (int test = 1; test <= T; test++) {
            System.err.println(test);
            j = readInt();
            p = readInt();
            s = readInt();
            k = readInt();


            for (int toX = 0; toX < j; toX++) {
                for (int toY = 0; toY < p; toY++) {
                    for (int toZ = 0; toZ < s; toZ++) {
                        iterations = 0;
                        bestAns = new ArrayList<>();
                        used = new boolean[j][p][s];
                        dfs(toX, toY, toZ, new int[1000 * 1000], new ArrayList<>());
                    }
                }
            }

            out.println(caseNum(test) + bestAns.size());
            for (Combination c : bestAns) {
                out.println(c.x + " " + c.y + " " + c.z);
            }
        }
    }
}
