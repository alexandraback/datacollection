import java.io.*;
import java.util.*;

import javax.security.auth.kerberos.*;


public class ProblemD {
	final static String PROBLEM_NAME = "/Users/autobee/work/gcm/problem_d";
	final static String FILE_NAME_IN =  "D-large.in";
	final static String FILE_NAME_OUT =  "D-large.out";
	
	/**
	 * @param args
	 */
	
	void solve(Scanner sc, PrintWriter pw) {
		int s = sc.nextInt();
		
		ArrayList<Double> nList = new ArrayList<Double>();
		for (int i = 0; i < s; i++) {
			nList.add(sc.nextDouble());
		}
		Collections.sort(nList);
		
		ArrayList<Double> kList = new ArrayList<Double>();
		for (int i = 0; i < s; i++) {
			kList.add(sc.nextDouble());
		}
		Collections.sort(kList);
		
		int itK = s-1;
		double nVal;
		int nScore = 0;
		for (int i = s-1; i >= 0; i--) {
			nVal = nList.get(i);
			
			while (nVal < kList.get(itK)) {
				if (itK == 0) break;
				itK--;
			}
			
			if (nVal > kList.get(itK)) nScore++;
			itK--;
			if (itK == -1) break;
		}
		
		itK = 0;
		int kScore = 0;
		for (int i = 0; i < s; i++) {
			nVal = nList.get(i);
			
			while (nVal > kList.get(itK)) {
				if (itK == s - 1) break;
				itK++;
			}
			
			if (nVal < kList.get(itK)) kScore++;
			itK++;
			if (itK == s) break;
		}
		
		pw.println(String.format("%d %d", nScore, s - kScore));
		
	}
	
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader(PROBLEM_NAME + "/" + FILE_NAME_IN));
        PrintWriter pw = new PrintWriter(new FileWriter(PROBLEM_NAME + "/" + FILE_NAME_OUT));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new ProblemD().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();

	}

}
