

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;
import java.util.Set;

public class ProblemC2 {
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
				ones.add(0);
				ones.add(1);
				ones.add(N-2);
				ones.add(N-1);
				int all3Parity = 2;
				for (int i=2; i<N-6; i++) {
					if (i%2==1) continue;
					if (r.nextBoolean()) {
						ones.add(i);
						ones.add(i+1);
						all3Parity = (all3Parity + 1)%3;
					}
				}
				
				if (all3Parity==1) {
					ones.add(N-3);
					ones.add(N-4);
					ones.add(N-5);
					ones.add(N-6);
				}
				if (all3Parity==2) {
					ones.add(N-3);
					ones.add(N-4);
				}
				
				
				boolean isJamCoin = true;
				List<Long> divs = new LinkedList<>();
				for (int b=2; b<=10; b++) {
					final int base = b;
					BigInteger num = BigInteger.ZERO;
					for (int i: ones) {
						num = num.add(BigInteger.valueOf(base).pow(i));
					}
					long div = isPrime(num);
					if (div==-1) {
						isJamCoin = false;
						break;
					}
					divs.add(div);
				}
				
				BigInteger num = BigInteger.ZERO;
				for (int i: ones) {
					num = num.add(BigInteger.valueOf(10).pow(i));
				}
				String coin = num.toString();
				
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
	
	public static long isPrime(BigInteger x) {
		for (long i=2; x.compareTo(BigInteger.valueOf(i))>0; i++) {
			if (x.mod(BigInteger.valueOf(i))==BigInteger.ZERO) return i;
		}
		return -1;
	}
}
