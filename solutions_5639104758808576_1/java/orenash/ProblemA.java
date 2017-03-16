package qualification;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ProblemA {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws Exception {
		
		int cases = readInt();
		
		for (int caseNum=0; caseNum<cases; caseNum++) {
			
			String[] params = readStrings();
			int max = Integer.parseInt(params[0]);
			int standingSoFar = 0;
			int extraNeeded = 0;
			for (int i=0; i<=max; i++) {
				if (i>standingSoFar && params[1].charAt(i)!='0') {
					extraNeeded += i-standingSoFar;
					standingSoFar += i-standingSoFar;
				}
				standingSoFar += Integer.parseInt(params[1].substring(i, i+1));
			}
			
			System.out.println(String.format("Case #%d: %d", caseNum+1, extraNeeded));
		}

	}
	
	private static int readInt() throws IOException {
		return Integer.parseInt(br.readLine());
	}
	
	private static String[] readStrings() throws IOException {
		return br.readLine().split(" ");
	}
}
