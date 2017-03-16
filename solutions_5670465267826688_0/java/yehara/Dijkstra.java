package gcj2015.qual;

import java.io.*;
import java.util.Scanner;

public class Dijkstra {

    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2015/qual/C-small";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        //out = new PrintWriter(System.out);
        for (int cc = 1; cc <= count; cc++) {
            out.print("Case #" + cc + ": ");
            int l = s.nextInt();
            long X = s.nextLong();
            String str = s.next();
            String res = solve(l, X, str);
            out.print(res);
            out.println();
        }
        out.close();
    }

    static String solve(int l, long X, String s) {
        StringBuffer sb = new StringBuffer();
        if(X > 16) {
            X %= 4;
            X += 8;
        }
        int x = (int) X;
        int n = l * x;
        Q mult = new Q(0);
        boolean fi = false;
        boolean fj = false;
        for(int i=0; i<n; i++) {
            mult = mult.mult(Q.valueOf(s.charAt(i % l)));
            if(mult.v == 1) {
                fi = true;
            } else if (mult.v == 3 && fi) {
                fj = true;
            }
        }
        return (mult.v == 4 && fi && fj)?"YES":"NO";
    }
    static class Q {
        public int v;
        static String[] map = {"1", "i", "j", "k", "-1", "-i", "-j", "-k"};


        static Q valueOf(char c) {
            return Q.valueOf(Character.toString(c));
        }
        static Q valueOf(String str) {
            for(int i=0; i<8; i++) {
                if(map[i].equals(str)) {
                    return new Q(i);
                }
            }
            return null;
        }

        public Q(int v) {
            this.v = v;
        }

        static int[][] mmap = {
                {0, 1, 2, 3, 4, 5, 6, 7},
                {1, 4, 3, 6, 5, 0, 7, 2},
                {2, 7, 4, 1, 6, 3, 0, 5},
                {3, 2, 5, 4, 7, 6, 1, 0},
                {4, 5, 6, 7, 0, 1, 2, 3},
                {5, 0, 7, 2, 1, 4, 3, 6},
                {6, 3, 0, 5, 2, 7, 4, 1},
                {7, 6, 1, 0, 3, 2, 5, 4}
        };

        public Q mult(Q a) {
            return new Q(mmap[v][a.v]);
        }

        public Q pow(long p) {
            p %= 4;
            switch((int)p) {
                case 0: return new Q(0);
                case 1: return new Q(v);
                case 2: return new Q(mmap[v][v]);
                case 3: return new Q(mmap[mmap[v][v]][v]);
            }
            return null;
        }
    }



}
