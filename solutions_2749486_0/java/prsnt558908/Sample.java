import java.io.*;
import java.util.*;
import static java.lang.Math.*;
public class Sample

{
     BufferedReader read;BufferedWriter write;
    public static void main(String args[])
    {
        try {   new Sample().init("B-small-attempt0");     } catch (Exception ex) {System.out.println(ex);}
    }
     void init(String name) throws Exception
    {
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
TreeSet<String>tree;
void result(String x,int q) throws Exception
{
               int p[]=sa(x);
                String s1=get(p[0],p[1]);
                System.out.println("Case #"+(q+1)+": "+s1);
               write.write("Case #"+(q+1)+": "+s1+"\n");
}

String get(int x,int y)
{
     tree=new TreeSet<String>();
     LinkedList<node>q=new LinkedList<node>();
     q.addFirst(new node(0,0,0,""));
     while(!q.isEmpty())
     {
         node p=q.removeLast();
         if(tree.contains(p.i+" "+p.j))continue;
         if(p.i==x&&p.j==y)return p.s;
         tree.add(p.i+" "+p.j);
         p.n++;
         q.addFirst(new node(p.n,p.i+p.n,p.j,p.s+'E'));
         q.addFirst(new node(p.n,p.i-p.n,p.j,p.s+'W'));
         q.addFirst(new node(p.n,p.i,p.j+p.n,p.s+'N'));
         q.addFirst(new node(p.n,p.i,p.j-p.n,p.s+'S'));
     }
    return "";
}
// for(j=i;j>=0;j=(j-1)&i) which iterates through all subsets of 1's in i
static BufferedWriter wf(String s) throws Exception{return new BufferedWriter(new FileWriter(new File(s)));}
static BufferedReader rf(String s) throws Exception{return new BufferedReader(new FileReader(new File(s)));}
static BufferedReader ri() throws Exception{return new BufferedReader(new InputStreamReader(System.in));}
int i(String s){return Integer.parseInt(s.trim());}
 int[] sa(String s1){String s[]=s1.trim().split(" ");int p[]=new int[s.length];for(int i=0;i<s.length;i++)p[i]=Integer.parseInt(s[i]);return p;}
 int bc(long l){return l==0?0:1+bc(l&=l-1);}
 long gcd(long a,long b){ return b==0?a:gcd(b,a%b); }

class node
{
    int n,i,j;
    String s;
    node(int n,int i,int j,String s)
    {
        this.n=n;
        this.i=i;
        this.j=j;
        this.s=s;
    }
}

}
