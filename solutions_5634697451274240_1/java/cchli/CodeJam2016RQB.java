import java.io.*;

/**
 * @auther chao
 * @date 16/4/9
 */
public class CodeJam2016RQB {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("/Users/chao/Downloads/B-large.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        FileWriter out = new FileWriter("/Users/chao/Desktop/B-large.txt");
        String[] s = in.readLine().split(" ");
        int T = Integer.parseInt(s[0]);

        for (int cases = 1; cases <= T; cases++) {
            String line = in.readLine();
            int ans =gao(line);
            out.write("Case #"+cases+": "+ans+"\n");
        }
        out.flush();
        out.close();
        in.close();
    }
    private static int gao(String s) {
        char c = s.charAt(0);
        int change = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != c) {
                change++;
            }
            c = s.charAt(i);
        }
        if (c == '-')   return change+1;
        else return change;
    }
}
