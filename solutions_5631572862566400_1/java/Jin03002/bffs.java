import java.math.*;
import java.io.*;
import java.util.*;
public class bffs
{
   public static long[] cAr, div;
   public static int N,M,K;
   public static long[][] values;
   public static final String fileName = "bffs";
   public static Map<Integer,Set<Integer>> map;
   public static long MOD = 1000000007;
   public static void main(String[] args) throws IOException{
      //InputReader in=new InputReader(new InputStreamReader(System.in));
      InputReader in=new InputReader(new FileReader(fileName+".in"));
      PrintWriter out=new PrintWriter(new FileWriter(fileName+".out"));
      int M = in.nextInt();
      
      for(int i=1;i<=M;i++){
         int N=in.nextInt();
         int[] ar=in.nextIntAr();
         for(int j=0;j<N;j++) ar[j]--;
         
         int[] cycle=new int[N];
         int[] maxPoint=new int[N];
         int max=0;
         
         for(int x=0;x<N;x++)
            if(ar[ar[x]]==x){
               cycle[x]=1;
               cycle[ar[x]]=1;
               max+=1;
            }
            
         int[] visited=new int[N];
         
         for(int x=0;x<N;x++)
            if(cycle[x]==1) visited[x]=1;
         
         for(int y=0;y<N;y++){
            int[] visitedp=new int[N];
            for(int z=0;z<N;z++)
               visitedp[z]=visited[z];
                     
            int cur=y;
            int total=0;
            while(visitedp[cur]==0){
               visitedp[cur]=1;
               total++;
               cur=ar[cur];
            }
                  
            if(cycle[cur]==1 && maxPoint[cur] < total)
               maxPoint[cur]=total;
         }
         
         for(int x=0;x<N;x++)
            max+=maxPoint[x];
         
         int[] cycleLength=new int[N+1];
         for(int x=0;x<N;x++){
            int[] visitedp=new int[N];
                     
            int cur=x;
            int total=0;
            while(visitedp[cur]==0){
               visitedp[cur]=1;
               total++;
               cur=ar[cur];
            }
            if(cur == x && total>2)
               cycleLength[total]++;
         }
         
         for(int x=3;x<=N;x++)
            if(cycleLength[x]>1)
               max=Math.max(max,x);
         out.println("Case #"+(i)+": "+max);
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