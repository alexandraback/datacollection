package gcj.rnd1a.q1;

import java.text.DecimalFormat;
import java.util.*;
import java.io.*;

public class PasswordProblem {
    void solve(Scanner sc, PrintWriter pw) {
        int A = sc.nextInt();
        int B = sc.nextInt();
        double P[] = new double[A];
        for (int I = 0; I < A; I++) {
        	P[I] = sc.nextDouble();
        }
        
        // keep typing
        int keepTypingStrokesAllCorrect = B - A + 1;
        double keepTypingProbAllCorrect = 1;
        for (int I = 0; I < A; I++) {
        	keepTypingProbAllCorrect *= P[I];
        }
        int keepTypingStrokesAllWrong = ((B + 1) * 2) - A;
        double keepTypingProbAllWrong = 1;
        for (int I = 0; I < A; I++) {
        	keepTypingProbAllWrong *= (1- P[I]);
        }        
        int keepTypingStrokesSomeWrong = keepTypingStrokesAllWrong;
        double keepTypingProbSomeWrong = 1 - keepTypingProbAllCorrect - keepTypingProbAllWrong;
        double expectedKeepTyping = (keepTypingStrokesAllCorrect * keepTypingProbAllCorrect) + 
        		(keepTypingStrokesAllWrong * keepTypingProbAllWrong) + (keepTypingStrokesSomeWrong * keepTypingProbSomeWrong);
        
                
        // press enter
        int pressEnterStrokesAllCorrect = 1 + B + 1;
        double pressEnterProbAllCorrect = keepTypingProbAllCorrect;        
        int pressEnterStrokesAllWrong = pressEnterStrokesAllCorrect;
        double pressEnterProbAllWrong = keepTypingProbAllWrong;
        int pressEnterStrokesSomeWrong = pressEnterStrokesAllCorrect;
        double pressEnterProbSomeWrong = keepTypingProbSomeWrong;
        double expectedPressEnter = (pressEnterStrokesAllCorrect * pressEnterProbAllCorrect) + 
        		(pressEnterStrokesAllWrong * pressEnterProbAllWrong) + (pressEnterStrokesSomeWrong * pressEnterProbSomeWrong);        
        
        double currentLowestExpected = (expectedKeepTyping < expectedPressEnter) ? expectedKeepTyping : expectedPressEnter;
        
        // backspace
        for (int I = 1; I <= A; I++) {
        	int strokesBackspaceAndCorrect = (2 * I) + (B - A) + 1;
        	int strokesBackspaceAndWrong = (2 * I) + (B - A) + 1 + B + 1;
        	
    			double probStrokesBackspaceAndCorrect = 1;
    			for (int J = 0; J < A - I; J++) {    				
    				probStrokesBackspaceAndCorrect *= P[J];
          }    			    			
    			double probStrokesBackspaceAndWrong = 1 - probStrokesBackspaceAndCorrect;    			
    			double expected = (strokesBackspaceAndCorrect * probStrokesBackspaceAndCorrect) + 
    					(strokesBackspaceAndWrong * probStrokesBackspaceAndWrong);
    			
    			currentLowestExpected = (expected < currentLowestExpected) ? expected : currentLowestExpected;  
        }
        
        DecimalFormat df = new DecimalFormat("#.000000");
        pw.println(df.format(currentLowestExpected));
    }
    
    public static int choose(long total, long choose){
	      if(total < choose)
	          return 0;
	      if(choose == 0 || choose == total)
	          return 1;
	      return choose(total-1,choose-1)+choose(total-1,choose);
	  }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader("input/A-large.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("output/output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum + 1) + ": ");
            new PasswordProblem().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
