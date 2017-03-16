import java.io.*;
import java.util.StringTokenizer;

/**
 * Created with IntelliJ IDEA.
 * User: DaiYang
 * Date: 13-4-13
 * Time: 下午11:49
 * To change this template use File | Settings | File Templates.
 */
public class TaskC {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("TaskC.in")));
        PrintWriter out = new PrintWriter(new FileOutputStream("TaskC.out"));
//        PrintWriter out = new PrintWriter(System.out);
        int T = Integer.valueOf(in.readLine());
        for (int i = 1; i <= T; ++i) {
            TaskC task = new TaskC();
            task.solve(i, in, out);
        }
        out.close();
    }

    public void solve(int testNumber, BufferedReader in, PrintWriter out) throws IOException {
        out.println("Case #" + testNumber + ": ");
        StringTokenizer tokenizer = new StringTokenizer(in.readLine());
        int R = Integer.valueOf(tokenizer.nextToken());
        int N = Integer.valueOf(tokenizer.nextToken());
        int M = Integer.valueOf(tokenizer.nextToken());
        int K = Integer.valueOf(tokenizer.nextToken());
        flagR:
        for (int r = 0; r < R; ++r) {
            int[] prods = new int[K];
            tokenizer = new StringTokenizer(in.readLine());
            for (int i = 0; i < prods.length; ++i) prods[i] = Integer.valueOf(tokenizer.nextToken());
            for (int d1 = 2; d1 <= M; ++d1)
                for (int d2 = 2; d2 <= M; ++d2)
                    for (int d3 = 2; d3 <= M; ++d3) {
                        boolean vis[] = new boolean[K];
                        int[] D = new int[]{d1, d2, d3};
                        for (int mask = 0; mask < (1 << N); ++mask) {
                            int product = 1;
                            for (int i = 0; i < N; ++i) if ((mask & (1 << i)) != 0) product *= D[i];
                            for(int i = 0; i < K; ++i ) if(prods[i] == product) vis[i] = true;
                        }
                        boolean find = true;
                        for(boolean e : vis) if(!e)find = false;
                        if(!find)continue;
                        for(int d : D) out.print(d);
                        out.println();
                        continue flagR;
                    }
        }
    }
}
