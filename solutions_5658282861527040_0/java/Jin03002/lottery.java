import java.io.*;
import java.util.*;
import java.math.*;
public class lottery{
   public static void main(String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("B-small-attempt0.in"));
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gjc.out")));
      conv(3,4);
      int Num=Integer.parseInt(f.readLine());
      for(int ind=0;ind<Num;ind++){
         String[] inar=f.readLine().split(" ");
         int A=Integer.parseInt(inar[0]);
         int B=Integer.parseInt(inar[1]);
         int K=Integer.parseInt(inar[2]);
         BigInteger total=new BigInteger("0");;
         for(int x=0;x<A;x++)
            for(int y=0;y<B;y++)
               if(conv(x,y)<K) total=total.add(new BigInteger("1"));
         out.println("Case #"+(ind+1)+": "+total);
      }
      out.close();
   }
   public static int conv(int t,int y){
      String s1=bool(t); String s2=bool(y);
      String s="";
      for(int x=0;x<Math.min(s1.length(),s2.length());x++)
      {
         if(s1.substring(s1.length()-1-x,s1.length()-x).compareTo("1")==0 && s2.substring(s2.length()-1-x,s2.length()-x).compareTo("1")==0)
            s="1"+s;
         else 
            s="0"+s;
      }
      return boolToInt(s);
   }
   
   public static String bool(int x){
      int temp=x;
      String s="";
      while(temp>0){
         if(temp%2==0){
            s="0"+s;
            temp/=2;}
         else{
            s="1"+s;
            temp=(temp-1)/2;
         }
      }
      return s;
   }
   
   public static int boolToInt(String s){
      int tot=0;
      for(int x=0;x<s.length();x++)
         if(s.substring(s.length()-1-x,s.length()-x).compareTo("1")==0)
            tot+=Math.pow(2,x);
      return tot;
   }
}
