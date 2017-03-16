import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class Ahard {

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
            ArrayList<Integer> pos=new ArrayList<Integer>();
            pos.add(n-2);
            int l=s.length();
            int len=0;
            for(int i=0;i<l;i++){
                if(isGood(s.charAt(i)))
                    len++;
                else
                    len=0;
                if(len>n)len=n;
                if(len==n)pos.add(i);
            }
            pos.add(l);
            long ans=0;
            for(int i=1;i<pos.size()-1;i++){
                //long x=pos.get(i-1);
                long x=0;
                long y=pos.get(i+1)-1;
                ans+=(long)((pos.get(i)-n+2))*(y-pos.get(i)+1);
            }
            out.printf("Case #%d: %d\n",testCase+1,ans);

        }



    }

    public static void main(String[] args) throws IOException {
        new Ahard().run();
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