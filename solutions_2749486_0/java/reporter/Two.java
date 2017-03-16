import java.io.*;
import java.util.*;

public class Two{
   BufferedReader in;
   StringTokenizer str;
   PrintWriter out;
   String SK;
   boolean f;
   String res="AA";
   boolean vis[][];
   void solve() throws IOException {
      int T=nextInt();
      String ress[]=new String[T];
      for (int i = 0; i < T; i++) {
         int x=nextInt();
         int y=nextInt();
         StringBuilder sb = new StringBuilder("");
         if(x>=0){
            for (int j = 0; j < x; j++) {
               sb.append("WE");
            }
         }
         else{
            x=-x;
            for (int j = 0; j < x; j++) {
               sb.append("EW");
            }
         }
         if(y>=0){
            for (int j = 0; j < y; j++) {
               sb.append("SN");
            }
         }
         else{
            y=-y;
            for (int j = 0; j < y; j++) {
               sb.append("NS");
            }
         }
         ress[i]=sb.toString();
        

      }


      for (int i = 1; i <= T; i++) {
         out.println("Case #"+i+": "+ress[i-1]);
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
