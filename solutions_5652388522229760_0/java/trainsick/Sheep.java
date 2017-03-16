
import java.util.Scanner;
import java.io.PrintStream;


public class Sheep {

    PrintStream out=System.out;
    Scanner sc=new Scanner(System.in);
    
    public static void main(String[] args) {
        new Sheep().main2();
    }
    
    void main2() {
        //allbf();
        int c,T,i,n;
        T=sc.nextInt();
        for (c=1;c<=T;c++) {
            out.printf("Case #%d: ",c);
            i=sc.nextInt();
            if (i==0) {
                out.printf("INSOMNIA\n");
            } else {
                n=findn(i);
                out.printf("%d\n",1L*n*i);
            }
        }
    }
    
    int bitdig(long m) {
        int mask=(1<<10)-1;
        do {
            mask &= ~(1<<(m % 10));
            m=m/10;
        } while (m!=0);
        return mask;
    }
    
    int findn(int i) {
        int n;
        int dig=(1<<10)-1;
        for (n=1;n<10_000_000;n++) {
            dig=dig & (bitdig(1L*n*i));
            if (dig==0) break;
        }
        return n;
    }
    
    void allbf() {
        int i,j,n;
        for (i=0;i<1_000_001;i++) {
            n=findn(i);
            if (n>99  || i==1692 || i==1 || i==2 || i==11)
                out.printf("%d %d\n",i,1L*n*i);
        }
    }
    
    
    /*
    int smart3(int m) {
        int d;
        if (m==0) return 10000;
        for (d=0;d<10;d++) {
            
        }
    }
    
    void allsmart() {
        int i;
        for (i=0;i<201;i++) {
            out.printf("%d %d\n",i,smart3(i));
        }
    }
    */
}
