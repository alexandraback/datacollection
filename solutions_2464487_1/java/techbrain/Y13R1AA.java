import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;

/**
 * User: Oleksiy Pylypenko
 * Date: 1/6/13
 * Time: 1:46 PM
 */
public class Y13R1AA {
    private static final boolean DEBUG_OUT = true;
    private static final BigInteger ONE = BigInteger.ONE;
    private static final BigInteger TWO = BigInteger.valueOf(2);

    private final String inFile = getClass().getName() + ".in";
    private final String outFile = getClass().getName() + ".out";
    {
        ClassLoader.getSystemClassLoader().setDefaultAssertionStatus(true);
        Locale.setDefault(Locale.US);
    }

    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer tok;

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

    private void solveTest() throws IOException {
        nextLine();
        long r = readLong(), t = readLong();
        BigInteger twoRm1 = BigInteger.valueOf(r).multiply(TWO).subtract(ONE);
        BigInteger d = twoRm1.multiply(twoRm1).add(
                BigInteger.valueOf(t).multiply(BigInteger.valueOf(8)));
        debugln(twoRm1 + " " + d);
        d = sqrt(d, false);
        BigInteger n = d.subtract(twoRm1).divide(BigInteger.valueOf(4));
        out.println(n);
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
    private void nextLine() throws IOException {tok = new StringTokenizer(readLine());}

    private String read() {return tok.nextToken();}
    private int readInt() {return Integer.parseInt(read());}
    private long readLong() {return Long.parseLong(read());}
    private double readDouble() {return Double.parseDouble(read());}

    private void debug(Object fmt, Object ...args) {
        if (!DEBUG_OUT) return;
        System.out.print(String.format(fmt.toString(), args));
    }
    private void debugln(Object fmt, Object ...args) {
        if (!DEBUG_OUT) return;
        System.out.println(String.format(fmt.toString(), args));
    }
    private void debugln() {
        if (!DEBUG_OUT) return;
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        new Y13R1AA().mainRun();
    }

    private void mainRun() {
        openFiles();
        process();
        outputOutput();
    }

    private void openFiles() {
        try {
            in = new BufferedReader(new FileReader(inFile));
            out = new PrintWriter(new BufferedWriter(new FileWriter(outFile)), true);
        } catch (IOException e) {
            System.out.println(e);
            System.exit(1);
        }
    }


    private void process() {
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
    }

    public String test(String input) {
        StringWriter resultOut = new StringWriter();
        in = new BufferedReader(new StringReader(input));
        out = new PrintWriter(resultOut);
        process();
        return resultOut.getBuffer().toString().trim();
    }

    public String testOne(String input) {
        StringWriter resultOut = new StringWriter();
        in = new BufferedReader(new StringReader(input));
        out = new PrintWriter(resultOut);
        try {
            solveTest();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            out.close();
            try {
                in.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return resultOut.getBuffer().toString().trim();
    }

    private void outputOutput() {
        try {
            FileInputStream input = new FileInputStream(outFile);
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

    static class Test1 {
        public static void main(String[] args) {
            System.out.println(new Y13R1AA().testOne("INPUT"));
        }
    }
}
