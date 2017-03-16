package cj_17_round1C;

import java.io.*;
import java.util.*;

public class R1C_ProblemA {

	final static String WORK_DIR = "E:\\CodeJam\\EclipseWrkSpc\\CodeJam\\src\\cj_17_round1C\\";
	
    // final static String FILE_NAME = "sample_a";
    final static String FILE_NAME = "A-small-attempt0";
    // final static String FILE_NAME = "A-large";

    void solve(Scanner sc, PrintWriter pw) {
    	
    	String sName = sc.next();
    	int iMinCons = sc.nextInt();
        
        System.out.println("Processing Line Content : [" + sName + "] " + iMinCons);
        
        int iValidCount = 0;
        
        for (int i = 0; i <= (sName.length() - 1); i++) {
			for (int j = i + 1; j <= sName.length(); j++) {
				
				String sSubStr = sName.substring(i, j);
				// System.out.println(" sub str " + sSubStr);
				
				if (IsValidStr(sSubStr, iMinCons)) {
					// System.out.println("valid " + sSubStr);
					iValidCount++;
				}
				
			}
		}
        
        System.out.println("ANS " + iValidCount);
        pw.println(iValidCount);
        
        if (sc.hasNext()) {
			sc.nextLine();
		}
        
    }
    
    boolean IsValidStr(String s, int iMinCons)
    {
    	
    	int iCount = 0;
    	
    	for (int i = 0; i < s.length(); i++) {
			if (
			(s.charAt(i) == 'a') ||
			(s.charAt(i) == 'e') ||
			(s.charAt(i) == 'i') ||
			(s.charAt(i) == 'o') ||
			(s.charAt(i) == 'u') )
			{
				 iCount = 0;
			}
			else
			{
				iCount++;
				if (iCount >= iMinCons) {
					return true;
				}
			}
		}

    	return false;
    }
    
	public static void main(String[] args) {

		Scanner scFileScanner = null;
		PrintWriter pwFileWriter = null;
		try {
			scFileScanner = new Scanner(new FileReader(WORK_DIR + "" + FILE_NAME + ".in"));
			pwFileWriter = new PrintWriter(new FileWriter(WORK_DIR + "" + FILE_NAME + ".out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
        
		if ((scFileScanner == null) || (pwFileWriter == null)) {
			System.exit(1);
		}
		
        int iCaseCount = scFileScanner.nextInt();
        scFileScanner.nextLine();
        for (int iCurrentCaseNum = 1; iCurrentCaseNum <= iCaseCount; iCurrentCaseNum++) {
            System.out.println("\nProcessing test case " + (iCurrentCaseNum));
            pwFileWriter.print("Case #" + (iCurrentCaseNum) + ": ");
            new R1C_ProblemA().solve(scFileScanner, pwFileWriter);
        }
        
        pwFileWriter.flush();
        pwFileWriter.close();
        scFileScanner.close();
	}
}
