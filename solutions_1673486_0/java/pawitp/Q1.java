import java.util.ArrayList;
import java.util.Scanner;


public class Q1 {
    
    public static class Result {
        int strat;
        int keys;
        double prob;
        
        public Result(int strat, int keys, double prob) {
            this.strat = strat;
            this.keys = keys;
            this.prob = prob;
        }
        
        @Override
        public String toString() {
            return String.format("[%d, %d, %f]", strat, keys, prob);
        }
    }
    
    // aaaXa a for correct, X for incorrect
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();
        
        for (int i = 0; i < cases; i++) {
            int typed = in.nextInt();
            int total = in.nextInt();
            double[] prob = new double[typed];
            for (int j = 0; j < typed; j++) {
                prob[j] = in.nextDouble();
            }
            
            System.out.printf("Case #%d: %.7f\n", i + 1, calculate(typed, total, prob));
        }
    }
    
    public static double calculate(int typed, int total, double[] prob) {
        ArrayList<String> perms = permutation(typed);
        int strats = typed + 2;
        Result[][] results = new Result[perms.size()][strats];
        for (int i = 0; i < perms.size(); i++) {
            ArrayList<Result> localRes = strat(perms.get(i), total, prob);
            for (int j = 0; j < localRes.size(); j++) {
                results[i][j] = localRes.get(j);
            }
        }
        
        // Compute the best
        double best = Double.MAX_VALUE;
        for (int i = 0; i < strats; i++) {
            double tot = 0;
            for (int j = 0; j < perms.size(); j++) {
                Result res = results[j][i];
                tot += res.keys * res.prob;
            }
            
            if (tot < best) best = tot;
        }
        
        return best;
    }
    
    public static ArrayList<Result> strat(String typed, int total, double[] prob) {
        ArrayList<Result> results = new ArrayList<Result>();
        
        // Calculate prob
        double curProb = 1;
        for (int i = 0; i < typed.length(); i++) {
            if (typed.charAt(i) == 'X') curProb *= (1 - prob[i]);
            else curProb *= prob[i];
        }
        
        // Strat 0: Keep typing
        if (!typed.contains("X")) {
            results.add(new Result(0, total - typed.length() + 1, curProb));
        }
        else {
            // total - pass.length() + 1 + total + 1
            results.add(new Result(0, total + total + 2 - typed.length(), curProb));
        }
        
        // Strat 1: Press enter
        results.add(new Result(1, total + 2, curProb));
        
        // Strat 2 to 2 + typed.length() - 1
        for (int i = 1; i <= typed.length(); i++) {
            int id = i + 1;
            
            // i + i + (total - typed.length())
            int base = i + i + total - typed.length();
            
            int fIndex = typed.indexOf("X");
            if (fIndex < (typed.length() - i) && fIndex != -1) {
                // still wrong :(
                // base + enter + total + enter
                results.add(new Result(id, base + 2 + total, curProb));
            }
            else {
                // we're good this time
                // base + enter
                results.add(new Result(id, base + 1, curProb));
            }
        }
        
        return results;
    }
    
    public static ArrayList<String> permutation(int num) {
        ArrayList<String> perms = new ArrayList<String>();
        permutation(num, 0, perms, "");
        return perms;
    }
    
    public static void permutation(int num, int i, ArrayList<String> perms, String cur) {
        if (i == num) {
            perms.add(cur);
            return;
        }
        
        permutation(num, i + 1, perms, cur + "a");
        permutation(num, i + 1, perms, cur + "X");
    }
}
