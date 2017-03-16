import java.io.*;
import java.util.*;


public class A {
	
	
	private static int [][] reachMap = new int[1005][1005];
	private static boolean [] explored = new boolean[1005];
	private static int N = 0;
	
	private static void visit(int [][] im, int []ni, int index) {
		if (explored[index]) {
			return;
		}
		
		for (int i = 0; i < ni[index]; ++i) {
			int inh = im[index][i];
			++reachMap[index][inh];
			if (!explored[inh]) {
				visit(im, ni, inh);
			}
			
			for (int j = 0; j < N; ++j) {
				if (reachMap[inh][j] != 0) {
					++reachMap[index][j];
				}
			}
		}
		
		explored[index] = true;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Scanner a = new Scanner(new File("src/input"));
		FileWriter w = new FileWriter(new File("src/output"));
		int T = a.nextInt();
		a.nextLine();

		for (int t = 1; t <= T; ++t) {
			N = a.nextInt();
			reachMap = new int[1005][1005];
			explored = new boolean[1005];
			int [] ni = new int[1005];
			int [][] im = new int[1005][15];
			
			for (int i = 0; i < N; ++i) {
				ni[i] = a.nextInt();
				for (int j = 0; j < ni[i]; ++j) {
					im[i][j] = a.nextInt() - 1;
				}
			}
			
			for (int i = 0; i < N; ++i) {
				visit(im, ni, i);
			}
			
			boolean diamond = false;
			outer: for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					if (reachMap[i][j] > 1) {
						diamond = true;
						break outer;
					}
				}
			}
			
			String value = diamond? "Yes": "No";
			w.write(String.format("Case #%d: %s\n", t, value));

		}
		
		w.close();

	}
	
	
	
	


}
