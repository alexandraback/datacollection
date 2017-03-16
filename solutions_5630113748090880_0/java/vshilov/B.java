import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class B {

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            int n=nextInt();
            int[][] a=new int[2*n-1][n];
            int[] count=new int[3000];
            for(int i=0;i<2*n-1;i++)
                for(int j=0;j<n;j++) {
                    a[i][j] = nextInt();
                    count[a[i][j]]++;
                }
            out.printf("Case #%d: ",testCase+1);
            for(int i=0;i<3000;i++)if(count[i]%2!=0)out.print(i+" ");
            out.println();

        }
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }

    void run() throws IOException {
//        reader = new BufferedReader(new InputStreamReader(System.in));
		reader = new BufferedReader(new FileReader("input.txt"));
        tokenizer = null;
//        out = new PrintWriter(new OutputStreamWriter(System.out));
		out = new PrintWriter(new FileWriter("output.txt"));
        solve();
        reader.close();
        out.flush();

    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}
