import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        new Main().solve();
    }

    //ArrayList<Integer>[] g;

    int mod = 1000000007;

    PrintWriter out;

    int n;

    ArrayList<Integer>[] g;

    void solve() throws IOException {

        Reader in = new Reader("B-large.in");
        out = new PrintWriter( new BufferedWriter(new FileWriter("B-large.out")) );

        //Reader in = new Reader();
        //out = new PrintWriter( new BufferedWriter(new OutputStreamWriter(System.out)) );

        //BufferedReader br = new BufferedReader( new FileReader("in.txt") );
        //BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );

        int t = in.nextInt();
        int cs = 1;

        while (t > 0) {

            out.print("Case #" + cs + ": ");

            int n = in.nextInt();
            long m = in.nextLong();

            long s = 1;
            long[] c = new long[n];
            c[0] = 1;

            int[][] ans = new int[n+1][n+1];

            long cnt = 1L << (n-2);

            if (cnt < m) {

                out.println("IMPOSSIBLE");
                t--;
                cs++;
                continue;
            }

            //System.err.println(cnt);

            for (int i = 1; i < n; i++) {
                for (int j = i+1; j <= n; j++)
                    ans[i][j] = 1;
            }

            for (int i = n-1; i > 1; i--) {

                long x = 1L << (i-2);

                if (cnt - x >= m) {

                     cnt-=x;
                     ans[i][n] = 0;
                }
            }

            out.println("POSSIBLE");
            t--;
            cs++;


            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++)
                    out.print(ans[i][j]);
                out.println();
            }

        }

        out.flush();
        out.close();
    }


    class Pair implements Comparable<Pair>{

        int a;
        int b;


        Pair(int a, int b) {

            this.a = a;
            this.b = b;
        }

        public int compareTo(Pair p) {

            if (a < p.a)
                return -1;

            if (a > p.a)
                return 1;

            if  (b < p.b)
                return -1;

            if (b > p.b)
                return 1;

            return 0;
        }
    }

    class Item {

        int a;
        int b;
        int c;

        Item(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

    }

    class Reader {

        BufferedReader  br;
        StringTokenizer tok;

        Reader(String file) throws IOException {
            br = new BufferedReader( new FileReader(file) );
        }

        Reader() throws IOException {
            br = new BufferedReader( new InputStreamReader(System.in) );
        }

        String next() throws IOException {

            while (tok == null || !tok.hasMoreElements())
                tok = new StringTokenizer(br.readLine());
            return tok.nextToken();
        }

        int nextInt() throws NumberFormatException, IOException {
            return Integer.valueOf(next());
        }

        long nextLong() throws NumberFormatException, IOException {
            return Long.valueOf(next());
        }

        double nextDouble() throws NumberFormatException, IOException {
            return Double.valueOf(next());
        }

        String nextLine() throws IOException {
            return br.readLine();
        }

    }

}