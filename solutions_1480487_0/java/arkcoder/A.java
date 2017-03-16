import java.io.*;
import java.util.*;


public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Scanner a = new Scanner(new File("src/input"));
		FileWriter w = new FileWriter(new File("src/output"));
		int T = a.nextInt();
		a.nextLine();

		for (int t = 1; t <= T; ++t) {
			int N = a.nextInt();
			int s[] = new int[205];
	
			int sum = 0;
			for (int i = 0; i < N; ++i) {
				s[i] = a.nextInt();
	
				sum += s[i];				
			}
			
			double max = 0;
			
			boolean found = true;
			int bar = Integer.MAX_VALUE;
			do {
				int includedSum = 0;
				int includedCount = 0;
				for (int i = 0; i < N; ++i) {
					if (s[i] >= bar) continue;
					includedSum += s[i];
					includedCount += 1;
					
				}
				max = (double) (sum + includedSum) / (includedCount);
				found = true;
				for (int i = 0; i <N; ++i) {
					if (s[i] > max && s[i] < bar) {
						bar = s[i];
						found = false;
						break;
					}
				}
				
			} while (!found);

			w.write(String.format("Case #%d:", t));
			for (int i = 0; i < N; ++i) {
				double ratio = (double) (max - s[i]) * 100 / sum;
				if (ratio < 0) ratio = 0;
				w.write(String.format(" %.6f", ratio));
			}

			w.write("\n");

		}
		
		w.close();

	}
	
	
	
	


}
