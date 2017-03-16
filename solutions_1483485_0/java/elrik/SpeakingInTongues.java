import java.io.*;
import java.util.*;

public class SpeakingInTongues {
    // -ea –Xmx256M –Xss64M
    String s;

    static Map<Character, Character> t = new HashMap<Character, Character>();

    static {
        String a = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
        String b = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
        t.put('q', 'z');
        t.put('z', 'q');
        t.put('e', 'o');
        t.put('y', 'a');
        t.put(' ', ' ');
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) == ' ') continue;
            Character ch = t.put(a.charAt(i), b.charAt(i));
            if (ch != null && ch != b.charAt(i)) throw new IllegalStateException();
        }

    }
    private Object solve() throws Exception {
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < s.length(); i++) {
            char ch = t.get(s.charAt(i));
            sb.append(ch);
        }
        return sb.toString();
    }

    private void load() throws Exception {
        s = nextLine();
        log.print(s);
    }


    private static final String PREFIX = "A-small-attempt1";
    private static final String PATH = "d:/gcjam12/qr/";
    private static final String POSTFIX_IN = ".in";
    private static final String POSTFIX_OUT = ".out";
    private static final PrintStream log = System.out;

    public static void main(String args[]) throws Exception {
        Locale.setDefault(Locale.US);
        InputStreamReader reader = new InputStreamReader(new BufferedInputStream(new FileInputStream(PATH + PREFIX + POSTFIX_IN)));
        PrintStream out = new PrintStream(new FileOutputStream(PATH + PREFIX + POSTFIX_OUT));
        Scanner in = new Scanner(reader);

        long t0 = System.nanoTime();
        int testCount = in.nextInt(); in.nextLine();
        for (int testIndex = 1; testIndex <= testCount; testIndex++) {
            log.printf("Data #%d: ", testIndex);

            SpeakingInTongues s = new SpeakingInTongues();
            s.in = in;
            s.load();
            s.in = null;
            log.println();

            long t1 = System.nanoTime();
            String result = "Case #" + testIndex + ": " + s.solve();

            out.println(result);
            log.println(result);
            log.printf("Time #%d: %.6f sec\n\n", testIndex, (System.nanoTime() - t1) / 1e9);
        }
        log.printf("Total time: %.6f sec", (System.nanoTime() - t0)/1e9);

        reader.close();
        out.close();
    }

    private Scanner in;
    private int nextInt() { return in.nextInt(); }
    private long nextLong() { return in.nextLong(); }
    private double nextDouble() { return Double.parseDouble(in.next()); }
    private String nextLine() { return in.nextLine().trim(); }
    private void skipLine() { in.nextLine(); }
    private String next() { return in.next().trim(); }
    private int[] nextIntArray(int size) { int[] a = new int[size]; for (int i = 0; i < size; i++) a[i] = in.nextInt(); return a; }
    private long[] nextLongArray(int size) { long[] a = new long[size]; for (int i = 0; i < size; i++) a[i] = in.nextLong(); return a; }
    private double[] nextDoubleArray(int size) { double[] a = new double[size]; for (int i = 0; i < size; i++) a[i] = Double.parseDouble(in.next());  return a; }
    private String[] nextLineArray(int size) { String[] a = new String[size]; for (int i = 0; i < size; i++) a[i] = in.nextLine().trim(); return a; }
    private String[] nextTokenArray(int size) { String[] a = new String[size]; for (int i = 0; i < size; i++) a[i] = in.next().trim(); return a; }
}
