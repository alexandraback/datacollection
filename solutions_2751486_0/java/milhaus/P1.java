package codeJam.y2013.r1c;

import java.util.*;
import java.io.*;
import java.math.*;
import java.util.regex.*;

public class P1 {
	static final String FILE = null;
	
	public static void main(String[] args) throws Exception {
		//System.setIn(new BufferedInputStream(new FileInputStream(FILE)));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int numOfTestCases = Integer.parseInt(br.readLine());
		for(int testCaseNumber = 1; testCaseNumber <= numOfTestCases; testCaseNumber++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			char[] word = st.nextToken().toCharArray();
			int n = Integer.parseInt(st.nextToken());
			List<Range> rangesOfSubstrings = new ArrayList<P1.Range>();
			int start = -1;
			for(int i = 0; i < word.length; i++) {
				char current = word[i];
				if(current != 'a' && current != 'e' && current != 'i' && current != 'o' && current != 'u') {
					if(start == -1) {
						start = i;
					}
					if(i == word.length-1 && i-start+1 >= n) {
						//System.out.println("1add " + start + ", " + i);
						rangesOfSubstrings.add(new Range(start, i));
						start = -1;
					}
				} else if(start != -1) {
					if((i-1)-start+1 >= n) {
						//System.out.println("2add " + start + ", " + (i-1));
						rangesOfSubstrings.add(new Range(start, i-1));
					}
					start = -1;
				}
			}
			BigInteger num = BigInteger.ZERO;
			/*num = num.add(BigInteger.valueOf(rangesOfSubstrings.get(0).start+1).multiply(BigInteger.valueOf(word.length-(rangesOfSubstrings.get(0).start+n)+1)));
			System.out.println("Multiply: " + BigInteger.valueOf(word.length-(start+n)));
			System.out.println("Multiply: BigInteger.valueOf(" + word.length + "-(" + start + "+" + n + ")));");
			System.out.println("Beginning num = " + num);*/
			int move = 1;
			out:
			for(int i = 0; i < rangesOfSubstrings.size(); i++) {
				//System.out.println("=====");
				Range currentRange = rangesOfSubstrings.get(i);
				int possibleBeginning = i == 0 ? currentRange.start : rangesOfSubstrings.get(i-1).end-n+2;
				int numOfBeginnings = i == 0 ? currentRange.start+1 : (currentRange.start-possibleBeginning+1);
				BigInteger numOfEndings = BigInteger.valueOf(word.length-(currentRange.start+n)+1);
				BigInteger add = BigInteger.valueOf(numOfBeginnings).multiply(numOfEndings);
				/*System.out.println("numOfBeginnings: " + numOfBeginnings);
				System.out.println("numOfEndings: " + numOfEndings);*/
				num = num.add(add);
				/*System.out.println(add);
				System.out.println(currentRange.start + "|" + currentRange.end);*/
				while(true) {
					int currentStart = currentRange.start+move;
					int currentEnd = currentStart+n-1;
					/*System.out.println("currentStart: " + currentStart);
					System.out.println("currentEnd: " + currentEnd);*/
					if(currentEnd <= currentRange.end) {
						add = BigInteger.valueOf(word.length-currentEnd);
						//System.out.println("add#3: " + add);
						num = num.add(add);
						move++;
					} else {
						//System.out.println("CONTINUE");
						move = 1;
						continue out;
					}
				}
			}
			System.out.println("Case #" + testCaseNumber + ": " + num);
		}
	}
	
	static class Range {
		public Range(int start, int end) {
			this.start = start;
			this.end = end;
		}
		int start;
		int end;
	}

}
