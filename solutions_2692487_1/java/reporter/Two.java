import java.io.*;
import java.util.*;

public class Two{
   BufferedReader in;
   StringTokenizer str;
   PrintWriter out;
   String SK;
   void solve() throws IOException {
      int T=nextInt();
      long res[]=new long[T];
      for (int i = 0; i < T; i++) {
         long A=nextLong();
         int S=nextInt();
         long mote[]=new long[S];
         for (int j = 0; j < S; j++) {
            mote[j]=nextLong();
         }
         Arrays.sort(mote);
     
         int n1=0;
         int min=S;
         int stop=0;
         if(A==1){
            res[i]=S;
            continue;
         }
         for (int j = 0; j < S; j++) {
            if(A<=mote[j]){
               while(A<=mote[j]){
                  A=A+A-1;
                  n1++;
               }
               A+=mote[j];
            }
            else{
               A+=mote[j];
            }
            min=Math.min(min, n1+S-j-1);
         }
         res[i]=min;

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
      new Two().run();
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
