import java.io.*;
import java.util.*;
import static java.lang.Math.*;
//import java.util.logging.Level;
//import java.util.logging.Logger;
public class Sample

{
     BufferedReader read;
     BufferedWriter write;
    public static void main(String args[]) throws Exception
    {
        new Sample().init("B-large");
    }
     void init(String name) throws Exception
    {
        
       read= rf(name+".in");
        write=wf(name+".out");
        String x="";
        x = read.readLine();
        int n = Integer.parseInt(x);
        for(int i=0;i<n;i++) result( i);
        write.flush(); write.close();read.close();
   }

void result(int p) throws Exception
{
    int p1[]=ia(read.readLine());long a1=p1[0]-1,b1=p1[1]-1,k1=p1[2]-1;
    a=new int[40];b=new int[40];k=new int[40];
    dp=new long[40][2][2][2];done=new boolean[40][2][2][2];
    for(int i=35;i>=0;i--)
    {
        if(((a1>>i)&1)!=0)a[i]=1;
        if(((b1>>i)&1)!=0)b[i]=1;
        if(((k1>>i)&1)!=0)k[i]=1;
    }
    long ans=dp(35,0,0,0);
  // System.out.println(dp(35,0,0,0)+"  ...   ");
    String s1=""+ans;
    System.out.println("Case #"+(p+1)+": "+s1);
    write.write("Case #"+(p+1)+": "+s1+"\n");
}
int a[],b[],k[];
long dp[][][][];
boolean done[][][][];
long dp(int p,int la,int lb,int lk)
{
if(p<0)return 1;
if(done[p][la][lb][lk])return dp[p][la][lb][lk];
done[p][la][lb][lk]=true;
long ans=0;
int ma=a[p],mb=b[p],mk=k[p];
if(la==1)ma=1;if(lb==1)mb=1;if(lk==1)mk=1;
for(int i=0;i<=ma;i++)for(int j=0;j<=mb;j++)
{
    int ia=la,ib=lb,ik=lk;
    if(i<ma)ia=1;
    if(j<mb)ib=1;
    if((i&j)<mk)ik=1;
    if((i&j)<=mk)ans+=dp(p-1,ia,ib,ik);
}
return dp[p][la][lb][lk]=ans;
}
boolean isPalindrome(long l)
{
   char c[]=(""+l).toCharArray();
   for(int i=0;i<c.length;i++)if(c[i]!=c[c.length-i-1])return false;
   return true;
}
int i(String s){return Integer.parseInt(s.trim());}
long l(String s){return Long.parseLong(s.trim());}
double d(String s){return Double.parseDouble(s.trim());}
 int[] ia(String s1){String s[]=s1.trim().split(" ");int p[]=new int[s.length];for(int i=0;i<s.length;i++)p[i]=Integer.parseInt(s[i]);return p;}
 long[] la(String s)
 {
     String s1[]=s.split(" ");
     long la[]=new long[s1.length];
     for(int i=0;i<s1.length;i++)la[i]=l(s1[i]);
     return la;
 }
 double [] ld(String s)
  {
    String s1[]=s.split(" ");
    int l=s1.length;
   double d[]=new double[l];
   for(int i=0;i<l;i++)d[i]=d(s1[i]);
   return d;
 }
static BufferedWriter wf(String s) throws Exception{return new BufferedWriter(new FileWriter(new File(s)));}
static BufferedReader rf(String s) throws Exception{return new BufferedReader(new FileReader(new File(s)));}
static BufferedReader ri() throws Exception{return new BufferedReader(new InputStreamReader(System.in));}
}
