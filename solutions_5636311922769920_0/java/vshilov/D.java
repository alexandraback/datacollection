import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class D {

    long pow(long k,long c){
        long res=1;
        for(int i=0;i<c;i++)res*=k;
        return res;
    }

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            long k=nextInt();
            long c=nextInt();
            long s=nextInt();
            ArrayList<Long> result=new ArrayList<Long>();
            boolean good=true;
            int checked=0;
            while(true){
                if(result.size()>=s){
                    good=false;
                    break;
                }
                long pos=1;
                for(int i=0;i<c&&checked<k;i++){
                    pos+=pow(k,c-1-i)*checked;
                    checked++;
                }
                result.add(pos);
                if(checked==k)break;
            }
            if(good){
                out.printf("Case #%d: ",testCase+1);
                for(int i=0;i<result.size();i++)out.print(" "+result.get(i));
                out.println();
            }
            else
                out.printf("Case %d: IMPOSSIBLE\n",testCase+1);
        }
    }

    public static void main(String[] args) throws IOException {
        new D().run();
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