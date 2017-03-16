import java.io.*;
import java.util.*;
import static java.lang.Math.*;
public class Sample

{
     BufferedReader read;BufferedWriter write;
     char nm[];boolean v[]=new boolean[26];
    public static void main(String args[])
    {
        try {   new Sample().init("A-small-attempt0");     } catch (Exception ex) {System.out.println(ex);}
    }
     void init(String name) throws Exception
    {
         v[0]=v['e'-'a']=v['i'-'a']=v['o'-'a']=v['u'-'a']=true;
        read= rf(name+".in");write=wf(name+".out");
        String x=read.readLine();
        int n = i(x);
              for(int i=0;i<n;i++)
                 {
                   x = read.readLine();
                   result(x, i);
                }
                write.flush();write.close();read.close();
    }

void result(String x,int q) throws Exception
{
                
                String ss[]=x.split(" ");
                nm=ss[0].toCharArray();
                int n=Integer.parseInt(ss[1]);
                int l=nm.length;
                long ans=0;
                for(int i=0;i<l;i++)for(int j=i+n-1;j<l;j++)if(check(i,j,n))ans++;
                String s1=""+ans;
                System.out.println("Case #"+(q+1)+": "+s1);
               write.write("Case #"+(q+1)+": "+s1+"\n");
}
boolean check(int i,int j,int n)
{
    int cnt=0;
    for(;i<=j;i++)
    {
        if(!v[nm[i]-'a'])
        {
            cnt++;
            if(cnt>=n)return true;
        }
        else cnt=0;
    }
    return cnt>=n?true:false;
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
