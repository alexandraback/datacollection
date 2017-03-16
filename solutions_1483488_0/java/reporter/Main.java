import java.io.*;
import java.util.*;
public class Main{
    public static void main (String[] args) throws java.lang.Exception{
      Scanner in = new Scanner(System.in);
      int T=in.nextInt();
      int res[]=new int[T];

      for(int t=0;t<T;t++){
          int A=in.nextInt();
          int B=in.nextInt();
          for(int i=A;i<=B;i++){
              HashSet<Integer> hs=new HashSet<Integer>();
              String tt=i+"";
              int lenT=tt.length();
              int len=lenT-1;
              int temp=i;
              while(len>0){
                  len--;
                  int rem=temp%10;
                  temp=temp/10;
                  if(rem!=0)
                    temp=rem*(int)Math.pow(10,lenT-1)+temp;
                  if(temp<=B && temp>i){  
                        hs.add(temp);
                  }
              }
              res[t]+=hs.size();
          }
      }
      for(int i=0;i<T;i++){
          System.out.println("Case #"+(i+1)+": "+res[i]);
      }

     
    }
}