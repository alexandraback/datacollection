import java.io.*;
import java.util.*;

public class One {
   BufferedReader in;
   StringTokenizer str;
   PrintWriter out;
   String SK;

   void solve() throws IOException {
      int T=nextInt();
      char vow[]={'a', 'e', 'i', 'o','u'};
      int res[]=new int[T];


      for (int i = 0; i < T; i++) {
         char ch[]=next().toCharArray();
         int len=ch.length;
         int n=nextInt();

         int sum[]=new int[len];
         sum[0]=1;
         for (int j = 0; j < 5; j++) {
            if(ch[0]==vow[j]){
               sum[0]=0;
            }
         }
         for (int j = 1; j < len; j++) {
            sum[j]=sum[j-1]+1;
            for (int k = 0; k < 5; k++) {
               if(ch[j]==vow[k]){
                  sum[j]=0;
                  break;
               }
            }
         }
         int p=0;
         int v=0;
         for (int j = 0; j < len; j++) {
            if(sum[j]>=n){
               v++;
               if((len-j)*(j-n+2-p)>=0){
                  res[i]+=(len-j)*(j-n+2-p);
               }
               p=j-n+2;
            }
         }
      }
      for (int i = 1; i <= T; i++) {
         out.println("Case #"+i+": "+res[i-1]);
      }

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
      new One().run();
   }
   void run() throws IOException {
      //in = new BufferedReader(new InputStreamReader(System.in));
      //out = new PrintWriter(System.out);
      in = new BufferedReader(new FileReader("input.in"));
      out = new PrintWriter("output.out");
      solve();
      out.close();
   }

}


