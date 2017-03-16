import java.io.*;
import java.util.*;
import static java.lang.Math.*;
public class Sample1

{
     BufferedReader read;BufferedWriter write;
    public static void main(String args[])
    {
        try {   new Sample1().init("A-large");     } catch (Exception ex) {System.out.println(ex);}
    }
     void init(String name) throws Exception
    {
          v[0]=v['e'-'a']=v['i'-'a']=v['o'-'a']=v['u'-'a']=true;
        read= rf(name+".in");write=wf(name+"1.out");
        String x=read.readLine();
        int n = i(x);
              for(int i=0;i<n;i++)
                 {
                   x = read.readLine();
                   result(x, i);
                }
                write.flush();write.close();read.close();
    }
boolean v[]=new boolean[26];
void result(String x,int q) throws Exception
{
                 String ss[]=x.split(" ");
                 int n=Integer.parseInt(ss[1]);
                 char nm[]=ss[0].toCharArray();
               //  System.out.println(ss[0]+"  "+n);
                 int l=nm.length;
                 int cnt[]=new int[l];
                 boolean is[]=new boolean[l];
                 cnt[0]=v[nm[0]-'a']?0:1;
                 for(int i=1;i<l;i++)cnt[i]+=cnt[i-1]+(v[nm[i]-'a']?0:1);
                 long ans=0;
                 for(int i=0;i+n<=l;i++)
                 {
                     int c=cnt[i+n-1]-cnt[i]+(v[nm[i]-'a']?0:1);
                     if(c==n)
                     {
                       
                         for(int kk=i;kk>=0&&!is[kk];kk-- )ans+=l-i-n+1;
                           is[i]=true;
                     }
                   //  System.out.println(i+"  "+cnt[i]+"   "+(i+n-1)+"  "+cnt[(i+n-1)]);
                 }
                String s1=""+ans;
                System.out.println("Case #"+(q+1)+": "+s1);
               write.write("Case #"+(q+1)+": "+s1+"\n");
}
// for(j=i;j>=0;j=(j-1)&i) which iterates through all subsets of 1's in i
static BufferedWriter wf(String s) throws Exception{return new BufferedWriter(new FileWriter(new File(s)));}
static BufferedReader rf(String s) throws Exception{return new BufferedReader(new FileReader(new File(s)));}
static BufferedReader ri() throws Exception{return new BufferedReader(new InputStreamReader(System.in));}
int i(String s){return Integer.parseInt(s.trim());}
 int[] sa(String s1){String s[]=s1.trim().split(" ");int p[]=new int[s.length];for(int i=0;i<s.length;i++)p[i]=Integer.parseInt(s[i]);return p;}
 int bc(long l){return l==0?0:1+bc(l&=l-1);}
 long gcd(long a,long b){ return b==0?a:gcd(b,a%b); }
}
