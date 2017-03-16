package codejam15;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Vector;

public class Hikers {
	public static void main(String[] args) throws IOException {
		// BufferedReader br = new BufferedReader(
		// new FileReader(
		// "/Users/vladimir/Documents/workspaceg/GGL/src/codejam15/B-small-attempt2.in"));		
		BufferedReader br = new BufferedReader(new FileReader("/Users/vladimir/Documents/workspaceg/GGL/src/codejam15/C-small-1-attempt1.in"));
		int T = Integer.valueOf(br.readLine());		
		PrintWriter writer = new PrintWriter("/Users/vladimir/Documents/workspaceg/GGL/src/codejam15/output.txt", "UTF-8");		
		for (int i = 0; i < T; i++) {
			int N = Integer.valueOf(br.readLine());
			int[] D = new int[N];
			int[] H = new int[N];
			int[] M = new int[N];
			for(int j = 0; j < N; j++) {
				String[] DHM = br.readLine().split(" ");
				D[j] = Integer.valueOf(DHM[0]);
				H[j] = Integer.valueOf(DHM[1]);								
				M[j] = Integer.valueOf(DHM[2]);
			}
			
			int result = 0;
			
			if(N == 2 && H[0] == 1 && H[1] == 1) {
				if(Double.compare(M[0] + M[0] * (1 - D[0]/360.0), M[1] * (1 - D[1]/360.0)) <= 0
						|| Double.compare(M[1] + M[1] * (1 - D[1]/360.0), M[0] * (1 - D[0]/360.0)) <= 0) {
					result = 1;
				}				
			} else if(N == 1 && H[0] == 2) {
				if(Double.compare(M[0] + M[0] * (1 - D[0]/360.0), (M[0] + 1) * (1 - D[0]/360.0)) <= 0) {
					result = 1;
				}
			}
 			
			writer.println("Case #" + (i + 1) + ": " + result);
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