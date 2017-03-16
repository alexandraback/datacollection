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
            in = new BufferedReader(new FileReader("A-large (1).in"));
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
            char[] a = readString().toCharArray();
            char first = 'A'-1;
            char last = 'A'-1;
            StringBuilder s = new StringBuilder("");
            for (int j = 0; j < a.length; j++) {
                if(a[j]>=first){
                    s = s.insert(0,a[j]);
                    first = a[j];
                    if(j==1)last=a[j];
                } else {
                    s = s.append(a[j]);
                    last = a[j];
                }
            }
            out.println(s.toString());
        }
    }
}







