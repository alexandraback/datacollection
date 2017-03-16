import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class C {
	private ArrayList<Integer> primeInt;
	private ArrayList<BigInteger> primeBig;
	int maxCheck;
	BigInteger maxCheckBig;

	public C() {
		// TODO Auto-generated constructor stub
		primeInt = new ArrayList<>();
		primeBig = new ArrayList<>();
		maxCheck = 2;
		maxCheckBig = new BigInteger("2");
		primeInt.add(2);
		primeBig.add(maxCheckBig);
	}

	private void populatePrimes(int base2Low) {
		for (int i = 3; i < base2Low; i++) {
			isPrime(i);
		}
	}

	private String[] getJamcoins(int N, int J) {
		String[] jamCoins = new String[J];
		int count = 0;
		int base2Low = (int) Math.pow(2, N - 1);
		int base2High = (int) Math.pow(2, N);
		populatePrimes(base2Low);
		for (int i = base2Low + 1; i < base2High && count < J; i = i + 2) {
			int divisor2 = isPrime(i);
			if (divisor2 == 0)
				continue;
			String binaryString = binaryString(i);
			String jamCoin = getJamCoin(binaryString, divisor2, N);
			if (jamCoin != null) {
				jamCoins[count] = jamCoin;
				count++;
			}
		}

		return jamCoins;
	}

	private String getJamCoin(String binaryString, int divisor2, int n) {
		String[] divisors = new String[9];
		divisors[0] = "" + divisor2;
		for (int i = 3; i < 11; i++) {
			BigInteger number = getNumber(binaryString, i);
			BigInteger divisor = isPrime(number);
			if (divisor == null)
				return null;
			else
				divisors[i - 2] = divisor.toString();
		}
		StringBuilder result = new StringBuilder(binaryString);
		for (int i = 0; i < 9; i++) {
			result.append(" " + divisors[i]);
		}
		return result.toString();
	}

	private int isPrime(int num) {
		for (int i : primeInt) {
			if (num % i == 0)
				return i;
		}
		for (int i = maxCheck; i < num; i++) {
			isPrime(i);
			maxCheck = i;
			maxCheckBig = new BigInteger("" + i);
			if (num % i == 0){
				return i;
			}
		}
		maxCheck = num;
		maxCheckBig = new BigInteger("" + num);
		primeInt.add(num);
		primeBig.add(new BigInteger("" + num));
		return 0;
	}

	private BigInteger isPrime(BigInteger num) {
		BigInteger num0 = new BigInteger("0");
		BigInteger num1 = new BigInteger("1");
		BigInteger num2 = new BigInteger("2");
		BigInteger numBy2 = num.divide(num2).add(num1);
		for (BigInteger i : primeBig) {
			if (num.remainder(i).equals(num0))
				return i;
		}
		/*for (BigInteger i = maxCheckBig; i.compareTo(numBy2) < 0; i = i.add(num1)) {
			isPrime(i);
			maxCheckBig = i;
			if (num.remainder(i).equals(num0)) {
				return i;
			}
		}*/
		maxCheckBig = new BigInteger(num.toString());
		primeBig.add(new BigInteger(num.toString()));
		return null;
	}

	private String binaryString(int num) {
		StringBuilder bin = new StringBuilder();
		while (num > 0) {
			bin.append(num % 2);
			num = num / 2;
		}
		bin.reverse();
		return bin.toString();
	}

	private BigInteger getNumber(String binary, int base) {
		BigInteger number = new BigInteger("0");
		for (int i = 0; i < binary.length(); i++) {
			number = number.multiply(new BigInteger("" + base)).add(new BigInteger("" + binary.charAt(i)));
		}
		return number;
	}

	public static void main(String[] args) {
		Scanner in = null;
		C c = new C();
		try {
			in = new Scanner(System.in);
			int count = in.nextInt();
			in.nextLine();
			for (int test = 1; test <= count; test++) {
				int N = in.nextInt();
				int J = in.nextInt();
				String result[] = c.getJamcoins(N, J);
				System.out.println("Case #" + test + ":");
				for (int i = 0; i < J; i++) {
					System.out.println(result[i]);
				}
			}
			in.close();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
