import java.io.*;
import java.util.*;

/**
 * @author master_j
 * @version 0.4.1
 * @since Mar 22, 2015
 */
public class Solution {

    private void solve() throws IOException {
        int T = io.nI();
        for (int t = 1; t <= T; t++) {
            int h = io.nI(), w = io.nI(), p = io.nI();
            io.wf("Case #%d: %d\n", t, solve(h, w, p));

        }
    }//2.2250738585072012e-308

    private int solve(int h, int w, int p) {
        int s = w / p + Math.min(1, w % p);
        return s * h + p - 1;
    }

    public static void main(String[] args) throws IOException {
        IO.launchSolution(args);
    }

    Solution(IO io) throws IOException {
        this.io = io;
        solve();
    }

    private final IO io;
}

class IO {
    static final String _localArg = "master_j";
    private static final String _problemName = "";
    private static final Mode _inMode = Mode.STD_;
    private static final Mode _outMode = Mode.STD_;
    private static final boolean _autoFlush = false;

    enum Mode {STD_, _PUT_TXT, PROBNAME_}

    private final StreamTokenizer st;
    private final BufferedReader br;
    private final Reader reader;

    private final PrintWriter pw;
    private final Writer writer;

    static void launchSolution(String[] args) throws IOException {
        boolean local = (args.length == 1 && args[0].equals(IO._localArg));
        IO io = new IO(local);

        long nanoTime = 0;
        if (local) {
            nanoTime -= System.nanoTime();
            io.wln("<output>");
        }

        io.flush();
        new Solution(io);
        io.flush();

        if (local) {
            io.wln("</output>");
            nanoTime += System.nanoTime();
            final long D9 = 1000000000, D6 = 1000000, D3 = 1000;
            if (nanoTime >= D9)
                io.wf("%d.%d seconds\n", nanoTime / D9, nanoTime % D9);
            else if (nanoTime >= D6)
                io.wf("%d.%d millis\n", nanoTime / D6, nanoTime % D6);
            else if (nanoTime >= D3)
                io.wf("%d.%d micros\n", nanoTime / D3, nanoTime % D3);
            else
                io.wf("%d nanos\n", nanoTime);
        }

        io.close();
    }

    IO(boolean local) throws IOException {
        if (_inMode == Mode.PROBNAME_ || _outMode == Mode.PROBNAME_)
            if (_problemName.length() == 0)
                throw new IllegalStateException("You imbecile. Where's my <_problemName>?");

        if (_problemName.length() > 0)
            if (_inMode != Mode.PROBNAME_ && _outMode != Mode.PROBNAME_)
                throw new IllegalStateException("You imbecile. What's the <_problemName> for?");

        Locale.setDefault(Locale.US);

        if (local) {
            reader = new FileReader("input.txt");
            writer = new OutputStreamWriter(System.out);
        } else {
            switch (_inMode) {
                case STD_:
                    reader = new InputStreamReader(System.in);
                    break;
                case PROBNAME_:
                    reader = new FileReader(_problemName + ".in");
                    break;
                case _PUT_TXT:
                    reader = new FileReader("input.txt");
                    break;
                default:
                    throw new NullPointerException("You imbecile. Gimme _inMode.");
            }
            switch (_outMode) {
                case STD_:
                    writer = new OutputStreamWriter(System.out);
                    break;
                case PROBNAME_:
                    writer = new FileWriter(_problemName + ".out");
                    break;
                case _PUT_TXT:
                    writer = new FileWriter("output.txt");
                    break;
                default:
                    throw new NullPointerException("You imbecile. Gimme _outMode.");
            }
        }

        br = new BufferedReader(reader);
        st = new StreamTokenizer(br);

        pw = new PrintWriter(writer, _autoFlush);

        if (local && _autoFlush)
            wln("Note: auto-flush is on.");
    }

    //@formatter:off
    void wln()          {pw.println(); }
    void wln(boolean x) {pw.println(x);}
    void wln(char x)    {pw.println(x);}
    void wln(char x[])  {pw.println(x);}
    void wln(double x)  {pw.println(x);}
    void wln(float x)   {pw.println(x);}
    void wln(int x)     {pw.println(x);}
    void wln(long x)    {pw.println(x);}
    void wln(Object x)  {pw.println(x);}
    void wln(String x)  {pw.println(x);}

    void wf(String f, Object... o) {pw.printf(f, o);}

    void w(boolean x)   {pw.print(x);}
    void w(char x) {pw.print(x);}
    void w(char x[]) {pw.print(x);}
    void w(double x)    {pw.print(x);}
    void w(float x)     {pw.print(x);}
    void w(int x)       {pw.print(x);}
    void w(long x)      {pw.print(x);}
    void w(Object x)    {pw.print(x);}
    void w(String x)    {pw.print(x);}

    int nI() throws IOException {st.nextToken(); return (int)st.nval;}
    double nD() throws IOException {st.nextToken(); return st.nval;}
    float nF() throws IOException {st.nextToken(); return (float)st.nval;}
    long nL() throws IOException   {st.nextToken(); return (long)st.nval;}
    String nS() throws IOException {st.nextToken(); return st.sval;}

    int[] nIa(int n) throws IOException {
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = nI();
        return a;
    }
    double[] nDa(int n) throws IOException {
        double[] a = new double[n];
        for (int i = 0; i < n; i++)
            a[i] = nD();
        return a;
    }
    String[] nSa(int n) throws IOException {
        String[] a = new String[n];
        for (int i = 0; i < n; i++)
            a[i] = nS();
        return a;
    }

    void wc(String x)         {wc(x.toCharArray());}
    void wc(char c1, char c2) {for (char c = c1; c<=c2; c++) wc(c);}
    void wc(char x[])         {for (char c : x) wc(c); }
    void wc(char x)           {st.ordinaryChar(x); st.wordChars(x, x);}

    public boolean eof() {return st.ttype == StreamTokenizer.TT_EOF;}
    public boolean eol() {return st.ttype == StreamTokenizer.TT_EOL;}

    void flush() {pw.flush();}
    void close() throws IOException {reader.close(); br.close(); flush(); pw.close();}
    //@formatter:on
}