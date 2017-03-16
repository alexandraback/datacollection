import java.io.*;
import java.util.*;

public class b {
    final static int MAXP = 1010;
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int T = Integer.parseInt(in.readLine());
        for(int t = 1; t <= T; t++) {
            int n = Integer.parseInt(in.readLine());
            StringTokenizer st = new StringTokenizer(in.readLine());
            int v[] = new int[n];
            int best = 0;
            for(int i = 0; i < n; i++) {
                v[i] = Integer.parseInt(st.nextToken());
                best = Math.max(best, v[i]);
            }
            for(int q = 2; q < MAXP; q++) {
                int got = 0;
                for(int i = 0; i < n; i++)
                    got += (v[i] + q - 1)/q - 1;
                best = Math.min(best, got + q);
            }            
            out.format("Case #%d: %d\n", t, best);
        }
        out.close();
    }
};
