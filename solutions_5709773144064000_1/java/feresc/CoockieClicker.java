import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Locale;


/*----------------------------------------------------------------
 *  Author:        Fernando
 *  Written:       12/04/2014
 *  Last updated:  12/04/2014
 *
 *  Compilation:   javac CoockeiClicker.java
 *  Execution:     java  CoockeiClicker.java
 *  
 *  <Insert description here>
 *
 *  
 *
 *----------------------------------------------------------------*/

/**
 * @author Fernando
 *
 */
public class CoockieClicker {
    private static String input = "B-large";
    private static boolean testing = false;
    
    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
        // TODO Auto-generated method stub
        PrintWriter out = null;
        if (!testing) {
            System.setIn(new FileInputStream(input + ".in"));
            out = new PrintWriter(new FileWriter(input + ".out"));
        }
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int cases = Integer.parseInt(in.readLine());
        for (int i = 0; i < cases; i++) {
            Cookie trick = read(in);
            if (testing)
                System.out.printf(Locale.US, "Case #%d: %.7f\n", i+1, solve(trick));
            else
                out.printf(Locale.US, "Case #%d: %.7f\n", i+1, solve(trick));
        }
        if (out != null)  out.close();
    }
    
    static class Cookie {
        Cookie(double cost, double prod, double go) {
            rate = 2.0;
            farmCost = cost;
            farmProduction = prod;
            goal = go;           
        }
        public double rate;
        public double farmCost;
        public double farmProduction;
        public double goal;        
    }
    
    private static Cookie read(BufferedReader in) throws IOException {
        String [] vals = in.readLine().split(" ");
        return new Cookie(Double.parseDouble(vals[0]), Double.parseDouble(vals[1]), Double.parseDouble(vals[2]));
    }
    
    private static double solve(Cookie c) {        
        double timeToFarm = c.farmCost / c.rate;
        double timeToGoal = c.goal / c.rate;
        double timeToGoalWithFarm = timeToFarm + c.goal / (c.rate + c.farmProduction);
        if (timeToGoal <= timeToGoalWithFarm) {
            return timeToGoal;
        }
        else {
            c.rate = c.rate + c.farmProduction;
            return timeToFarm + solve(c); 
        }    
    }
}
