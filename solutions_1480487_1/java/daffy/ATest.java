package y2012.r1b;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class ATest {

    final static String PROBLEM_NAME = "y2012\\r1b";
    final static String WORK_DIR = "C:\\gcj\\src\\" + PROBLEM_NAME + "\\";
    // final static String INPUT = WORK_DIR + "A-sample.in";
    // final static String INPUT = WORK_DIR + "A-small-attempt3.in";
    final static String INPUT = WORK_DIR + "A-large.in";
    final static String OUTPUT = WORK_DIR + "output.txt";

	public static String solve(int numContestants, int[] judgeScore)  {
		double X = 0.0;
		for (int i = 0; i < numContestants; i++)  {
			X += judgeScore[i];
		}

		double[] minPercent = new double[numContestants];
		boolean[] nonZeroIndex = new boolean[numContestants];
		double cumulativeScore = 0.0;
		int nonZeroScores = 0;
		for (int i = 0; i < numContestants; i++)  {
			double temp = 2.0 / (double) numContestants - (double) judgeScore[i] / X;
			if (temp < 0.0)  {
				minPercent[i] = 0.0;
				cumulativeScore += judgeScore[i];
				nonZeroIndex[i] = false;
			}
			else  {
				nonZeroIndex[i] = true;
				nonZeroScores++;
			}
		}
		
		for (int i = 0; i < numContestants; i++)  {
			if (nonZeroIndex[i])  {
				minPercent[i] = 100.0 * (((2 * X - cumulativeScore) / nonZeroScores - judgeScore[i]) / X);
			}
		}

		String result = new Double(minPercent[0]).toString();
		for (int i = 1; i < numContestants; i++)  {
			result = result + " " + new Double(minPercent[i]).toString();
		}
		return result;
	}
    
    public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader(INPUT));
        PrintWriter pw = new PrintWriter(new FileWriter(OUTPUT));
        int caseCnt = sc.nextInt();

        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            sc.nextLine();
            System.out.println("Processing test case " + (caseNum + 1));
            int numContestants = sc.nextInt();
            int[] judgeScore = new int[numContestants];
            for (int i = 0; i < numContestants; i++)  {
            	judgeScore[i] = sc.nextInt();
            }
            pw.println("Case #" + (caseNum + 1) + ": " + solve(numContestants, judgeScore));
        }
        pw.flush();
        pw.close();
        sc.close();
	}
}