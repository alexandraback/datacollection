package gcj.rnd1b.q1;

import java.text.DecimalFormat;
import java.util.*;
import java.io.*;

public class Round1BQ1 {
	static void solve(Scanner sc, PrintWriter pw) {
      int N = sc.nextInt();
      int S[] = new int[N];
      Integer sortedS[] = new Integer[N];
      //double res[] = new double[N];
      
      int totalScore = 0;
      for (int i = 0; i < N; i++) {
      	S[i] = sc.nextInt();
      	sortedS[i] = S[i];
      	totalScore += S[i];
      }
      Arrays.sort(sortedS, Collections.reverseOrder());
      
      int sumScoreAfterFirst = 0;
      for (int i = 1; i < N; i++)
			{
      	sumScoreAfterFirst += sortedS[i];
			}
      
      int formula = (N - 1) * sortedS[0];
      double formula1 = totalScore + sumScoreAfterFirst - formula;
      double formula2 = N * totalScore;
      
      
      double firstPersonFrac = formula1 / formula2;
      double leastScore = sortedS[0] + totalScore*firstPersonFrac;
      double distribute = 0;
      int numLesserThanZero = 0;
      for (int i = 0; i < N; i++) {
      	double percentage = ((leastScore - sortedS[i]) / totalScore) * 100;
      	if (percentage < 0) {
      		distribute += percentage;
      		numLesserThanZero++;
				} else {
					break;
				}
			}
      if (numLesserThanZero > 0) {
      	distribute /= (N-numLesserThanZero);      	
			}
      
      DecimalFormat df = new DecimalFormat("0.000000");
      for (int i = 0; i < N; i++) {
      	double percentage = ((leastScore - S[i]) / totalScore) * 100;
      	if (percentage < 0) {
      		pw.print(df.format(0) + " ");
				} else {
					pw.print(df.format(percentage + distribute) + " ");
				}
			}
      
      pw.println();
  }

	public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(new FileReader("input/A-small-attempt2.in"));
    PrintWriter pw = new PrintWriter(new FileWriter("output/output.txt"));
    int caseCnt = sc.nextInt();
    for (int caseNum=0; caseNum<caseCnt; caseNum++) {
        System.out.println("Processing test case " + (caseNum + 1));
        pw.print("Case #" + (caseNum+1) + ": ");
        Round1BQ1.solve(sc, pw);
    }
    pw.flush();
    pw.close();
    sc.close();
}
}
