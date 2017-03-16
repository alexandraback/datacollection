import java.io.*;
import java.util.*;


public class ProblemB {
	final static String PROBLEM_NAME = "/Users/autobee/work/gcm/problem_b";
	final static String FILE_NAME_IN =  "B-small-attempt0.in";
	final static String FILE_NAME_OUT =  "output.txt";
	
	/**
	 * @param args
	 */
	
	double C, F, X;
	
	double getBestTime(double prevTime, double spentTime, double r) {
//		C <= F * t
//		C / r + C / (r + F) + C / (r + )
//		
//		double remainT = prevTime - spentTime;
		double genT = C / r; 
		
		double tIfGen = spentTime + genT + X / (r + F);
		if (prevTime > tIfGen) {
			return getBestTime(tIfGen, spentTime + genT, r + F);
		}
		return prevTime;
		
	}
	
	
	
	
	void solve(Scanner sc, PrintWriter pw) {
		C = sc.nextDouble();
		F = sc.nextDouble();
		X = sc.nextDouble();
		
		double r = 2.0;
		
//		double prevTime = X / r;
//		double nextTime = X / r;
//		
//		while (prevTime > nextTime) {
//			
//		}
		
//		remainTime = longTime - nowTime
//		C <= F * t
		double bestTime = getBestTime(X / r, 0, r);
		
		pw.println(bestTime);
		
		
		
		
		
//		double bestTime = getBestTime();
		
	}
	
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader(PROBLEM_NAME + "/" + FILE_NAME_IN));
        PrintWriter pw = new PrintWriter(new FileWriter(PROBLEM_NAME + "/" + FILE_NAME_OUT));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new ProblemB().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();

	}

}
