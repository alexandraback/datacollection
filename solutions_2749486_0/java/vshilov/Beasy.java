import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class Beasy {

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            int x=nextInt();
            int y=nextInt();
            out.printf("Case #%d: ",testCase+1);
            if(x!=0){
                int q=x/Math.abs(x);
                x=Math.abs(x);
                for(int i=0;i<x;i++){
                    if(q<0){
                        out.print("EW");
                    }
                    else
                        out.print("WE");
                }
            }
            if(y!=0){
                int q=y/Math.abs(y);
                y=Math.abs(y);
                for(int i=0;i<y;i++){
                    if(q<0){
                        out.print("NS");
                    }
                    else
                        out.print("SN");
                }
            }
            out.println();


        }
    }

    public static void main(String[] args) throws IOException {
        new Beasy().run();
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