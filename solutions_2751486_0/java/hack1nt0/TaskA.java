import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TaskA {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("TaskA.in")));
        PrintWriter out = new PrintWriter(new FileOutputStream("TaskA.out"));
//        PrintWriter out = new PrintWriter(System.out);
        int T = Integer.valueOf(in.readLine());
        for (int i = 1; i <= T; ++i) {
            TaskA task = new TaskA();
            task.solve(i, in, out);
        }
        out.close();
    }

    public void solve(int testNumber, BufferedReader in, PrintWriter out) throws IOException {
        out.print("Case #" + testNumber + ": ");
        StringTokenizer tokenizer = new StringTokenizer(in.readLine());
        char[] name = tokenizer.nextToken().toCharArray();
        int n = Integer.valueOf(tokenizer.nextToken());
        long ans = 0;
        boolean first = true;
        for(int i = 0, cnt = 0, pre = -1; i < name.length; ++i){
            if(vomer(name[i])) {
                if(cnt >= n) {
                    first = false;
                    pre = i - 1;
                }
                cnt = 0;
            }
            else if(cnt < n) cnt++;
            if(cnt >= n) {
                long right = name.length - i;
                long left = i - n - pre + n - 1 + 1;
                if(first){
                    left = i - n + 1 + 1;
                }
                if(i - n < 0 || i - n >= 0 && !vomer(name[i - n]))
                    left = 1;
                ans += left * right;
            }
        }

        out.println(ans);
    }

    private boolean vomer(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }

}
