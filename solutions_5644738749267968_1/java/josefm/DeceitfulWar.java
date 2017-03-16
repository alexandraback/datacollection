package codejam2014;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

/**
 * Title: DeceitfulWar
 * 
 * Link: https://code.google.com/codejam/contest/2974486/dashboard#s=p3
 */
public class DeceitfulWar {
    public static void main(String... args) throws Exception {
        //resolve("2014-QR-war-tiny");
        //resolve("2014-QR-war-small0");
        //resolve("2014-QR-war-small1");
        resolve("2014-QR-war-large");
    }
    
    private static void resolve(String dataFile) throws Exception {
        // Initialize input and output.
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(new File(dataFile + ".in"));
        PrintWriter printer = new PrintWriter(dataFile + ".out");
        
        // Read number of test cases.
        int T = scanner.nextInt();
        
        // Evaluate each test case.
        for(int t=0; t<T; t++) {
            // Read input.
            int cant = scanner.nextInt();
            double[] naomi = new double[cant]; 
            double[] ken = new double[cant]; 
            for(int i=0; i<cant; i++) naomi[i] = scanner.nextDouble();
            for(int i=0; i<cant; i++) ken[i] = scanner.nextDouble();
            
            // Calculate result.
            String result = resolveTestCase(naomi, ken, cant);
            
            // Print output.
            String message = "Case #" + (t+1) + ": " + (result) + "\n";
            System.out.print(message);
            printer.append(message);
        }
        
        printer.flush();
        printer.close();
    }
    
    private static String resolveTestCase(double[] naomi, double[] ken, int cant) {
        int war;
        int deceitful;
        
        // Sort numbers.
        Arrays.sort(naomi);
        Arrays.sort(ken);
        System.out.println(Arrays.toString(naomi));
        System.out.println(Arrays.toString(ken));

        // Calculate War, by calculating the pair of numbers in which Ken beats Naomi.
        war = cant;
        int k = cant-1;
        for(int i=cant-1; i>=0 && k>=0; i--) {
            boolean more = false;
            while(!more && k>=0) {
                if(ken[i] > naomi[k]) {
                    more = true;
                    war--;
                }
                k--;
            }
        }
        
        if(cant == 1) {
            deceitful = war;
        } else {
            // In Deceitful War, we must find the smallest number of Noemi which is greater than the smallets number of Ken.
            int h = 0;
            for(int i=0; i<cant; i++) {
                if(naomi[i] > ken[h]) {
                   h++;
                }
            }
            deceitful = h;
        }
        
        return deceitful + " " + war;
    }
}

