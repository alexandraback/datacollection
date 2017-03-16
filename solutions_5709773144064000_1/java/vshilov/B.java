import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class B {

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            double c=nextDouble();
            double f=nextDouble();
            double x=nextDouble();
            double ans=x/2;
            int fac=1;
            double ct=0;
            double add=2;
            while(true){
                double q=c/add;
                ct+=q;
                add+=f;
                double ca=ct+x/add;
                if(ca<ans)ans=ca;else break;
            }
            out.printf(Locale.US,"Case #%d: %.9f\n",testCase+1,ans);
        }
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }

    void run() throws IOException {
        reader = new BufferedReader(new InputStreamReader(System.in));
        reader = new BufferedReader(new FileReader("input.txt"));
        tokenizer = null;
        out = new PrintWriter(new OutputStreamWriter(System.out));
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