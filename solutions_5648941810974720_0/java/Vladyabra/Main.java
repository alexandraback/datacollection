import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {

    private NotMyScanner in;
    private PrintWriter out;
    //    private Timer timer = new Timer();

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    void dec(int[] cnt, String s, int d) {
        for (char c : s.toCharArray()) {
            cnt[c] -= d;
        }
    }

    void proc(char d, char num, String s, int[] cnt, ArrayList<Character> ans) {
        for (int i = 0; i < cnt[d]; i++) {
            ans.add(num);
        }
        dec(cnt, s, cnt[d]);
    }

    private void solve() throws IOException {
        int cnt[] = new int[256];
        String s = in.next();
        for (char c : s.toCharArray()) {
            cnt[c]++;
        }
        ArrayList<Character> ans = new ArrayList<>();

        proc('G', '8', "EIGHT", cnt, ans);
        proc('W', '2', "TWO", cnt, ans);
        proc('Z', '0', "ZERO", cnt, ans);
        proc('H', '3', "THREE", cnt, ans);
        proc('R', '4', "FOUR", cnt, ans);
        proc('O', '1', "ONE", cnt, ans);
        proc('F', '5', "FIVE", cnt, ans);
        proc('X', '6', "SIX", cnt, ans);
        proc('I', '9', "NINE", cnt, ans);
        proc('S', '7', "SEVEN", cnt, ans);

        Collections.sort(ans);
        for (Character character : ans) {
            out.print(character);
        }
        out.println();
    }

    private void run() throws IOException {
        in = new NotMyScanner();
        out = new PrintWriter(System.out, false);
//        in = new NotMyScanner("in.txt");
        out = new PrintWriter(new FileOutputStream("out.txt"), false);
        int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            out.print("Case #" + i + ": ");
            solve();
        }
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