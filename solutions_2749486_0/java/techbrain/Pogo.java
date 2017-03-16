import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

/**
 * User: Oleksiy Pylypenko
 * Date: 1/6/13
 * Time: 1:46 PM
 */
public class Pogo {
    private static final boolean DEBUG_OUT = true;

    private final String inFile = getClass().getName() + ".in";
    private final String outFile = getClass().getName() + ".out";
    {
        ClassLoader.getSystemClassLoader().setDefaultAssertionStatus(true);
        Locale.setDefault(Locale.US);
    }

    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer tok;

    private void solveTest() throws IOException {
        nextLine();
        int x = readInt(), y = readInt();
        for (int i = 0; i < Math.abs(x); i++) {
            if (x > 0) {
                out.print("WE");
            } else {
                out.print("EW");
            }
        }
        for (int i = 0; i < Math.abs(y); i++) {
            if (y > 0) {
                out.print("SN");
            } else {
                out.print("NS");
            }
        }
        out.println();
    }

    private void solveNTests() throws IOException {
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
        new Pogo().mainRun();
    }

    private void mainRun() {
        openFiles();
        solveNTestsAndCloseFiles();
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


    private void solveNTestsAndCloseFiles() {
        try {
            solveNTests();
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
        solveNTestsAndCloseFiles();
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
            System.out.println(new Pogo().testOne("INPUT"));
        }
    }
}
