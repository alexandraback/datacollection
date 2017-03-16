import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;


public class ProblemC {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws Exception {
		
		int T = readInt();
		
		for (int caseNum=1; caseNum<=T; caseNum++) {
			int[] prms = readInts();
			int C = prms[0];
			int D = prms[1];
			int V = prms[2];
			int[] coins = readInts();
			Set<Integer> coinSet = new HashSet<Integer>();
			for (int c : coins) {
				coinSet.add(c);
			}
			
			int i;
			for (i=0; i<5; i++) {
				boolean success = choose(coinSet, i, 1, C, V);
				if (success) {
					break;
				}
			}
			
			
			System.out.println(String.format("Case #%d: %d", caseNum, i));
		}

	}
	

	private static boolean choose(Set<Integer> coins, int more, int start, int c, int v) {
		if (more==0) {
			boolean[] values = new boolean[v+1];
			Integer[] cArr = new Integer[coins.size()];
			coins.toArray(cArr);
			for (int i=0; i<Math.pow(2, coins.size()); i++) {
				int ii = i;
				int sum = 0;
				for (int j=0; j<coins.size(); j++) {
					boolean take = ii % 2 == 1;
					if (take) sum+= cArr[j];
					ii /=2;
				}
				if (sum<=v) values[sum] = true;
			}
			for (int i=1; i<=v; i++) {
				if (!values[i]) return false;
			}
			return true;
	
		} else {
			for (int i=start; i<=v; i++) {
				if (!coins.contains(i)) {
					coins.add(i);
					if (choose(coins, more-1, i+1, c, v))
						return true;
					coins.remove(i);
				}
			}
			return false;
		}
	}


	private static int readInt() throws IOException {
		return Integer.parseInt(br.readLine());
	}
	
	private static int[] readInts() throws IOException {
		return Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
	}
}
