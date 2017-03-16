import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line = stdin.readLine();
        int T = Integer.parseInt(line);
        
        for (int t = 1; t <= T; t++) {
            System.out.printf("Case #%d:\n", t);
            
            line = stdin.readLine();
            String[] prms = line.split(" ");
            
            int n = Integer.parseInt(prms[0]);
            int j = Integer.parseInt(prms[1]);
            
            int v = 3;
            for (int i = 0; i < j; i++) {
                boolean[] f = new boolean[32];
                int x = v;
                int k = 0;
                while (x > 0) {
                    if (x % 2 == 1) {
                        f[k] = true;
                    }
                    x /= 2;
                    k++;
                }
                int[] y = new int[11];
                for (int l = 0; l < k; l++) {
                    f[n-k+l] = f[l];
                    if (f[l]) {
                        for (int m = 2; m <= 10; m++) {
                            y[m] += Math.pow(m, l);
                        }
                    }
                }
                
                for (int l = n-1; l >= 0; l--) {
                    if (f[l]) {
                        System.out.print("1");
                    } else {
                        System.out.print("0");
                    }
                }
                for (int m = 2; m <= 10; m++) {
                    System.out.print(" ");
                    System.out.print(y[m]);
                }
                System.out.println();
                
                v += 2;
            }
        }
    }
}
