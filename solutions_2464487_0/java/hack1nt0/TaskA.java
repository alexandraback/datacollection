import java.io.*;
import java.util.StringTokenizer;

/**
 * Created with IntelliJ IDEA.
 * User: DaiYang
 * Date: 13-4-13
 * Time: 下午1:42
 * To change this template use File | Settings | File Templates.
 */
public class TaskA {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("TaskA.in")));
        PrintWriter out = new PrintWriter(new FileOutputStream("TaskA.out"));
//        PrintWriter out = new PrintWriter(System.out);
        int T = Integer.valueOf(in.readLine());
        for(int i = 1; i <= T; ++i){
           TaskA task = new TaskA();
           task.solve(i, in, out);
        }
        out.close();
    }
    public char[][] grid ;
    public void solve(int testNumber, BufferedReader in, PrintWriter out) throws IOException {
        out.print("Case #" + testNumber + ": ");
        StringTokenizer tokenizer = new StringTokenizer(in.readLine());
        double r = Double.valueOf(tokenizer.nextToken());
        double t = Double.valueOf(tokenizer.nextToken());
//        out.println(r + ", " + t);
//        out.println((1 - 2 * r + Math.sqrt((2 * r - 1) * (2 * r - 1) + 8 * t)) / 4);
//        out.println(Math.sqrt((2 * r - 1) * (2 * r - 1) + 8 * t) / 4);
        long ans = (long) Math.floor((1 - 2 * r + Math.sqrt((2 * r - 1) * (2 * r - 1) + 8 * t)) / 4);
        if(2L * ans * ans + (long)(2 * r - 1) * ans > (long)t) ans--;
        out.println(ans);
    }
}
