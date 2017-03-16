package codejam2013.qual.fairsquare;

import java.util.*;
import java.io.*;

public class FairSquare {
	final static String PROBLEM_NAME = "fairsquare";
	final static String WORK_DIR = "./src/codejam2013/qual/fairsquare/";

	void solve(Scanner sc, PrintWriter pw) {
		int a = sc.nextInt();
		int b = sc.nextInt();

		int sqrtA = (int) Math.sqrt(a);
		int sqrtB = (int) Math.sqrt(b);
		
		int countFairSquares = 0;
		int init = ((int)(sqrtA*sqrtA) == a?sqrtA:sqrtA+1);
		for(int i=init;i<=sqrtB;i++){
			int iSquare = i*i;
			if(isPalindrome(iSquare)&&isPalindrome(i)){
//				System.out.print(" "+iSquare);
				countFairSquares++;
			}
		}
//		System.out.println();
		pw.println(""+countFairSquares);
	}

	private boolean isPalindrome(int iSquare) {
		String str = iSquare+"";
		int len = str.length();
		char[] chars = new char[len];
		str.getChars(0, len, chars , 0);
		for(int i=0;i<len;i++){
			if(chars[i]!=chars[len-i-1]){
				return false;
			}
		}
		return true;
	}

	public static void main1(String[] args) throws Exception {
		System.out.println(new FairSquare().isPalindrome(1001));
	}

	public static void main(String[] args) throws Exception {

		Scanner sc = new Scanner(new FileReader(WORK_DIR + "C-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
		int caseCnt = sc.nextInt();
		sc.nextLine();
		for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
			System.out.println("Processing test case " + (caseNum + 1));
			pw.print("Case #" + (caseNum + 1) + ": ");
			new FairSquare().solve(sc, pw);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
}
