package CodeJam.codejam2014.round1c;

/**
 * Round 1C 2014 Problem A. Part Elf
 *
 * @author ashutosh
 */
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Quest1 {

    private static BufferedReader br;
    private static PrintWriter pw;
    private static String str[];
    private static long p, q;
    private static boolean DEBUG = false;

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new FileReader("in.txt"));
        pw = new PrintWriter("out.txt");

        int t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; i++) {
            if (i == 1) {
//                DEBUG = true;
            } else {
//                DEBUG = false;
            }
            input();
            pw.printf("Case #%d: ", i);
            pw.println(work());
        }

        pw.close();
    }

    private static void input() throws IOException {
        StringTokenizer data = new StringTokenizer(br.readLine(), "/");
        p = Long.parseLong(data.nextToken());
        q = Long.parseLong(data.nextToken());
    }

    private static String work() {
        long g = gcd(p, q);
        long n = p / g;
        long d = q / g;
        if (DEBUG) {
            System.out.printf("%d %d%n", n, d);
        }

        long bits = d & (d - 1);
        if (bits != 0) {
            return "impossible";
        }

        if (n * 2 >= d) {
            return "1";
        } else {
            int m = (int)Math.ceil(Math.log(((double) d) / n) / Math.log(2.0));
            return Integer.toString(m);
        }
    }

    private static long gcd(long p, long q) {
        long min = Math.min(p, q);
        long max = Math.max(p, q);
        long rem = max % min;
        if (min == 1) {
            return 1;
        } else if (rem == 0) {
            return min;
        } else {
            return gcd(min, rem);
        }
    }

//    private static class Fraction {
//
//        private int num;
//        private int den;
//
//        public static final Fraction ONE = new Fraction(1, 1),
//                ZERO = new Fraction(0, 1);
//
//        public Fraction(int num, int den) {
//            this.num = num;
//            this.den = den;
//        }
//
//        public Fraction reduce() {
//            int g = gcd(num, den);
//            num /= g;
//            den /= g;
//            return this;
//        }
//
//        private int gcd(int p, int q) {
//            int min = Math.min(p, q);
//            int max = Math.max(p, q);
//            int rem = max % min;
//            if (min == 1) {
//                return 1;
//            } else if (rem == 1) {
//                return min;
//            } else {
//                return gcd(min, rem);
//            }
//        }
//
//        public int getDen() {
//            return den;
//        }
//
//        public void setDen(int den) {
//            this.den = den;
//        }
//
//        public int getNum() {
//            return num;
//        }
//
//        public void setNum(int num) {
//            this.num = num;
//        }
//
//        public Fraction add(Fraction f) {
//            int d = this.den + f.den;
//            int n = this.den * f.num + f.den * this.num;
//            return new Fraction(n, d).reduce();
//        }
//
//        public double getDoubleRep() {
//            return ((double) num) / den;
//        }
//
//        public Fraction multiply(int m) {
//            int g = gcd(m, this.den);
//            return new Fraction(this.num * m / g, den / g);
//        }
//
//        public Fraction negative() {
//            return new Fraction(-this.num, this.den);
//        }
//
//        @Override
//        public boolean equals(Object obj) {
//            if (obj == null) {
//                return false;
//            }
//            if (getClass() != obj.getClass()) {
//                return false;
//            }
//            final Fraction other = (Fraction) obj;
//            if (this.num != other.num) {
//                return false;
//            }
//            if (this.den != other.den && this.num != 0) {
//                return false;
//            }
//            return true;
//        }
//    }

}
