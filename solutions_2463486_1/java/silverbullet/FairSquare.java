package codejam2013.qual.fairsquare;

import java.util.*;
import java.io.*;

public class FairSquare {
	final static String PROBLEM_NAME = "fairsquare";
	final static String WORK_DIR = "./src/codejam2013/qual/fairsquare/";

	long[] fairsquares = new long[100];
	int fairsquarescount = 0;

	void preCalculate(){
		System.out.println("Precalculating..");
		Arrays.fill(fairsquares, -1);
		long a = 1;
		long b = 1000000000000000L;

		long sqrtA = (int) Math.sqrt(a);
		long sqrtB = (int) Math.sqrt(b);
		
		long init = ((long)(sqrtA*sqrtA) == a?sqrtA:sqrtA+1);
		for(long i=init;i<=sqrtB;i++){
			if(isPalindrome(i)){
				long iSquare = i*i;
				if(isPalindrome(iSquare)){
					fairsquares[fairsquarescount++] = iSquare;
				}
			}
		}		
	}
	
	void solve(Scanner sc, PrintWriter pw) {
		long a = sc.nextLong();
		long b = sc.nextLong();

		int count=0;
		for(int i=0;i<fairsquares.length;i++){
			if(fairsquares[i]>=a&&fairsquares[i]<=b)
				count++;
		}

		pw.println(""+count);
	}

	private boolean isPalindrome(long iSquare) {
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

	public static void main(String[] args) throws Exception {

		FairSquare fairSquareProb = new FairSquare();
		fairSquareProb.preCalculate();
		
		Scanner sc = new Scanner(new FileReader(WORK_DIR + "C-large-1.in"));
		PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
		int caseCnt = sc.nextInt();
		sc.nextLine();
		for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
			System.out.println("Processing test case " + (caseNum + 1));
			pw.print("Case #" + (caseNum + 1) + ": ");
			
			fairSquareProb.solve(sc, pw);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
}
