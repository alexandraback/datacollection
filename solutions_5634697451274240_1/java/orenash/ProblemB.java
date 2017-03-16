

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;

public class ProblemB {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws Exception {
		
		int cases = readInt();
		
		for (int caseNum=0; caseNum<cases; caseNum++) {
			
			String s = br.readLine();
			
			int count = 0;;
			for (int i=0; i<s.length()-1; i++) {
				if (s.charAt(i)!=s.charAt(i+1)) {
					count++;
				}
			}
			if (s.charAt(s.length()-1)=='-') {
				count++;
			}
			
			System.out.println(String.format("Case #%d: %d", caseNum+1, count));
		}

	}
	
	private static int readInt() throws IOException {
		return Integer.parseInt(br.readLine());
	}
}
