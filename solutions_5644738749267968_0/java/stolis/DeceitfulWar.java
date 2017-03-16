package qualification;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class DeceitfulWar {
    
    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);
        File inputFile = new File("D-small-attempt0.in");
        Scanner in = new Scanner(inputFile);
        File outputFile = new File("output.txt");
        PrintWriter out = new PrintWriter(outputFile);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            int N = in.nextInt();
            double[] naomi = new double[N];
            double[] ken = new double[N];
            for (int n=0; n<N; n++) {
                naomi[n] = in.nextDouble();
            }
            for (int n=0; n<N; n++) {
                ken[n] = in.nextDouble();
            }
            Arrays.sort(naomi);
            Arrays.sort(ken);
            
            int warScore = 0;
            int kenIndex = N-1;
            for (int n=N-1; n>=0; n--) {
                if (naomi[n] > ken[kenIndex]) {
                    warScore++;
                } else {
                    kenIndex--;
                }
            }
            
            int deceitfulWarScore = 0;
            int naomiIndex = N-1;
            for (int n=N-1; n>=0; n--) {
                if (ken[n] < naomi[naomiIndex]) {
                    deceitfulWarScore++;
                    naomiIndex--;
                }
            }            

            out.println("Case #"+(t+1)+": "+deceitfulWarScore+" "+warScore);
        }

        out.close();
    }
    
}
