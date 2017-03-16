package cjm13.r1b;

import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class ProbA {
    private static Scanner sc;
    private static BufferedWriter bw;

    public static void main(String[] args) throws Exception {
        sc = new Scanner(new FileInputStream("input/cjm13/r1aprac/A-small-attempt2.in"));
        bw = new BufferedWriter(new FileWriter("output/cjm13/A-small-attempt2.out"));
//        sc = new Scanner(System.in);
//        bw = new BufferedWriter(new PrintWriter(System.out));

        int T = sc.nextInt();

        for (int l = 1; l <= T; l++) {
            bw.write("Case #" + l + ": ");
            solve();
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }

    private static void solve() throws IOException {
        long m = sc.nextLong();
        int n = sc.nextInt();
        long a[] = new long[n];
        long c = 0;
        long res =0 ;
        long nm = m;

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }

        Arrays.sort(a);

        if(m==1) {
            bw.write(n + "");
            return;
        }


        for (int i = 0; i < n; i++) {

            if (m <= a[i]) {
                while(m <= a[i]){
                    m += m-1;
                    c++;
                }
                i--;
            } else {
                m += a[i];
            }
        }

        if(c>n) {
            res = n;
        } else {
            res = c;
        }

        c=0; m=nm;

        for (int i = 0; i < n; i++) {

            if (m <= a[i]) {
                long t = m + m - 1;
                if (t <= a[i]) {
                    c++;
                } else {
                    c++;
                    m = t;
                    i--;
                }
            } else {
                m += a[i];
            }
        }

        if(c<res)
            res = c;

        bw.write(res + "");
    }
}