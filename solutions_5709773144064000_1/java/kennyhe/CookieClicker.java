

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class CookieClicker {

    /**
     * @param args
     */
    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("Please add the file name as the first parameter");
        }
        
        try {
            BufferedReader in = new BufferedReader(new FileReader(args[0]));
            int cases = Integer.parseInt(in.readLine());
            
            double c, f, x;
            int maxFarmCount = 0;
            
            for (int caseNo = 1; caseNo <= cases; caseNo++) {
                // get test case data
                String[] vars = in.readLine().split("\\s");
                c = Double.parseDouble(vars[0]);
                f = Double.parseDouble(vars[1]);
                x = Double.parseDouble(vars[2]);
                
                maxFarmCount = getMaxFarmsToBuy(c, f, x);
                
                System.out.format("Case #%d: %.7f\n", caseNo, getGamingTime(maxFarmCount, c, f, x));
            }
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    
    /**
     * Count maximum farms need to buy
     * @param C
     * @param F
     * @param X
     * @return The maximum farms need to buy to minimize the gaming time
     */
    public static int getMaxFarmsToBuy(double C, double F, double X) {
        /*
         * Assume try k buys, then delta in the k'th buy to the (k-1)th buy is:
         * Delta = X/(2 + k*F) - (X-C)/[2+(k-1)*F].
         * To get the max k while satisfy Delta < 0:
         * k < X/C - 2/F.
         */
        double tries = X/C - 2/F;
        if (tries < 0)
            return 0;
        
        return (int) Math.floor(tries);
    }


    /**
     * Count the gaming time
     * @param farms The count of farms to buy
     * @param C
     * @param F
     * @param X
     * @return
     */
    public static double getGamingTime(int farms, double C, double F, double X) {
        if (farms <= 0) {
            return X / 2.0;
        }
        
        double time = X / (2.0 + farms * F);
        double farmProduce = 0.0d;
        
        for (int i = 0; i < farms; i++) {
            time += (C / (2.0 + farmProduce));
            farmProduce += F;
        }
        
        return time;
    }

}
