import java.io.*;
import java.util.*;

public class D {
    static final String filename = "D";

    public static void main(String[] args) throws IOException {
        String finput = filename+".in";
        String foutput = filename+".out";
        Scanner s = new Scanner(new FileInputStream(finput));
        Writer w = new OutputStreamWriter(new FileOutputStream(foutput));
        D solver = new D();
        solver.solve(s, w);
        w.close();
        s.close();
    }
    void solve(Scanner s, Writer w) throws IOException {
        int T = s.nextInt();
        for (int t = 1; t <= T; t++) {
            N=s.nextInt();
            naomi=new double[N];
            ken=new double[N];
            for(int i=0;i<N;i++)naomi[i]=s.nextDouble();
            for(int i=0;i<N;i++)ken[i]=s.nextDouble();
            String ans=solve();
            String out="Case #" + t + ": ";
            out+=ans;
            out+="\n";
            w.write(out);
            System.out.print(out);
        }
    }
    int N;
    double[]naomi;
    double[]ken;
    boolean[]bnaomi;
    boolean[]bken;
    String solve(){
        Arrays.sort(naomi);
        Arrays.sort(ken);
        bnaomi=new boolean[N];
        bken=new boolean[N];
        int dwar=dwar();
        bnaomi=new boolean[N];
        bken=new boolean[N];
        int war=war();
        return dwar+" "+war;
    }
    private int dwar() {
        int cnt=0;
        for(int i=0;i<N;i++){
            int k=can(naomi[i]);
            if(k==-1)k=largest();
            else cnt++;
            bnaomi[i]=true;
            bken[k]=true;
        }
        return cnt;
    }

    private int can(double v) {
        for(int i=N-1;i>=0;i--)if(!bken[i]&&v>ken[i])
            return i;
        return -1;
    }
    private int largest() {
        for(int i=N-1;i>=0;i--)if(!bken[i])
            return i;
        throw new RuntimeException("Not supposed to reach here");
    }
    private int war() {
        int cnt=0;
        for(int i=0;i<N;i++)if(!bnaomi[i]){
            bnaomi[i]=true;
            int k=getBestWKen(naomi[i]);
            bken[k]=true;
            if(naomi[i]>ken[k])
                cnt++;
            //System.out.println(naomi[i]+"|"+ken[k]+"|"+cnt);
        }
        return cnt;
    }
    private int getBestWKen(double x){
        for(int i=0;i<N;i++)
            if(!bken[i]&&ken[i]>x)
                return i;
        for(int i=0;i<N;i++)
            if(!bken[i])
                return i;
        throw new RuntimeException("Not supposed to reach here");
    }
}