
import java.util.Scanner;
import java.io.PrintStream;
import java.util.Random;
import java.math.BigInteger;
import java.util.HashSet;

public class Coin2 {
    public static void main(String[] args) {
        new Coin2().main2();
    }
    
    Scanner sc=new Scanner(System.in);
    PrintStream out=System.out;
    Random rnd=new Random();
    
    int N,J;
    long bit;
    
    void main2() {
        int T;
        T=sc.nextInt();
        out.printf("Case #1:\n");
        N=sc.nextInt();
        J=sc.nextInt();
        search();
    }
    
    void search() {
        int d;
        String bitstr;
        BigInteger three=BigInteger.valueOf(3);
        int[] factor;
        HashSet<Long> done=new HashSet<>();
        whiler:
        while (J>0) {
            bit=rnd.nextInt();
            bit &=(1L<<N)-1;
            bit |=1;
            bit |=(1L<<(N-1));
            bitstr=Long.toBinaryString(bit);
            if (done.contains(bit)) continue;
            for (d=2;d<11;d++) {
                BigInteger a=new BigInteger(bitstr,d);
                BigInteger a1=a.subtract(BigInteger.ONE);
                a=three.modPow(a1,a);
                if (a.equals(BigInteger.ONE)) continue whiler;
            }
            if ((factor=easyfactor(bitstr))==null) continue;
            out.printf("%s ",bitstr);
            for (d=2;d<11;d++) {
                out.printf("%d ",factor[d]);
            }
            out.printf("\n");
            done.add(bit);
            J--;
        }
            
    }
    
    int[] easyfactor(String bitstr) {
        int[] r=new int[11];
        int d;
        for (d=2;d<11;d++) {
            r[d]=easyfactor(bitstr,d);
            if (r[d]==0) return null;
        }
        return r;
    }
    
    int easyfactor(String bitstr, int d) {
        int f,i,dx,m;
        for (f=2;f<1000;f++) {
            m=0;
            for (i=0;i<bitstr.length();i++) {
                m=(m*d) % f;
                if (bitstr.charAt(i)=='1') m++;
            }
            m=m % f;
            if (m==0) return f;
        }
        return 0;
    }
    
}
