

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;

public class ProblemD {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws Exception {
		
		int cases = readInt();
		
		for (int caseNum=0; caseNum<cases; caseNum++) {
			
			int[] params = readInts();
			int K = params[0];
			int C = params[1];
			int S = params[2];
			
			if (S*C<K) {
				System.out.println(String.format("Case #%d: IMPOSSIBLE", caseNum+1));
				continue;
			}
			
			System.out.print(String.format("Case #%d:", caseNum+1));
			
			int next = 0;
			while (next<K) {
				BigInteger pos = BigInteger.ZERO;
				for (int i=0; i<C; i++) {
					int n = Math.min(next+i, K-1);
					pos = pos.add(BigInteger.valueOf(K).pow(i).multiply(BigInteger.valueOf(n)));
				}
				
				pos = pos.add(BigInteger.ONE);
				
				System.out.print(" " + pos);
				
				next = next + C;
			}
			
			System.out.println();
		}

	}
	
	private static int readInt() throws IOException {
		return Integer.parseInt(br.readLine());
	}
	
	private static int[] readInts() throws IOException {
		return Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
	}
	
}
