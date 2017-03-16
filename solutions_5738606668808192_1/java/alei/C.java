import java.math.*;
import java.util.*;
import java.io.*;

public class C{   
   void solve(int n,int Q){
      int mx=(1<<17)+17;
      boolean[] criba=new boolean[mx];
      int[]primes=new int[mx];
      int np=0;
      for(int i=0;i<mx;i++)criba[i]=true;
      criba[0]=criba[1]=false;
      for(int i=0;i<mx;i++){
         if(criba[i]){
            primes[np++]=i;
            for(int j=i+i;j<mx;j+=i){
               criba[j]=false;
            }
         }
      }
      int cnt=0;
      for(long b=0;b<(1l<<(n-2)) && cnt<Q;b++){
         long c=b;
         c<<=1;
         c|=1;
         c|=( 1<<(n-1) );
         boolean ok=true;
         ArrayList<Integer>factors=new ArrayList<Integer>();
         String s="";
         for(int i=0;i<n;i++){
            if((c&(1l<<i))!=0)s="1"+s;
            else s="0"+s;
         }
         for(int base=2;base<=10;base++){         
            BigInteger x=new BigInteger(s,base);
            if(x.isProbablePrime(20)){
               ok=false;
               break;
            }
            int f=-1;
            for(int i=0;i<np;i++){
               if(x.remainder(new BigInteger(primes[i]+"")).equals(BigInteger.ZERO)){
                  f=primes[i];
                  break;
               }
            }
            if(f==-1){
               ok=false;
               break;
            }
            factors.add(f);
         }
         if(ok){
            cnt+=1;
            System.out.print(s);
            for(int i=0;i<factors.size();i++){
               System.out.print(" "+factors.get(i));
            }
            System.out.println();
         }
      }
   }
   public static void main(String args[])throws Exception{
      System.setIn(new FileInputStream("cl.in"));
      System.setOut(new PrintStream(new FileOutputStream("cl.out")));
      Scanner sn=new Scanner(System.in);
      int t=sn.nextInt();
      int n=sn.nextInt();
      int q=sn.nextInt();
      System.out.println("Case #1:");
      C c=new C();      
      c.solve(n,q);
   }
}
