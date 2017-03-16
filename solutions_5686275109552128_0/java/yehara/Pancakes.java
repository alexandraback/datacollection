package gcj2015.qual;

import java.io.*;
import java.util.Scanner;

public class Pancakes {

    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2015/qual/B-small";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        //out = new PrintWriter(System.out);
        for (int i = 1; i <= count; i++) {
            out.print("Case #" + i + ": ");
            int n = s.nextInt();
            int[] a = new int[n];
            for(int j=0; j<n; j++) {
                a[j] = s.nextInt();
            }
            int res = solve(n, a);
            out.print(res);
            out.println();
        }
        out.close();
    }

    static int solve(int n, int[] a) {
        int max = 0;
        for(int aa: a) {
            max = Math.max(max, aa);
        }
        int res = max;
        for(int i=1; i<=max; i++) {
            int s = i;
            for(int j=0; j<n; j++) {
                s += (a[j] - 1) / i;
            }
            res = Math.min(res, s);
        }

        return res;
    }

}
