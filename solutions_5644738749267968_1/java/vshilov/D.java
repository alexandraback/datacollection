import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class D {

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            int n=nextInt();
            double[] a=new double[n];
            double[] b=new double[n];
            for(int i=0;i<n;i++)
                a[i]=nextDouble();
            for(int i=0;i<n;i++)
                b[i]=nextDouble();
            int count1=0;
            int count2=0;
            Arrays.sort(a);

            Arrays.sort(b);
//            for(int i=0;i<n;i++)
//                System.err.printf("%.3f ",a[i]);
//            System.err.println();
//            for(int i=0;i<n;i++)
//                System.err.printf("%.3f ",b[i]);
//            System.err.println();
            boolean[] used=new boolean[n];
            for(int i=0;i<n;i++){
                int ind=-1;
                for(int j=0;j<n;j++)
                    if(b[j]>a[i]&&!used[j]){
                        ind=j;
                        break;
                    }
                if(ind==-1)count1++;
                else used[ind]=true;
            }
            int i=0;
            int j=0;
            int k=n-1;
            while(j<=k){
                if(a[i]>b[j]){
                    count2++;
                    i++;
                    j++;
                }
                else{
                    i++;
                    k--;
                }
            }
            out.printf("Case #%d: %d %d\n",testCase+1,count2,count1);
        }
    }

    public static void main(String[] args) throws IOException {
        new D().run();
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
