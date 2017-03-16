import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {

    private NotMyScanner in;
    private PrintWriter out;
        private Timer timer = new Timer();

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    boolean matches(String f, String s) {
        for (int i = 0; i < f.length(); i++) {
            if (f.charAt(i) == '.') {
                continue;
            }
            if (f.charAt(i) != s.charAt(i)) {
                return false;
            }
        }
        return true;
    }

    private void solve() throws IOException {
//        String a = "...".replace('?', '.'), b = "...".replace('?', '.');
        String a = in.next().replace('?', '.'), b = in.next().replace('?', '.');

        int p10 = 1;
        for (int i = 0; i < a.length(); i++) {
            p10 *= 10;
        }

        ArrayList<Integer> fir = new ArrayList<>(), sec = new ArrayList<>();
        String format = "%0" + a.length() + "d";
        for (int i = 0; i < p10; i++) {
            String s = String.format(format, i);
            if (s.matches(a)) {
                fir.add(i);
            }
            if (s.matches(b)) {
                sec.add(i);
            }
        }

        int f = 0, s = 10000;
        for (Integer A : fir) {
            for (Integer B : sec) {
                if (Math.abs(A - B) < Math.abs(f - s)) {
                    f = A;
                    s = B;
                }
            }
        }

        String o = String.format(format, f);
        String t = String.format(format, s);
        out.println(o + " " + t);
    }

    private void run() throws IOException {
        in = new NotMyScanner();
        out = new PrintWriter(System.out, false);
//        in = new NotMyScanner("in.txt");
        out = new PrintWriter(new FileOutputStream("out.txt"), false);
        int t = in.nextInt();
        timer.start();
        for (int i = 1; i <= t; i++) {
            out.print("Case #" + i + ": ");
            solve();
        }
        timer.stop();
        out.close();
    }
}

class NotMyScanner {

    private final BufferedReader br;
    private StringTokenizer st;
    private String last;

    public NotMyScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    public NotMyScanner(String path) throws IOException {
        br = new BufferedReader(new FileReader(path));
    }

    public NotMyScanner(String path, String decoder) throws IOException {
        br = new BufferedReader(new InputStreamReader(new FileInputStream(path), decoder));
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreElements())
            st = new StringTokenizer(br.readLine());
        last = null;
        return st.nextToken();
    }

    String nextLine() throws IOException {
        st = null;
        return (last == null) ? br.readLine() : last;
    }

    boolean hasNext() {
        if (st != null && st.hasMoreElements())
            return true;

        try {
            while (st == null || !st.hasMoreElements()) {
                last = br.readLine();
                st = new StringTokenizer(last);
            }
        } catch (Exception e) {
            return false;
        }

        return true;
    }

    String[] nextStrings(int n) throws IOException {
        String[] arr = new String[n];
        for (int i = 0; i < n; i++)
            arr[i] = next();
        return arr;
    }

    String[] nextLines(int n) throws IOException {
        String[] arr = new String[n];
        for (int i = 0; i < n; i++)
            arr[i] = nextLine();
        return arr;
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    int[] nextInts(int n) throws IOException {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = nextInt();
        return arr;
    }

    Integer[] nextIntegers(int n) throws IOException {
        Integer[] arr = new Integer[n];
        for (int i = 0; i < n; i++)
            arr[i] = nextInt();
        return arr;
    }

    int[][] next2Ints(int n, int m) throws IOException {
        int[][] arr = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                arr[i][j] = nextInt();
        return arr;
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    long[] nextLongs(int n) throws IOException {
        long[] arr = new long[n];
        for (int i = 0; i < n; i++)
            arr[i] = nextLong();
        return arr;
    }

    long[][] next2Longs(int n, int m) throws IOException {
        long[][] arr = new long[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                arr[i][j] = nextLong();
        return arr;
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next().replace(',', '.'));
    }

    double[] nextDoubles(int size) throws IOException {
        double[] arr = new double[size];
        for (int i = 0; i < size; i++)
            arr[i] = nextDouble();
        return arr;
    }

    boolean nextBool() throws IOException {
        String s = next();
        if (s.equalsIgnoreCase("true") || s.equals("1"))
            return true;

        if (s.equalsIgnoreCase("false") || s.equals("0"))
            return false;

        throw new IOException("Boolean expected, String found!");
    }
}