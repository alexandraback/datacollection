import java.io.*;
import java.util.*;

public class Main2 {
    public static void main(String args[]) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line = stdin.readLine();
        int T = Integer.parseInt(line);
        
        for (int t = 1; t <= T; t++) {
            line = stdin.readLine();
            String[] prms = line.split(" ");
            
            int k = Integer.parseInt(prms[0]);
            int c = Integer.parseInt(prms[1]);
            int s = Integer.parseInt(prms[2]);
            
            boolean f = true;
            long[] ans = new long[s];
            long cnt = 0;
            int r = 0;
            while (true) {
                long pos = cnt;
                for (int i = 0; i < c-1; i++) {
                    if (cnt < k-1) {
                        cnt++;
                    }
                    pos = k * pos + cnt;
                }
                ans[r++] = pos + 1;
                if (r == s || cnt >= k-1) {
                    if (cnt < k-1) f = false;
                    break;
                }
                cnt++;
            }
            
            System.out.printf("Case #%d:", t);
            if (!f) {
                System.out.print(" IMPOSSIBLE");
            } else {
                int d = 0;
                boolean[] a = new boolean[k];
                for (int i = 0; i < r; i++) {
                    System.out.printf(" %d", ans[i]);
                }
                /*
                for (int i = 0; i < r; i++) {
                    long x = ans[i] - 1;
                    while (true) {
                        int p = (int)(x%k);
                        if (!a[p]) {
                            a[p] = true;
                            d++;
                        }
                        if (x == 0) break;
                        if (k == 1) break;
                        x /= k;
                    }
                }
                if (d == k) {
                    System.out.print(" OK");
                } else {
                    System.out.print(" NG :");
                    for (int i = 0; i < k; i++) {
                        if (!a[i]) {
                            System.out.print(" "+i);
                        }
                    }
                }
                */
            }
            System.out.println();
        }
    }
}
