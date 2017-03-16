import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

/**
 *
 * Using java Operator Overloading found here: http://amelentev.github.io/java-oo/
 */
public class CodeJam2016Round1A {
    public static void main(String [] args) throws Exception {
        long start = System.currentTimeMillis();
        a();
//        b();
//        c();
//        d();

        long end = System.currentTimeMillis();

        System.out.printf("Took: %d(ms)\n", (end - start));
    }



    public static void a() throws Exception {
//        String questionName = "A-test";
        String questionName = "A-small-attempt0";
//        String questionName = "A-large";
        BufferedReader r = getBufferedReader(questionName + ".in");
        PrintStream out = System.out;
        out = getPrintStream(questionName + ".out");
        int count = readNumber(r);
        for(int x = 0; x < count; x++) {
            String answer = "";
            String S = r.readLine();
            answer += S.charAt(0);
            for(int a = 1; a < S.length(); a++) {
                String tmp = "" + S.charAt(a) + answer;
                if(tmp.compareTo(answer) > 0) {
                    answer = tmp;
                } else {
                    answer = answer + S.charAt(a);
                }
            }

            out.printf("Case #%d: ", x + 1);
            out.print(answer);
            out.println();
        }
    }

    public static void b() throws Exception {
        String questionName = "B-test";
//        String questionName = "B-small-attempt0";
//        String questionName = "B-large";
        BufferedReader r = getBufferedReader(questionName + ".in");
        PrintStream out = System.out;
//        out = getPrintStream(questionName + ".out");
        int count = readNumber(r);

        for(int x = 0; x < count; x++) {
            String answer = "";

            out.printf("Case #%d: ", x + 1);
            out.print(answer);
            out.println();
        }
    }



    public static void c() throws Exception {
        String questionName = "C-test";
//        String questionName = "C-small-attempt0";
//        String questionName = "C-large";
        BufferedReader r = getBufferedReader(questionName + ".in");
        PrintStream out = System.out;
//        out = getPrintStream(questionName + ".out");
        int count = readNumber(r);

        for(int x = 0; x < count; x++) {
            String answer = "";

            out.printf("Case #%d: ", x + 1);
            out.print(answer);
            out.println();
        }
    }



    public static void d() throws Exception {
        String questionName = "D-test";
//        String questionName = "D-small-attempt0";
//        String questionName = "D-large";
        BufferedReader r = getBufferedReader(questionName + ".in");
        PrintStream out = System.out;
//        out = getPrintStream(questionName + ".out");
        int count = readNumber(r);

        for(int x = 0; x < count; x++) {
            String answer = "";

            out.printf("Case #%d: ", x + 1);
            out.print(answer);
            out.println();
        }
    }

    static String padBinary(long number, int zeros) {
        String binary = Long.toBinaryString(number);
        while(binary.length() < zeros) {
            binary = "0" + binary;
        }
        return binary;
    }


    public static long isPrime(long num) {
        if(num % 2 == 0) return 2;
        long limit = (long)Math.sqrt(num) + 1;
        for(long x = 3; x <= limit; x+=2) {
            if(num % x == 0) {
                return x;
            }
        }
        return 0;
    }

    public static void addToMap(Map<Long, Long> map, Long key, Long value, Set<Long> add) {
        Long r = map.get(key);
        if(key == 0) {
            return;
        }
        if(r == null) {
            if(add != null)  add.add(key);
            map.put(key, value);
        } else if(r > value) {
            map.put(key, value);
            if(add != null)  add.add(key);
        }
    }

    public static long reverse (long v) {
        long ret = 0;
        while(v > 0) {
            long tmp = v % 10;
            v /= 10;
            ret *= 10;
            ret += tmp;
        }
        return ret;
    }

    public static int countAround(boolean [][]a, int x, int y) {
        int count = 0;
        try {
            if(a[x-1][y]) {
                count++;
            }
        } catch (Exception e) { //hahahahahahah

        }
        try {
            if(a[x+1][y]) {
                count++;
            }
        } catch (Exception e) { //hahahahahahah

        }
        try {
            if(a[x][y-1]) {
                count++;
            }
        } catch (Exception e) { //hahahahahahah

        }
        try {
            if(a[x][y+1]) {
                count++;
            }
        } catch (Exception e) { //hahahahahahah

        }


        return count;
    }




    public static void fill(boolean [][] a, boolean v) {
        for(boolean [] i : a) {
            Arrays.fill(i, v);
        }
    }

    public static List<Integer> toList(int [] a) {
        final List<Integer> ret = new ArrayList<Integer>();
        for(int i : a) {
            ret.add(i);
        }
        return ret;
    }

    public static BufferedReader getBufferedReader(String file) throws Exception {
        return new BufferedReader(new FileReader(file));
    }
    public static int readNumber(BufferedReader reader) throws Exception {
        return Integer.parseInt(reader.readLine());
    }

    public static long readLong(BufferedReader reader) throws Exception {
        return Long.parseLong(reader.readLine());
    }



    public static int [] readNumbers(BufferedReader reader) throws Exception {
        String [] nums = reader.readLine().split(" ");
        int [] ret = new int[nums.length];
        for(int x = 0; x < nums.length; x++) {
            ret[x] = Integer.parseInt(nums[x]);
        }
        return ret;
    }

