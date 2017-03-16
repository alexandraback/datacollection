import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class A {

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            String s=nextToken();
            String ns="";
            for(int i=0;i<s.length();i++){
                String s1=ns+s.charAt(i);
                String s2=s.charAt(i)+ns;
                if(s1.compareTo(s2)>0)ns=s1;
                else ns=s2;
            }

            out.printf("Case #%d: %s\n",testCase+1,ns);

        }
    }

    public static void main(String[] args) throws IOException {
        new A().run();
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
