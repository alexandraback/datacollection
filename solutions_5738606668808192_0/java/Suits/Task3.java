package suits.codejam.logic;

import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Hello world!
 *
 */
public class Task3 {
	public static void main(String[] args) throws FileNotFoundException, IOException {
		PrintWriter pw = new PrintWriter(new FileWriter("D:\\outPut.txt"));

		pw.println("Case #" + 1 + ":");
		int amount = 50;
		for (long i = 32769; i < 65536; i = i + 2) {
			String dividents = check(Long.valueOf(converter(i, 2)));
			if (dividents != "") {
				pw.println(converter(i, 2) + dividents);
				amount--;

			}
			if (amount == 0)
				break;
		}

		pw.close();
	}

	public static String check(long number) {
		String dividents = "";
		for (int i = 2; i < 11; i++) {
			String divident = isPrimNumber(Long.valueOf(Long.toString(Long.parseLong(String.valueOf(number), i), 10)));
			if (divident == "")
				return "";
			dividents = dividents + " " + divident;
		}
		return dividents;
	}

	public static String isPrimNumber(long numberToTest) {
		if (numberToTest % 2 == 0)
			return "2";
		for (long i = 3; i * i <= numberToTest; i += 2) {
			if (numberToTest % i == 0)
				return String.valueOf(i);
		}
		return "";
	}

	public static String converter(long number, int base) {
		long quot = number / base;
		long remaind = number % base;

		if (quot == 0) {
			return Long.toString(remaind);
		} else {
			return converter(quot, base) + Long.toString(remaind);
		}
	}
}
