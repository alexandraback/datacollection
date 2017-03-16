import java.io.*;

/**
 * @auther chao
 * @date 16/4/9
 */
public class CodeJam2016RQD {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("/Users/chao/Downloads/D-small-attempt2.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        FileWriter out = new FileWriter("/Users/chao/Desktop/D-small-attempt2.txt");
        //PrintWriter out = new PrintWriter(System.out);;
        String[] s = in.readLine().split(" ");
        int T = Integer.parseInt(s[0]);

        for (int cases = 1; cases <= T; cases++) {
            out.write("Case #" + cases + ":");
            s = in.readLine().split(" ");
            int k = Integer.parseInt(s[0]);
            int c = Integer.parseInt(s[1]);
            int v = Integer.parseInt(s[2]);
            //out.write(k+" "+c+" "+v+"\n");
            c = Math.min(k, c);
            int ans = k - c + 1;
            if (ans > v) {
                out.write(" IMPOSSIBLE\n");
                continue;
            }
            long x = 1;
            for (int i = 2; i <= c; i++) {
                x =(x-1)*k+i;
            }
            out.write(" "+x);
            for (int i = c+1; i <=k; i++) {
                out.write(" "+i);
            }
            out.write("\n");
        }
        out.flush();
        out.close();
        in.close();
    }
}
