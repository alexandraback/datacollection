import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

/**
 * User: Oleksiy Pylypenko
 * Date: 1/6/13
 * Time: 1:46 PM
 */
public class Y13QC {
    public static final BigInteger ONE = BigInteger.ONE;
    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer tok;
    public static final BigInteger TWO = BigInteger.valueOf(2);

    private void solveTest() throws IOException {
        nextLine();
        long a = readLong(), b = readLong();
        long cnt = 0;
        for (long i = (long)Math.ceil(Math.sqrt(a)); i <= Math.floor(Math.sqrt(b)); i++) {
            if (isPal(i) && isPal(i * i)) {
                cnt++;
            }
        }
        out.println(cnt);
    }

    private boolean isPal(long pal) {
        String s = "" + pal;
        for (int i = 0; i < (s.length() + 1) / 2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - i - 1)) {
                return false;
            }
        }
        return true;
    }

    private static BigInteger sqrt(BigInteger val, boolean ceil) {
        if (ONE.equals(val)) {
            return val;
        }

        BigInteger res = ONE.shiftLeft(val.bitLength() / 2);

        while (res.subtract(val.divide(res)).abs().compareTo(ONE) > 0) {
            BigInteger v = val.divide(res);
            v = v.add(res);
            res = v.divide(TWO);
        }

        BigInteger squareRes = res.multiply(res);
        int cmp = val.compareTo(squareRes);
        if (cmp != 0) {
            if (cmp > 0 && ceil) {
                res = res.add(ONE);
            } else if (cmp < 0 && !ceil) {
                res = res.subtract(ONE);
            }
        }
        return res;
    }

    private void solve() throws IOException {
        nextLine();
        int nt = readInt();
        for (int t = 1; t <= nt; t++) {
            out.print("Case #" + t + ": ");
            solveTest();
        }
    }

    private String readLine() throws IOException {return in.readLine();}
    private void nextLine() throws IOException {tok = new StringTokenizer(in.readLine());}

    private String read() {return tok.nextToken();}
    private int readInt() {return Integer.parseInt(tok.nextToken());}
    private long readLong() {return Long.parseLong(tok.nextToken());}
    private double readDouble() {return Double.parseDouble(tok.nextToken());}

    public static void main(String[] args) throws IOException {
        new Y13QC().exec();
    }

    private void exec() {
        try {
            in = new BufferedReader(new FileReader(getInFile()));
            out = new PrintWriter(new FileWriter(getOutFile()), true);
        } catch (IOException e) {
            System.out.println(e);
            System.exit(1);
        }

        try {
            solve();
        } catch (IOException e) {
            System.out.println(e);
            System.exit(1);
        } finally {
            out.close();
            try {
                in.close();
            } catch (IOException e) {
                System.out.println(e);
                System.exit(1);
            }
        }
        try {
            FileInputStream input = new FileInputStream(getOutFile());
            byte []buf = new byte[1024];
            int r;
            while ((r = input.read(buf)) != -1) {
                System.out.write(buf, 0, r);
            }
            input.close();
        } catch (IOException e) {
            System.out.println(e);
            System.exit(1);
        }
    }

    private String getOutFile() {
        return getClass().getName() + ".out";
    }

    private String getInFile() {
        return getClass().getName() + ".in";
    }


    static class TestSqrt {
        public static void main(String[] args) {
            for (int i = 1; i <= 10000000; i++) {
                int v1 = sqrt(BigInteger.valueOf(i), true).intValue();
                int v2 = (int) Math.ceil(Math.sqrt(i));
                if (v1 != v2) {
                    System.out.println(i + " " + v1 + " " + v2);
                    System.exit(1);
                }
                if (sqrt(BigInteger.valueOf(i), false).intValue() != (int)Math.floor(Math.sqrt(i))) {
                    System.out.println("FL" + i);
                    System.exit(1);
                }
            }
            System.out.println("OK!");
        }
    }
}
