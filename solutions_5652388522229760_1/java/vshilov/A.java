import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class A {

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            int n=nextInt();
            if(n==0)out.printf("Case #%d: INSOMNIA\n",testCase+1);
            else{
                int count=0;
                boolean[] a=new boolean[10];
                long times=0;
                while(count!=10){
                    times++;
                    long cur=n*times;
                    while(cur!=0){
                        int x=(int)(cur%10);
                        if(!a[x]){
                            a[x]=true;
                            count++;
                        }
                        cur/=10;
                    }
                }
                out.printf("Case #%d: %d\n",testCase+1,n*times);
            }
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