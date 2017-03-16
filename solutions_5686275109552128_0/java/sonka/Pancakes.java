package qual_b;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Pancakes {

	static final String inFile = "src/qual_b/B-small-attempt0.in";
	static final String outFile = "src/qual_b/output.txt";
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
		int D = reader.nextInt();
		int[] pancakes = new int[D];
		int maxP = 0;
		for (int i = 0; i < D; i++)
		{
			pancakes[i] = reader.nextInt();
			if (pancakes[i] > maxP) maxP = pancakes[i];
		}
		
		int min = maxP;
		
		if (min > 3) {
			for (int eat = 1; eat < maxP; eat++)
			{
				int steps = eat;
				for (int p = 0; p < D; p++)
				{
					if (pancakes[p] > eat) {
						steps += (pancakes[p] - 1) / eat;
					}
				}
				if (steps < min) min = steps;
			}
		}
		
		writer.println("Case #"+caseNo+": " + min);		
	}
	
}
