import java.io.*;
import java.util.*;

/**
 *
 * @author Sethera
 */
public class ProblemA {
    
    public static BufferedWriter bw;
    public static BufferedReader br;

    public static void main(String[] args) {
        try {

            String filename = "A-small-attempt1";

            br = new BufferedReader(new FileReader("E:\\Downloads\\" + filename + ".in"));
            bw = new BufferedWriter(new FileWriter("E:\\Downloads\\" + filename + ".out"));
            //bw = new BufferedWriter(new OutputStreamWriter(System.out));

            ProblemA prob = new ProblemA();
            prob.solveFile();

        } catch (Exception exc) {
            System.out.println(exc.toString());
        }
    }
    

    public void solveFile() throws Exception {
        int caseCount = Integer.parseInt(br.readLine());

        for (int caseNumber = 0; caseNumber < caseCount; caseNumber++) {
            String[] setupLine = br.readLine().split(" ");
            String[] charProbs = br.readLine().split(" ");

            int A = Integer.parseInt(setupLine[0]);
            int B = Integer.parseInt(setupLine[1]);
            
            double[] probs = new double[charProbs.length];
            
            for(int i = 0; i<charProbs.length; i++){
                probs[i] = Double.parseDouble(charProbs[i]);
            }
            
            solveCase(caseNumber + 1, A, B, probs);
        }
    }

    public void solveCase(int caseNumber, int A, int B, double[] probs) throws Exception {
        double enterNow = 2 + B;
        double chanceOfPerfection = chanceYouTypedItRight(probs, probs.length);
        double keepTyping = chanceOfPerfection * (double)((B-A)+1) + (1.0-chanceOfPerfection) * (double)(((B-A)+1) + B+1);
        
        double bestSoFar = Math.min(enterNow, keepTyping);
        
        for(int i = 1; i<=A; i++){
            double newChance = findBestBackspace(A, B, probs, i);
            bestSoFar = Math.min(newChance, bestSoFar);
        }
        
        double answer = bestSoFar;
        
        bw.write("Case #" + caseNumber + ": " + answer + "\n");
        bw.flush();
    }
    
    public double chanceYouTypedItRight(double[] probs, int toChar){
        double chance = 1.0;
        for(int i = 0; i<toChar; i++){
            chance *= probs[i];
        }
        /*for(int i = toChar; i<probs.length; i++){
            chance *= (1.0-probs[i]);
        }*/
        return chance;
    }
    
    public double findBestBackspace(int A, int B, double[] probs, int backspacesSoFar){
        double chance = chanceYouTypedItRight(probs, A-backspacesSoFar);
        
        int charsIfRight = backspacesSoFar + backspacesSoFar + (B-A) + 1;
        double thisTotalKeys = chance * (double)(charsIfRight) + (1.0-chance) * (double)(charsIfRight + B + 1); 
        
        return thisTotalKeys;        
    }
}
