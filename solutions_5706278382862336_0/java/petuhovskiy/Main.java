import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Scanner;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] params) throws IOException {
        Locale.setDefault(Locale.ENGLISH);
        Scanner sc = new Scanner(new FileInputStream("input.txt"));
        PrintWriter pw = new PrintWriter("output.txt");
        int t = sc.nextInt();
        sc.nextLine();
        for (int tt = 1; tt <= t; tt++) {
            pw.print("Case #" + tt + ": ");
            String[] ms = sc.nextLine().split("/");
            long n = Long.valueOf(ms[0]);
            long m = Long.valueOf(ms[1]);
            int k = 0;
            while (n % m != 0 && m % 2 == 0) {
                m /= 2;
                k++;
            }
            if (n % m != 0) {
                pw.println("impossible");
                continue;
            }
            n = Long.valueOf(ms[0]);
            m = Long.valueOf(ms[1]);
            k = 0;
            while (n / m < 1 && m % 2 == 0) {
                m /= 2;
                k++;
            }
            pw.println(k);
        }
        pw.close();
    }
}

class AReader {

    private static BufferedReader in;
    private static StringTokenizer st;

    AReader(InputStream is) {
        in = new BufferedReader(new InputStreamReader(is));
        st = null;
    }

    public String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }

    public String nextLine() throws IOException {
        if (st == null) return in.readLine();
        String res = st.nextToken("");
        st = null;
        return res;
    }

    public int nextInt()  throws IOException {
        return Integer.parseInt(next());
    }

    public BigInteger nextBigInteger() throws IOException {
        return new BigInteger(next());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}