using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public struct Q{
    static int[][] table0=new[]{
        new[]{ 1, 1, 1, 1},
        new[]{ 1,-1, 1,-1},    
        new[]{ 1,-1,-1, 1},
        new[]{ 1, 1,-1,-1}
    };
    static int[][] table1=new[]{
        new[]{0,1,2,3},
        new[]{1,0,3,2},
        new[]{2,3,0,1},
        new[]{3,2,1,0}
    };
    public int sign;
    public int component;
    public Q(int a, int b)
    {
        sign=a;
        component=b;
    }
    public static bool operator==(Q a, Q b){
        return a.sign==b.sign&&a.component==b.component;
    }
    public static bool operator!=(Q a, Q b){
        return !(a==b);
    }
    public static Q operator*(Q a, Q b){
        return new Q(a.sign*b.sign*table0[a.component][b.component],
                table1[a.component][b.component]);
    }
}
public class A {
    public static int Comp(string a, string b)
    {
        if(a.Length<b.Length){
            return -1;
        }
        else if(a.Length>b.Length){
            return 1;
        }
        else {
            return string.Compare(a,b);
        }
    }
    public void solve()
    {
        var l=Console.ReadLine().Split();
        var L=int.Parse(l[0]);
        var X=l[1];
        int rem=0;
        foreach (var c in X){
            rem*=10;
            rem+=c-'0';
            rem%=4;
        }

        var s=Console.ReadLine();
        var p=new Q(1,0);
        var iPos=-1;
        var ijPos=-1;
        var lastUpdated=0;
        Q total=new Q(1,0);
        for(int j=0;Comp(j.ToString(),X)<0&&ijPos==-1;j++){
            if(j-lastUpdated>4){
                break;
            }
            for(int i=0;i<L;i++){
                var c=s[i];
                Q q=new Q(1,0);
                switch(c){
                    case 'i':
                        q=new Q(1,1);
                        break;
                    case 'j':
                        q=new Q(1,2);
                        break;
                    case 'k':
                        q=new Q(1,3);
                        break;
                }
                p=p*q;
                if(iPos==-1&&p==new Q(1,1)){
                    iPos=L*j+i;
                    lastUpdated=j;
                }
                if(iPos>=0&&ijPos==-1&&p==new Q(1,3)){
                    ijPos=L*j+i;
                    lastUpdated=j;
                }
                /*
                if(j==0){
                    Console.Write("{0}{1} ",(p.sign==-1?"-":""),p.component);
                }
                */
            }
            if(j==0){
                total=new Q(1,0);
                for(int i=0;i<rem;i++){
                    total=total*p;
                }
            }
        }
        if(total==new Q(-1,0)&&iPos!=-1&&ijPos!=-1){
            Console.WriteLine("YES");
        }
        else {
            Console.WriteLine("NO");
        }
    }
    
    public static void Main() {
        var a = new A();
        int n = int.Parse(Console.ReadLine());
        
        for (int i = 1; i <= n; ++i)
        {
            Console.Write("Case #{0}: ", i);
            a.solve();
        }
    }
}
