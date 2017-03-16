/* Created by Wolfgang Beyer */

import java.io.*;
import java.util.StringTokenizer;
import java.util.Locale;

public class Main {
    static BufferedReader in;
    static StringTokenizer tok;

    static void solve(int caseNumber) throws Exception {
        long b = nextInt();
        long m = nextLong();
        if (m > Math.pow(2, b - 2)) {
            System.out.println("Case #" + caseNumber + ": IMPOSSIBLE");
            return;
        }

        boolean[] link = new boolean[(int) b];
        if (m == Math.pow(2, b - 2)) {
            for (int i = 0; i < b - 1; i++) link[i] = true;
        } else {
            String bin = Long.toBinaryString(m);
            //System.out.println("bin: " + bin);
            for (int i = 0; i < bin.length(); i++) {
                if (bin.charAt(i) =='1') {
                    link[bin.length() - i] = true;
                }
            }
        }

        System.out.println("Case #" + caseNumber + ": POSSIBLE");
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < b - 1; j++) {
                if (j <= i) System.out.print("0");
                if (j > i) System.out.print("1");
            }
            System.out.println(link[i]? 1 : 0);
        }
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static String next() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    public static void main(String[] args) {
        try {
            Locale.setDefault(Locale.US);
            //in = new BufferedReader(new InputStreamReader (System.in));
            //in = new BufferedReader(new FileReader ("test.in"));
            in = new BufferedReader(new FileReader ("B-small-attempt0.in"));
            //in = new BufferedReader(new FileReader ("B-large.in"));
            int n = nextInt();
            for (int i = 0; i < n; i++) {
                solve(i + 1);
            }
            in.close();
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }

}
