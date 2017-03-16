import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class C {

    int n;

    //3 2 5 2 7 2 3 2 11
    int[] a1={129,135,141,147,165,177,195,201,225,255};

    long convert(int x,int k){
        long ans=0;
        int y=1;
        for(int i=0;i<n;i++){
            if((x&(1<<i))!=0)ans+=y;
            y*=k;
        }
        return ans;
    }

    String toBin(int x){
        String result="";
        while(x!=0){
            if(x%2==0)result=result+'0';
            else result=result+'1';
            x/=2;
        }
        return result;
    }

    void solve() throws IOException {
        int count=0;
        out.println("Case #1:");
        for(int i=0;i<a1.length&&count<50;i++){
            for(int j=0;j<a1.length&&count<50;j++,count++){
                out.println(toBin(a1[i])+toBin(a1[j])+" 3 2 5 2 7 2 3 2 11");
            }
        }

    }

    public static void main(String[] args) throws IOException {
        new C().run();
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