import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;


public class ProblemA {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws Exception {
		
		int T = readInt();
		
		for (int caseNum=1; caseNum<=T; caseNum++) {
			
			int[] prm = readInts();
			int R = prm[0];
			int C = prm[1];
			int W = prm[2];
			
			int count = 0;
			count += (C/W) * (R-1);
			while (C>=2*W) {
				C-=W;
				count++;
			}
			
			count += solve(C, W, 0);
			
			System.out.println(String.format("Case #%d: %d", caseNum, count));
		}

	}
	
	private static int solve(int C, int W, int hits) {
		if (C==W) return W-hits;
		int min = Integer.MAX_VALUE;
		for (int i=0; i<C-W && i < Math.ceil(C/2.0); i++) {
			int miss = solve(C-i-1, W, hits);
			int hit = solve(i+W, W, hits+1);
			min = Math.min(min, 1+Math.max(miss, hit));
		}
		return min;
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(br.readLine());
	}
	
	private static int[] readInts() throws IOException {
		return Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
	}
}
