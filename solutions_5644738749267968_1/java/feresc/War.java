import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;


/*----------------------------------------------------------------
 *  Author:        Fernando
 *  Written:       12/04/2014
 *  Last updated:  12/04/2014
 *
 *  Compilation:   javac War.java
 *  Execution:     java  War.java
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
public class War {
    private static String input = "D-large";
    private static boolean testing = false;
    
    private static class WarCase {
        public int size;
        public double[] naomi;
        public double[] ken;
        
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append("NAOMI\t: ");
            for (double d: naomi) {sb.append(d);sb.append(' ');}
            sb.append('\n');
            
            sb.append("KEN\t: ");
            for (double d: ken) {sb.append(d);sb.append(' ');}
            sb.append('\n');
            return sb.toString();
            
        }
    }
    
    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
        PrintWriter out = null;
        if (!testing) {
            System.setIn(new FileInputStream(input + ".in"));
            out = new PrintWriter(new FileWriter(input + ".out"));
        }
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int cases = Integer.parseInt(in.readLine());
        for (int i = 0; i < cases; i++) {
            WarCase wc = read(in);
            if (testing)
                System.out.printf("Case #%d: %s\n", i+1, solve(wc));
            else
                out.printf("Case #%d: %s\n", i+1, solve(wc));
        }
        if (out != null)  out.close();
    }
        
    private static WarCase read(BufferedReader in) throws IOException {
        WarCase wc = new WarCase();
        int size = Integer.parseInt(in.readLine());
        String[] ns = in.readLine().split(" ");
        String[] ks = in.readLine().split(" ");
        wc.size = size;
        wc.naomi = new double[size];
        wc.ken = new double[size];
        
        for (int i = 0; i < size; i++) 
        {
            wc.naomi[i] = Double.parseDouble(ns[i]);
            wc.ken[i] = Double.parseDouble(ks[i]);
        }
        
        return wc;
    }
    
    private static String solve(WarCase wc) {
        Arrays.sort(wc.naomi);
        Arrays.sort(wc.ken);
        //System.out.print(wc);
        return cheatWins(wc) + " " + normalWins(wc);    
    }

    private static int cheatWins(WarCase wc) {
        int wins = 0;
        int kmax = wc.size - 1;
        int kmin = 0;
        for (int i = 0; i < wc.size; i++) {
            double nplay = wc.naomi[i];
            double kplay = 0;
            if (nplay > wc.ken[kmin]) {
                kplay = wc.ken[kmin++];
            }
            else {
                kplay = wc.ken[kmax--]; 
            }
            
            if (nplay  > kplay)
                wins++;
        }
        return wins;
    }

    private static int normalWins(WarCase wc) {
        int wins = 0;
        TreeSet<Double> kenSet = new TreeSet<>();
        for (int i = 0; i < wc.size; i++) {
            kenSet.add(wc.ken[i]);
        }
        for (int i = 0; i < wc.size; i++) {
            Double kenPlay = kenSet.ceiling(wc.naomi[i]); 
            if ( kenPlay != null) {
                kenSet.remove(kenPlay);
            }
            else {
                kenSet.remove(kenSet.ceiling(0.0));
                wins++;
            }
        }
        return wins;
    }
}
