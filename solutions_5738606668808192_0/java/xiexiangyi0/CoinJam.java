
import java.lang.Math;
import java.math.BigInteger;
import java.util.Set;
import java.util.HashSet;

public class CoinJam {
	private static class Result {
		public String number;
		public BigInteger[] divisors;

		public Result(String number) {
			this.number = number;
			this.divisors = new BigInteger[11];
		}
	}

	Result[] solve(int num_bits, int num_result) {
		Result[] results = new Result[num_result];
		Set<String> dict = new HashSet<String>();

		int cur_result_num = 0;
		while (cur_result_num < num_result) {
			String digits = randomCoinJam(num_bits);
			if (dict.contains(digits)) {
				// System.out.println("number already tested " + digits);
				continue;
			}
			dict.add(digits);

			// System.out.println("test number " + digits);

			Result result = new Result(digits);
			boolean is_coin_jam = true;
			for (int base = 2; base <= 10; ++base) {
				BigInteger number = new BigInteger(digits, base);
				if (number.isProbablePrime(100)) {
					is_coin_jam = false;
					break;
				}

				BigInteger divisor = new BigInteger("2");
				int num_test = 0;
				while (!number.mod(divisor).equals(BigInteger.ZERO)
						&& num_test < 1000) {
					divisor = divisor.nextProbablePrime();
					num_test++;
				}

				if (number.mod(divisor).equals(BigInteger.ZERO)) {
					result.divisors[base] = divisor;
				} else {
					is_coin_jam = false;
					break;
				}
			}

			if (is_coin_jam) {
				results[cur_result_num] = result;
				cur_result_num++;
				//System.out.println("Find " + result.number);
			}
		}

		return results;
	}

	String randomCoinJam(int num_bits) {
		StringBuilder digits = new StringBuilder(num_bits);

		digits.append('1');

		for (int i = 1; i <= num_bits - 2; ++i) {
			double ran = Math.random();
			if (ran < 0.5) {
				digits.append('0');
			} else {
				digits.append('1');
			}
		}

		digits.append('1');

		return digits.toString();
	}
	
	
	public static void main(String[] args) {
		CoinJam coin_jam = new CoinJam();
		int N = 16, J = 50;
		Result[] results = coin_jam.solve(N, J);

		System.out.println("Case #1:");
		for (int i = 0; i < J; ++i) {
			System.out.print(results[i].number);
			for (int base = 2; base <= 10; ++base) {
				System.out.print(" " + results[i].divisors[base].toString());
			}
			System.out.print("\n");
		}
	}
}
