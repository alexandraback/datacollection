package gcj2016.r1;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class FashionPolice {
    
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2016/r1/C-small";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        //out = new PrintWriter(System.out);
        for (int cc = 1; cc <= count; cc++) {
            out.print("Case #" + cc + ": ");
            solve(s.nextInt(), s.nextInt(), s.nextInt(), s.nextInt());
        }
        out.close();
    }

    static void solve(int j, int p, int s, int k) {
        int bits = j * p * s;
        int n = 1<<bits;
        int maxbc = 0;
        int maxi = -1;
        OUTER: for(int i=0; i<n; i++) {
            int bc = Integer.bitCount(i);
            if(bc <= maxbc) continue;
            int[][] jp = new int[j][p];
            int[][] ps = new int[p][s];
            int[][] sj = new int[s][j];
            for(int l=0; l<bits; l++) {
                if((i>>l)%2 == 1) {
                    int ji = l % j;
                    if(j == 1) { ji = 0; }
                    int pi = (l / j) % p;
                    if(p == 1) { pi = 0;}
                    int si = (l / j / p) % s;
                    if(s == 1) { si = 0;}
                    jp[ji][pi] ++;
                    ps[pi][si] ++;
                    sj[si][ji] ++;
                    if(jp[ji][pi] > k || ps[pi][si] > k || sj[si][ji] > k) {
                        continue OUTER;
                    }
                }
            }
            maxbc = bc;
            maxi = i;
        }

        out.println(maxbc);
        for(int l=0; l<bits; l++) {
            if((maxi>>l)%2 == 1) {
                int ji = l % j;
                int pi = (l / j) % p;
                int si = (l / j / p) % s;
                out.println((ji + 1) + " " + (pi + 1) + " " + (si + 1));
            }
        }
    }

}
