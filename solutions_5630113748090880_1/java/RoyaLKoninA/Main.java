import java.io.*;
import java.math.BigInteger;
import java.util.*;

/**
 * Created with IntelliJ IDEA.
 * User: olymp
 * Date: 13.09.15
 * Time: 11:00
 * To change this template use File | Settings | File Templates.
 */
public class Main {
    static BufferedReader in = null;
    static PrintWriter out = null;
    static StringTokenizer st = new StringTokenizer("");

    public static void main(String[] args) {
        try {
            in = new BufferedReader(new FileReader("B-large.in"));
            out = new PrintWriter(new FileWriter("output.txt"));
            solve();

            out.close();
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static String readString() {
        while (!st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(in.readLine());
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    public static int readInt() {
        return Integer.parseInt(readString());
    }

    public static long readLong() {
        return Long.parseLong(readString());
    }

    public static double readDouble() {
        return Double.parseDouble(readString());
    }

    public static class Pair implements Comparable<Pair> {
        public int x, y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Pair o) {
            if (Integer.compare(this.x, o.x) != 0) return Integer.compare(this.x, o.x);
            else return Integer.compare(this.y, o.y);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pair pair = (Pair) o;

            if (x != pair.x) return false;
            return y == pair.y;

        }

        @Override
        public int hashCode() {
            int result = x;
            result = 1000000 * result + y;
            return result;
        }
    }

    public static int phi(int n) {
        int result = n;
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0) {
                while (n % i == 0)
                    n /= i;
                result -= result / i;
            }
        if (n > 1)
            result -= result / n;
        return result;
    }

    public static long binPow(int x, long value) {
        if (x < 1) return 1;
        if (x == 1) return value;
        if (x % 2 == 0) {
            long t = binPow(x / 2, value);
            return t * t;
        }
        return value * binPow(x - 1, value);
    }


    static void solve() throws IOException {
        int t = readInt();
        for (int i = 0; i < t; i++) {
            out.print("Case #" + (i + 1) + ": ");

            int n = readInt();
            int[][] a = new int[2 * n - 1][n];
            for (int j = 0; j < 2 * n - 1; j++) {
                for (int k = 0; k < n; k++) {
                    a[j][k] = readInt();
                }
            }
            Pair[] mins = new Pair[n];
            int badLine = 0;
            int[] ans = new int[n];
            int p = 0;
            boolean[] used = new boolean[2 * n - 1];
            Arrays.fill(used, false);
            for (int k = 0; k < n; k++) { //номер символа
                int min = 1000000;
                int count = 0;
                int index1 = 0;
                int index2 = 0;
                int j = 0;
                for (; j < 2 * n - 1; j++) { //номер строчки
                    if (min > a[j][k] && !used[j]) {
                        min = a[j][k];
                        count = 1;
                        index1 = j;
                    } else if (min == a[j][k] && !used[j]) {
                        count++;
                        index2 = j;
                    }
                }
                if (count == 1) {
                    badLine = k;
                    ans[k] = min;
                    p = index1;
                    used[index1] = true;
                    continue;
                }
                used[index1] = true;
                used[index2] = true;
                Pair temp = new Pair(index1, index2);
                mins[k] = temp;
            }
            for (int j = 0; j < n; j++) {
                if (mins[j] != null) {
                    int x = a[p][j];
                    if (a[mins[j].x][badLine] == x) {
                        ans[j] = a[mins[j].y][badLine];
                    } else ans[j] = a[mins[j].x][badLine];
                }
            }
            for (int j = 0; j < n; j++) {
                out.print(ans[j] + " ");
            }
            out.println();

        }
    }
}







