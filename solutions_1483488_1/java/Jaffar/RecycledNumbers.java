/**
 * 
 */
package codejam2012.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

/**
 * @author Jaffar Ramay
 *
 *
Problem

Do you ever become frustrated with television because you keep seeing the same things, recycled over and over again? Well I personally don't care about television, but I do sometimes feel that way about numbers.

Let's say a pair of distinct positive integers (n, m) is recycled if you can obtain m by moving some digits from the back of n to the front without changing their order. For example, (12345, 34512) is a recycled pair since you can obtain 34512 by moving 345 from the end of 12345 to the front. Note that n and m must have the same number of digits in order to be a recycled pair. Neither n nor m can have leading zeros.

Given integers A and B with the same number of digits and no leading zeros, how many distinct recycled pairs (n, m) are there with A ≤ n < m ≤ B?

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of a single line containing the integers A and B.

Output

For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1), and y is the number of recycled pairs (n, m) with A ≤ n < m ≤ B.

Limits

1 ≤ T ≤ 50.
A and B have the same number of digits.

Small dataset

1 ≤ A ≤ B ≤ 1000.

Large dataset

1 ≤ A ≤ B ≤ 2000000.

Sample


Input 
 	 
4
1 9
10 40
100 500
1111 2222

Output 

Case #1: 0
Case #2: 3
Case #3: 156
Case #4: 287

Are we sure about the output to Case #4?

Yes, we're sure about the output to Case #4.
 */
public class RecycledNumbers {

	public static void solve() throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(new File("/Users/jaffar_ramay/Workspaces/eclipseWorkspace/Revision/src/codejam2012/qualification/RecycledNumbers.in")));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("/Users/jaffar_ramay/Workspaces/eclipseWorkspace/Revision/src/codejam2012/qualification/RecycledNumbers.out")));
		String line = null;
		while((line=reader.readLine())!=null){
			int testCases = Integer.parseInt(line);
			for (int i = 1; i <= testCases; i++) {
				String[] testCase = reader.readLine().split(" ");
			     int numberA = Integer.parseInt(testCase[0]);
			     int numberB = Integer.parseInt(testCase[1]);
			     int result = getRecycledCount(numberA, numberB);
			     writer.write("Case #"+i+": "+result);
			     if(i<testCases)
			    	 writer.newLine();
			}
		}
		reader.close();
		writer.close();
	}
	public static int getRecycledCount(int numberA, int numberB) {
		int result=0;
		Set<String> set = new HashSet<String>();
		for (int i = numberA; i <= numberB; i++) {
			
			String number = i+"";
			
			for (int j = 0; j < number.length(); j++) {
				
				int firstNumber = Integer.parseInt(number);
				int index = (number.length()-(j+1));
				if(index>0 && index<number.length()){
					int secondNumber =  (Integer.parseInt(number.substring(index,number.length())+number.substring(0,index)));
					
					if(numberA<=firstNumber && firstNumber<secondNumber && secondNumber<=numberB && (firstNumber+"").length() == (secondNumber+"").length()){
						set.add(firstNumber+""+secondNumber);
					}	
				}
				
			}
			
		}
		return set.size();
	}
	
	public static void main(String[] args) throws IOException {
		solve();
	}
}
