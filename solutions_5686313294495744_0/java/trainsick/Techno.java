
import java.util.Scanner;
import java.io.PrintStream;
import java.util.HashMap;


public class Techno {
    
    public static void main(String[] args) {
        new Techno().main2();
    }
    
    Scanner sc=new Scanner(System.in);
    PrintStream out=System.out;
    
    void main2() {
        int i,T;
        T=sc.nextInt();
        for (i=1;i<=T;i++) {
            out.printf("Case #%d: ",i);
            problem();
        }
    }
    
    int N;
    
    HashMap<String,Integer> topic1;
    HashMap<String,Integer> topic2;  
    
    int[] title;
    
    Node[] all;
    
    void readstuff() {
        int i;
        String t1,t2;
        int m1,m2;
        for (i=0;i<N;i++) {
            t1=sc.next();
            t2=sc.next();
            if (topic1.containsKey(t1)) m1=topic1.get(t1);
            else {
                m1=1<<(topic1.size());
                topic1.put(t1,m1);
            }
            if (topic2.containsKey(t2)) m2=topic2.get(t2);
            else {
                m2=1<<(16+topic2.size());
                topic2.put(t2,m2);
            }
            title[i]=m1 | m2;
        }
    }
    
    void calcAll(int n) {
        int i;
        int ni;
        int b,m;
        Node q,p;
        if (all[n]!=null) return;
        q=null;
        p=null;
        for (i=0;i<N;i++) {
            if (((1<<i) & n)==0) continue;
            ni=n & ~(1<<i);
            calcAll(ni);
            p=all[ni];
            b=p.best;
            m=p.mask & title[i];
            if (m==title[i]) b++;
            if (q==null) {q=new Node(); q.mask=p.mask | title[i]; q.best=b;}
            if (q.best<b) q.best=b; 
        }
        all[n]=q;
    }
    
    void problem() {
        N=sc.nextInt();
        title=new int[N];
        topic1=new HashMap<String,Integer>();
        topic2=new HashMap<String,Integer>();
        all=new Node[1<<N];

        readstuff();
        all[0]=new Node();
        calcAll((1<<N)-1);
        out.println(all[(1<<N)-1].best);
        
    }
    
    static class Node {
        int best;
        int mask;
    }
    
}
