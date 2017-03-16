import java.io.*;
import java.util.*;

public class One {
   BufferedReader in;
   StringTokenizer str;
   PrintWriter out;
   String SK;

   void solve() throws IOException {
      int T=nextInt();
      String res[]=new String[T];
      for (int i = 0; i < T; i++) {
         char game[][]=new char[4][4];
         for(int j = 0;j < 4; j++){
            game[j]=next().toCharArray();
         }
         String all[]=new String[10];
         int q=0;
         for(int j=0;j<4;j++){
            all[q++]=String.valueOf(game[j]);
         }
         for (int j = 0; j < 4; j++) {
            String s="";
            for (int k = 0; k < 4; k++) {
               s+=game[k][j];
            }
            all[q++]=s;
         }
         String s="";
         for(int j=0;j<4;j++){
            s+=game[j][j];
         }
         all[q++]=s;
         s="";
         for(int j=0;j<4;j++){
            s+=game[j][3-j];
         }
         all[q++]=s;
         
         boolean comp=false;
         int d=0;
         boolean ob=false;
         for (int j = 0; j < 10; j++) {
            StringBuilder sb = new StringBuilder(all[j]);
            if(all[j].contains("."))comp=true;
            if(all[j].equals("XXXX")){
               res[i]="X won";
               ob=true;
               break;
            }
            if(all[j].equals("OOOO")){
               res[i]="O won";
               ob=true;
               break;
            }
            int ind=all[j].indexOf("T");
            if(ind>=0){
               sb=sb.deleteCharAt(ind);
               if("XXX".equals(sb.toString())){
                  res[i]="X won";
                  ob=true;
                  break;
               }
               if("OOO".equals(sb.toString())){
                  res[i]="O won";
                  ob=true;
                  break;
               }
            }
         }
         if(!ob){
            if(comp){
               res[i]="Game has not completed";
            }
            else{
               res[i]="Draw";
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
      in = new BufferedReader(new FileReader("input.in"));
      out = new PrintWriter("output.out");
      solve();
      out.close();
   }

}


