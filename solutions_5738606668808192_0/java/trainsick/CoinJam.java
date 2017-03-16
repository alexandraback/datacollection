
import java.util.Scanner;
import java.io.PrintStream;
import java.math.BigInteger;

public class CoinJam {
    
    public static void main(String[] args) {
        new CoinJam().main2();
    }
    
    Scanner sc=new Scanner(System.in);
    PrintStream out=System.out;
    
    int[] prime;
    int[][] mods;
    
    int N=16,J=50;
    
    int M;
    int bit;
    
    
    void main2() {
        makePrimes(100);
        int T=sc.nextInt();
        N=sc.nextInt();
        J=sc.nextInt();
        bit=(1<<(N-1))+1;
        startmods();
        out.printf("Case #1:\n");
        
        search();
    }
    
    void search() {
        int i,d;
        int[] f=new int[11];
        boolean first=true;
        loop:
        while (J>0) {
            if (!first) {
                bit+=2;
                increment();
            }
            first=false;
            for (d=2;d<11;d++) {
                for (i=0;i<M;i++) {
                    if (mods[d][i]==0) {f[d]=prime[i]; break;}
                }
                if (i==M) continue loop;
            }
            out.printf("%s ",Integer.toBinaryString(bit));
            for (d=2;d<11;d++) {
                out.printf("%d ",f[d]);
                //checkBig(bit,d,f[d],0);
            }
            out.println();
            J--;
        }
    }
    
    void increment(int d, int i) {
        int p=prime[i];
        int b=1;
        int m=mods[d][i];
        int dd=(d) % p;
        /*if (!checkBig(bit-2,d,p,m))
            out.printf("prebit=%x d=%d p=%d m=%d  b=%d \n",
                        bit-2    ,d   ,p   ,m, b);
        */
        do {
            if (((1<<(b))&bit)==0) {
                m=(m+p-dd) % p;
            } else {
                m=(m+dd) % p;
                break;
            }
            b++;
            dd=(dd*d) % p;
        } while(true);
        mods[d][i]=m;
        /*
        if (!checkBig(bit,d,p,m))
            out.printf("bit=%x d=%d p=%d m=%d  b=%d \n",
                        bit    ,d   ,p   ,m, b);
        */
    }
    
    void increment() {
        int d,i;
        for (d=2;d<11;d++) {
            for (i=0;i<M;i++) {
                increment(d,i);
            }
        }
    }
    
    boolean isPrime(int n) {
        int i;
        for (i=2;i*i<=n;i++) {
            if (n % i==0) return false;
        }
        return true;
    }
    
    void makePrimes(int m) {
        M=m;
        prime=new int[m];
        mods=new int[11][m];
        int i=0,j=2;
        while (i<m) {
            if (isPrime(j)) prime[i++]=j;
            j++;
        }
    }
    
    void startmods() {
        int d,j,b;
        for (d=2;d<11;d++) {
            for (j=0;j<M;j++) {
                mods[d][j]=basemod(bit,d,prime[j]);
                /*
                b=basemodBig(bit,d,prime[j]);
                if (mods[d][j]!=b)
                    out.printf("bad start mod(%d,%d)=%d vs %d\n",
                                               d, prime[j],mods[d][j],b); 
                */
            }
        }
    }
    
    int basemod(int b, int d, int p) {
        int r=0;
        int dd=1;
        while (b!=0) {
            if ((b & 1)!=0) r=(r+dd) % p;
            b>>=1;
            dd=(dd*d) % p;
        }
        return r;
    }
    
    int basemodBig(int b, int d, int p) {
        String s=Integer.toBinaryString(b);
        BigInteger big=new BigInteger(s,d);
        big=big.mod(BigInteger.valueOf(p));
        return big.intValue();
    }
    
    boolean checkBig(int b, int d, int f, int x) {
        String s=Integer.toBinaryString(b);
        BigInteger big=new BigInteger(s,d);
        big=big.mod(BigInteger.valueOf(f));
        if (! big.equals(BigInteger.valueOf(x))) {
            out.printf("FAIL ");
            return false;
        }
        return true;
    }
    
    
    
}
