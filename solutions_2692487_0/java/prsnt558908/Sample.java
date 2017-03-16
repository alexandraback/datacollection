import java.io.*;
import java.util.*;
import static java.lang.Math.*;
public class Sample

{
     BufferedReader read;BufferedWriter write;
     int n=0,m[];
    public static void main(String args[])
    {
        try {   new Sample().init("A-small-attempt0");     } catch (Exception ex) {System.out.println(ex);}
    }
     void init(String name) throws Exception
    {
        read= rf(name+".in");write=wf(name+".out");
        String x=read.readLine();
        int n = i(x);
        System.out.println(n);
              for(int i=0;i<n;i++)
                 {
                  
                   result(i);
                   System.out.println(" \n.........................  ");
                }
                write.flush();write.close();read.close();
    }

void result(int i) throws Exception
{
                 int p[]=sa(read.readLine());
                 n=p[1];long a=p[0];        System.out.println("  n = "+n+"    a = "+a);
                 m=sa(read.readLine());     for(int k:m)System.out.print("  "+k);
                 Arrays.sort(m);
                String s1=""+dp(0,a);
                System.out.println("Case #"+(i+1)+": "+s1);
               write.write("Case #"+(i+1)+": "+s1+"\n");
}
int dp(int i,long a)
{
    if(i>=n)return 0;
    if(m[i]<a)return dp(i+1,a+m[i]);
    int min=n-i;
    int cnt=0;
    if(a==1)return min;
    while(a<=m[i])
    {
        cnt++;
        a=a*2-1;
    }
    return min(min,cnt+dp(i+1,a+m[i]));
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
