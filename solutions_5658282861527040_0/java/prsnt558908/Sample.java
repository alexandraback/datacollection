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
        new Sample().init("B-small-attempt0");
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
    int p1[]=ia(read.readLine()),a=p1[0],b=p1[1],k=p1[2];
    long ans=0;
    for(int i=0;i<a;i++)for(int j=0;j<b;j++)if((i&j)<k)ans++;
    String s1=""+ans;
    System.out.println("Case #"+(p+1)+": "+s1);
    write.write("Case #"+(p+1)+": "+s1+"\n");
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
