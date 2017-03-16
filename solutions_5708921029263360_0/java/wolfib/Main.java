/* Created by Wolfgang Beyer */

import java.io.*;
import java.util.StringTokenizer;
import java.util.Locale;

public class Main {
    static BufferedReader in;
    static StringTokenizer tok;

    static void solve(int caseNumber) throws Exception {
        int j = nextInt();
        int p = nextInt();
        int s = nextInt();
        int k = nextInt();

        int[][] jp = new int[j][p];
        int[][] js = new int[j][s];
        int[][] ps = new int[p][s];
        StringBuilder sol = new StringBuilder();
        int counter = 0;

        for (int ji = 0; ji < j; ji++) {
            for (int pi = 0; pi < p; pi++) {
                for (int si = 0; si < s; si++) {
                    if ((jp[ji][pi] < k) && (js[ji][si] < k) && (ps[pi][si] < k)) {
                        sol.append((ji + 1) + " " + (pi + 1) + " " + (si + 1) + "\n");
                        counter++;
                        jp[ji][pi]++;
                        js[ji][si]++;
                        ps[pi][si]++;
                    }
                }
            }
        }
        System.out.println("Case #" + caseNumber + ": " + counter);
        System.out.print(sol);
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
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
            in = new BufferedReader(new FileReader ("C-small-attempt0.in"));
            //in = new BufferedReader(new FileReader ("C-large.in"));
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
