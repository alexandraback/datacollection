import java.io.*;

/**
 * @auther chao
 * @date 16/4/9
 */
public class CodeJam2016RQ {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("/Users/chao/Downloads/A-large.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        FileWriter out = new FileWriter("/Users/chao/Desktop/A-large.txt");

        String[] s = in.readLine().split(" ");
        int T = Integer.parseInt(s[0]);

        for (int cases = 1; cases <= T; cases++) {
            s = in.readLine().split(" ");
            int n = Integer.parseInt(s[0]);
            int ans = getLast(n);
            if (ans < 0) {
                out.write("Case #"+cases+": INSOMNIA\n");
            } else {
                out.write("Case #"+cases+": "+ans+"\n");
            }
        }
        out.flush();
        out.close();
        in.close();
    }

    private static int getLast(int n) {
        if (n <= 0) {
            return -1;
        }
        boolean[] bitMap = new boolean[10];
        int cnt = 0;
        int x = 0;
        while (cnt < 10) {
            x+=n;
            int t = x;
            while (t > 0) {
                if (!bitMap[t%10]) {
                    bitMap[t%10] = true;
                    cnt++;
                }
                t/=10;
            }
        }
        return x;
    }
}
