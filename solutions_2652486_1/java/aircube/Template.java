import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

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
    private Random random = new Random(374829374);

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
        for (int iter=0;iter<tc;++iter) {
            int R=nextInt();
            int N=nextInt();
            int M=nextInt();
            int K=nextInt();
            for (int test = 0; test < R; ++test) {
                prepareBrute(N, M, K);
            }
        }
    }

    ArrayList<int[]> availableSets = new ArrayList<int[]>();

    int[] stack = new int[20];
    int N;
    int M;
    int K;
    final int BUBEN = 10000;
    int enter = 0;
    void go (int pos, int last, int cnt, long  [] product) {
        if (availableSets.size() >= BUBEN)
            return;
        if (pos == N) {
            ++enter;
            for (long x : product)
                if (x != 1)
                    return;
            int[] x = new int[N];
            for (int i = 0; i < N; ++i)
                x[i] = stack[i];
            availableSets.add(x);
        } else {
            ArrayList<Integer> perm = new ArrayList<Integer>();
            for (int i = 2; i <= M; ++i)
                perm.add(i);
            Collections.shuffle(perm, random);
            ArrayList<Integer> tmp = new ArrayList<Integer>();
            for (int next : perm) {
                if (next < last)
                    continue;
                boolean atLeastOne = false;
                for (long x : product)
                    if (x % next == 0)
                        atLeastOne = true;
                if (!atLeastOne) {
                    tmp.add(next);
                    continue;
                }
                long[] nextProduct = new long[product.length];
                for (int j = 0; j < product.length; ++j)
                    nextProduct[j] = (product[j] % next == 0 ? product[j] / next : product[j]);
                stack[pos] = next;
                go(pos + 1, next, cnt, nextProduct);
            }
            if (cnt > 0 && tmp.size() > 0) {
                for (int x : tmp) {
                    if (x < last)
                        continue;
                    long[] nextProduct = new long[product.length];
                    for (int j = 0; j < product.length; ++j)
                        nextProduct[j] = (product[j] % x == 0 ? product[j] / x : product[j]);
                    stack[pos] = x;
                    go(pos + 1, x, cnt - 1, nextProduct);
                }
            }
        }
    }
    void prepareBrute(int N, int M, int K) throws IOException{
        availableSets.clear();
        long [] product = new long[K];
        for (int i =0 ; i < K; ++i) {
            product[i] = nextLong();
        }
        this.N = N;
        this.M = M;
        this.K = K;
        go(0, -1, 1, product);
        if (availableSets.size() == 0)   {
            for (int i=0;i<N; ++i)
                writer.print(random.nextInt(M-2)+2);
            writer.print("\n");
            return;
        }
        int[] x = availableSets.get(random.nextInt(availableSets.size()));
        ArrayList<Integer> dd=new ArrayList<Integer>();
        for (int y:x)
        dd.add(y);
        Collections.shuffle(dd, random);
        for (int i:dd)
            writer.print(i);
        writer.print("\n");
    }




    private int nextInt() throws IOException {
        String t=next();
        try{
        return Integer.parseInt(t);
        } catch (Exception e) {
            int dd=1;
        }
        return -1;
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