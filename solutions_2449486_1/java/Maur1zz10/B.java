import java.io.*;
import java.util.*;


public class B {
    static final String filename = "B";

    public static void main(String[] args) throws IOException {
        String finput = filename+".in";
        String foutput = filename+".out";
        Scanner s = new Scanner(new FileInputStream(finput));
        Writer w = new OutputStreamWriter(new FileOutputStream(foutput));
        B solver = new B();
        solver.solve(s, w);
        w.close();
    }

    void solve(Scanner s, Writer w) throws IOException {
        int T = s.nextInt();
        for (int t = 1; t <= T; t++) {
            int N=s.nextInt();
            int M=s.nextInt();
            int[][]A=new int[N][M];
            for(int n=0;n<N;n++)for(int m=0;m<M;m++)
                A[n][m]=s.nextInt();

            String ans=solve(A);

            String out="Case #" + t + ": ";
            out+=ans;
            out+="\n";

            w.write(out);
            System.out.print(out);
        }

    }

    void print(int[][]A){
        System.out.println("--------------");
        for(int i=0;i<A.length;i++){
            for(int j=0;j<A[i].length;j++){
                System.out.print(A[i][j]+"\t");
            }
            System.out.println();
        }
        System.out.println("--------------");
    }

    String solve(int[][]A){
        int[][]L=new int[A.length][A[0].length];
        for(int i=0;i<L.length;i++)for(int j=0;j<L[i].length;j++)
            L[i][j]=100;
        while(!check(A,L)){
            boolean f=true;
            int[]p=findMax(A,L);
            if(check(A,L,p[0],0,0,1,A[p[0]][p[1]])){
                cut(A,L,p[0],0,0,1,A[p[0]][p[1]]);
                //System.out.println("Cutting "+p[0]+"|"+0+"|"+0+"|"+1+"|"+A[p[0]][p[1]]);
                //print(L);
                f=false;
            }
            if(check(A,L,0,p[1],1,0,A[p[0]][p[1]])){
                cut(A,L,0,p[1],1,0,A[p[0]][p[1]]);
                //System.out.println("Cutting "+0+"|"+p[1]+"|"+1+"|"+0+"|"+A[p[0]][p[1]]);
                //print(L);
                f=false;
            }
            if(f)
                return "NO";
        }
        return "YES";
    }

    void cut(int[][] A, int[][] L, int h, int w, int dx, int dy,int z) {
        while(h<A.length&&w<A[h].length){
            L[h][w]=z;
            h+=dx;
            w+=dy;
        }
    }

    boolean check(int[][] A, int[][] L, int h, int w, int dx, int dy,int z) {
        while(h<A.length&&w<A[h].length){
            if(A[h][w]>z)
                return false;
            h+=dx;
            w+=dy;
        }
        return true;
    }

    int[] findMax(int[][]A,int[][]L){
        int[]r={-1,-1};
        int max=0;
        for(int i=0;i<L.length;i++)for(int j=0;j<L[i].length;j++){
            if(A[i][j]<L[i][j]&&A[i][j]>max){
                max=A[i][j];
                r[0]=i;
                r[1]=j;
            }
        }
        return r;
    }

    boolean check(int[][]A,int[][]L){
        for(int i=0;i<L.length;i++)for(int j=0;j<L[i].length;j++)
            if(A[i][j]!=L[i][j])
                return false;
        return true;
    }
}