package gcj2016.r1;

import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class Slides {
    
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2016/r1/B-small";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        //out = new PrintWriter(System.out);
        for (int cc = 1; cc <= count; cc++) {
            out.print("Case #" + cc + ": ");
            solve(s.nextInt(), s.nextInt());
            //out.println();
        }
        out.close();
    }

    static void solve(int b, int m) {
        int bits = b * (b - 1) / 2;
        int[] si = new int[b];
        for(int i = 1 ; i < b ; i++) {
            si[i] = si[i-1] + b - i;
        }
        int n = 1<<bits;
        for(int i=0; i<n; i++) {
            boolean[][] a = new boolean[b][b];
            int[] r = new int[b];
            r[0] = 1;
            int ind = 0;
            for(int j=0; j<b-1; j++) {
                for(int k=j+1; k<b; k++) {
                    if((i>>ind) % 2 == 1) {
                        a[j][k] = true;
                        r[k] += r[j];
                    }
                    ind++;
                }
            }
            if(r[b-1] == m) {
                out.println("POSSIBLE");
                for(int j=0; j<b; j++) {
                    for(int k=0; k<b; k++) {
                        out.print(a[j][k]?"1":"0");
                    }
                    out.println();
                }
                return;
            }
        }
        out.println("IMPOSSIBLE");
        return;
    }

}
