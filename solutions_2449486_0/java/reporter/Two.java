import java.io.*;
import java.util.*;

public class Two{
   BufferedReader in;
   StringTokenizer str;
   PrintWriter out;
   String SK;
   boolean was[][];
   int lawn[][];
   void solve() throws IOException {
      int T=nextInt();
      String res[]=new String[T];
      for (int i = 0; i < T; i++) {
         int n=nextInt();
         int m=nextInt();
         was=new boolean[n][m];
         lawn=new int[n][m];
         Loc locs[]=new Loc[101];
         for(int j=0;j<=100;j++){
            locs[j]=new Loc();
         }
         for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
               int v=nextInt();
               lawn[j][k]=v;
               locs[v].add(j);
               locs[v].add(k);
            }
         }
         boolean err=false;
         for(int h=1;h<=100;h++){
            for(int j=0;j<locs[h].locat.size();j+=2){
               int x=locs[h].locat.get(j);
               int y=locs[h].locat.get(j+1);
               if(was[x][y])continue;
               boolean bv=goHorizontal(x,y,h,m);
               boolean bh=goVertical(x,y,h,n);
               if(!(bv || bh)){
                  res[i]="NO";
                  err=true;
                  break;
               }
            }
         }
         if(!err)res[i]="YES";
      }
      for (int i = 1; i <= T; i++) {
         out.println("Case #"+i+": "+res[i-1]);
      }

   }
   boolean goVertical(int x, int y, int val, int n){
      for(int i=0;i<x;i++){
         if(was[i][y])continue;
         if(lawn[i][y]>val)return false;
      }
      for(int i=x+1;i<n;i++){
         if(was[i][y])continue;
         if(lawn[i][y]>val)return false;
      }
      for(int i=0;i<n;i++){
         was[i][y]=true;
      }
      return true;
   }
   boolean goHorizontal(int x, int y, int val, int n){
      for(int i=0;i<y;i++){
         if(was[x][i])continue;
         if(lawn[x][i]>val)return false;
      }
      for(int i=y+1;i<n;i++){
         if(was[x][i])continue;
         if(lawn[x][i]>val)return false;
      }
      for(int i=0;i<n;i++){
         was[x][i]=true;
      }
      return true;
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
      in = new BufferedReader(new FileReader("input.in"));
      out = new PrintWriter("output.out");
      solve();
      out.close();
   }

}

class Loc{
   ArrayList<Integer> locat;
   public Loc(){
      locat= new ArrayList<Integer>();
   }
   public void add(int x){
      locat.add(x);
   }
}
