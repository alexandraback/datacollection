/*
 * 
 */
package codejam2016.round1b.a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Arrays;

/**
 *
 * @author Gabor Bakos
 */
public class GettingDigits {
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		String lineSep = System.getProperty("line.separator");
		try (BufferedReader br = new BufferedReader(
				args.length > 0 ? new FileReader(args[0]) : new InputStreamReader(System.in));
				Writer out = new BufferedWriter(
						args.length > 1 ? new FileWriter(args[1]) : new OutputStreamWriter(System.out))) {
			int numCases = Integer.parseInt(br.readLine().trim());
			for (int i = 1; i <= numCases; ++i) {
				String s = br.readLine();
				out.write("Case #" + i + ": " + phoneNumber(s, new StringBuilder(s.length())) + lineSep);
			}
		}
	}

	private static String phoneNumber(String s, StringBuilder present) {
		//0124567
		if (s.contains("Z")) {
			present.append("0");
			s = 			s.replaceFirst("Z", "");
			s = s.replaceFirst("E", "");
			s = s.replaceFirst("R", "");
			s = s.replaceFirst("O", "");
			phoneNumber(s, present);
		} else 		if (s.contains("W")) {
			present.append("2");
			s = s.replaceFirst("T", "");
			s = s.replaceFirst("W", "");
			s = s.replaceFirst("O", "");
			phoneNumber(s, present);
		}else
		if (s.contains("X")) {
			present.append("6");
			s = s.replaceFirst("S", "");
			s = s.replaceFirst("I", "");
			s = s.replaceFirst("X", "");
			phoneNumber(s, present);
		}else
		if (s.contains("S")) {
			present.append("7");
			s = s.replaceFirst("S", "");
			s = s.replaceFirst("E", "");
			s = s.replaceFirst("V", "");
			s = s.replaceFirst("E", "");
			s = s.replaceFirst("N", "");
			phoneNumber(s, present);
		} else
		if (s.contains("V")) {
			present.append("5");
			s = s.replaceFirst("F", "");
			s = s.replaceFirst("I", "");
			s = s.replaceFirst("V", "");
			s = s.replaceFirst("E", "");
			phoneNumber(s, present);
		}else
		if (s.contains("F")) {
			present.append("4");
			s = s.replaceFirst("F", "");
			s = s.replaceFirst("O", "");
			s = s.replaceFirst("U", "");
			s = s.replaceFirst("R", "");
			phoneNumber(s, present);
		}else
		if (s.contains("O")) {
			present.append("1");
			s = s.replaceFirst("O", "");
			s = s.replaceFirst("N", "");
			s = s.replaceFirst("E", "");
			phoneNumber(s, present);
		}else
		if (s.contains("G")) {
			present.append("8");
			s = s.replaceFirst("E", "");
			s = s.replaceFirst("I", "");
			s = s.replaceFirst("G", "");
			s = s.replaceFirst("H", "");
			s = s.replaceFirst("T", "");
			phoneNumber(s, present);
		}else
		if (s.contains("N")) {
			present.append("9");
			s = s.replaceFirst("N", "");
			s = s.replaceFirst("I", "");
			s = s.replaceFirst("N", "");
			s = s.replaceFirst("E", "");
			phoneNumber(s, present);
		}else
		if (s.contains("T")) {
			present.append("3");
			s = s.replaceFirst("T", "");
			s = s.replaceFirst("H", "");
			s = s.replaceFirst("R", "");
			s = s.replaceFirst("E", "");
			s = s.replaceFirst("E", "");
			phoneNumber(s, present);
		}
		char[] array = present.toString().toCharArray();
		Arrays.sort(array);
		return new String(array);
	}

}
