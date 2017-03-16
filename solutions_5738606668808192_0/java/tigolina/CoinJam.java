import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CoinJam {

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int testCount = in.nextInt();
		
		for (int test = 0; test < testCount; test++) {
			int N = in.nextInt();
			int J = in.nextInt();
			
			solveCase(test, N, J);
		}
		
		in.close();
	}
	
	private static void solveCase(int test, int length, int maxCount) {
		long start = (1L << length - 1) + 1;
		long end = (1L << length) - 1;
		int count = 0;
		
		System.out.println("Case #" + (test + 1) + ":");
		for (long l = start; l <= end && count < maxCount; l+=2) {
			Coin coin = new Coin(l);
			if (coin.isValid()) {
				count++;
				System.out.println(coin);
			}
		}
	}
	
	private static class Coin {
		private long coinValue;
		private List<Long> divisorList = new ArrayList<>();
		
		public Coin(long coinValue) {
			this.coinValue = coinValue;
			validate();
		}
		
		public boolean isValid() {
			return divisorList.size() == 9;
		}

		@Override
		public String toString() {
			String divisors = "";
			for (long l : divisorList) {
				divisors = divisors + l + " ";
			}
			return Long.toString(coinValue, 2) + " " + divisors.trim();
		}
		
		private void validate() {
			if (coinValue % 2 == 0) {
				return;
			}
			String binarString = Long.toString(coinValue, 2);
			for (int base = 2; base <= 10; base++) {
				boolean isPrime = true;
				long valueByBase = Long.parseLong(binarString, base);
				for (long div = 2; div <= valueByBase / 2 && div < 1000; div++) {
					if (valueByBase % div == 0) {
						divisorList.add(div);
						isPrime = false;
						break;
					}
				}
				if (isPrime) {
					break;
				}
			}
		}
	}
}
