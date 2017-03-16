package FirstRound;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class A {
	public static void main(String[] args) {
		try {
			FileWriter w = new FileWriter(new File("E:\\output.out"));
			BufferedReader r = new BufferedReader(new FileReader(new File("E:\\A-large.in")));
			int numbeOfCases = Integer.parseInt(r.readLine());
			for(int t = 0; t < numbeOfCases; t++) {
				String[] s = r.readLine().split(" ");
				int alTy = Integer.parseInt(s[0]);
				int totalCh = Integer.parseInt(s[1]);
				s = r.readLine().split(" ");
				double[] prob = new double[alTy];
				for(int i = 0; i < s.length; i++)
					prob[i] = Double.parseDouble(s[i]);
				//Case 1 - keep typing
				double expectedNumber = Double.MAX_VALUE;
				
				for(int j = 0; j < alTy; j++) {
					double caseProb = 1;
					for(int i = 0; i < s.length; i++)
						if(i < s.length - j)
							caseProb = caseProb * prob[i];
					expectedNumber = Math.min(expectedNumber, caseProb * (totalCh - alTy + 1 + (2 * j))
						+ (1 - caseProb) * (totalCh - alTy + 1 + (2 * j) + totalCh + 1));
				}
				expectedNumber = Math.min(expectedNumber, 1 + totalCh + 1);
				w.write("Case #" + (t + 1) + ": " + expectedNumber);
				//System.out.println("Case #" + (t + 1) + ": " + expectedNumber);
				if(t < numbeOfCases - 1)
					w.write("\n");
				System.out.println(t);
			}
			w.close();
			r.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
