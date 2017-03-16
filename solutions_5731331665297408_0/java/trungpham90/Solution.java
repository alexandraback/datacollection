
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.StringTokenizer;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Trung Pham
 */
public class Solution {

    public static long Mod = 1000000007;
    public static String result;
    public static int[] x = {0, 0, 1, -1};
    public static int[] y = {1, -1, 0, 0};

    public static void main(String[] args) throws FileNotFoundException {
        PrintWriter out = new PrintWriter(new FileOutputStream(new File("output.txt")));
        //PrintWriter out = new PrintWriter(System.out);
        Scanner in = new Scanner();

        int t = in.nextInt();
        //System.out.println(t);
        for (int z = 0; z < t; z++) {
            // System.out.println("HE HE");
            int n = in.nextInt();
            int m = in.nextInt();
            String[] zip = new String[n];
            for (int i = 0; i < n; i++) {
                zip[i] = in.next();
            }
            boolean[][] map = new boolean[n][n];
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                map[a][b] = true;
                map[b][a] = true;
            }
            result = null;
            for (int i = 0; i < n; i++) {
                boolean[] vis = new boolean[n];
                vis[i] = true;
                vis(i, vis, new boolean[n][n], map, zip[i], zip);
            }
            out.println("Case #" + (z + 1) + ": " + result);

        }
        out.close();
    }

    public static void vis(int node, boolean[] vis, boolean[][] res, boolean[][] map, String cur, String[] zip) {
        if (result != null && cur.length() > result.length()) {
            return;
        }
        // System.out.println(node + " " + cur);
        boolean ok = true;
        for (int i = 0; i < res.length && ok; i++) {
            for (int j = 0; j < res.length; j++) {
                if (res[i][j]) {
                    ok = false;
                    break;
                }
            }
        }
        for (int i = 0; i < vis.length; i++) {
            if (!vis[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            if (result == null) {
                result = cur;
            } else if (result.length() > cur.length()) {
                result = cur;
            } else if (result.length() == cur.length()) {
                //System.out.println(result + " " + cur);
                if (result.compareTo(cur) > 0) {
                    result = cur;
                }
            }
            return;
        }

        for (int i = 0; i < map[node].length; i++) {
            if (!vis[i] && map[node][i]) {
                vis[i] = true;
                res[i][node] = true;
                vis(i, vis, res, map, cur + zip[i], zip);
                vis[i] = false;
                res[i][node] = false;
            }
        }
        for (int i = 0; i < res.length; i++) {
            if (res[node][i]) {
                res[node][i] = false;
                vis(i, vis, res, map, cur, zip);
                res[node][i] = true;
            }
        }


    }

    public static class Pair {

        int x, y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int hashCode() {
            int hash = 7;
            hash = 37 * hash + this.x;
            hash = 37 * hash + this.y;
            return hash;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == null) {
                return false;
            }
            if (getClass() != obj.getClass()) {
                return false;
            }
            final Pair other = (Pair) obj;
            if (this.x != other.x) {
                return false;
            }
            if (this.y != other.y) {
                return false;
            }
            return true;
        }
    }

    public static class Count {

        char a;
        int c;

        public Count(char a, int c) {
            this.a = a;
            this.c = c;
        }
    }

    public static long pow(long a, int b) {
        if (b == 0) {
            return 1;
        }
        long val = pow(a, b / 2);
        if (b % 2 == 0) {
            return val * val;
        }
        return val * val * a;
    }

    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static class Scanner {

        BufferedReader br;
        StringTokenizer st;

        public Scanner() throws FileNotFoundException {
            //System.setOut(new PrintStream(new BufferedOutputStream(System.out), true));
            //br = new BufferedReader(new InputStreamReader(System.in));
            br = new BufferedReader(new FileReader(new File("C-small-attempt0.in")));
        }

        public String next() {


            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                    throw new RuntimeException();
                }
            }
            return st.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            st = null;
            try {
                return br.readLine();
            } catch (Exception e) {
                throw new RuntimeException();
            }
        }

        public boolean endLine() {
            try {
                String next = br.readLine();
                while (next != null && next.trim().isEmpty()) {
                    next = br.readLine();
                }
                if (next == null) {
                    return true;
                }
                st = new StringTokenizer(next);
                return st.hasMoreTokens();
            } catch (Exception e) {
                throw new RuntimeException();
            }
        }
    }
}
