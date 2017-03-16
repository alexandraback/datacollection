package qualification;

import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class CookieClickerAlpha {
    
    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);
        File inputFile = new File("B-large.in");
        Scanner in = new Scanner(inputFile);
        File outputFile = new File("output.txt");
        PrintWriter out = new PrintWriter(outputFile);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            double C = in.nextDouble();
            double F = in.nextDouble();
            double X = in.nextDouble();
            double rate = 2;
            double timeSpent = 0;
            double timeWithoutANewFarm = X/rate;
            double timeWithANewFarm = C/rate+X/(rate+F);
            while (timeWithANewFarm < timeWithoutANewFarm) {
                timeSpent += C/rate;
                rate += F;
                timeWithoutANewFarm = X/rate;
                timeWithANewFarm = C/rate+X/(rate+F);
            }
            timeSpent += X/rate;
            
            out.println("Case #"+(t+1)+": "+timeSpent);
        }

        out.close();
    }
    
}
