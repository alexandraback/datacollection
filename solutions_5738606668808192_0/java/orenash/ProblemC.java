

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;
import java.util.Set;

public class ProblemC {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws Exception {
		
		int cases = readInt();
		
		for (int caseNum=0; caseNum<cases; caseNum++) {
			
			System.out.println(String.format("Case #%d:", caseNum+1));
			
			int[] params = readInts();
			int N = params[0];
			int J = params[1];
			
			Random r = new Random();
			
			Set<String> coins = new HashSet<>();
			while (coins.size()<J) {
				List<Integer> ones = new LinkedList<>();
				for (int i=1; i<N-1; i++) {
					if (r.nextBoolean()) {
						ones.add(i);
					}
				}
				boolean isJamCoin = true;
				List<Long> divs = new LinkedList<>();
				for (int b=2; b<=10; b++) {
					final int base = b;
					long num = ones.stream().mapToLong(i-> Math.round(Math.pow(base, i))).sum();
					num += Math.round(Math.pow(base, N-1)) + 1;
					long div = isPrime(num);
					if (div==-1) {
						isJamCoin = false;
						break;
					}
					divs.add(div);
				}
				String coin = String.valueOf(ones.stream().mapToLong(i-> Math.round(Math.pow(10, i))).sum() + 1 + Math.round(Math.pow(10, N-1)));
				
				if (isJamCoin && !coins.contains(coin)) {
					coins.add(coin);
					System.out.print(coin);
					divs.forEach(d -> System.out.print(" " + d));
					System.out.println();
				}
			}
		}

	}

	private static int readInt() throws IOException {
		return Integer.parseInt(br.readLine());
	}
	
	private static int[] readInts() throws IOException {
		return Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
	}
	
	public static long isPrime(long x) {
		for (long i=2; i<=Math.sqrt(x); i++) {
			if (x%i==0) return i;
		}
		return -1;
	}
}
