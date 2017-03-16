package suits.codejam.logic;

import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;

/**
 * Hello world!
 *
 */
public class Task3 {
	public static void main(String[] args) throws FileNotFoundException, IOException {
		PrintWriter pw = new PrintWriter(new FileWriter("D:\\outPut.txt"));

		pw.println("Case #" + 1 + ":");
		int amount = 500;
		for (long i = 2147483649L; i < 4294967295L; i = i + 2) {
//		for (long i = 32769L; i < 65535L; i = i + 2) {
			String dividents = check(converter(i, 2));
			if (dividents != "") {
				pw.println(converter(i, 2) + dividents);
				amount--;
				System.out.println("done");

			}
			if (amount == 0)
				break;
		}

		pw.close();
	}

	public static String check(String number) {
		
		String dividents = "";
		for (int i = 2; i < 11; i++) {
			String divident = isPrimNumber(new BigInteger(number,i));
			if (divident == "")
				return "";
			dividents = dividents + " " + divident;
		}
		return dividents;
	}

	public static String isPrimNumber(BigInteger numberToTest) {
		if (numberToTest.mod(new BigInteger("2")) == new BigInteger("0"))
			return "2";
		for (long i = 3; new BigInteger(String.valueOf(i * i)).compareTo(numberToTest) != 1; i += 2) {
			if (numberToTest.mod(new BigInteger(String.valueOf(i))).equals(new BigInteger("0")))
				return String.valueOf(i);
			if (i >= 1000000)
				return "";
		}
		return "";
	}

	public static String converter(long number, int base) {
		long quot = number / base;
		long remaind = number % base;

		if (quot == 0) {
			return new BigInteger(String.valueOf(remaind)).toString();
		} else {
			return converter(quot, base) + Long.toString(remaind);
		}
	}
}
