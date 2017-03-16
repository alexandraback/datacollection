import java.io.*;
import java.util.*;
public class Main{
    public static void main (String[] args) throws java.lang.Exception{
      BufferedReader bfr=new BufferedReader(new InputStreamReader(System.in));
      int T=Integer.parseInt(bfr.readLine());
      int res[]=new int[T];
      Arrays.fill(res,0);
      for(int i=0;i<T;i++){
          String t[]=bfr.readLine().split(" ");
          int N=Integer.parseInt(t[0]);
          int S=Integer.parseInt(t[1]);
          int p=Integer.parseInt(t[2]);
          int x=3*p-4;
          for(int j=3;j<t.length;j++){
              int q=Integer.parseInt(t[j]);
              if(p==1){
                  if(q>0){
                    res[i]++;
                  }
                  continue;
              }
              if(q>x+1){
                  res[i]++;
              }
              else if(q>=x && S>0){
                  res[i]++;
                  S--;
              }
          }
      }
      for(int i=0;i<T;i++){
          System.out.println("Case #"+(i+1)+": "+res[i]);
      }

     
    }
}