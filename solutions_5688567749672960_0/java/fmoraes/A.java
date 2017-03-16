import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;

public class A {
    public final static int MODULO = 1000000007;

    public static void main(String[] args)
    {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        PrintWriter out = new PrintWriter(outputStream);
        A solver = new A();
        solver.solve(1, new InputStreamReader(inputStream), out);
        out.close();
    }

    static long reverse(long n)
    {
      long res = 0;
      
      while(n != 0) {
        res = res * 10;
        res = res + n % 10;
        n = n / 10;
      }
      return res;
    }
    
    public void solve(int test, Reader input, PrintWriter out)
    {
        MyScanner in = new MyScanner(input);
        
        int T = in.nextInt();

        int[] min = new int[1_000_001];
        for(int i = 1; i < 1_000_001; i++) {
          if(i < 21) min[i] = i;
          else {
            int r = (int)reverse(i);
            int min1 = min[i-1] + 1;
            if(r < i && i % 10 != 0)
              min1 = Math.min(min1, min[r] + 1);
            min[i] = min1;
          }
        }
        for(int t = 1; t <= T; t++) {
          long n = in.nextLong();

          out.printf("Case #%d: %d\n", t, min[(int)n]);
        }
    }

    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner(Reader reader) {
            br = new BufferedReader(reader);
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
    //--------------------------------------------------------

}
