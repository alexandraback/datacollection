package gcj2015.qual;

import java.io.*;
import java.util.Scanner;

public class StandingOvation {

    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2015/qual/A-large";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        //out = new PrintWriter(System.out);
        for (int i = 1; i <= count; i++) {
            out.print("Case #" + i + ": ");
            int n = s.nextInt();
            int[] a = new int[n+1];
            String str = s.next();
            for(int j=0; j<=n; j++) {
                a[j] = str.charAt(j) - '0';
            }
            int res = solve(n, a);
            out.print(res);
            out.println();
        }
        out.close();
    }

    static int solve(int n, int[] a) {
        int res = 0;
        int s = 0;
        for(int i=0; i<=n; i++) {
            if(s<i) {
                res += i-s;
                s = i;
            }
            s += a[i];
        }
        return res;
    }

}
