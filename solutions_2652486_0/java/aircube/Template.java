import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Random;
import java.util.StringTokenizer;

/**
 * Created with IntelliJ IDEA.
 * User: 1
 * Date: 25.02.13
 * Time: 3:21
 * To change this template use File | Settings | File Templates.
 */
public class Template {
    private StringTokenizer tokenizer;
    private BufferedReader reader;
    private PrintWriter writer;

    public static void main(String[] args) throws IOException {
        new Template().run();
    }




    private void run() throws IOException {
//        reader = new BufferedReader(new InputStreamReader(System.in));
//        writer = new PrintWriter(System.out);
        reader = new BufferedReader(new FileReader("input.txt"));
        writer = new PrintWriter("output.txt");
        solve();
        writer.flush();
    }

    private void solve() throws IOException {
        int tc = nextInt();
        writer.print("Case #1:\n");
        Random random = new Random(298374);
        for (int iter = 1; iter <= tc; ++iter) {
            int r = nextInt();
            int N = nextInt();
            int M = nextInt();
            int K = nextInt();
            int[][] all = new int[4 * 4 * 4][N];
            int sz = 0;
            for (int i1 = 2; i1 <= M; ++i1)
                for (int i2 = 2; i2 <= M; ++i2)
                    for (int i3 = 2; i3 <= M; ++i3) {
                        all[sz][0] = i1;
                        all[sz][1] = i2;
                        all[sz][2] = i3;
                        ++sz;
                    }
            ArrayList<Integer> [] allSubsets = new ArrayList[4 * 4 * 4];
            for (int i = 0; i < allSubsets.length; ++i)
                allSubsets[i] = new ArrayList<Integer>();
            for (int i = 0; i < 4 * 4 * 4; ++i) {
                for (int j = 0; j < (1 << N); ++j) {
                    int product = 1;
                    for (int u = 0; u < N; ++u)
                        if (((j >> u) & 1) != 0)
                            product *= all[i][u];
                    allSubsets[i].add(product);
                }
            }
            for (int iterr = 0; iterr < r; ++iterr) {
                int[] products = new int[K];
                for (int i = 0; i < K; ++i) {
                    products[i] = nextInt();
                }
                ArrayList<Integer> available = new ArrayList<Integer>();
                for (int set = 0; set < 4 * 4 * 4; ++set) {
                    boolean containsAll = true;
                    for (int x : products) {
                        containsAll &= allSubsets[set].contains(x);
                        if (!containsAll)
                            break;
                    }
                    if (containsAll)
                        available.add(set);
                }
                if (available.size() == 0) {
                    throw new RuntimeException("не нашли множество");
                }
                int x = available.get(random.nextInt(available.size()));
                for (int z = 0; z < N; ++z)
                    writer.print(all[x][z]);
                writer.print("\n");
            }
        }
    }




    private int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
    private double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
    private long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    private String next() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine()) ;
        }
        return tokenizer.nextToken();
    }
}