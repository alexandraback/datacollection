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
		BufferedReader br = new BufferedReader(new FileReader("/Users/vladimir/Documents/workspaceg/GGL/src/codejam15/C-small-2-attempt0.in"));
		int T = Integer.valueOf(br.readLine());		
		PrintWriter writer = new PrintWriter("/Users/vladimir/Documents/workspaceg/GGL/src/codejam15/output.txt", "UTF-8");		
		for (int i = 0; i < T; i++) {
			int N = Integer.valueOf(br.readLine());
			List<Integer> D = new Vector<Integer>();
			List<Integer> M = new Vector<Integer>();
			for(int j = 0; j < N; j++) {
				String[] DHM = br.readLine().split(" ");
				
				int h = Integer.valueOf(DHM[1]);
				for(int k = 0; k < h; k++) {
					D.add(Integer.valueOf(DHM[0]));
					M.add(Integer.valueOf(DHM[2]));
				}				
			}
			
			int result = 0;
			
			for(int i1 = 0; i1 < D.size(); i1++) {
				for(int i2 = 0; i2 < D.size(); i2++) {
					if(i1 != i2) {
						if(Double.compare(M.get(i1) + M.get(i1) * (1 - D.get(i1)/360.0), (M.get(i2) + 1) * (1 - D.get(i2)/360.0)) <= 0) {
							result++;
						}
					}
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