import java.io.*;
import java.math.*;
import java.util.*;

public class CodeJam {

    void runCase(int caseNum) throws IOException {
        int a = nextInt();
        int b = nextInt();
        Set<Long> res = new HashSet<Long>();

        for (long i = a; i <= b; ++i) {
            String s = Long.toString(i);
            for (int j = 1; j < s.length(); ++j) {
                char[] arr = new char[s.length()];
                for (int k = j; k < s.length(); ++k)
                    arr[k - j] = s.charAt(k);
                for (int k = 0; k < j; ++k)
                    arr[s.length() - j + k] = s.charAt(k);
                Long t = Long.parseLong(new String(arr));
                if (t > b || t <= i)
                    continue;
                if (!res.contains(i * 10000000 + t))
                    res.add(i * 10000000 + t);
            }
        }

        System.out.print(new StringBuilder().append("Case #").append(caseNum).append(": ").append(res.size()).toString());

        System.out.println();
    }


    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream(new File(
                "input.txt")));
        PrintStream ps = new PrintStream(new File(
                "output.txt"));
        System.setOut(ps);
        new CodeJam().runit();
        ps.flush();
        ps.close();
        return;
    }

    BufferedReader in;
    private StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (!st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }



    void runit() throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));
        st = new StringTokenizer("");

        int N = nextInt();
        for (int i = 0; i < N; i++) {
            runCase(i + 1);
        }

        out.flush();
    }

}
