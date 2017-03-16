import java.io.*;
import java.util.*;

public class Three{
   BufferedReader in;
   StringTokenizer str;
   PrintWriter out;
   String SK;

   void solve() throws IOException {
      int T=nextInt();
      int res[]=new int[T];
      ArrayList<Long> fs = new ArrayList<Long>();

      for(long i=1;i*i<=100000000000100L;i++){
         if(isit(i+"") && isit(i*i+"")){
            fs.add(i*i);
         }
      }

      for (int i = 0; i < T; i++) {
         long A=nextLong();
         long B=nextLong();
         int c=0;
         for (int j = 0; j < fs.size(); j++) {
            long f=fs.get(j);
            if(f>=A && f<=B){
               c++;
            }
         }
         res[i]=c;
      }
      for (int i = 1; i <= T; i++) {
         out.println("Case #"+i+": "+res[i-1]);
      }

   }
    boolean isit(String st) {
      StringBuilder sb = new StringBuilder(st);
      sb = sb.reverse();
      if (st.equals(sb.toString()))return true;
      return false;
   }

   String next() throws IOException {
      while ((str == null) || (!str.hasMoreTokens())) {
         SK = in.readLine();
         if (SK == null)
              return null;
         str = new StringTokenizer(SK);
      }
      return str.nextToken();
   }
   int nextInt() throws IOException {
      return Integer.parseInt(next());
   }
   double nextDouble() throws IOException {
      return Double.parseDouble(next());
   }
   long nextLong() throws IOException {
      return Long.parseLong(next());
   }

   public static void main(String[] args) throws IOException {
      new Three().run();
   }
   void run() throws IOException {
      in = new BufferedReader(new FileReader("input.in"));
      out = new PrintWriter("output.out");
      solve();
      out.close();
   }

}
