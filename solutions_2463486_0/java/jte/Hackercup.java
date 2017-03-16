/**
 * Created with IntelliJ IDEA.
 * User: brzezinsky
 * Date: 1/26/13
 * Time: 7:58 AM
 * To change this template use File | Settings | File Templates.
 */

import com.sun.servicetag.SystemEnvironment;

import java.io.*;
import java.util.*;
import java.util.concurrent.atomic.AtomicReferenceArray;

public class Hackercup extends Thread {
    public Hackercup(String inputFileName, String outputFileName) {
        try {
            if (inputFileName != null) {
                this.input = new BufferedReader(new FileReader(inputFileName));
            } else {
                this.input = new BufferedReader(new InputStreamReader(System.in));
            }
            if (outputFileName != null) {
                this.output = new PrintWriter(outputFileName);
            } else {
                this.output = new PrintWriter(System.out);
            }
            this.setPriority(Thread.MAX_PRIORITY);
        } catch (Throwable e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(666);
        }
    }

    ArrayList<Long> ret = new ArrayList<Long>();

    static final boolean  isPal(long a) {
        String s = Long.toString(a);
        for (int l = 0, r = s.length() - 1; l < r; ++l, --r) {
            if (s.charAt(l) != s.charAt(r)) return false;
        }
        return true;
    }

    private void solve2() throws Throwable {
        for (int i = 1; i <= 10000000; ++i) {
            long ii = i;
            if (isPal(ii) && isPal(ii * ii)) {
                ret.add(ii * ii);
            }
        }
    }

    final int doit() throws IOException {
        long A = nextLong(), B = nextLong();
        int ans = 0;
        for (long t : ret) {
            if (t >= A && t <= B) ++ans;
        }
        return ans;
    }


    private void solve() throws Throwable {
        solve2();
        int n = nextInt();
        for (int i = 1; i <= n; ++i) {
            output.printf("Case #%d: ", i);
            output.println(doit());
        }
    }

    public void run() {
        try {
            solve();
        } catch (Throwable e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(666);
        } finally {
            output.close();
        }
    }

    public static void main(String... args) {
       // new Hackercup(null, null).start();
        new Hackercup("/users/brzezinsky/IdeaProjects/contests/codeforces155/input.txt", "/users/brzezinsky/IdeaProjects/contests/codeforces155/output.txt").start();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    private String nextLine() throws IOException {
        return input.readLine();
    }


    private String next() throws IOException {
        while (tokens == null || !tokens.hasMoreTokens()) {
            tokens = new StringTokenizer(input.readLine());
        }
        return tokens.nextToken();
    }

    private StringTokenizer tokens;
    private BufferedReader input;
    private PrintWriter output;
}