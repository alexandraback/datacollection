import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by vinaysaini on 5/7/16.
 */
class codeJam1cB {

    public static void main(String[] args) {
        PrintWriter out = null;
        try {
            out = new PrintWriter("/Users/vinaysaini/bitbucket/javaprog/src/output_b.txt");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        int T = in.nextInt();
        for (int t = 0; t < T; t++) {
            int B = in.nextInt();
            long M = in.nextLong();
            if(M > (long)Math.pow(2, B-2)) {
                out.println("Case #"+(t+1)+": "+"IMPOSSIBLE");
            } else {
                out.println("Case #"+(t+1)+": "+"POSSIBLE");
                int ar[][] = new int[B][B];
                solve(B, M, ar);
                for (int i = 0; i < B; i++) {
                    for (int j = 0; j < B; j++) {
                        out.print(ar[i][j]);
                    }
                    out.println();
                }
            }
        }
        out.close();
    }

    static void solve(int B, long M, int ar[][]) {

        long b = M;
        int pos = 0;
        while(b > 0) {
            if((b & 1) > 0) {
                if(pos+1 != B-1) ar[pos+1][B-1] = 1;
            }
            b = b >> 1;
            pos++;
        }
        pos--;
        if(pos+1 != B-1) ar[pos+1][B-1] = 1;
        for (int i = 0; i < pos+2; i++) {
            for (int j = i+1; j < pos+2; j++) {
                ar[i][j] = 1;
            }
        }
    }



    public static FastScanner in = new FastScanner();

    public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
           // br = new BufferedReader(new InputStreamReader(System.in));
            try {
                br = new BufferedReader(new FileReader("/Users/vinaysaini/bitbucket/javaprog/src/B-small-attempt.in"));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static class Pair implements Comparable<Pair>{
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
        @Override
        public int compareTo(Pair o) {
            return  this.x - o.x;
        }
        public String toString() {
            return "{"+this.x+","+this.y+"}";
        }
    }
}
