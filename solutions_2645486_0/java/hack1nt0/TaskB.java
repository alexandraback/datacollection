import java.io.*;
import java.util.StringTokenizer;

/**
 * Created with IntelliJ IDEA.
 * User: DaiYang
 * Date: 13-4-13
 * Time: 下午5:29
 * To change this template use File | Settings | File Templates.
 */
public class TaskB {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("TaskB.in")));
        PrintWriter out = new PrintWriter(new FileOutputStream("TaskB.out"));
//        PrintWriter out = new PrintWriter(System.out);
        int T = Integer.valueOf(in.readLine());
        for(int i = 1; i <= T; ++i){
            TaskB task = new TaskB();
            task.solve(i, in, out);
        }
        out.close();
    }
    int[][] mem;
    int[] V;
    int E, R, N;
    public void solve(int testNumber, BufferedReader in, PrintWriter out) throws IOException {
        out.print("Case #" + testNumber + ": ");
        StringTokenizer tokenizer = new StringTokenizer(in.readLine());
        E = Integer.valueOf(tokenizer.nextToken());
        R = Integer.valueOf(tokenizer.nextToken());
        N = Integer.valueOf(tokenizer.nextToken());
        V = new int[N];
        tokenizer = new StringTokenizer(in.readLine());
        for(int i = 0; i < V.length; ++i) V[i] = Integer.valueOf(tokenizer.nextToken());
        mem = new int[N][10];
        int ans = dp(0, E);
        out.println(ans);
    }

    public int dp(int cur, int e){
        if(e > E) e = E;
        if(cur >= N) return 0;
        if(mem[cur][e] != 0) return mem[cur][e];
        int res = Integer.MIN_VALUE;
        for(int i = 0; i <= e; ++i)
            res = Math.max(i * V[cur] + dp(cur + 1, e - i + R), res);
        return mem[cur][e] = res;
    }
}
