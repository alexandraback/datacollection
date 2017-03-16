import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;

/**
 * @author TRINH May 5, 2012 trinh.h.nguyen@uia.no
 */
public class solution {
	public static void main(String[] args) throws Exception {
		// Scanner sc = new Scanner(System.in);
		// PrintWriter pw = new PrintWriter(System.out);
		Scanner sc = new Scanner(new FileReader("A-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("A.out"));

		int ntest = sc.nextInt();
		DecimalFormat df = new DecimalFormat("#.000000");
		DecimalFormat dff = new DecimalFormat("#.0");
		for (int test = 1; test <= ntest; test++) {
			int nContestant = sc.nextInt();
			ArrayList<Integer> scores = new ArrayList<Integer>();
			double Ntotal = 0;
			int curr = 0;
			for (int iContestant = 0; iContestant < nContestant; iContestant++) {
				curr = sc.nextInt();
				scores.add(curr);
				Ntotal += curr;
			}
			String result = "";
			double minimumScore = 2*Ntotal/nContestant;
			ArrayList<Double> results = new ArrayList<Double>();
			for (int i=0;i<200;i++){
				results.add(0.0);
			}
			int numberM = 0;
			int sumScore =0;
			for (int iContestant = 0; iContestant < nContestant; iContestant++) {
				if (scores.get(iContestant) >= minimumScore){
					results.add(iContestant, 0.000000);
					sumScore += scores.get(iContestant);
				}
				else {
					numberM++;
				}
			}
			double restScore = 2*Ntotal - sumScore;
			double scoreForEach = restScore/numberM;
			for (int iContestant = 0; iContestant < nContestant; iContestant++) {
				if (scores.get(iContestant) < minimumScore){
					double res = (scoreForEach-scores.get(iContestant))/Ntotal*100;
					results.add(iContestant,res);
				}
			}
			for (int i=0;i<nContestant;i++){
				result += " " + df.format(results.get(i));
			}
			
			
			pw.print("Case #" + test + ":" + result);
			if (test < ntest)
				pw.println();
		}
		pw.close();
		sc.close();
	}
}
