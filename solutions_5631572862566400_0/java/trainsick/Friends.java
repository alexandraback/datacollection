
import java.util.Scanner;
import java.io.PrintStream;

public class Friends {
    
    public static void main(String[] args) {
        new Friends().main2();
    }
    
    Scanner sc=new Scanner(System.in);
    PrintStream out=System.out;
    
    int N;
    int[] F;
    int[] perm;
    int biggest;
    
    void main2() {
        int i,T;
        T=sc.nextInt();
        for (i=1;i<=T;i++) {
            out.printf("Case #%d: ",i);
            problem();
        }
    }
    
    void problem() {
        int i;
        N=sc.nextInt();
        F=new int[N];
        perm=new int[N];
        for (i=0;i<N;i++) F[i]=sc.nextInt()-1;
        biggest=0;
        permute(0,0);
        out.printf("%d\n",biggest);
    }
    
    void permute(int a, int used) {
        int i;
        if (a>biggest && checkbff(a)) biggest=a;
        if (a>=N) {
            //for (int x : perm) out.print(x+" ");
            //out.println();
            return;
        }
        for (i=0;i<N;i++) {
            if ((used & (1<<i))!=0) continue;
            perm[a]=i;
            permute(a+1,used | (1<<i));
        }
    }
    
    boolean checkbff(int a) {
        --a;
        int i;
        if (a==0) return false;
        for (i=1;i<a;i++) {
            if (F[perm[i]]!=perm[i-1] && F[perm[i]]!=perm[i+1])
                return false;
        }
        if (F[perm[0]]!=perm[1] && F[perm[0]]!=perm[a]) return false;
        if (F[perm[a]]!=perm[0] && F[perm[a]]!=perm[a-1]) return false;
        return true;
    }
    
}
