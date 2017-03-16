package codejam2014;


import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

/**
 * Title: CookieClickerAlpha
 * 
 * Link: https://code.google.com/codejam/contest/2974486/dashboard#s=p1
 */
public class CookieClickerAlpha {
    public static void main(String... args) throws Exception {
        //resolve("2014-QR-cookie-tiny");
        //resolve("2014-QR-cookie-small0");
        //resolve("2014-QR-cookie-small1");
        resolve("2014-QR-cookie-large");
    }
    
    private static void resolve(String dataFile) throws Exception {
        Locale.setDefault(Locale.US);
        // Initialize input and output.
        Scanner scanner = new Scanner(new File(dataFile + ".in"));
        PrintWriter printer = new PrintWriter(dataFile + ".out");
        
        // Read number of test cases.
        int T = scanner.nextInt();
        
        // Evaluate each test case.
        for(int t=0; t<T; t++) {
            // Read input.
            double C = scanner.nextDouble();
            double F = scanner.nextDouble();
            double X = scanner.nextDouble();
            
            // Calculate result.
            //System.out.println(C + " - " + F + " - " + X);
            double result = resolveTestCase(C, F, X);
            
            // Print output.
            String message = "Case #" + (t+1) + ": " + String.format("%.7f", result) + "\n";
            System.out.printf(message);
            printer.append(message);
        }
        
        printer.flush();
        printer.close();
    }
    
    private static double resolveTestCase(final double farmCost, final double farmRate, final double goal) {
        // Calculate number of farms to buy:  X/(2 + n*F) <= (X + C)/(2 + n*F + F)
        long n = 0;
        double aprox = (farmRate * goal - 2*farmCost - farmRate*farmCost) / (farmRate*farmCost); 
        if(aprox > 0) n = (long) Math.ceil(aprox);
        //System.out.println("n: " + n + " - " + aprox);   
        
        // Since 'n' is round, try two alternatives.
        double hooker1 = blackJack(farmCost, farmRate, goal, n);
        double hooker2 = blackJack(farmCost, farmRate, goal, n-1);
        
        return hooker1 < hooker2? hooker1 : hooker2;
    }
    
    public static double blackJack(final double farmCost, final double farmRate, final double goal, long n) {
        // Verify if at least one farm is going to be buyed.
        double rate = 2.0;
        double farmTime = 0.0;
        if(n > 0) {
            // Calculate the time need to buy all the farms.
            for(long i=0; i<n; i++) {
                farmTime += farmCost/rate;
                rate += farmRate;
            }
        }
        
        // Sum farm time to goal time.
        return farmTime + goal/rate;
    }
}