    public static long [] readLongs(BufferedReader reader) throws Exception {
        String [] nums = reader.readLine().split(" ");
        long [] ret = new long[nums.length];
        for(int x = 0; x < nums.length; x++) {
            ret[x] = Long.parseLong(nums[x]);
        }
        return ret;
    }
    public static double [] readDoubles(BufferedReader reader) throws Exception {
        String line = reader.readLine();
        String [] nums = line.split(" ");
        double [] ret = new double[nums.length];
        for(int x = 0; x < nums.length; x++) {
            ret[x] = Double.parseDouble(nums[x]);
        }
        return ret;
    }

    public static String readString(BufferedReader reader) throws Exception {
        return reader.readLine();
    }
    public static String [] readStrings(BufferedReader reader) throws Exception {
        String line = reader.readLine();
        String [] nums = line.split(" ");
        return nums;
    }

    public static long [] readBinaryLongs(BufferedReader reader) throws Exception {
        String [] line = readStrings(reader);
        long [] nums = new long[line.length];
        for(int x = 0; x < line.length; x++) {
            nums[x] = Long.parseLong(line[x], 2);
        }
        return nums;
    }


    public static PrintStream getPrintStream(String file) throws Exception {
        if(new File(file).exists()) {
            throw new RuntimeException(new File(file).getAbsolutePath() + " Already exists");
        }

        FileOutputStream fos = new FileOutputStream(new File(file), true);
        PrintStream printStream = new PrintStream(fos);
        return printStream;
    }

    public static class Fraction extends Pair<BigInteger, BigInteger> {
        final public static Fraction ONE = new Fraction(BigInteger.ONE,BigInteger.ONE);
        final public static Fraction TEN = new Fraction(BigInteger.TEN,BigInteger.ONE);
        final public static Fraction ZERO = new Fraction(BigInteger.ZERO, BigInteger.ONE);

        public Fraction(long numerator, long denominator) {
            super(BigInteger.valueOf(numerator), BigInteger.valueOf(denominator));
        }
        public Fraction(BigInteger numerator, BigInteger denominator) {
            super(numerator,denominator);
        }

        public Fraction reduce() {
            BigInteger gcd = left.gcd(right);
            Fraction d = new Fraction(left.divide(gcd), right.divide(gcd));
            if(d.right.compareTo(BigInteger.ZERO) < 0) {
                d.right = d.right.negate();
                d.left = d.left.negate();
            }
            return d;
        }

        public BigInteger toBigInteger() {
            return left.divide(right);
        }
        public String toString() {
            return left.toString() + "/" + right.toString();
        }

        public Fraction add(final long o) {
            return add(BigInteger.valueOf(o));
        }
        public Fraction add(final BigInteger o) {
            return add(new Fraction(o, BigInteger.ONE));

        }
        public Fraction add(final Fraction o) {
            BigInteger num = left.multiply(o.right).add(right.multiply(o.left));
            BigInteger den = right.multiply(o.right);
            return new Fraction(num, den).reduce();
        }
        public Fraction multiply(final Fraction o) {
            return new Fraction(left.multiply(o.left), right.multiply(o.right)).reduce();
        }
        public Fraction divide(final Fraction o) {
            return this.multiply(new Fraction(o.right, o.left));
        }
        public Fraction subtract(final Fraction o) {
            return this.add(new Fraction(o.left.negate(), o.right));
        }
        public BigInteger floor() {
            return left.divide(right);
        }

        @Override
        public boolean equals(Object o) {
            Fraction f = (Fraction)o;
            f = f.reduce();
            Fraction t = this.reduce();
            if(f.left.equals(t.left) && f.right.equals(t.right)) {
                return true;
            }
            return false;
        }

        public boolean greaterThan(Fraction o) {
            return new BigDecimal(left).divide(new BigDecimal(right), 100, BigDecimal.ROUND_HALF_UP).compareTo(new BigDecimal(o.left).divide(new BigDecimal(o.right), 100, BigDecimal.ROUND_HALF_UP)) > 0;
        }

        public boolean lessThan(Fraction o) {
            return new BigDecimal(left).divide(new BigDecimal(right), 100, BigDecimal.ROUND_HALF_UP).compareTo(new BigDecimal(o.left).divide(new BigDecimal(o.right), 100, BigDecimal.ROUND_HALF_UP)) < 0;
        }
    }
    public static class Point extends Pair<Long, Long> {
        public Point(long x, long y) {
            super(x, y);
        }
        public long getX() {
            return left;
        }
        public long getY() {
            return right;
        }
    }
    public static class Pair<L extends Comparable, R extends Comparable> implements Comparable<Pair<L, R>> {
        public L left;
        public R right;

        public Pair(L l, R r) {
            left = l;
            right = r;
        }

        public L getLeft() {
            return left;
        }
        public R getRight() {
            return right;
        }

        public int compareTo(Pair<L, R> o) {
            if(this == o) {
                return 0;
            }
            int res = left.compareTo(o.getLeft());
            if(res == 0) {
                res = right.compareTo(o.getRight());
            }
            return res;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;

            Pair pair = (Pair) o;

            if (left != null ? !left.equals(pair.left) : pair.left != null) return false;
            if (right != null ? !right.equals(pair.right) : pair.right != null) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = left != null ? left.hashCode() : 0;
            result = 31 * result + (right != null ? right.hashCode() : 0);
            return result;
        }

        @Override
        public String toString() {
            return "[" + left + ", " + right + "]";
        }
    }
}
