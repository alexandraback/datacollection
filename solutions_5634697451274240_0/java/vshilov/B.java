import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class B {

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            String s=nextToken();
            char cur=s.charAt(0);
            int ans=0;
            for(int i=1;i<s.length();i++)
                if(cur!=s.charAt(i)){
                    ans++;
                    cur=s.charAt(i);
                }
            if(cur!='+')ans++;
            out.printf("Case #%d: %d\n",testCase+1,ans);
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