import java.io.*;
import java.util.*;
public class partelf{
   public static void main(String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("A-small.in"));
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gcj.out")));
      int Num=Integer.parseInt(f.readLine());
      for(int ind=0;ind<Num;ind++){
         String[] inar=f.readLine().split("/");
         long P=Long.parseLong(inar[0]);
         long Q=Long.parseLong(inar[1]);
         long gcd=GCD(P,Q);
         P=P/gcd; Q=Q/gcd;
         if((Q & -Q) != Q)
            out.println("Case #"+(ind+1)+": impossible");
         else{
            long min=0;
            while(P<Q){
               min++;
               P*=2;}
            out.println("Case #"+(ind+1)+": "+min);
         }
      }
      out.close();
   }
   public static long GCD(long a, long b) {
      if (b==0) 
         return a;
      return GCD(b,a%b);
   }
}
