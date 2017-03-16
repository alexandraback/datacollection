import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line = stdin.readLine();
        int T = Integer.parseInt(line);
        
        for (int t = 1; t <= T; t++) {
            line = stdin.readLine();
            int n = Integer.parseInt(line);
            if (n == 0) {
                System.out.printf("Case #%d: INSOMNIA\n", t);
            } else {
                boolean[] f = new boolean[10];
                int cnt = 0;
                int m = n;
                while (true) {
                    int l = m;
                    while (l > 0) {
                        int v = l % 10;
                        if (!f[v]) {
                            f[v] = true;
                            cnt++;
                        }
                        l /= 10;
                    }
                    if (cnt == 10) break;
                    m += n;
                }
                System.out.printf("Case #%d: %d\n", t, m);
            }
        }
    }
}
