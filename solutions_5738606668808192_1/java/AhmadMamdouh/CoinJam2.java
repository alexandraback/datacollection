import java.math.BigInteger;
import java.util.Arrays;
import java.util.Random;

public class CoinJam2 {
	public static void main(String[] args) {
		int cnt=0;
		char[] arr = new char[32];
		BigInteger[] divisors = new BigInteger[1010];
		for (int i = 0; i < divisors.length; i++) {
			divisors[i] = new BigInteger(i + "");
		}
		arr[0] = '1';
		arr[31] = '1';
		Random rand = new Random();
		while (true) {
			for (int i = 1; i < 31; i++) {
				if (rand.nextFloat() < 0.5)
					arr[i] = '0';
				else
					arr[i] = '1';
			}
			BigInteger[] div = new BigInteger[11];
			Arrays.fill(div, BigInteger.ZERO);
			for (int base = 2; base <= 10; base++) {
				BigInteger big = new BigInteger(new String(arr), base);
				for (int x = 2; x <= 1000; x++) {
					if (big.mod(divisors[x]).equals(BigInteger.ZERO)) {
						div[base] = divisors[x];
						break;
					}
				}
			}
			boolean can = true;
			for (int i = 2; i < div.length; i++) {
				if (div[i].equals(BigInteger.ZERO))
					can = false;
			}
			if (can) {
				System.out.print(new String(arr));
				for (int i = 2; i < div.length; i++) {
					System.out.print(" " + div[i]);
				}
				System.out.println();
				cnt++;
				if(cnt==500){
					return;
				}
			}
		}
	}
}
