import java.io.*;
import java.text.DecimalFormat;
import java.util.Scanner;

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
        s.close();
    }
    void solve(Scanner s, Writer w) throws IOException {
        int T = s.nextInt();
        for (int t = 1; t <= T; t++) {
            C=s.nextDouble();
            F=s.nextDouble();
            X=s.nextDouble();
            String ans=solve();
            String out="Case #" + t + ": ";
            out+=ans;
            out+="\n";
            w.write(out);
            System.out.print(out);
        }
    }
    double C,F,X;
    String solve(){
        int L=(int)(X+1);
        getProduction(L);
        double ans=X/2;
        for(int i=1;i<=L;i++)
            ans=Math.min(ans,time[i]+X/prod[i]);
        return new DecimalFormat("0.0000000").format(ans);
    }
    double[]time;
    double[]prod;
    void getProduction(int L){
        time=new double[L+1];
        prod=new double[L+1];
        double curr=2.0d;
        time[0]=0;
        prod[0]=curr;
        for(int i=1;i<=L;i++){
            time[i]=C/curr+time[i-1];
            curr+=F;
            prod[i]=curr;
        }
    }
}