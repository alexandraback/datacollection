import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class A{
    public static void main(String[] args) throws Exception{
        new A().run();
    }

    int A, B;
    double[] p;
    double[] fail;

    void run() throws Exception{
        //Scanner sc = new Scanner(System.in);
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available
        int T = Integer.parseInt(sc.readLine());
        for(int o = 1; o <= T; o++){
            String[] AB = sc.readLine().split(" ");
            A = Integer.parseInt(AB[0]);
            B = Integer.parseInt(AB[1]);
            p = new double[A];
            StringTokenizer st = new StringTokenizer(sc.readLine(), " ");
            for(int i = 0; i < A; i++)
                p[i] = Double.parseDouble(st.nextToken());
            fail = new double[A+1];
            double correct = 1.0;
            for(int i = 0; i < A; i++){
                fail[i] = correct * (1.0 - p[i]);
                correct *= p[i];
            }
            fail[A] = correct;
            //for(int i = 0; i < fail.length; i++)System.out.printf("%.2f ", fail[i]);System.out.println();
            int rest = B-A;
            double ans = 2+B;
            for(int i = 0; i < A; i++){
                double sum = 0;
                for(int j = 0; j < fail.length; j++){
                    int need = A - j;
                    if(need <= i)
                        sum += (i+i+rest+1)*fail[j];
                    else
                        sum += (i+i+rest+1+B+1)*fail[j];
                }
                //System.out.println(sum);
                ans = min(ans, sum);
            }
            System.out.printf("Case #%d: %.9f\n", o, ans);
        }
    }
}
