/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam;

/**
 *
 * @author Raj90 
 */
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class R1C_2014_A {
    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer stk;

    public static void main(String[] args) throws Exception {
        //in = new BufferedReader(new InputStreamReader(System.in));
        in = new BufferedReader(new FileReader("test.txt"));
        out=new PrintWriter(new FileWriter("R1C_A.txt"));
        stk = new StringTokenizer(in.readLine());
        int i,j,k,l,m,n,t;String s,s1[];long a,b,c,d,gcd;;
        t=ni();
        for(i=0;i<t;i++){
        s=ns();
            System.out.println(s);
        s1=s.split("/");
        m=0;
        a=Long.parseLong(s1[0]);
        b=Long.parseLong(s1[1]);
        gcd=gcd(a,b);
        a=a/gcd;
        b=b/gcd;
        c=1;
        int ans=check(a, b);
        boolean f=false;
        while(c!=0){
            gcd=gcd(a,b);
        a=a/gcd;
        b=b/gcd;
            n=check(a, b);
            m+=n;
            
            if(m>40){
               
                break;
            }
            c=remainder(n, a, b);
            //System.out.println("n = "+n+"c = "+c);
            if(m<=40&&c==0)
                f=true;
            a=c;
            
        }
        if(f)
        out.println("Case #"+(i+1)+": "+ans);
        else
            out.println("Case #"+(i+1)+": impossible");
        }
        out.flush();
        out.close();
}
    static int check(long a, long b){
        int i=0;long num=a;
        while(num<b){
            num*=2;
            i++;
        }
        return i;
    }
    static long remainder(int i,long a,long b){
        long x,y,c;
        x=(long) Math.pow(2.0, i)*a;
        y=x-b;
        return y;
    }
static void printf(String format, Object... args) {
        System.out.printf(format, args);
        out.printf(format, args);
    }

    static int ni() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Integer.parseInt(stk.nextToken());
    }

    static long nl() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Long.parseLong(stk.nextToken());
    }

    static double nd() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Double.parseDouble(stk.nextToken());
    }

    static String ns() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return stk.nextToken();
    }

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    static int max(int a, int b) {
        return a > b ? a : b;
    }

    static long min(long a, long b) {
        return a < b ? a : b;
    }

    static long max(long a, long b) {
        return a > b ? a : b;
    }

    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}


