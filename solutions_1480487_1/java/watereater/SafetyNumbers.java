
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class SafetyNumbers {

    static Scanner in;

    public static void main(String argsp[]) throws FileNotFoundException {
        in = new Scanner(new File("safe.in"));
        PrintWriter out = new PrintWriter(new File("safe.out"));
        int cases = in.nextInt();
        for (int c = 1; c <= cases; c++) {
            String o = "Case #" + c + ":";
            int N = in.nextInt();
            double total = 0;
            int a[] = new int[N];
            for (int i = 0; i < N; i++) {
                int temp = in.nextInt();
                total += temp;
                a[i] = temp;
            }
            double dAvg = total / N / N;
            DecimalFormat df = new DecimalFormat("0.0######");
            if (N == 2) {
                for (int i = 0; i < N; i++) {
                    double d = (total - a[i]) / (double) total * 100;
                    o += " " + df.format(d);
                }
            } else {


                double output[] = new double[N];
                boolean redo = false;
                int n = N;
                for (int i = 0; i < N; i++) {
                    double plus = 0;
                    for (int j = 0; j < N; j++) {
                        if (j == i) {
                            continue;
                        }
                        plus += a[j] - a[i];
                    }
                    plus /= total;
                    plus += 1;
                    if (plus < 0) {
                        plus = 0;
                        n--;
                        redo = true;
                    }
                    double d = (plus) / N * 100;
                    output[i] = d;


                }
                if (redo) {
                    for (int i = 0; i < N; i++) {
                        if(output[i]==0.0) continue;
                        double plus = 0;
                        for (int j = 0; j < N; j++) {
                            if (j == i) {
                                continue;
                            }
                            if(output[j]==0.0) continue;
                            plus += a[j] - a[i];
                        }
                        plus /= total;
                        plus += 1;
                        
                        double d = (plus) / n * 100;
                        output[i] = d;
                    }                    
                }//redo
                for(int i = 0; i < N; i++){
                    o += " " + df.format(output[i]);
                }
            }//else
            out.println(o);
        }
        out.close();
    }
}
