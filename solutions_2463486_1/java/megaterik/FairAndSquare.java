
import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;

public class FairAndSquare implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new FairAndSquare(), "", 256 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();

            out = new PrintWriter(System.out);
            in = new BufferedReader(new FileReader("src/input.txt"));
            out = new PrintWriter("src/fairoutput.txt");

            Locale.setDefault(Locale.US);
            solve();
            in.close();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Throwable t) {
            t.printStackTrace(System.err);
            System.exit(-1);
        }
    }

    String readString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }
    ArrayList<Long> perfectNumbers = new ArrayList<>();

    boolean isPalindrome(Long x) {
        String s = Long.toString(x);
        if (s.equals(new StringBuffer(s).reverse().toString())) {
            return true;
        } else {
            return false;
        }
    }
    ArrayList<Long> valid;
    // solution

    void solve() throws IOException {
        valid = new ArrayList<>();
        for (long x = 1; x * x <= 500000000000000L; x++) {
            if (isPalindrome(x) && isPalindrome(x * x)) {
                valid.add(x * x);
            }
        }
        int ct = readInt();
        int n = 0;
        while (ct-- > 0) {
            solveTestCase(++n);
        }
    }
    static final char EMPTY = '.';

    void solveTestCase(int number) throws IOException {
        long l = readLong();
        long r = readLong();
        int left = Math.abs(Collections.binarySearch(valid, l));
        while (left > 0 && valid.get(left - 1) >= l) {
            left--;
        }
        while (valid.get(left) < l) {
            left++;
        }
        int right = Math.abs(Collections.binarySearch(valid, r));
        while (valid.get(right + 1) <= r) {
            right++;
        }
        while (valid.get(right) > r) {
            right--;
        }
        out.println("Case #" + number + ": " + (right - left + 1));
    }
}