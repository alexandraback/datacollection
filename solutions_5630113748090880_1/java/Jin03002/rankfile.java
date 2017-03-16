import java.math.*;
import java.io.*;
import java.util.*;
public class rankfile
{
   public static long[] cAr, div;
   public static int N,M,K;
   public static long[][] values;
   public static final String fileName = "rankfile";
   public static Map<Integer,Set<Integer>> map;
   public static long MOD = 1000000007;
   public static void main(String[] args) throws IOException{
      //InputReader in=new InputReader(new InputStreamReader(System.in));
      InputReader in=new InputReader(new FileReader(fileName+".in"));
      PrintWriter out=new PrintWriter(new FileWriter(fileName+".out"));
      int M = in.nextInt();
      
      for(int i=1;i<=M;i++){
         int N=in.nextInt();
         HashMap<Integer,Integer> heights=new HashMap<Integer,Integer>();
         for(int x=0;x<2*N-1;x++){
            int[] ar=in.nextIntAr();
            for(int y=0;y<N;y++){
               int c=ar[y];
               if(heights.containsKey(c))
                  heights.put(c,(heights.get(c)+1)%2);
               else heights.put(c,1);
            }
         }
         int[] ar=new int[N];
         int ind=0;
         for(int x:heights.keySet())
            if(heights.get(x)==1)
            {
               ar[ind]=x;
               ind++;
            }
         Arrays.sort(ar);
         out.print("Case #"+(i)+": ");
         for(int x=0;x<N;x++)
            out.print(ar[x]+" ");
         out.print("\n");
      }
      out.close();
   }
   
   public static void setUpChoose(int t){
      cAr=new long[t+1];
      div=new long[t+1];
      cAr[0]=1;
      div[0]=1;
      
      for(int x=1;x<=t;x++){
         cAr[x]=(x*cAr[x-1])%(MOD);
         div[x]=pow(cAr[x],MOD-2);} 
   }
   
   public static long choose(int x,int y){
      long a=cAr[x+y];
      long b=div[x];
      long c=div[y];
      a=(a*b)%MOD;
      a=(a*c)%MOD;
      return a;
   } 
   
   public static long pow(long a,long b){
      if(b==1) 
         return a;
      long c=b/2;
      long temp=pow(a,c)%MOD;
      temp=(temp*temp)%MOD;
      if(b%2==1) temp=temp*a;
      return temp%MOD;
   }
}

class InputReader{
   private BufferedReader br;
   public InputReader(InputStreamReader in){
      br=new BufferedReader(in);
   }
   public int nextInt(){
      try{
         return Integer.parseInt(br.readLine());}
      catch(IOException e){throw new InputMismatchException();}
   }
   public int[] nextIntAr(){
      try{
         String[] s=br.readLine().split(" ");
         int[] ret=new int[s.length];
         for(int x=0;x<s.length;x++)
            ret[x]=Integer.parseInt(s[x]);
         return ret;}
         
      catch(IOException e){throw new InputMismatchException();}
   }
   
   public long nextLong(){
      try{
         return Long.parseLong(br.readLine());}
      catch(IOException e){throw new InputMismatchException();}
   }
   public long[] nextLongAr(){
      try{
         String[] s=br.readLine().split(" ");
         long[] ret=new long[s.length];
         for(int x=0;x<s.length;x++)
            ret[x]=Long.parseLong(s[x]);
         return ret;}
         
      catch(IOException e){throw new InputMismatchException();}
   }
   
   public String[] nextStringAr(){
      try{
         return br.readLine().split(" ");}
         
      catch(IOException e){throw new InputMismatchException();}
   }
   
   public String nextString(){
      try{
         return br.readLine();}
         
      catch(IOException e){throw new InputMismatchException();}
   }
}
   
class Pair implements Comparable<Pair>{
   long a;
   long b;
   
   public Pair(long ma, long mb){
      a = ma;
      b = mb;
   }
   
   public int compareTo(Pair o){
      if(a == o.a){
         if(b==o.b) 
            return 0;
         return b<o.b?-1:1;
      }
      return a<o.a?-1:1;
   }
}