import java.util.*;
import java.io.*;
import java.math.*;


// Author: vt12
// Google Code Jam 2010


public class SolutionB {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		
		long time = System.currentTimeMillis();
		
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			double C = sc.nextDouble();
                        double F = sc.nextDouble();
                        double X = sc.nextDouble();
                        double T = 2;
			double ans = 0; 
                        
                        if (X<=C) {
                            ans = X/T;
                        }
                        else { 
                            while (X/T > (C/T+X/(T+F))) {
                                ans += C/T;
                                T += F;
                            }
                            ans += X/T;
                        }
			
                        pw.print("Case #" + caseNum + ": ");                        
                        pw.printf("%.7f", ans); 
                        pw.println();
			
			System.out.println("Finished testcase " + caseNum + ", time = " + (System.currentTimeMillis() - time));
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new SolutionB()).doMain();
	}
}