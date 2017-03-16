

/**
 * 
 * @author RasPat
 *Problem can be found here:
 * https://code.google.com/codejam/contest/189252/dashboard#s=p0
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Prob1 {
	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		String pathRoot = "C:\\Users\\RasPat\\workspace\\2013_1C\\";
		String relRoot = "A-small-attempt0.in";
//		relRoot = "testA.in";
		String in = pathRoot + relRoot;
		// Length of the file extension
		int extLength = 2;
		String out = in.substring(0, in.length() - extLength) + "out";

		BufferedReader r = null;
		BufferedWriter w = null;
		try {
			r = new BufferedReader(new FileReader(in));
			w = new BufferedWriter(new FileWriter(out));
			String[] line;
			// First line of Input is the # of test cases
			int testCases = Integer.parseInt(r.readLine());
			int caseCount = 0;

			while (caseCount < testCases) {
				caseCount++;
				line = r.readLine().split(" ");
				String name = line[0];
				int n = Integer.parseInt(line[1]);
				int nVal = 0;
				
				for (int i = 0; i <= name.length() - n; i++) {
					for (int j = i + n; j <= name.length(); j++) {
						String sub = name.substring(i, j);
						for(int k = 0; k <= sub.length() - n; k++) {
							String sub2 = sub.substring(k, k+n);
							if (!(sub2.contains("a") || sub2.contains("e")
									|| sub2.contains("i") || sub2.contains("o") || sub2
										.contains("u"))) {
								nVal++;
								break;
							}
						}
						
					}
				}
				System.out.println(nVal);
//				if(caseCount == 1) break;
/**
 * Pseudo Code
 * Find the number of substrings in a give name with n consecutive consonants
 * naive:
 * 	  find each substring of the name
 * 	  if it has a n letter consonant substring count
 * 		to find a  consonant substring take every slice of length n and make sure it doesnt contain a vowel
 * return the number of strings
 * 
 * 
 */
				
				
				
				
				
				
				
				System.out.println(nVal);
				
				
				if(caseCount == 1) System.out.println(nVal);
				w.write("Case #" + caseCount + ": " + nVal);
				

//				w.write(" " + String.format("%.6f", d));
				w.newLine();
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				r.close();
				if (w != null) {
					w.flush();
					w.close();
				}
				System.out.println("Time elapsed: "+ (System.currentTimeMillis() - start));
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
