import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line = stdin.readLine();
        String[] prms;
        int T = Integer.parseInt(line);
        
        for (int t = 1; t <= T; t++) {
            line = stdin.readLine();
            int n = Integer.parseInt(line);
            
            long a1 = -1;
            long a2 = -1;
            long s1 = -1;
            long s2 = -1;
            if (n == 1) {
                line = stdin.readLine();
                prms = line.split(" ");
                int d = Integer.parseInt(prms[0]);
                int h = Integer.parseInt(prms[1]);
                int m = Integer.parseInt(prms[2]);
                a1 = (long)d;
                s1 = (long)m;
                if (h == 2) {
                    a2 = (long)d;
                    s2 = (long)(m+1);
                }
            } else {
                line = stdin.readLine();
                prms = line.split(" ");
                int d = Integer.parseInt(prms[0]);
                int h = Integer.parseInt(prms[1]);
                int m = Integer.parseInt(prms[2]);
                a1 = (long)d;
                s1 = (long)m;
                line = stdin.readLine();
                prms = line.split(" ");
                d = Integer.parseInt(prms[0]);
                h = Integer.parseInt(prms[1]);
                m = Integer.parseInt(prms[2]);
                a2 = (long)d;
                s2 = (long)m;
                if (s2 < s1) {
                    long tmp = a1;
                    a1 = a2;
                    a2 = tmp;
                    tmp = s1;
                    s1 = s2;
                    s2 = tmp;
                }
            }
            
            int ans = 0;
            if (a2 != -1 || s1 != s2) {
                if (s2*(360-a2) > s1*(720-a1)) ans = 1;
            }
            
            System.out.printf("Case #%d: %d\n", t, ans);
        }
    }
}
