import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;


public class Jamcoins {
	private static final boolean INDEBUG = true;
	public static BigInteger getBigIntegerBase(String number, int baseInt) {
		BigInteger temp = new BigInteger("0");
		BigInteger base = new BigInteger("" + baseInt);
		for (int i = 0; i < number.length(); i++) {
			temp = temp.multiply(base).add(number.charAt(i) == '1' ? BigInteger.ONE : BigInteger.ZERO);
			if (INDEBUG && number.charAt(i) != '1' && number.charAt(i) != '0') {
				System.out.println("Big problem - not binary number");
			}
		}
		return temp;
	}
	
	public static void printDivisors(BufferedWriter out, String bigNumber, String divisor) throws IOException {
		out.write(bigNumber);
		for (int i = 2; i <= 10; i++) {
			BigInteger div = getBigIntegerBase(divisor, i);
			
			if (INDEBUG) {
				BigInteger baseNumber = getBigIntegerBase(bigNumber, i);
				if (!baseNumber.remainder(div).equals(BigInteger.ZERO)) {
					System.out.println("Problem in division!! " + baseNumber + " " + div + " base " + i);
				}
			}
			out.write(" ");
			out.write(div.toString());
		}
		out.write("\n");
	}
	
	private static String convertToBinary(int n) {
		StringBuilder sb = new StringBuilder();
		while (n > 0) {
			sb.append(n % 2 == 1 ? '1' : '0');
			n /= 2;
		}
		return sb.reverse().toString();
	}
	
	private static String getNumber(int length, String base) {
		StringBuilder result = new StringBuilder();
		int numZeroes = length - base.length() - 2;
		result.append('1');
		for (int i = 0; i < numZeroes; i++) {
			result.append('0');
		}
		result.append(base);
		result.append('1');
		return result.toString();
	}
	
	private static void solve(BufferedWriter out, int length, int numberAnswers) throws IOException {
		String divisorGeneralFormat = "1%%0%dd1";
		String divisorFormat = String.format(divisorGeneralFormat, length - 1);
		String divisor = String.format(divisorFormat, 0);
		for (int i = 0; i < numberAnswers; i++) {
			String number = getNumber(length, convertToBinary(i));
			number = number + number;
			printDivisors(out, number, divisor);
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		File intput = new File("google.in");
		File output = new File("google.out");
		Scanner sc = new Scanner(intput);
		FileWriter outputBuffer = new FileWriter(output);
		BufferedWriter out = new BufferedWriter(outputBuffer);
		int numTests;
		numTests = sc.nextInt();
		for(int o = 0; o < numTests; o++)
		{
			out.write("Case #" + (o + 1) + ":\n");
			int n = sc.nextInt();
			n /= 2;
			int j = sc.nextInt();
			solve(out, n, j);
		}
		out.close();
		sc.close();

	}
}
