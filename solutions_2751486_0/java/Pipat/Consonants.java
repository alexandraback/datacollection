package codejam;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CodeJam {
	final static String PROBLEM_NAME = "Consonants";
    final static String WORK_DIR = "D:\\CodeJam\\" + PROBLEM_NAME + "\\";
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader(WORK_DIR + "A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
		
		String ansStr;
		String[] splitBuff;
		String name;
		long n, combination, bufCom, csnCnt, vowCnt, lastMatch, alpCnt;
		
		int caseCnt = sc.nextInt();
		for (int caseNum = 1; caseNum <= caseCnt; caseNum++) {
			name = sc.next();
			n = sc.nextLong();
			combination = 0;
			csnCnt = 0;
			vowCnt = 0;
			lastMatch = -1;
			alpCnt = 0;
			bufCom = 0;
			
			for(int i=0;i<name.length();i++){
				if( !isVowel(name.charAt(i)) ){
					csnCnt++;
				}else{
					csnCnt=0;
				}
				if( csnCnt >= n ){
					alpCnt = i-n-lastMatch+1;
					//System.out.println("alpCnt = "+alpCnt);
					bufCom = alpCnt * ( name.length() - i );
					lastMatch = i-n+1;
					//System.out.println("lastMatch = "+lastMatch);
				}else{
					bufCom = 0;
				}
				//System.out.println("bufCom = "+bufCom);
				combination += bufCom;
			}
			
			ansStr = combination+"";
			ansStr = "Case #"+caseNum+": "+ansStr;
			System.out.println( ansStr );
			pw.println( ansStr );
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static boolean isVowel(char c){
		if(c=='a'||c=='e'||c=='i'|c=='o'||c=='u'){
			return true;
		}
		return false;
	}
	
}