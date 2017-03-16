import java.io.PrintWriter;
import java.util.Scanner;
/**
 *
 * @author pulasthi
 */
public class B1C {
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter("B.txt");
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            out.println("Case #" + (i + 1) + ":");
            double D = sc.nextDouble();
            int N = sc.nextInt();
            int A = sc.nextInt();
            double[] t = new double[N];
            double[] x = new double[N];
            double fin = 0.0;
            for (int j = 0; j < N; j++) {
                t[j] = sc.nextDouble();
                x[j] = sc.nextDouble();                
                if(x[j]>=D && j>0){
                    double addis = D - x[j-1];
                    fin = (t[j]-t[j-1])*addis/(x[j]-x[j-1]);
                }
            }
            double[] a = new double[A];
            for (int j = 0; j < A; j++) {
                a[j] = sc.nextDouble();
            }
            for (int j = 0; j < A; j++) {
                double stdelay = 0;
                double tk;
                for (int k = 0; k < N; k++) {
                    if(x[k]<=D){
                        tk = Math.sqrt(2*x[k]/a[j]);
                        stdelay = Math.max(stdelay, t[k]-tk);
                    }
                }
                tk = Math.sqrt(2*D/a[j]);
                stdelay = Math.max(stdelay, fin-tk);
                double res = Math.sqrt(2*D/a[j])+stdelay;
                out.println(String.format("%.6f", res));
            }
        }
        out.flush();
        out.close();
    } 
}
