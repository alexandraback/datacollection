package qual_a;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class StandingOvation {
	static final String inFile = "src/qual_a/A-small-attempt0.in";
	static final String outFile = "src/qual_a/output.txt";
	static Scanner reader;
	static PrintWriter writer;
	
	public static void main(String[] args) throws IOException{
		reader = new Scanner(new File(inFile));
		writer = new PrintWriter(new File(outFile));
		int numberOfTests = reader.nextInt();
		for(int caseNo = 1; caseNo <= numberOfTests; caseNo++){
			solve(caseNo);
		}
		reader.close();
		writer.flush();
		writer.close();	
	}
	
	public static void solve(int caseNo) {
		int Smax = reader.nextInt();
		String str = reader.next();
		int need = 0;
		int standing = 0;
		
		if (Smax > 0){
			for (int i = 0; i <= Smax; i++)
			{
				int add = i - standing;
				if(add > 0) {
					need += add;
					standing += add;
				}
				standing += Character.getNumericValue(str.charAt(i));
			}
		}
		
		writer.println("Case #"+caseNo+": " + need);		
	}
}
