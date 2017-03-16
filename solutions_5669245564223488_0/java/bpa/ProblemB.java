import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class ProblemB implements Runnable {

    void solveMultiTest() throws IOException {
        int testCases = nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            out.println("Case #" + testCase + ": " + solveOneTest());
        }
    }

    String solveOneTest() throws IOException {
        int n = nextInt();
        t = new String[n];
        for (int i = 0; i < n; i++)
            t[i] = nextToken();
        s = new HashSet<Integer>();
        a = new ArrayList<Integer>();
        c = 0;
        gen(n);
        return c + "";
    }

    String[] t;

    Set<Integer> s;
    ArrayList<Integer> a;
    int c;

    boolean isValid(String st) {
        boolean[] f = new boolean[26];
        Arrays.fill(f, false);
        for (int i = 1; i < st.length(); i++) {
            if (f[st.charAt(i) - 'a'])
                return false;
            if (st.charAt(i) != st.charAt(i - 1))
                f[st.charAt(i - 1) - 'a'] = true;
        }
        return true;
    }

    void gen(int n) {
        if (a.size() == n) {
            String st = "";
            for (int x : a)
                st += t[x - 1];
            if (isValid(st))
                c++;
            return;
        }
        for (int i = 1; i <= n; i++)
            if (!s.contains(i)) {
                s.add(i);
                a.add(i);
                gen(n);
                s.remove(i);
                a.remove(a.size() - 1);
            }
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public void run() {
        try {
            InputStream input = System.in;
            PrintStream output = System.out;
            File file = new File("a.in");
            if (file.exists() && file.canRead()) {
                input = new FileInputStream(file);
                output = new PrintStream(new File("a.out"));
            }
            br = new BufferedReader(new InputStreamReader(input));
            out = new PrintWriter(output);
            solveMultiTest();
            out.close();
        } catch (IOException e) {
        }
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    public static void main(String[] args) {
        new Thread(new ProblemB()).run();
    }
}