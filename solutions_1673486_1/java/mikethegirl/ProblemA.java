import java.util.*;

public class ProblemA {

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int nCases = in.nextInt();
        for(int caseN = 1; caseN <= nCases; caseN++){
            int charsTyped = in.nextInt();
            int passLength = in.nextInt();
            double[] probabilities = new double[charsTyped];
            for(int i = 0; i<charsTyped; i++){
                probabilities[i] = in.nextDouble();
            }
            double expected = expectedValue(passLength, charsTyped, probabilities);
            System.out.printf("Case #%d: %.6f\n", caseN, expected);
        }
    }
    
    public static double expectedValue(int passLength, int charsTyped, double[] probCorrect){
        double[] firstFalseProb = firstFalseProbs(charsTyped, probCorrect);
        double minExpected = passLength + 2; //Case of pressing enter immediately
        for(int delCount = 0; delCount <= charsTyped; delCount++){
            double totalExpected = 0;
            for(int errPos = 0; errPos <= charsTyped; errPos++){
                double thisExpected = passLength - charsTyped + 1;
                if(delCount < charsTyped - errPos) {
                    thisExpected += passLength + 1;
                }
                thisExpected += delCount * 2;
                thisExpected *= firstFalseProb[errPos];
                totalExpected += thisExpected;
            }
            if(totalExpected < minExpected){
                minExpected = totalExpected;
            }
        }
        return minExpected;
    }
    
    public static double[] firstFalseProbs(int charsTyped, double[] probCorrect) {
        double[] probs = new double[charsTyped + 1];
        for(int firstFalse = 0; firstFalse < charsTyped + 1; firstFalse++){
            double thisProb = 1;
            for(int correct = 0; correct < firstFalse; correct++){
                thisProb *= probCorrect[correct];
            }
            if(firstFalse < charsTyped){
                thisProb *= (1 - probCorrect[firstFalse]);
            }
            probs[firstFalse] = thisProb;
        }
        return probs;
    }
}
