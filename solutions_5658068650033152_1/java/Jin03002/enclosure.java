import java.io.*;
import java.util.*;
public class enclosure{
   public static void main(String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("C-small.in"));
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gcj.out")));
      int Num=Integer.parseInt(f.readLine());
      for(int ind=0;ind<Num;ind++){
         String[] inar=f.readLine().split(" ");
         long N=Long.parseLong(inar[0]);
         long M=Long.parseLong(inar[1]);
         long K=Long.parseLong(inar[2]);
         long min=0;
         if(N<3 || M<3) out.println("Case #"+(ind+1)+": "+K);
         else if(N==3 || M==3){
            if(K>4){
               long temp=K-2;
               temp=temp-temp%3;
               temp=temp/3;
               if(temp>((N-2)*(M-2))) temp=(N-2)*(M-2);
               out.println("Case #"+(ind+1)+": "+(K-temp));
            }
            else out.println("Case #"+(ind+1)+": "+K);
         }
         else
         {
            if(K<5)
               out.println("Case #"+(ind+1)+": "+K);
            else if (K<8)
               out.println("Case #"+(ind+1)+": "+(K-1));
            else{
               long temp=K;
               temp=temp-temp%2;
               temp=temp/2-2;
               if(temp>((N-2)*(M-2))) temp=(N-2)*(M-2);
               out.println("Case #"+(ind+1)+": "+(K-temp));
            }  
                    
         }
      }
      out.close();
   }
}
