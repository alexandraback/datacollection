import java.io.*;
import java.util.*;
public class partelf{
   public static void main(String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("A-small.in"));
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gcj.out")));
      int Num=Integer.parseInt(f.readLine());
      for(int ind=0;ind<Num;ind++){
         String[] inar=f.readLine().split("/");
         int P=Integer.parseInt(inar[0]);
         int Q=Integer.parseInt(inar[1]);
         int gcd=GCD(P,Q);
         P=P/gcd; Q=Q/gcd;
         if((Q & -Q) != Q)
            out.println("Case #"+(ind+1)+": impossible");
         else{
            int min=0;
            while(P<Q){
               min++;
               P*=2;}
            out.println("Case #"+(ind+1)+": "+min);
         }
      }
      out.close();
   }
   public static int GCD(int a, int b) {
      if (b==0) 
         return a;
      return GCD(b,a%b);
   }
}
