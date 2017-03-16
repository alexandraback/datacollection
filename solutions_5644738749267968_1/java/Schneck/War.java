import java.io.*;
import java.util.*;

public class War {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        int N = scan.nextInt();
        List<Double> naomi = new ArrayList<Double>();
        line = in.readLine();
        scan = new Scanner(line);
        for (int i = 0; i < N; i++) {
            naomi.add(scan.nextDouble());
        }
        List<Double> ken = new ArrayList<Double>();
        line = in.readLine();
        scan = new Scanner(line);
        for (int i = 0; i < N; i++) {
            ken.add(scan.nextDouble());
        }
        System.out.println(optimalDeceitfulWar(naomi, ken) + " " + optimalWar(naomi, ken));
    }
    
    public int optimalWar(List<Double> naomi, List<Double> ken) {
        if (naomi.isEmpty()) return 0;
        double naomiLargest = -1.0;
        for (Double x : naomi) {
            if (x > naomiLargest) naomiLargest = x;
        }
        double kenChoice = -1.0;
        for (Double x : ken) {
            if (x > naomiLargest && (kenChoice < 0 || x < kenChoice)) kenChoice = x;
        }
        boolean naomiWon = kenChoice < 0;
        if (naomiWon) {
            for (Double x : ken) {
                if (kenChoice < 0 || x < kenChoice) kenChoice = x;
            }
        }
        List<Double> newNaomi = new ArrayList<Double>(naomi);
        newNaomi.remove(Double.valueOf(naomiLargest));
        List<Double> newKen = new ArrayList<Double>(ken);
        newKen.remove(Double.valueOf(kenChoice));
        return (naomiWon ? 1 : 0) + optimalWar(newNaomi, newKen);
    }

    public int optimalDeceitfulWar(List<Double> naomi, List<Double> ken) {
        Collections.sort(ken);
        List<Double> naomiClone = new ArrayList<Double>(naomi);
        for (int i = 0; i < ken.size(); i++) {
            double kenChoice = ken.get(i);
            double naomiWinner = -1.0;
            for (Double x : naomiClone) {
                if (x < kenChoice) continue;
                if (naomiWinner < 0 || x < naomiWinner) naomiWinner = x;
            }
            if (naomiWinner < 0) return i;
            naomiClone.remove(naomiWinner);
        }
        return ken.size();
    }
    
    public int oldOptimalDeceitfulWar(List<Double> naomi, List<Double> ken) {
        if (naomi.isEmpty()) return 0;
        int loseVal;
        {
            double kenLargest = -1.0;
            for (Double x : ken) {
                if (x > kenLargest) kenLargest = x;
            }
            double naomiSmallest = -1.0;
            for (Double x : naomi) {
                if (naomiSmallest < 0 || x < naomiSmallest) naomiSmallest = x;
            }
            if (naomiSmallest > kenLargest) return naomi.size();
            List<Double> newNaomi = new ArrayList<Double>(naomi);
            newNaomi.remove(Double.valueOf(naomiSmallest));
            List<Double> newKen = new ArrayList<Double>(ken);
            newKen.remove(Double.valueOf(kenLargest));
            loseVal = oldOptimalDeceitfulWar(newNaomi, newKen);
        }
        int winVal;
        {
            double kenSmallest = -1.0;
            for (Double x : ken) {
                if (kenSmallest < 0 || x < kenSmallest) kenSmallest = x;
            }
            double naomiWinner = -1.0;
            for (Double x : naomi) {
                if (x < kenSmallest) continue;
                if (naomiWinner < 0 || x < naomiWinner) naomiWinner = x;
            }
            if (naomiWinner < 0) return loseVal;
            List<Double> newNaomi = new ArrayList<Double>(naomi);
            newNaomi.remove(Double.valueOf(naomiWinner));
            List<Double> newKen = new ArrayList<Double>(ken);
            newKen.remove(Double.valueOf(kenSmallest));
            winVal = 1 + oldOptimalDeceitfulWar(newNaomi, newKen);
        }
        if (winVal > loseVal) return winVal;
        return loseVal;
    }

    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new War().run();
    }

}
