import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class Aeasy {

    boolean isGood(char c){
        char[] bad={'a','i','o','e','u'};
        for(int i=0;i<bad.length;i++)
            if(c==bad[i])return false;
        return true;
    }

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            String s=nextToken();
            int n=nextInt();
            int l=s.length();
            int res=0;
            for(int i=0;i<l;i++)
                for(int j=i+n;j<=l;j++){
                    int k=i;
                    boolean good=false;
                    while(k<j){
                        while(k<j&&!isGood(s.charAt(k)))k++;
                        int count=0;
                        while(k<j&&isGood(s.charAt(k))){
                            k++;
                            count++;
                        }
                        if(count>=n)good=true;
                    }
                    if(good)res++;
                }
            out.printf("Case #%d: %d\n",testCase+1,res);
        }

    }

    public static void main(String[] args) throws IOException {
        new Aeasy().run();
    }

    void run() throws IOException {
        reader = new BufferedReader(new FileReader("input.txt"));
        tokenizer = null;
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