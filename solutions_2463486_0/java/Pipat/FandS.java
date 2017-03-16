/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class CodeJam {
	final static String PROBLEM_NAME = "Fair and Square";
    final static String WORK_DIR = "D:\\CodeJam\\" + PROBLEM_NAME + "\\";
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader(WORK_DIR + "C-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
		long min ,max, cnt, rMin, rMax;
		String ansStr;
		
		int caseCnt = sc.nextInt();
		
		for (int caseNum = 1; caseNum <= caseCnt; caseNum++) {
			min = sc.nextLong();
			max = sc.nextLong();
			rMin = (long)Math.ceil( Math.pow(min, 0.5) );
			rMax = (long)Math.floor( Math.pow(max, 0.5) );
			cnt = 0;
			
			for(long i=rMin;i<=rMax;i++){
				if( isPal(i) ){
					if( isPal(i*i)){
						cnt++;
					}
				}
			}
			
			//ansStr = "";
			ansStr = "Case #"+caseNum+": "+cnt;
			System.out.println( ansStr );
			pw.println( ansStr );
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static boolean isPal(long l){
		return l==reverse(l);
	}
	
	public static long reverse(long n) {
		long result = 0;
		while (n != 0) {
			result = result * 10 + (n%10);
			n /= 10;
		}
		return result;
	}
	
}