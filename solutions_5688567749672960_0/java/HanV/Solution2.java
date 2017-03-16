package codejam15;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Vector;

public class Solution2 {
	public static void main(String[] args) throws IOException {
		// BufferedReader br = new BufferedReader(
		// new FileReader(
		// "/Users/vladimir/Documents/workspaceg/GGL/src/codejam15/B-small-attempt2.in"));
		BufferedReader br = new BufferedReader(new FileReader("/Users/vladimir/Documents/workspaceg/GGL/src/codejam15/A-small-attempt3.in"));
		int T = Integer.valueOf(br.readLine());		
		PrintWriter writer = new PrintWriter("/Users/vladimir/Documents/workspaceg/GGL/src/codejam15/output.txt", "UTF-8");

		for (int i = 0; i < T; i++) {
			int N = Integer.valueOf(br.readLine());			
			int[] tillHere = new int[N + 1];
			tillHere[1] = 1;			
			for(int j = 2; j <= N; j++) {
				if(tillHere[j] != 0) {
					tillHere[j] = Math.min(tillHere[j - 1] + 1, tillHere[j]);
				} else {
					tillHere[j] = tillHere[j - 1] + 1;
				}
				int r = reverse(j);
				if(r <= N && r > j) {
					tillHere[r] = tillHere[j] + 1;
				}
			}
						
			writer.println("Case #" + (i + 1) + ": " + tillHere[N]);
		}
		writer.close();
	}
	
	public static int reverse(int base) {
		String s = String.valueOf(base);
		StringBuffer sb = new StringBuffer();		
		for(int i = s.length() - 1; i >= 0; i--) {
			sb.append(s.charAt(i));
		}
		
		return(Integer.valueOf(sb.toString()));
	}
}